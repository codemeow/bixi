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

#ifndef BXIIPV4_H
#define BXIIPV4_H

#include "../definitions/bxiexport.h"
#include "../types/bxiints.h"
#include "../types/bxibools.h"
#include "../types/bxiboints.h"

EXPORT_FROM
#define BXI_IPV4_ZERO (0)
#define BXI_IPV4_STRLEN (3 /* 255 */ + 1 /* .  */ + \
                         3 /* 255 */ + 1 /* .  */ + \
                         3 /* 255 */ + 1 /* .  */ + \
                         3 /* 255 */ + 1 /* \0 */)
EXPORT_TO

EXPORT typedef u32 bxi_ipv4;

EXPORT bxi_ipv4 bxi_str2ipv4(       const char * str);
EXPORT char *   bxi_ipv42str(bxi_ipv4 ip, char * str);

#endif /* BXIIPV4_H */

