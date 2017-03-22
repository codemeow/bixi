/*
 * «Bixi» - Basic types management C89 library
 *
 *  Copyright (C) Alexey Shishkin 2017
 *
 *  This file is part of Project «Bixi».
 *
 *  Project «Bixi» is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Project «Bixi» is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with Project «Bixi». If not, see <http://www.gnu.org/licenses/>.
 */

#include "../utils/bximemutils.h"

void * bxi_memmove(void * dst, void * src, u32 cnt)
{
    u8 * dst_u8 = dst;
    u8 * src_u8 = src;

    if (dst == src)
        return dst;

    if (dst > src)
    {
        while (cnt--)
           dst_u8[cnt] = src_u8[cnt];
    }
    else
    {
        u32 len = cnt;
        while (cnt--)
            dst_u8[len - cnt - 1] = src_u8[len - cnt - 1];
    }

    return dst;
}

void * bxi_memset(void * ptr, i32 val, u32 cnt)
{
    u8 * ptr_u8 = ptr;

    while (cnt--)
        ptr_u8[cnt] = (val & 0xff);

    return ptr;
}

void * bxi_memcpy(void * dst, const void * src, u32 cnt)
{
          u8 * dst_u8 = dst;
    const u8 * src_u8 = src;

    while (cnt--)
        dst_u8[cnt] = src_u8[cnt];

    return dst;
}

i32 bxi_memcmp(const void * p1, const void * p2, u32 n)
{
  u32 i;
  const u8 * p1u8 = (const u8 *) p1;
  const u8 * p2u8 = (const u8 *) p2;

  for (i = 0; i < n; i++, p1u8++, p2u8++)
  {
      if      (*p1u8 < *p2u8) return -1;
      else if (*p1u8 > *p2u8) return  1;
  }

  return 0;
}

