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

#include "../serials/bxiserread.h"
#include "../utils/bximemutils.h"

static void read_generic(void * val, u8 * src, u32 size)
{
    bxi_memcpy(val, src, size);
}

i8  bxi_read_i8(u8 * src)
{
    i8 res = 0;
    read_generic(&res, src, sizeof(i8));
    return res;
}

u8  bxi_read_u8(u8 * src)
{
    u8 res = 0;
    read_generic(&res, src, sizeof(u8));
    return res;
}

i16 bxi_read_i16(u8 * src)
{
    i16 res = 0;
    read_generic(&res, src, sizeof(i16));
    return res;
}

u16 bxi_read_u16(u8 * src)
{
    u16 res = 0;
    read_generic(&res, src, sizeof(u16));
    return res;
}

i32 bxi_read_i32(u8 * src)
{
    i32 res = 0;
    read_generic(&res, src, sizeof(i32));
    return res;
}

u32 bxi_read_u32(u8 * src)
{
    u32 res = 0;
    read_generic(&res, src, sizeof(u32));
    return res;
}

i16_be bxi_read_i16_be(u8 * src)
{
    i16 res = 0;
    read_generic(&res, src, sizeof(i16));
    return bxi_i162i16_be(res);
}

u16_be bxi_read_u16_be(u8 * src)
{
    u16 res = 0;
    read_generic(&res, src, sizeof(u16));
    return bxi_u162u16_be(res);
}

i32_be bxi_read_i32_be(u8 * src)
{
    i32 res = 0;
    read_generic(&res, src, sizeof(i32));
    return bxi_i322i32_be(res);
}

u32_be bxi_read_u32_be(u8 * src)
{
    u32 res = 0;
    read_generic(&res, src, sizeof(u32));
    return bxi_u322u32_be(res);
}

i16_le bxi_read_i16_le(u8 * src)
{
    i16 res = 0;
    read_generic(&res, src, sizeof(i16));
    return bxi_i162i16_le(res);
}

u16_le bxi_read_u16_le(u8 * src)
{
    u16 res = 0;
    read_generic(&res, src, sizeof(u16));
    return bxi_u162u16_le(res);
}

i32_le bxi_read_i32_le(u8 * src)
{
    i32 res = 0;
    read_generic(&res, src, sizeof(i32));
    return bxi_i322i32_le(res);
}

u32_le bxi_read_u32_le(u8 * src)
{
    u32 res = 0;
    read_generic(&res, src, sizeof(u32));
    return bxi_u322u32_le(res);
}
