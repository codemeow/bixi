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

#ifndef BXIINTS_H
#define BXIINTS_H

#include "../definitions/bxiexport.h"
#include "../definitions/bxiassert.h"

EXPORT typedef   signed       char i8;
EXPORT typedef unsigned       char u8;
EXPORT typedef   signed short int i16;
EXPORT typedef unsigned short int u16;
EXPORT typedef   signed       int i32;
EXPORT typedef unsigned       int u32;

EXPORT_FROM
#define BITS_IN_BYTE ( 8)
#define BITS_IN_U8   ( 8)
#define BITS_IN_U16  (16)
#define BITS_IN_U32  (32)
#define BITS_IN_I8   ( 8)
#define BITS_IN_I16  (16)
#define BITS_IN_I32  (32)
EXPORT_TO

EXPORT_FROM
COMPILE_ASSERT(sizeof( i8) == 1);
COMPILE_ASSERT(sizeof( u8) == 1);
COMPILE_ASSERT(sizeof(i16) == 2);
COMPILE_ASSERT(sizeof(u16) == 2);
COMPILE_ASSERT(sizeof(i32) == 4);
COMPILE_ASSERT(sizeof(u32) == 4);
EXPORT_TO

EXPORT_FROM
#define  U8_MIN (0)
#define U16_MIN (0)
#define U32_MIN (0)

#define  U8_MAX (0xffu)
#define U16_MAX (0xffffu)
#define U32_MAX (0xffffffffu)

#define  I8_MIN (-128)
#define I16_MIN (-32768)
#define I32_MIN (-2147483648)

#define  I8_MAX (+127)
#define I16_MAX (+32767)
#define I32_MAX (+2147483647)
EXPORT_TO

#endif /* BXIINTS_H */

