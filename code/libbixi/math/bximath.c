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
