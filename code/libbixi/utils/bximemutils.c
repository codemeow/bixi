/*
 * "Bixi" - Basic types management C89 library
 *
 *  Copyright (C) Alexey Shishkin 2017
 *
 *  This file is part of Project "Bixi".
 *
 *  Project "Bixi" is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Project "Bixi" is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with Project "Bixi". If not, see <http://www.gnu.org/licenses/>.
 */

#include "../definitions/bximacros.h"
#include "../utils/bximemutils.h"
#include "../math/bximath.h"
#include "../definitions/bxienv.h"
#include "../utils/bxibitutils.h"

/* As linux systems use overcommit tech by default
 * we only can receive trusted block of memory by
 * manually zerofying the received block. That is
 * why BXI_MEM_ZERO is enabled by default       */
bxi_memopt_t bxi_memopt_val = BXI_MEM_ZERO;

static void * bxi_malloc_dummy (            u32 size, const char * file, u32 line);
static void   bxi_free_dummy   (void * ptr          , const char * file, u32 line);
static void * bxi_realloc_dummy(void * ptr, u32 size, const char * file, u32 line);
static void   bxi_memerr_dummy (            u32 size, const char * file, u32 line);

bxi_malloc_t  bxi_malloc_func  = bxi_malloc_dummy;
bxi_free_t    bxi_free_func    = bxi_free_dummy;
bxi_realloc_t bxi_realloc_func = bxi_realloc_dummy;
bxi_memerr_t  bxi_memerr_func  = bxi_memerr_dummy;

static void * bxi_malloc_dummy(u32 size, const char * file, u32 line)
{
    UNUSED(size);
    UNUSED(file);
    UNUSED(line);
    return NULL;
}

static void bxi_free_dummy(void * ptr, const char * file, u32 line)
{
    UNUSED(ptr);
    UNUSED(file);
    UNUSED(line);
}

static void * bxi_realloc_dummy(void * ptr, u32 size, const char * file, u32 line)
{
    UNUSED(ptr);
    UNUSED(size);
    UNUSED(file);
    UNUSED(line);
    return NULL;
}

static void bxi_memerr_dummy(u32 size, const char * file, u32 line)
{
    UNUSED(size);
    UNUSED(file);
    UNUSED(line);
}

void bxi_malloc_set (bxi_malloc_t   func) { bxi_malloc_func  = func;   }
void bxi_free_set   (bxi_free_t     func) { bxi_free_func    = func;   }
void bxi_realloc_set(bxi_realloc_t  func) { bxi_realloc_func = func;   }
void bxi_memerr_set (bxi_memerr_t   func) { bxi_memerr_func  = func;   }
void bxi_memopt_set (bxi_memopt_t memopt) { bxi_memopt_val   = memopt; }

void * bxi_malloc_call(u32 size, const char * file, u32 line)
{
    void * mem = bxi_malloc_func(size, file, line);

    if (!mem)
    {
        bxi_memerr_func(size, file, line);
        return NULL;
    }

    if (bxi_memopt_val & BXI_MEM_ZERO)
        bxi_memset(mem, 0, size);

    return mem;
}

void bxi_free_call(void * ptr, const char * file, u32 line)
{
    bxi_free_func(ptr, file, line);
}

void * bxi_realloc_call(void * ptr, u32 size, const char * file, u32 line)
{
    void * mem = bxi_realloc_func(ptr, size, file, line);
    if (!mem && size)
        bxi_memerr_func(size, file, line);
    else
        ptr = mem;
    return ptr;
}

void * bxi_memmove(void * dst, const void * src, u32 cnt)
{
          u32 i;
          u32 pre;
          u32 cen;
          u32 end;
           u8 * dst_u8 = dst;
    const  u8 * src_u8 = src;
          pu_t * dst_pt;
    const pu_t * src_pt;
    const u32  presh = sizeof(pu_t) - 1;

    if (!dst)
        return NULL;
    if (!src)
        return dst;
    if (dst == src)
        return dst;
    if (!cnt)
        return dst;

    pre = BXI_MIN((BXI_WORD_SIZE - ((pu_t)dst & (BXI_WORD_SIZE - 1)))
                  & (BXI_WORD_SIZE - 1), cnt);
    cen = (cnt - pre) / BXI_WORD_SIZE;
    end =  cnt - pre - (cen * BXI_WORD_SIZE);

    if (dst > src)
    {
        dst_u8 += cnt - 1;
        src_u8 += cnt - 1;
        for (i = 0; i < end; i++, dst_u8--, src_u8--)
            *dst_u8 = *src_u8;

        if (cen)
        {
            dst_pt = (      pu_t *)(dst_u8 - presh);
            src_pt = (const pu_t *)(src_u8 - presh);
            for (i = 0; i < cen; i++, dst_pt--, src_pt--)
            {
                /* I'm not sure if we can directly copy
             * overlapping areas like this, therefore
             * I'm having a buffer                 */
                /* [ ][ ][ ][ ][ ][ ][ ][ ]
             *    [   dst    ]
             *          [    src   ]               */
                pu_t pp = *src_pt;
                *dst_pt = pp;
            }

            dst_u8 = (      u8 *)dst_pt + presh;
            src_u8 = (const u8 *)src_pt + presh;
        }

        for (i = 0; i < pre; i++, dst_u8--, src_u8--)
            *dst_u8 = *src_u8;
    }
    else
    {
        for (i = 0; i < pre; i++, dst_u8++, src_u8++)
            *dst_u8 = *src_u8;

        dst_pt = (      pu_t *)dst_u8;
        src_pt = (const pu_t *)src_u8;
        for (i = 0; i < cen; i++, dst_pt++, src_pt++)
        {
            /* I'm not sure if we can directly copy
             * overlapping areas like this, therefore
             * I'm having a buffer                 */
            /* [ ][ ][ ][ ][ ][ ][ ][ ]
             *    [   dst    ]
             *          [    src   ]               */
            pu_t pp = *src_pt;
            *dst_pt = pp;
        }

        dst_u8 = (      u8 *)dst_pt;
        src_u8 = (const u8 *)src_pt;
        for (i = 0; i < end; i++, dst_u8++, src_u8++)
            *dst_u8 = *src_u8;
    }

    return dst;
}

void * bxi_memset(void * ptr, i32 val, u32 cnt)
{
    pu_t f = 0;
    u32 i;
    u32 pre;
    u32 cen;
    u32 end;
    u8   * ptr_u8 = ptr;
    pu_t * ptr_pt;

    if (!ptr)
        return NULL;
    if (!cnt)
        return ptr;

    pre = BXI_MIN((BXI_WORD_SIZE - ((pu_t)ptr & (BXI_WORD_SIZE - 1)))
                  & (BXI_WORD_SIZE - 1), cnt);
    cen = (cnt - pre) / BXI_WORD_SIZE;
    end =  cnt - pre - (cen * BXI_WORD_SIZE);

    f = val & 0xFF;
    f |= f << 8;
    f |= f << 16;
#   if defined(BXI_BITS_64)
        f |= f << 32;
#   endif


    for (i = 0; i < pre; i++, ptr_u8++)
        *ptr_u8 = val;
    ptr_pt = (pu_t *)ptr_u8;
    for (i = 0; i < cen; i++, ptr_pt++)
        *ptr_pt = f;
    ptr_u8 = (u8 *)ptr_pt;
    for (i = 0; i < end; i++, ptr_u8++)
        *ptr_u8 = val;

    return ptr;
}

void * bxi_memset16(void * ptr, u32 val, u32 cnt)
{
    pu_t   fll    = val & 0xffff;
    pu_t   shf    = (BXI_WORD_SIZE - ((pu_t)ptr & (BXI_WORD_SIZE - 1))) &
                    (BXI_WORD_SIZE - 1);
    pu_t * ptr_pt;
    u8   * ptr_u8 = ptr;

    fll |= fll << 16;
#   if defined(BXI_BITS_64)
        fll |= fll << 32;
#   endif

    if (!ptr)
        return NULL;
    if (!cnt)
        return ptr;

    cnt <<= 1;

    if (shf % 2)
        fll = fll >> 8 | fll << ((sizeof(pu_t) << 3) - 8);

    while (cnt && shf)
    {
        if (cnt % 2) *ptr_u8++ = (val >> 8) & 0xff;
                else *ptr_u8++ = (val     ) & 0xff;
        cnt--;
        shf--;
    }

    ptr_pt = (pu_t *)ptr_u8;
    while (cnt > BXI_WORD_SIZE)
    {
        *ptr_pt++ = fll;
        cnt -= BXI_WORD_SIZE;
    }

    ptr_u8 = (u8 *)ptr_pt;
    while (cnt)
    {
        if (cnt % 2) *ptr_u8++ = (val >> 8) & 0xff;
                else *ptr_u8++ = (val     ) & 0xff;
        cnt--;
    }

    return ptr;
}


void * bxi_memset32(void * ptr, u32 val, u32 cnt)
{
    pu_t   fll    = val;
    pu_t   shf    = (BXI_WORD_SIZE - ((pu_t)ptr & (BXI_WORD_SIZE - 1))) &
                    (BXI_WORD_SIZE - 1);
    pu_t * ptr_pt;
    u8   * ptr_u8 = ptr;

#   if defined(BXI_BITS_64)
        fll |= fll << 32;
#   endif

    if (!ptr)
        return NULL;
    if (!cnt)
        return ptr;

    cnt <<= 2;

    switch (shf % 4)
    {
    case  1: fll = fll >> 0x08 | fll << ((sizeof(pu_t) << 3) - 0x08); break;
    case  2: fll = fll >> 0x10 | fll << ((sizeof(pu_t) << 3) - 0x10); break;
    case  3: fll = fll >> 0x18 | fll << ((sizeof(pu_t) << 3) - 0x18); break;
    default: break;
    }

    while (cnt && shf)
    {
        switch (cnt % 4)
        {
        case  0: *ptr_u8++ = (val         ) & 0xff; break;
        case  1: *ptr_u8++ = (val >> 0x18 ) & 0xff; break;
        case  2: *ptr_u8++ = (val >> 0x10 ) & 0xff; break;
        default: *ptr_u8++ = (val >> 0x08 ) & 0xff; break;
        }
        cnt--;
        shf--;
    }

    ptr_pt = (pu_t *)ptr_u8;
    while (cnt > BXI_WORD_SIZE)
    {
        *ptr_pt++ = fll;
        cnt -= BXI_WORD_SIZE;
    }

    ptr_u8 = (u8 *)ptr_pt;
    while (cnt)
    {
        switch (cnt % 4)
        {
        case  0: *ptr_u8++ = (val         ) & 0xff; break;
        case  1: *ptr_u8++ = (val >> 0x18 ) & 0xff; break;
        case  2: *ptr_u8++ = (val >> 0x10 ) & 0xff; break;
        default: *ptr_u8++ = (val >> 0x08 ) & 0xff; break;
        }
        cnt--;
    }

    return ptr;
}


void * bxi_memcpy(void * dst, const void * src, u32 cnt)
{
          u32   pre;
          u32   cen;
          u32   end;
           u8 * dst_u8 = dst;
   const   u8 * src_u8 = src;
         pu_t * dst_pt;
   const pu_t * src_pt;
          u32   i;

    if (!dst)
        return NULL;
    if (!src)
        return dst;
    if (!cnt)
        return dst;

    if ((((u8 *)src < ((u8 *)dst) + cnt) && ((u8 *)src > (u8 *)dst)) ||
        (((u8 *)dst < ((u8 *)src) + cnt) && ((u8 *)dst > (u8 *)src)))
        return bxi_memmove(dst, src, cnt);

    pre = BXI_MIN((BXI_WORD_SIZE - ((pu_t)dst & (BXI_WORD_SIZE - 1)))
                  & (BXI_WORD_SIZE - 1), cnt);
    cen = (cnt - pre) / BXI_WORD_SIZE;
    end =  cnt - pre - (cen * BXI_WORD_SIZE);

    for (i = 0; i < pre; i++, dst_u8++, src_u8++)
        *dst_u8 = *src_u8;

    dst_pt = (      pu_t *)dst_u8;
    src_pt = (const pu_t *)src_u8;
    for (i = 0; i < cen; i++, dst_pt++, src_pt++)
        *dst_pt = *src_pt;

    dst_u8 = (      u8 *)dst_pt;
    src_u8 = (const u8 *)src_pt;
    for (i = 0; i < end; i++, dst_u8++, src_u8++)
        *dst_u8 = *src_u8;

    return dst;
}

i32 bxi_memcmp(const void * p1, const void * p2, u32 cnt)
{
    const u8   * p1_u8 = p1;
    const u8   * p2_u8 = p2;
    const pu_t * p1_pt = p1;
    const pu_t * p2_pt = p2;

    if (p1_u8 == p2_u8)
        return 0;
    if (p1_u8 == NULL)
        return *p2_u8;
    if (p2_u8 == NULL)
        return *p1_u8;
    if (!cnt)
        return 0;

    if (((pu_t)p1_pt & (BXI_WORD_SIZE - 1)) ==
        ((pu_t)p2_pt & (BXI_WORD_SIZE - 1)))
    {
        u32 skip = BXI_MIN((BXI_WORD_SIZE - ((pu_t)p1_pt
                           & (BXI_WORD_SIZE - 1)))
                           & (BXI_WORD_SIZE - 1), cnt);
        if (skip)
        {
            while ((skip--) && (cnt--))
            {
                if      (*p1_u8 < *p2_u8)
                    return -(*p2_u8 - *p1_u8);
                else if (*p1_u8 > *p2_u8)
                    return  (*p1_u8 - *p2_u8);
                p1_u8++;
                p2_u8++;
            }
            p1_pt = (const pu_t *)p1_u8;
            p2_pt = (const pu_t *)p2_u8;
        }

        while (cnt >= BXI_WORD_SIZE)
        {
            if (*p1_pt < *p2_pt)
            {
                p1_u8 = (const u8 *)p1_pt;
                p2_u8 = (const u8 *)p2_pt;
                while (*p1_u8 == *p2_u8)
                {
                    p1_u8++;
                    p2_u8++;
                }
                return -(*p2_u8 - *p1_u8);
            }
            else if (*p1_pt > *p2_pt)
            {
                p1_u8 = (const u8 *)p1_pt;
                p2_u8 = (const u8 *)p2_pt;
                while (*p1_u8 == *p2_u8)
                {
                    p1_u8++;
                    p2_u8++;
                }
                return  (*p1_u8 - *p2_u8);
            }
            p1_pt++;
            p2_pt++;
            cnt -= BXI_WORD_SIZE;
        }
        p1_u8 = (const u8 *)p1_pt;
        p2_u8 = (const u8 *)p2_pt;
    }

    while (cnt--)
    {
        if      (*p1_u8 < *p2_u8)
            return -(*p2_u8 - *p1_u8);
        else if (*p1_u8 > *p2_u8)
            return  (*p1_u8 - *p2_u8);
        p1_u8++;
        p2_u8++;
    }

    return 0;
}

void * bxi_memfrob(void * ptr, u8 val, u32 cnt)
{
    pu_t f = 0;
    u32 i;
    u32 pre;
    u32 cen;
    u32 end;
    u8   * ptr_u8 = ptr;
    pu_t * ptr_pt;

    if (!ptr)
        return NULL;
    if (!cnt)
        return ptr;

    pre = BXI_MIN((BXI_WORD_SIZE - ((pu_t)ptr & (BXI_WORD_SIZE - 1)))
                  & (BXI_WORD_SIZE - 1), cnt);
    cen = (cnt - pre) / BXI_WORD_SIZE;
    end =  cnt - pre - (cen * BXI_WORD_SIZE);

    f = val;
    f |= f << 8;
    f |= f << 16;
#   if defined(BXI_BITS_64)
        f |= f << 32;
#   endif

    for (i = 0; i < pre; i++, ptr_u8++)
        *ptr_u8 ^= val;
    ptr_pt = (pu_t *)ptr_u8;
    for (i = 0; i < cen; i++, ptr_pt++)
        *ptr_pt ^= f;
    ptr_u8 = (u8 *)ptr_pt;
    for (i = 0; i < end; i++, ptr_u8++)
        *ptr_u8 ^= val;

    return ptr;
}

void * bxi_memchr (const void * ptr, u8 val, u32 cnt)
{
    u32 i;
    const u8 * ptru8 = (const u8 *)ptr;
    if (!ptr)
        return NULL;
    if (!cnt)
        return NULL;

    for (i = 0; i < cnt; i++)
        if (ptru8[i] == val)
            return (void *)(ptru8 + i);
    return NULL;
}

void * bxi_memrchr(const void * ptr, u8 val, u32 cnt)
{
    const u8 * ptru8 = (const u8 *)ptr;
    if (!ptr)
        return NULL;
    if (!cnt)
        return NULL;

    ptru8 += cnt;
    while (cnt--)
        if (*ptru8-- == val)
            return (void *)(ptru8 + 1);

    if (*ptru8 == val)
        return (void *)(ptru8);

    return NULL;
}

void * bxi_mempcpy(void * dst, const void * src, u32 cnt)
{
    if (!dst)
        return NULL;
    if (!src)
        return dst;

    return (u8 *)bxi_memcpy(dst, src, cnt) + cnt;
}

void * bxi_memccpy(void * dst, const void * src, i32 c, u32 cnt)
{
    const u8 * src_u8  = src;
         u32   src_cnt = cnt;

    if (!dst)
        return NULL;
    if (!src)
        return dst;

    c &= 0xff;

    while (src_cnt)
    {
        if (*src_u8++ == c)
            break;

        src_cnt--;
    }

    return (u8 *)bxi_memcpy(dst, src, src_cnt) + (cnt - src_cnt + 1);
}
