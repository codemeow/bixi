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

#ifndef BXISTRCONV_H
#define BXISTRCONV_H

#include "../definitions/bxiexport.h"
#include "../types/bxiboints.h"

extern const char bxi_hexes_high[];
extern const char bxi_hexes_low [];

EXPORT typedef enum
{
    BXI_HEX_DOUBLEHEX,
    BXI_HEX_DOUBLEHEXWITHSPACE,
    BXI_HEX_DOUBLEHEXWITHCOMMAANDSPACE,
    BXI_HEX_DOUBLELOWHEX,
    BXI_HEX_DOUBLELOWHEXWITHSPACE,
    BXI_HEX_DOUBLELOWHEXWITHCOMMAANDSPACE,
    BXI_HEX_ASCII,

    BXI_HEX_COUNT
} bxi_hex_format;

#define BXI_HEX_DEFAULT (BXI_HEX_DOUBLELOWHEX)

/* @todo EXPORT i8  str2i8 (char * str); */
/* @todo EXPORT u8  str2u8 (char * str); */
/* @todo EXPORT i16 str2i16(char * str); */
/* @todo EXPORT u16 str2u16(char * str); */
EXPORT i32 str2i32(const char * str, i32 * len);
/* @todo EXPORT u32 str2u32(char * str); */

/* @todo EXPORT i8  hex2i8 (char * str); */
/* @todo EXPORT u8  hex2u8 (char * str); */
/* @todo EXPORT i16 hex2i16(char * str); */
/* @todo EXPORT u16 hex2u16(char * str); */
/* @todo EXPORT i32 hex2i32(char * str); */
/* @todo EXPORT u32 hex2u32(char * str); */

/* @todo EXPORT i16_le hex2i16_le(char * str); */
/* @todo EXPORT u16_le hex2u16_le(char * str); */
/* @todo EXPORT i32_le hex2i32_le(char * str); */
/* @todo EXPORT u32_le hex2u32_le(char * str); */

/* @todo EXPORT i16_be hex2i16_be(char * str); */
/* @todo EXPORT u16_be hex2u16_be(char * str); */
/* @todo EXPORT i32_be hex2i32_be(char * str); */
/* @todo EXPORT u32_be hex2u32_be(char * str); */

EXPORT u32 hex2raw(const char * hex, u8 * raw);

EXPORT u32    i82hex (char * str, i8     val);
EXPORT u32    i82str (char * str, i8     val);
EXPORT u32    i162hex(char * str, i16    val);
EXPORT u32    i162str(char * str, i16    val);
EXPORT u32 i16_be2hex(char * str, i16_be val);
EXPORT u32 i16_be2str(char * str, i16_be val);
EXPORT u32 i16_le2hex(char * str, i16_le val);
EXPORT u32 i16_le2str(char * str, i16_le val);
EXPORT u32    i322hex(char * str, i32    val);
EXPORT u32    i322str(char * str, i32    val);
EXPORT u32 i32_be2hex(char * str, i32_be val);
EXPORT u32 i32_be2str(char * str, i32_be val);
EXPORT u32 i32_le2hex(char * str, i32_le val);
EXPORT u32 i32_le2str(char * str, i32_le val);
EXPORT u32    u82hex (char * str, u8     val);
EXPORT u32    u82str (char * str, u8     val);
EXPORT u32    u162hex(char * str, u16    val);
EXPORT u32    u162str(char * str, u16    val);
EXPORT u32 u16_be2hex(char * str, u16_be val);
EXPORT u32 u16_be2str(char * str, u16_be val);
EXPORT u32 u16_le2hex(char * str, u16_le val);
EXPORT u32 u16_le2str(char * str, u16_le val);
EXPORT u32    u322hex(char * str, u32    val);
EXPORT u32    u322str(char * str, u32    val);
EXPORT u32 u32_be2hex(char * str, u32_be val);
EXPORT u32 u32_be2str(char * str, u32_be val);
EXPORT u32 u32_le2hex(char * str, u32_le val);
EXPORT u32 u32_le2str(char * str, u32_le val);


/* @todo padded versions + format */

#endif /* BXISTRCONV_H */

