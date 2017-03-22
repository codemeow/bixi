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

EXPORT typedef u32 bxi_hash;

EXPORT bxi_hash strhash  (char * str);
EXPORT char *   strtrim  (char * str);
EXPORT char *   strshiftl(char * str, u32 count);
EXPORT char *   strtriml (char * str);
EXPORT char *   strtrimr (char * str);
EXPORT char *   strtrim  (char * str);

EXPORT u32  bxi_strlen(char * str);

EXPORT bool isasciicntrl(u32 c);
EXPORT bool isasciiprint(u32 c);
EXPORT bool isasciispace(u32 c);
EXPORT bool isasciiblank(u32 c);
EXPORT bool isasciigraph(u32 c);
EXPORT bool isasciipunct(u32 c);
EXPORT bool isasciialnum(u32 c);
EXPORT bool isasciialpha(u32 c);
EXPORT bool isasciiupper(u32 c);
EXPORT bool isasciilower(u32 c);
EXPORT bool isasciidigit(u32 c);
EXPORT bool isasciixdigit(u32 c);

#endif /* BXISTRING_H */

