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

#ifndef BXISTRING_H
#define BXISTRING_H

#include "../definitions/bxiexport.h"
#include "../types/bxiints.h"

EXPORT typedef u32 bxi_hash;

EXPORT bxi_hash strhash(char * str);

/* @todo EXPORT i8  str2i8 (char * str); */
/* @todo EXPORT u8  str2u8 (char * str); */
/* @todo EXPORT i16 str2i16(char * str); */
/* @todo EXPORT u16 str2u16(char * str); */
/* @todo EXPORT i32 str2i32(char * str); */
/* @todo EXPORT u32 str2u32(char * str); */

/* @todo EXPORT i8  hex2i8 (char * str); */
/* @todo EXPORT u8  hex2u8 (char * str); */
/* @todo EXPORT i16 hex2i16(char * str); */
/* @todo EXPORT u16 hex2u16(char * str); */
/* @todo EXPORT i32 hex2i32(char * str); */
/* @todo EXPORT u32 hex2u32(char * str); */

/* @todo EXPORT void i82str (char * str, i8 val); */
/* @todo EXPORT void u82str (char * str, u8 val); */
/* @todo EXPORT void i162str(char * str, i16 val); */
/* @todo EXPORT void u162str(char * str, u16 val); */
/* @todo EXPORT void i322str(char * str, i32 val); */
/* @todo EXPORT void u322str(char * str, u32 val); */

/* @todo EXPORT void i82hex (char * str, i8  val); */
/* @todo EXPORT void u82hex (char * str, u8  val); */
/* @todo EXPORT void i162hex(char * str, i16 val); */
/* @todo EXPORT void u162hex(char * str, u16 val); */
/* @todo EXPORT void i322hex(char * str, i32 val); */
/* @todo EXPORT void u322hex(char * str, u32 val); */

#endif /* BXISTRING_H */

