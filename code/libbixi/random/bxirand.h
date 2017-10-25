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

#ifndef BXIRAND_H
#define BXIRAND_H

#include "../definitions/bxiexport.h"
#include "../types/bxiints.h"

EXPORT_FROM
#define     BXI_RAND32_MAX ((u32)U32_MAX)
#define     BXI_RAND16_MAX ((u32)U16_MAX)
#define     BXI_RAND8_MAX  ((u32)U8_MAX )
EXPORT_TO

EXPORT void bxi_srand(u32 seed);
EXPORT u32  bxi_randu32(void);
EXPORT u16  bxi_randu16(void);
EXPORT u8   bxi_randu8 (void);
EXPORT i32  bxi_randi32(void);
EXPORT i16  bxi_randi16(void);
EXPORT i8   bxi_randi8 (void);

#endif /* BXIRAND_H */

