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
#define BXI_4_DIV_PI     (1.27323954473516268615) /* 4 / Pi         */
#define BXI_4_DIV_SQR_PI (0.40528473456935108577) /* 4 / Pi^2       */

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
#define BXI_FAST_DIV_2(x)          ((x) >> 0x01)
#define BXI_FAST_DIV_4(x)          ((x) >> 0x02)
#define BXI_FAST_DIV_8(x)          ((x) >> 0x03)
#define BXI_FAST_DIV_16(x)         ((x) >> 0x04)
#define BXI_FAST_DIV_32(x)         ((x) >> 0x05)
#define BXI_FAST_DIV_64(x)         ((x) >> 0x06)
#define BXI_FAST_DIV_128(x)        ((x) >> 0x07)
#define BXI_FAST_DIV_256(x)        ((x) >> 0x08)
#define BXI_FAST_DIV_512(x)        ((x) >> 0x09)
#define BXI_FAST_DIV_1024(x)       ((x) >> 0x0a)
#define BXI_FAST_DIV_2048(x)       ((x) >> 0x0b)
#define BXI_FAST_DIV_4096(x)       ((x) >> 0x0c)
#define BXI_FAST_DIV_8192(x)       ((x) >> 0x0d)
#define BXI_FAST_DIV_16384(x)      ((x) >> 0x0e)
#define BXI_FAST_DIV_32768(x)      ((x) >> 0x0f)
#define BXI_FAST_DIV_65536(x)      ((x) >> 0x10)
#define BXI_FAST_DIV_131072(x)     ((x) >> 0x11)
#define BXI_FAST_DIV_262144(x)     ((x) >> 0x12)
#define BXI_FAST_DIV_524288(x)     ((x) >> 0x13)
#define BXI_FAST_DIV_1048576(x)    ((x) >> 0x14)
#define BXI_FAST_DIV_2097152(x)    ((x) >> 0x15)
#define BXI_FAST_DIV_4194304(x)    ((x) >> 0x16)
#define BXI_FAST_DIV_8388608(x)    ((x) >> 0x17)
#define BXI_FAST_DIV_16777216(x)   ((x) >> 0x18)
#define BXI_FAST_DIV_33554432(x)   ((x) >> 0x19)
#define BXI_FAST_DIV_67108864(x)   ((x) >> 0x1a)
#define BXI_FAST_DIV_134217728(x)  ((x) >> 0x1b)
#define BXI_FAST_DIV_268435456(x)  ((x) >> 0x1c)
#define BXI_FAST_DIV_536870912(x)  ((x) >> 0x1d)
#define BXI_FAST_DIV_1073741824(x) ((x) >> 0x1e)
#define BXI_FAST_DIV_2147483648(x) ((x) >> 0x1f)

#define BXI_FAST_MUL_2(x)          ((x) << 0x01)
#define BXI_FAST_MUL_4(x)          ((x) << 0x02)
#define BXI_FAST_MUL_8(x)          ((x) << 0x03)
#define BXI_FAST_MUL_16(x)         ((x) << 0x04)
#define BXI_FAST_MUL_32(x)         ((x) << 0x05)
#define BXI_FAST_MUL_64(x)         ((x) << 0x06)
#define BXI_FAST_MUL_128(x)        ((x) << 0x07)
#define BXI_FAST_MUL_256(x)        ((x) << 0x08)
#define BXI_FAST_MUL_512(x)        ((x) << 0x09)
#define BXI_FAST_MUL_1024(x)       ((x) << 0x0a)
#define BXI_FAST_MUL_2048(x)       ((x) << 0x0b)
#define BXI_FAST_MUL_4096(x)       ((x) << 0x0c)
#define BXI_FAST_MUL_8192(x)       ((x) << 0x0d)
#define BXI_FAST_MUL_16384(x)      ((x) << 0x0e)
#define BXI_FAST_MUL_32768(x)      ((x) << 0x0f)
#define BXI_FAST_MUL_65536(x)      ((x) << 0x10)
#define BXI_FAST_MUL_131072(x)     ((x) << 0x11)
#define BXI_FAST_MUL_262144(x)     ((x) << 0x12)
#define BXI_FAST_MUL_524288(x)     ((x) << 0x13)
#define BXI_FAST_MUL_1048576(x)    ((x) << 0x14)
#define BXI_FAST_MUL_2097152(x)    ((x) << 0x15)
#define BXI_FAST_MUL_4194304(x)    ((x) << 0x16)
#define BXI_FAST_MUL_8388608(x)    ((x) << 0x17)
#define BXI_FAST_MUL_16777216(x)   ((x) << 0x18)
#define BXI_FAST_MUL_33554432(x)   ((x) << 0x19)
#define BXI_FAST_MUL_67108864(x)   ((x) << 0x1a)
#define BXI_FAST_MUL_134217728(x)  ((x) << 0x1b)
#define BXI_FAST_MUL_268435456(x)  ((x) << 0x1c)
#define BXI_FAST_MUL_536870912(x)  ((x) << 0x1d)
#define BXI_FAST_MUL_1073741824(x) ((x) << 0x1e)
#define BXI_FAST_MUL_2147483648(x) ((x) << 0x1f)

#define BXI_FAST_U16DIV255(x) (((u32)(x) + 1 + (((u32)(x) + 1) >> 8)) >> 8)
EXPORT_TO

EXPORT_FROM
#define BXI_NAN     ( 0.0 / 0.0)
#define BXI_INF_POS ( 1.0 / 0.0)
#define BXI_INF_NEG (-1.0 / 0.0)
EXPORT_TO

/* @todo acos */
/* @todo asin */
/* @todo atan */
/* @todo atan2 */
/* @todo exp */
/* @todo frexp */
/* @todo ldexp */
/* @todo log */
/* @todo log10 */
/* @todo pow */
/* @todo sinh */
/* @todo sqrt */
/* @todo tan */
/* @todo tanh */

/* @todo cbrt */
/* @todo log2 */

EXPORT u32  bxi_abs(i32 val);
EXPORT i32  bxi_sign(i32 val);
EXPORT i32  bxi_gcd(i32 a, i32 b);
EXPORT i32  bxi_lcm(i32 a, i32 b);
EXPORT u32  bxi_sqrti(u32 x);
EXPORT f64  bxi_nan    (void);
EXPORT f64  bxi_inf_pos(void);
EXPORT f64  bxi_inf_neg(void);

EXPORT bool bxi_isnan(f64 x);
EXPORT bool bxi_isinfpos(f64 x);
EXPORT bool bxi_isinfneg(f64 x);

EXPORT f64  bxi_floor(f64 x);
EXPORT f64  bxi_round(f64 x);
EXPORT f64  bxi_ceil (f64 x);
EXPORT f64  bxi_trunc(f64 x);
EXPORT f64  bxi_modf (f64 x, f64 * i);
EXPORT f64  bxi_fmod (f64 x, f64   y);

EXPORT f64  bxi_fabs (f64 x);

EXPORT f64  bxi_fsin(f64 x); /* -Pi..+Pi */
EXPORT f64  bxi_fcos(f64 x); /* -Pi..+Pi */

#endif /* BXI_MATH_H */

