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

#ifndef BXISERREAD_H
#define BXISERREAD_H

#include "../definitions/bxiexport.h"
#include "../types/bxiboints.h"

EXPORT i8     read_i8    (u8 * src);
EXPORT u8     read_u8    (u8 * src);
EXPORT i16    read_i16   (u8 * src);
EXPORT u16    read_u16   (u8 * src);
EXPORT i32    read_i32   (u8 * src);
EXPORT u32    read_u32   (u8 * src);

EXPORT i16_be read_i16_be(u8 * src);
EXPORT u16_be read_u16_be(u8 * src);
EXPORT i32_be read_i32_be(u8 * src);
EXPORT u32_be read_u32_be(u8 * src);

EXPORT i16_le read_i16_le(u8 * src);
EXPORT u16_le read_u16_le(u8 * src);
EXPORT i32_le read_i32_le(u8 * src);
EXPORT u32_le read_u32_le(u8 * src);

#endif /* BXISERREAD_H */

