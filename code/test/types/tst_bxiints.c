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
#include "../types/tst_bxiints.h"

static void test_types_defines(void)
{
    printf("    defines\n");

    TEST_BXI_MACRO_U32(BITS_IN_BYTE);
    TEST_BXI_MACRO_U32(BITS_IN_U16);
    TEST_BXI_MACRO_U32(BITS_IN_U32);
    TEST_BXI_MACRO_U32(BITS_IN_I8);
    TEST_BXI_MACRO_U32(BITS_IN_I16);
    TEST_BXI_MACRO_U32(BITS_IN_I32);
    TEST_BXI_MACRO_U32(U8_MIN);
    TEST_BXI_MACRO_U32(U16_MIN);
    TEST_BXI_MACRO_U32(U32_MIN);
    TEST_BXI_MACRO_U32(U8_MAX);
    TEST_BXI_MACRO_U32(U16_MAX);
    TEST_BXI_MACRO_U32(U32_MAX);
    TEST_BXI_MACRO_I32(I8_MIN);
    TEST_BXI_MACRO_I32(I16_MIN);
    TEST_BXI_MACRO_I32(I32_MIN);
    TEST_BXI_MACRO_I32(I8_MAX);
    TEST_BXI_MACRO_I32(I16_MAX);
    TEST_BXI_MACRO_I32(I32_MAX);
}

void test_types_bxiints(void)
{
    print_info;

    test_types_defines();

    print_passed();
}
