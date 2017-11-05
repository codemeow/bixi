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

#ifndef BXISERWRITE_H
#define BXISERWRITE_H

#include "../definitions/bxiexport.h"
#include "../types/bxiints.h"
#include "../types/bxiboints.h"

EXPORT void bxi_write_i8    (i8     val, u8 * dst);
EXPORT void bxi_write_u8    (u8     val, u8 * dst);
EXPORT void bxi_write_i16   (i16    val, u8 * dst);
EXPORT void bxi_write_u16   (u16    val, u8 * dst);
EXPORT void bxi_write_i32   (i32    val, u8 * dst);
EXPORT void bxi_write_u32   (u32    val, u8 * dst);

EXPORT void bxi_write_i16_be(i16_be val, u8 * dst);
EXPORT void bxi_write_u16_be(u16_be val, u8 * dst);
EXPORT void bxi_write_i32_be(i32_be val, u8 * dst);
EXPORT void bxi_write_u32_be(u32_be val, u8 * dst);

EXPORT void bxi_write_i16_le(i16_le val, u8 * dst);
EXPORT void bxi_write_u16_le(u16_le val, u8 * dst);
EXPORT void bxi_write_i32_le(i32_le val, u8 * dst);
EXPORT void bxi_write_u32_le(u32_le val, u8 * dst);

#endif /* BXISERWRITE_H */

