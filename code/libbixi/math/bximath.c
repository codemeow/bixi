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

#include "../math/bximath.h"
#include "../definitions/bximacros.h"
#include "../tables/bxisqrti.h"

u32 bxi_abs(i32 val)
{
    return val < 0 ? -val : val;
}

i32 bxi_sign(i32 val)
{
    return val < 0 ? -1 : val > 0 ? 1 : 0;
}

/*- This version is actually faster by 17%-24%, but
--- recursion is unsafe. This bxi_gcd can do
--- 20 000 000+ calls/sec on i5-6200U CPU @ 2.30GHz (-O1)

i32 bxi_gcd(i32 a, i32 b)
{
    a = bxi_abs(a);
    b = bxi_abs(b);
    return b == 0 ? a : bxi_gcd(b, a % b);
} */

i32 bxi_gcd(i32 a, i32 b)
{
    a = bxi_abs(a);
    b = bxi_abs(b);

    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }

    return 0;
}

i32 bxi_lcm(i32 a, i32 b)
{
    i32 g = bxi_gcd(a, b);
    if (g == 0)
        return 0;

    return a / g * b;
}

u32 bxi_sqrti(u32 x)
{
#   if (!defined(BXI_NO_SQRTI))
    u32 i;
    u32 c;

    if (x < 0x1000)
    {
        u32 shf = x >> 4;
        i = ((bxi_data_sqrti.arr[(x      ) & 0xF][shf]      )) >> 12;
    }
    else if (x < 0x10000)
    {
        u32 shf = x >> 8;
        i = ((bxi_data_sqrti.arr[(x >>  4) & 0xF][shf]      )  +
             (bxi_data_sqrti.cor[(x      ) & 0xF][shf]      )) >> 10;
    }
    else if (x < 0x100000)
    {
        u32 shf = x >> 12;
        i = ((bxi_data_sqrti.arr[(x >>  8) & 0xF][shf]      )  +
             (bxi_data_sqrti.cor[(x >>  4) & 0xF][shf]      )  +
             (bxi_data_sqrti.cor[(x      ) & 0xF][shf] >>  4)) >> 8;
    }
    else if (x < 0x1000000)
    {
        u32 shf = x >> 16;
        i = ((bxi_data_sqrti.arr[(x >> 12) & 0xF][shf]      )  +
             (bxi_data_sqrti.cor[(x >>  8) & 0xF][shf]      )  +
             (bxi_data_sqrti.cor[(x >>  4) & 0xF][shf] >>  4)  +
             (bxi_data_sqrti.cor[(x      ) & 0xF][shf] >>  8)) >> 6;
    }
    else if (x < 0x10000000)
    {
        u32 shf = x >> 20;
        i = ((bxi_data_sqrti.arr[(x >> 16) & 0xF][shf]      )  +
             (bxi_data_sqrti.cor[(x >> 12) & 0xF][shf]      )  +
             (bxi_data_sqrti.cor[(x >>  8) & 0xF][shf] >>  4)  +
             (bxi_data_sqrti.cor[(x >>  4) & 0xF][shf] >>  8)  +
             (bxi_data_sqrti.cor[(x      ) & 0xF][shf] >> 12)) >> 4;
    }
    else
    {
        u32 shf = x >> 24;
        i = ((bxi_data_sqrti.arr[(x >> 20) & 0xF][shf]      )  +
             (bxi_data_sqrti.cor[(x >> 16) & 0xF][shf]      )  +
             (bxi_data_sqrti.cor[(x >> 12) & 0xF][shf] >>  4)  +
             (bxi_data_sqrti.cor[(x >>  8) & 0xF][shf] >>  8)  +
             (bxi_data_sqrti.cor[(x >>  4) & 0xF][shf] >> 12)  +
             (bxi_data_sqrti.cor[(x      ) & 0xF][shf] >> 16)) >> 2;
    }

    c = i & 0xFFF;
    i >>= 12;
    if (c > 0x800) i++;
    return i;

#   else
    UNUSED(x);
    return 0;
#   endif /* BXI_NO_SQRTI */
}

f64 bxi_nan(void)
{
    /* cppcheck-suppress duplicateExpression */
    return 0.0 / 0.0;
}

f64 bxi_inf_pos(void)
{
    return 1.0 / 0.0;
}

f64 bxi_inf_neg(void)
{
    return -1.0 / 0.0;
}

bool bxi_isnan(f64 x)
{
    return x != x;
}

bool bxi_isinfpos(f64 x)
{
    return x == BXI_INF_POS;
}

bool bxi_isinfneg(f64 x)
{
    return x == BXI_INF_NEG;
}

f64 bxi_fmod(f64 x, f64 y)
{
    if ((bxi_isnan(x)) || (bxi_isnan(y)))
        return BXI_NAN;

    if ((bxi_isinfpos(x)) || (bxi_isinfneg(x)))
        return BXI_NAN;

    if ((y == 0.0))
        return BXI_NAN;

    if ((x == 0.0))
        return x;

    /* @todo bxi_fmod does not work */
    return (x - y * bxi_floor(x / y));
}

f64 bxi_floor(f64 x)
{
    i32 ix;
    f64 dx;

    if (bxi_isnan(x))
        return 0;
    if (x > I32_MAX)
        return I32_MAX;
    if (x < I32_MIN)
        return I32_MIN;

    ix = (i32)x;
    dx = x - (f64)ix;

    return x < 0.0 ? (dx < 0.0 ? ix - 1 : ix) : (ix);
}

f64 bxi_round(f64 x)
{
    if (bxi_isnan(x))
        return 0;
    if (x > I32_MAX)
        return I32_MAX;
    if (x < I32_MIN)
        return I32_MIN;

    return x < 0.0 ? (i32)(x - 0.5) :
                     (i32)(x + 0.5);
}

f64 bxi_ceil(f64 x)
{
    i32 ix;
    f64 dx;

    if (bxi_isnan(x))
        return 0;
    if (x > I32_MAX)
        return I32_MAX;
    if (x < I32_MIN)
        return I32_MIN;

    ix = (i32)x;
    dx = x - (f64)ix;

    return x > 0.0 ? (dx > 0.0 ? ix + 1 : ix) : (ix);
}

f64 bxi_trunc(f64 x)
{
    if (bxi_isnan(x))
        return 0;
    if (x > I32_MAX)
        return I32_MAX;
    if (x < I32_MIN)
        return I32_MIN;

    return (i32)x;
}

f64 bxi_fabs(f64 x)
{
    return x > 0 ? x : -x;
}

f64 bxi_modf(f64 x, f64 * i)
{
    i32 ix = (i32)x;

    if (bxi_isnan(x))
    {
        if (i)
            *i = BXI_NAN;
        return BXI_NAN;
    }

    ix = (i32)x;

    if (i)
        *i = ix;

    return x - ix;
}

/* @todo make it calculable on the whole line
 * instead of -Pi..+Pi */
f64 bxi_fsin(f64 x)
{
    /* Slightly optimised algo from Nick
     * http://forum.devmaster.net/t/9648 */
    double y = BXI_4_DIV_PI * x + (-BXI_4_DIV_SQR_PI) * x * bxi_fabs(x);
    return y * (0.225 * bxi_fabs(y) + 0.775);
}

f64 bxi_fcos(f64 x)
{
    return bxi_fsin(x + BXI_PI_DIV_2);
}
