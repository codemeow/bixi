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

#include <stdio.h>
#include <libbixi.h>
#include "../test.h"
#include "../math/bximath.h"

void test_math_bximath(void)
{
    print_info;

    printf("    defines:\n");

    /* BXI_MAX */
#   if defined(BXI_MAX)
        printf("        defined : BXI_MAX\n");
        if (BXI_MAX(5, 6) != 6)
        {
            print_failed();
            return;
        }
#   else
        print_failed();
        return;
#   endif

    /* BXI_MIN */
#   if defined(BXI_MIN)
        printf("        defined : BXI_MIN\n");
        if (BXI_MIN(6, 5) != 5)
        {
            print_failed();
            return;
        }
#   else
        print_failed();
        return;
#   endif

    printf("    functions:\n");

    /* bxi_abs */
    printf("        checking: bxi_abs\n");
    if (bxi_abs(-5) != 5)
    {
        print_failed();
        return;
    }
    if (bxi_abs(0) != 0)
    {
        print_failed();
        return;
    }
    if (bxi_abs(5) != 5)
    {
        print_failed();
        return;
    }

    /* bxi_sign */
    printf("        checking: bxi_sign\n");
    if (bxi_sign(-5) != -1)
    {
        print_failed();
        return;
    }
    if (bxi_sign(0) != 0)
    {
        print_failed();
        return;
    }
    if (bxi_sign(5) != 1)
    {
        print_failed();
        return;
    }

    /* bxi_gcd */
    printf("        checking: bxi_gcd\n");
    if (bxi_gcd(28, 17) != 1)
    {
        print_failed();
        return;
    }
    if (bxi_gcd(28, 34) != 2)
    {
        print_failed();
        return;
    }
    if (bxi_gcd(-17, 34) != 17)
    {
        print_failed();
        return;
    }

    /* bxi_lcm */
    printf("        checking: bxi_lcm\n");
    if (bxi_lcm(65, 10) != 130)
    {
        print_failed();
        return;
    }
    if (bxi_lcm(17, 34) != 34)
    {
        print_failed();
        return;
    }
    if (bxi_lcm(12, 13) != 156)
    {
        print_failed();
        return;
    }

    print_passed();
}
