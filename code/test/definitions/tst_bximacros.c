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

/* @todo good tests */

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
    TEST_BXI_MACRO_EXISTS_3(IN);
    TEST_BXI_MACRO_EXISTS_3(IN_INC);
}

void test_definitions_bximacros(void)
{
    print_info;
    test_definitions_defines();

    print_passed();
}
