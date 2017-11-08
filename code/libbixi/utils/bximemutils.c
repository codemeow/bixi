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
        bxi_memerr_func(size, file, line);

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
          u32 * dst_u32;
    const u32 * src_u32;

    if (!dst)
        return NULL;
    if (!src)
        return dst;
    if (dst == src)
        return dst;

    pre = BXI_MIN((4 - ((pu_t)dst & 3)) & 3, cnt);
    cen = (cnt - pre) >> 2;
    end = cnt - pre - (cen << 2);

    if (dst > src)
    {
        dst_u8 += cnt - 1;
        src_u8 += cnt - 1;
        for (i = 0; i < end; i++, dst_u8--, src_u8--)
            *dst_u8 = *src_u8;

        if (cen)
        {
            dst_u32 = (      u32 *)(dst_u8 - 3);
            src_u32 = (const u32 *)(src_u8 - 3);
            for (i = 0; i < cen; i++, dst_u32--, src_u32--)
            {
                /* I'm not sure if we can directly copy
             * overlapping areas like this, therefore
             * I'm having a buffer                 */
                /* [ ][ ][ ][ ][ ][ ][ ][ ]
             *    [   dst    ]
             *          [    src   ]               */
                u32 pp = *src_u32;
                *dst_u32 = pp;
            }

            dst_u8 = (      u8 *)dst_u32 + 3;
            src_u8 = (const u8 *)src_u32 + 3;
        }

        for (i = 0; i < pre; i++, dst_u8--, src_u8--)
            *dst_u8 = *src_u8;
    }
    else
    {
        for (i = 0; i < pre; i++, dst_u8++, src_u8++)
            *dst_u8 = *src_u8;

        dst_u32 = (      u32 *)dst_u8;
        src_u32 = (const u32 *)src_u8;
        for (i = 0; i < cen; i++, dst_u32++, src_u32++)
        {
            /* I'm not sure if we can directly copy
             * overlapping areas like this, therefore
             * I'm having a buffer                 */
            /* [ ][ ][ ][ ][ ][ ][ ][ ]
             *    [   dst    ]
             *          [    src   ]               */
            u32 pp = *src_u32;
            *dst_u32 = pp;
        }

        dst_u8 = (      u8 *)dst_u32;
        src_u8 = (const u8 *)src_u32;
        for (i = 0; i < end; i++, dst_u8++, src_u8++)
            *dst_u8 = *src_u8;
    }

    return dst;
}

/* @todo 4-bytes memset via asm like in smilo */

void * bxi_memset(void * ptr, i32 val, u32 cnt)
{
    u32 f = 0;
    u32 i;
    u32 pre;
    u32 cen;
    u32 end;
    u8  * ptr_u8 = ptr;
    u32 * ptr_u32;

    if (!ptr)
        return NULL;

    pre = BXI_MIN((4 - ((pu_t)ptr & 3)) & 3, cnt);
    cen = (cnt - pre) >> 2;
    end = cnt - pre - (cen << 2);

    f = val & 0xFF;
    f |= f << 8;
    f |= f << 16;

    for (i = 0; i < pre; i++, ptr_u8++)
        *ptr_u8 = val;
    ptr_u32 = (u32 *)ptr_u8;
    for (i = 0; i < cen; i++, ptr_u32++)
        *ptr_u32 = f;
    ptr_u8 = (u8 *)ptr_u32;
    for (i = 0; i < end; i++, ptr_u8++)
        *ptr_u8 = val;

    return ptr;
}

void * bxi_memcpy(void * dst, const void * src, u32 cnt)
{
         u32   pre;
         u32   cen;
         u32   end;
          u8 * dst_u8 = dst;
   const  u8 * src_u8 = src;
         u32 * dst_u32;
   const u32 * src_u32;
         u32   i;

    if (!dst)
        return NULL;
    if (!src)
        return dst;

    if ((((u8 *)src < ((u8 *)dst) + cnt) && ((u8 *)src > (u8 *)dst)) ||
        (((u8 *)dst < ((u8 *)src) + cnt) && ((u8 *)dst > (u8 *)src)))
        return bxi_memmove(dst, src, cnt);

    pre = BXI_MIN((4 - ((pu_t)dst & 3)) & 3, cnt);
    cen = (cnt - pre) >> 2;
    end = cnt - pre - (cen << 2);

    for (i = 0; i < pre; i++, dst_u8++, src_u8++)
        *dst_u8 = *src_u8;

    dst_u32 = (      u32 *)dst_u8;
    src_u32 = (const u32 *)src_u8;
    for (i = 0; i < cen; i++, dst_u32++, src_u32++)
        *dst_u32 = *src_u32;

    dst_u8 = (      u8 *)dst_u32;
    src_u8 = (const u8 *)src_u32;
    for (i = 0; i < end; i++, dst_u8++, src_u8++)
        *dst_u8 = *src_u8;

    return dst;
}

i32 bxi_memcmp(const void * p1, const void * p2, u32 cnt)
{
  u32 i;
  const u8 * p1u8 = (const u8 *) p1;
  const u8 * p2u8 = (const u8 *) p2;

  if (p1u8 == p2u8)
      return 0;
  if (p1u8 == NULL)
      return *p2u8;
  if (p2u8 == NULL)
      return *p1u8;

  for (i = 0; i < cnt; i++, p1u8++, p2u8++)
  {
      if      (*p1u8 < *p2u8) return -(*p2u8 - *p1u8);
      else if (*p1u8 > *p2u8) return  (*p1u8 - *p2u8);
  }

  return 0;
}

void * bxi_memfrob(void * ptr, u8 val, u32 cnt)
{
    u32 f = 0;
    u32 i;
    u32 pre;
    u32 cen;
    u32 end;
    u8  * ptr_u8 = ptr;
    u32 * ptr_u32;

    if (!ptr)
        return NULL;
    if (!cnt)
        return ptr;

    pre = BXI_MIN((4 - ((pu_t)ptr & 3)) & 3, cnt);
    cen = (cnt - pre) >> 2;
    end = cnt - pre - (cen << 2);

    f = val;
    f |= f << 8;
    f |= f << 16;

    for (i = 0; i < pre; i++, ptr_u8++)
        *ptr_u8 ^= val;
    ptr_u32 = (u32 *)ptr_u8;
    for (i = 0; i < cen; i++, ptr_u32++)
        *ptr_u32 ^= f;
    ptr_u8 = (u8 *)ptr_u32;
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

    for (i = 0; i < cnt; i++)
        if (ptru8[i] == val)
            return (void *)(ptru8 + i);
    return NULL;
}

void * bxi_memrchr(const void * ptr, u8 val, u32 cnt)
{
    i32 i;
    const u8 * ptru8 = (const u8 *)ptr;
    if (!ptr)
        return NULL;

    for (i = cnt - 1; i >= 0; i--)
        if (ptru8[i] == val)
            return (void *)(ptru8 + i);
    return NULL;
}
