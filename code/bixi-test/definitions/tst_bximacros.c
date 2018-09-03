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
#include "../definitions/tst_bximacros.h"

static void test_definitions_test_bxi_array_size(void)
{
    u8  data1[10];
    u16 data2[20];
    u32 data3[30];

    if (BXI_ARRAY_SIZE(data1) != 10)
        test_failed();
    if (BXI_ARRAY_SIZE(data2) != 20)
        test_failed();
    if (BXI_ARRAY_SIZE(data3) != 30)
        test_failed();
}

static void test_definitions_test_bxi_in(void)
{
    if (!BXI_IN(5, 10, 0))
        test_failed();
    if (!BXI_IN(9, 10, 0))
        test_failed();
    if ( BXI_IN(10, 10, 0))
        test_failed();
}

static void test_definitions_test_bxi_in_inc(void)
{
    if (!BXI_IN_INC(5, 10, 0))
        test_failed();
    if (!BXI_IN_INC(9, 10, 0))
        test_failed();
    if (!BXI_IN_INC(10, 10, 0))
        test_failed();
}

static void test_definitions_defines(void)
{
    printf("    defines:\n");

    TEST_BXI_MACRO_EXISTS(UNUSED);
    TEST_BXI_MACRO_EXISTS(NULL);
    TEST_BXI_MACRO_EXISTS(forever);
    TEST_BXI_MACRO_EXISTS(BXI_KB);
    TEST_BXI_MACRO_EXISTS(BXI_MB);
    TEST_BXI_MACRO_EXISTS(BXI_GB);
    TEST_BXI_MACRO_EXISTS(BXI_ARRAY_SIZE);
        test_definitions_test_bxi_array_size();
    TEST_BXI_MACRO_EXISTS_3(BXI_IN);
        test_definitions_test_bxi_in();
    TEST_BXI_MACRO_EXISTS_3(BXI_IN_INC);
        test_definitions_test_bxi_in_inc();
}

void test_definitions_bximacros(void)
{
    print_info;
    test_definitions_defines();

    print_passed();
}
