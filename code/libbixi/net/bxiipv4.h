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

EXPORT typedef u8 bxi_ipv4[4];

EXPORT bool bxi_str2ipv4(const char * str, bxi_ipv4 *  ip);
EXPORT bool bxi_ipv42str(bxi_ipv4   * ip,      char * str);
EXPORT u32  bxi_ipv42u32(bxi_ipv4     ip);                   /* @test */
EXPORT void bxi_u322ipv4(u32 pack,         bxi_ipv4    ip);  /* @test */

#endif /* BXIIPV4_H */

