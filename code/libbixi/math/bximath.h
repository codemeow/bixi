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
#define BXI_PI           (3.14159265358979323846) /* Pi             */
#define BXI_PI_DIV_2     (1.57079632679489661923) /* Pi / 2         */
#define BXI_PI_DIV_4     (0.78539816339744830962) /* Pi / 4         */
#define BXI_1_DIV_PI     (0.31830988618379067154) /* 1 / Pi         */
#define BXI_2_DIV_PI     (0.63661977236758134308) /* 2 / Pi         */

#define BXI_E            (2.71828182845904523536) /* Euler's number */
#define BXI_PHI          (1.61803398874989484820) /* Golden ratio   */
#define BXI_E_POW_PI     (23.1406926327792690057) /* e^Pi           */

#define BXI_LOG2_E       (1.44269504088896340735) /* Log2(e)        */
#define BXI_LOG10_E      (0.43429448190325182765) /* Log10(e)       */
#define BXI_LN_E         (0.69314718055994530942) /* Ln(2)          */
#define BXI_LN_10        (2.30258509299404568402) /* Ln(10)         */

#define BXI_SQRT_2       (1.41421356237309504880) /* Sqrt(2)        */
#define BXI_SQRT_3       (1.73205080756887729352) /* Sqrt(3)        */
#define BXI_SQRT_5       (2.23606797749978969640) /* Sqrt(5)        */
#define BXI_1_DIV_SQRT_2 (0.70710678118654752440) /* 1 / Sqrt(2)    */
EXPORT_TO

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

EXPORT f64  bxi_fabs (f64 x);

EXPORT f64  bxi_fsin(f64 x); /* 0..1 */

#endif /* BXI_MATH_H */

