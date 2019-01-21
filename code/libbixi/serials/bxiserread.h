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

#ifndef BXISERREAD_H
#define BXISERREAD_H

#include "../definitions/bxiexport.h"
#include "../types/bxiboints.h"
#include "../hashes/bxiuuid.h"

EXPORT i8     bxi_read_i8    (const u8 * src);
EXPORT u8     bxi_read_u8    (const u8 * src);
EXPORT i16    bxi_read_i16   (const u8 * src);
EXPORT u16    bxi_read_u16   (const u8 * src);
EXPORT i32    bxi_read_i32   (const u8 * src);
EXPORT u32    bxi_read_u32   (const u8 * src);

EXPORT i16_be bxi_read_i16_be(const u8 * src);
EXPORT u16_be bxi_read_u16_be(const u8 * src);
EXPORT i32_be bxi_read_i32_be(const u8 * src);
EXPORT u32_be bxi_read_u32_be(const u8 * src);

EXPORT i16_le bxi_read_i16_le(const u8 * src);
EXPORT u16_le bxi_read_u16_le(const u8 * src);
EXPORT i32_le bxi_read_i32_le(const u8 * src);
EXPORT u32_le bxi_read_u32_le(const u8 * src);

EXPORT void   bxi_read_uuid  (const u8 * src, bxi_uuid_t uuid);

#endif /* BXISERREAD_H */


