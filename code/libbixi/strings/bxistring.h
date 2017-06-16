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
#include "../types/bxibools.h"

EXPORT_FROM
#define BXI_IS_ASCII_MAX (127)
EXPORT_TO

EXPORT enum bxi_ascii_characters
{
    BXI_CHAR_NUL, BXI_CHAR_SOH, BXI_CHAR_STX, BXI_CHAR_ETX,
    BXI_CHAR_EOT, BXI_CHAR_ENQ, BXI_CHAR_ACK, BXI_CHAR_BEL,
    BXI_CHAR_BS , BXI_CHAR_TAB, BXI_CHAR_LF , BXI_CHAR_VT ,
    BXI_CHAR_FF , BXI_CHAR_CR , BXI_CHAR_SO , BXI_CHAR_SI ,
    BXI_CHAR_DLE, BXI_CHAR_DC1, BXI_CHAR_DC2, BXI_CHAR_DC3,
    BXI_CHAR_DC4, BXI_CHAR_NAK, BXI_CHAR_SYN, BXI_CHAR_ETB,
    BXI_CHAR_CAN, BXI_CHAR_EM , BXI_CHAR_SUB, BXI_CHAR_ESC,
    BXI_CHAR_FS , BXI_CHAR_GS , BXI_CHAR_RS , BXI_CHAR_US ,
    BXI_CHAR_DEL = (0x7F)
};

EXPORT enum bxi_strerror
{
    BXI_STRERROR_SUCCESS      = ( 0),
    BXI_STRERROR_NOSTRING     = (-1),
    BXI_STRERROR_NOEND        = (-2),
    BXI_STRERROR_CONVOVERFLOW = (-3),
    BXI_STRERROR_BADSTRING    = (-4)
};

EXPORT typedef u32 bxi_hash;

EXPORT bxi_hash     strhash  (const char * str);
EXPORT       char * strshiftl(      char * str, u32 count);
EXPORT       char * strtriml (      char * str);
EXPORT       char * strtrimr (      char * str);
EXPORT       char * strtrim  (      char * str);
EXPORT const char * strparam (const char * str, i32 * len);

EXPORT u32  bxi_strlen(const char * str);
EXPORT i32  bxi_strcmp(const char * str1, const char * str2);
EXPORT u32  bxi_strparse(    char * str, u32 * count, char ** output);

EXPORT bool isasciicntrl (u32 c);
EXPORT bool isasciiprint (u32 c);
EXPORT bool isasciispace (u32 c);
EXPORT bool isasciiblank (u32 c);
EXPORT bool isasciigraph (u32 c);
EXPORT bool isasciipunct (u32 c);
EXPORT bool isasciialnum (u32 c);
EXPORT bool isasciialpha (u32 c);
EXPORT bool isasciiupper (u32 c);
EXPORT bool isasciilower (u32 c);
EXPORT bool isasciidigit (u32 c);
EXPORT bool isasciixdigit(u32 c);

EXPORT u32 toasciiupper(u32 c);
EXPORT u32 toasciilower(u32 c);

EXPORT void strtoasciiupper(char * str);
EXPORT void strtoasciilower(char * str);

#endif /* BXISTRING_H */

