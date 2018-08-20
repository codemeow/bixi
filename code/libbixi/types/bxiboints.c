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

#include "../definitions/bxienv.h"
#include "../types/bxiboints.h"

u16 bxi_chgend16(u16 val)
{
    u16 res = 0;
    res |= (val & 0x00ffu) << 8;
    res |= (val & 0xff00u) >> 8;
    return res;
}

u32 bxi_chgend32(u32 val)
{
    u32 res = 0;
    res |= (val & 0x000000ffu) << 24;
    res |= (val & 0x0000ff00u) << 8;
    res |= (val & 0x00ff0000u) >> 8;
    res |= (val & 0xff000000u) >> 24;
    return res;
}

i16 bxi_i16_le2i16(i16_le value)
{
    return IS_LE ? value : (i16)bxi_chgend16((i16_le)value);
}

i16 bxi_i16_be2i16(i16_be value)
{
    return IS_BE ? value : (i16)bxi_chgend16((i16_be)value);
}

i16_be bxi_i16_le2i16_be(i16_le value)
{
    return (i16_be)bxi_chgend16((i16_le)value);
}

i16_le bxi_i16_be2i16_le(i16_be value)
{
    return (i16_le)bxi_chgend16((i16_be)value);
}

i16_be bxi_i162i16_be(i16 value)
{
    return IS_BE ? value : (i16_be)bxi_chgend16((i16)value);
}

i16_le bxi_i162i16_le(i16 value)
{
    return IS_LE ? value : (i16_le)bxi_chgend16((i16)value);
}

i32 bxi_i32_le2i32(i32_le value)
{
    return IS_LE ? value : (i32)bxi_chgend32((i32_le)value);
}

i32 bxi_i32_be2i32(i32_be value)
{
    return IS_BE ? value : (i32)bxi_chgend32((i32_be)value);
}

i32_be bxi_i322i32_be(i32 value)
{
    return IS_BE ? value : (i32_be)bxi_chgend32((i32)value);
}

i32_le bxi_i322i32_le(i32 value)
{
    return IS_LE ? value : (i32_le)bxi_chgend32((i32)value);
}

i32_be bxi_i32_le2i32_be(i32_le value)
{
    return (i32_be)bxi_chgend32((i32_le)value);
}

i32_le bxi_i32_be2i32_le(i32_be value)
{
    return (i32_le)bxi_chgend32((i32_le)value);
}

u16 bxi_u16_le2u16(u16_le value)
{
    return IS_LE ? value : bxi_chgend16(value);
}

u16 bxi_u16_be2u16(u16_be value)
{
    return IS_BE ? value : bxi_chgend16(value);
}

u16_be bxi_u16_le2u16_be(u16_le value)
{
    return bxi_chgend16(value);
}

u16_le bxi_u16_be2u16_le(u16_be value)
{
    return bxi_chgend16(value);
}

u16_be bxi_u162u16_be(u16 value)
{
    return IS_BE ? value : bxi_chgend16(value);
}

u16_le bxi_u162u16_le(u16 value)
{
    return IS_LE ? value : bxi_chgend16(value);
}

u32 bxi_u32_le2u32(u32_le value)
{
    return IS_LE ? value : bxi_chgend32(value);
}

u32 bxi_u32_be2u32(u32_be value)
{
    return IS_BE ? value : bxi_chgend32(value);
}

u32_be bxi_u32_le2u32_be(u32_le value)
{
    return bxi_chgend32(value);
}

u32_le bxi_u32_be2u32_le(u32_be value)
{
    return bxi_chgend32(value);
}

u32_be bxi_u322u32_be(u32 value)
{
    return IS_BE ? value : bxi_chgend32(value);
}

u32_le bxi_u322u32_le(u32 value)
{
    return IS_LE ? value : bxi_chgend32(value);
}
