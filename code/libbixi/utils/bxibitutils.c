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

#include "../utils/bxibitutils.h"

u8 rotl8(u8 val, u32 n)
{
      u8 t1, t2;

      n = n % (sizeof(val) * 8);
      t1 = val << n;
      t2 = val >> (sizeof(val) * 8 - n);

      return t1 | t2;
}

u8 rotr8(u8 val, u32 n)
{
      u8 t1, t2;

      n = n % (sizeof(val) * 8);
      t1 = val >> n;
      t2 = val << (sizeof(val) * 8 - n);

      return t1 | t2;
}

u16 rotl16(u16 val, u32 n)
{
      u16 t1, t2;

      n = n % (sizeof(val) * 8);
      t1 = val << n;
      t2 = val >> (sizeof(val) * 8 - n);

      return t1 | t2;
}

u16 rotr16(u16 val, u32 n)
{
      u16 t1, t2;

      n = n % (sizeof(val) * 8);
      t1 = val >> n;
      t2 = val << (sizeof(val) * 8 - n);

      return t1 | t2;
}

u32 rotl32(u32 val, u32 n)
{
      u32 t1, t2;

      n = n % (sizeof(val) * 8);
      t1 = val << n;
      t2 = val >> (sizeof(val) * 8 - n);

      return t1 | t2;
}

u32 rotr32(u32 val, u32 n)
{
      u32 t1, t2;

      n = n % (sizeof(val) * 8);
      t1 = val >> n;
      t2 = val << (sizeof(val) * 8 - n);

      return t1 | t2;
}

u8 getbit(u32 val, u8 n)
{
    return (val >> n) & 1;
}

u32 setbit(u32 val, u8 n)
{
    return (val | (1 << n));
}

u32 tglbit(u32 val, u8 n)
{
    return (val ^ (1 << n));
}

u32 clrbit(u32 val, u8 n)
{
    return (val & ~(1 << n));
}

u32 chgbit(u32 val, u8 n, u8 bit)
{
    return ((val & ~(1 << n)) | ((bit & 1) << n));
}

