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

#include "../serials/bxiserwrite.h"
#include "../utils/bximemutils.h"

static void write_generic(void * src, u8 * dst, u32 size)
{
    bxi_memcpy(dst, src, size);
}

void bxi_write_i8(i8 val, u8 * dst)
{
    write_generic(&val, dst, sizeof(i8));
}

void bxi_write_u8(u8 val, u8 * dst)
{
    write_generic(&val, dst, sizeof(u8));
}

void bxi_write_i16(i16 val, u8 * dst)
{
    write_generic(&val, dst, sizeof(i16));
}

void bxi_write_u16(u16 val, u8 * dst)
{
    write_generic(&val, dst, sizeof(u16));
}

void bxi_write_i32(i32 val, u8 * dst)
{
    write_generic(&val, dst, sizeof(i32));
}

void bxi_write_u32(u32 val, u8 * dst)
{
    write_generic(&val, dst, sizeof(u32));
}

void bxi_write_i16_be(i16_be val, u8 * dst)
{
    i16 t = bxi_i16_be2i16(val);
    write_generic(&t, dst, sizeof(i16));
}

void bxi_write_u16_be(u16_be val, u8 * dst)
{
    u16 t = bxi_u16_be2u16(val);
    write_generic(&t, dst, sizeof(u16));
}

void bxi_write_i32_be(i32_be val, u8 * dst)
{
    i32 t = bxi_i32_be2i32(val);
    write_generic(&t, dst, sizeof(i32));
}

void bxi_write_u32_be(u32_be val, u8 * dst)
{
    u32 t = bxi_u32_be2u32(val);
    write_generic(&t, dst, sizeof(u32));
}

void bxi_write_i16_le(i16_le val, u8 * dst)
{
    i16 t = bxi_i16_le2i16(val);
    write_generic(&t, dst, sizeof(i16));
}

void bxi_write_u16_le(u16_le val, u8 * dst)
{
    u16 t = bxi_u16_le2u16(val);
    write_generic(&t, dst, sizeof(u16));
}

void bxi_write_i32_le(i32_le val, u8 * dst)
{
    i32 t = bxi_i32_le2i32(val);
    write_generic(&t, dst, sizeof(i32));
}

void bxi_write_u32_le(u32_le val, u8 * dst)
{
    u32 t = bxi_u32_le2u32(val);
    write_generic(&t, dst, sizeof(u32));
}
