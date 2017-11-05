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

#ifndef BXIFLOATS_H
#define BXIFLOATS_H

#include "../definitions/bxiexport.h"
#include "../definitions/bxiassert.h"

EXPORT typedef float  f32;
EXPORT typedef double f64;

EXPORT_FROM
#define BITS_IN_F32  (32)
#define BITS_IN_F64  (64)
EXPORT_TO

EXPORT_FROM
COMPILE_ASSERT(sizeof(f32) == 4);
COMPILE_ASSERT(sizeof(f64) == 8);
EXPORT_TO

#endif /* BXIFLOATS_H */

