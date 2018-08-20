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

#ifndef BXIBOINTS_H
#define BXIBOINTS_H

#include "../definitions/bxiexport.h"
#include "../types/bxiints.h"

EXPORT typedef enum
{
    BXI_END_BE,
    BXI_END_LE
} bxi_ends;

EXPORT typedef i16 i16_le;
EXPORT typedef i16 i16_be;
EXPORT typedef u16 u16_le;
EXPORT typedef u16 u16_be;
EXPORT typedef i32 i32_le;
EXPORT typedef i32 i32_be;
EXPORT typedef u32 u32_le;
EXPORT typedef u32 u32_be;

EXPORT_FROM
#define BITS_IN_U16_LE  (16)
#define BITS_IN_U32_LE  (32)
#define BITS_IN_I16_LE  (16)
#define BITS_IN_I32_LE  (32)
#define BITS_IN_U16_BE  (16)
#define BITS_IN_U32_BE  (32)
#define BITS_IN_I16_BE  (16)
#define BITS_IN_I32_BE  (32)
EXPORT_TO

EXPORT_FROM
#define  U8_LE_MIN ( U8_MIN)
#define  U8_BE_MIN ( U8_MIN)
#define U16_LE_MIN (U16_MIN)
#define U16_BE_MIN (U16_MIN)
#define U32_LE_MIN (U32_MIN)
#define U32_BE_MIN (U32_MIN)

#define  I8_LE_MIN ( I8_MIN)
#define  I8_BE_MIN ( I8_MIN)
#define I16_LE_MIN (I16_MIN)
#define I16_BE_MIN (I16_MIN)
#define I32_LE_MIN (I32_MIN)
#define I32_BE_MIN (I32_MIN)

#define  U8_LE_MAX ( U8_MAX)
#define  U8_BE_MAX ( U8_MAX)
#define U16_LE_MAX (U16_MAX)
#define U16_BE_MAX (U16_MAX)
#define U32_LE_MAX (U32_MAX)
#define U32_BE_MAX (U32_MAX)

#define  I8_LE_MAX ( I8_MAX)
#define  I8_BE_MAX ( I8_MAX)
#define I16_LE_MAX (I16_MAX)
#define I16_BE_MAX (I16_MAX)
#define I32_LE_MAX (I32_MAX)
#define I32_BE_MAX (I32_MAX)
EXPORT_TO

EXPORT_FROM
#define IS_BE (*(u16 *)"\0\xff" < 0x100)
#define IS_LE (*(u16 *)"\0\xff" > 0x100)
EXPORT_TO

EXPORT u16 bxi_chgend16(u16 val);
EXPORT u32 bxi_chgend32(u32 val);

EXPORT i16    bxi_i16_le2i16   (i16_le value);
EXPORT i16    bxi_i16_be2i16   (i16_be value);
EXPORT i16_be bxi_i16_le2i16_be(i16_le value);
EXPORT i16_le bxi_i16_be2i16_le(i16_be value);
EXPORT i16_be    bxi_i162i16_be(i16    value);
EXPORT i16_le    bxi_i162i16_le(i16    value);

EXPORT i32    bxi_i32_le2i32   (i32_le value);
EXPORT i32    bxi_i32_be2i32   (i32_be value);
EXPORT i32_be bxi_i32_le2i32_be(i32_le value);
EXPORT i32_le bxi_i32_be2i32_le(i32_be value);
EXPORT i32_be    bxi_i322i32_be(i32    value);
EXPORT i32_le    bxi_i322i32_le(i32    value);

EXPORT u16    bxi_u16_le2u16   (u16_le value);
EXPORT u16    bxi_u16_be2u16   (u16_be value);
EXPORT u16_be bxi_u16_le2u16_be(u16_le value);
EXPORT u16_le bxi_u16_be2u16_le(u16_be value);
EXPORT u16_be    bxi_u162u16_be(u16    value);
EXPORT u16_le    bxi_u162u16_le(u16    value);

EXPORT u32    bxi_u32_le2u32   (u32_le value);
EXPORT u32    bxi_u32_be2u32   (u32_be value);
EXPORT u32_be bxi_u32_le2u32_be(u32_le value);
EXPORT u32_le bxi_u32_be2u32_le(u32_be value);
EXPORT u32_be    bxi_u322u32_be(u32    value);
EXPORT u32_le    bxi_u322u32_le(u32    value);

#endif /* BXIBOINT_H */

