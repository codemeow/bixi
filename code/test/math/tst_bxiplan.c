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

#include <stdio.h>
#include <libbixi.h>
#include "../test.h"
#include "../math/tst_bxiplan.h"

static void test_math_definitions(void)
{
    printf("    defines:\n");
    TEST_BXI_MACRO_FLT(MM_PER_INCH);
}

static void test_math_bxi_segment_cross(void)
{
    bxi_line l1;
    bxi_line l2;
    bxi_point p1;

    printf("        checking: test_math_bxi_segment_cross\n");
    l1.p1.x = -1;
    l1.p1.y = 1;
    l1.p2.x = 5;
    l1.p2.y = 3;

    l2.p1.x = 2;
    l2.p1.y = 5;
    l2.p2.x = 2;
    l2.p2.y = -1;

    if (bxi_segment_cross(&l1, &l2, &p1) != true)
        test_failed();
    if ((p1.x != 2) || (p1.y != 2))
        test_failed();

    if (bxi_segment_cross(&l2, &l1, &p1) != true)
        test_failed();
    if ((p1.x != 2) || (p1.y != 2))
        test_failed();

    l1.p2.x = -1;
    l1.p2.y = 1;
    l1.p1.x = 5;
    l1.p1.y = 3;

    l2.p2.x = 2;
    l2.p2.y = 5;
    l2.p1.x = 2;
    l2.p1.y = -1;

    if (bxi_segment_cross(&l1, &l2, &p1) != true)
        test_failed();
    if ((p1.x != 2) || (p1.y != 2))
        test_failed();

    l1.p1.x = 5;
    l1.p1.y = 3;
    l1.p2.x = 1;
    l1.p2.y = 1;

    l2.p1.x = 1;
    l2.p1.y = 3;
    l2.p2.x = 5;
    l2.p2.y = 1;

    if (bxi_segment_cross(&l1, &l2, &p1) != true)
        test_failed();
    if ((p1.x != 3) || (p1.y != 2))
        test_failed();

    l1.p1.x = 1;
    l1.p1.y = 1;
    l1.p2.x = 5;
    l1.p2.y = 3;

    l2.p1.x = 1;
    l2.p1.y = 2;
    l2.p2.x = 5;
    l2.p2.y = 4;

    if (bxi_segment_cross(&l1, &l2, &p1) != false)
        test_failed();
}

static void test_math_functions(void)
{
    printf("    functions:\n");
    test_math_bxi_segment_cross();
}

void test_math_bxigeotypes(void)
{
    print_info;

    test_math_definitions();
    test_math_functions();

    print_passed();
}
