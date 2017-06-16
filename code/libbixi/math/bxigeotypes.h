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

#ifndef BXIGEOTYPES_H
#define BXIGEOTYPES_H

#include "../definitions/bxiexport.h"
#include "../types/bxiints.h"

EXPORT_FROM
#define MM_PER_INCH (25.4)
EXPORT_TO

EXPORT typedef struct
{
    i32 x;
    i32 y;
} bxi_pointi;

EXPORT typedef struct
{
    u32 x;
    u32 y;
} bxi_pointu;

EXPORT typedef bxi_pointu bxi_size;
EXPORT typedef bxi_pointi bxi_point;

#endif /* BXIGEOTYPES_H */

