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

#ifndef BXI_MATH_H
#define BXI_MATH_H

#include "../types/bxiints.h"
#include "../types/bxifloats.h"
#include "../types/bxibools.h"

EXPORT_FROM
#define BXI_MAX(a, b) ((a) > (b) ? (a) : (b))
#define BXI_MIN(a, b) ((a) > (b) ? (b) : (a))
EXPORT_TO

EXPORT_FROM
#define BXI_FAST_U16DIV255(x) ((u32)(x) + 1 + (((u32)(x) + 1) >> 8)) >> 8
EXPORT_TO

EXPORT u32 bxi_abs(i32 val);
EXPORT i32 bxi_sign(i32 val);
EXPORT i32 bxi_gcd(i32 a, i32 b);
EXPORT i32 bxi_lcm(i32 a, i32 b);

EXPORT u32  bxi_sqrti(u32 x);

EXPORT bool bxi_isnan(f64 x);
EXPORT i32  bxi_floor(f64 x);
EXPORT i32  bxi_round(f64 x);
EXPORT i32  bxi_ceil (f64 x);

#endif /* BXI_MATH_H */

