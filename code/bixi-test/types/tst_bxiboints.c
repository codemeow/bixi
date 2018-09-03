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
#include "../types/tst_bxiboints.h"

static void test_types_defines(void)
{
    printf("    defines:\n");

    TEST_BXI_MACRO_U32(BITS_IN_U16_LE);
    TEST_BXI_MACRO_U32(BITS_IN_U32_LE);
    TEST_BXI_MACRO_U32(BITS_IN_I16_LE);
    TEST_BXI_MACRO_U32(BITS_IN_I32_LE);

    TEST_BXI_MACRO_U32(BITS_IN_U16_BE);
    TEST_BXI_MACRO_U32(BITS_IN_U32_BE);
    TEST_BXI_MACRO_U32(BITS_IN_I16_BE);
    TEST_BXI_MACRO_U32(BITS_IN_I32_BE);

    TEST_BXI_MACRO_U32(U8_LE_MIN);
    TEST_BXI_MACRO_U32(U8_BE_MIN);
    TEST_BXI_MACRO_U32(U16_LE_MIN);
    TEST_BXI_MACRO_U32(U16_BE_MIN);
    TEST_BXI_MACRO_U32(U32_LE_MIN);
    TEST_BXI_MACRO_U32(U32_BE_MIN);

    TEST_BXI_MACRO_I32(I8_LE_MIN);
    TEST_BXI_MACRO_I32(I8_BE_MIN);
    TEST_BXI_MACRO_I32(I16_LE_MIN);
    TEST_BXI_MACRO_I32(I16_BE_MIN);
    TEST_BXI_MACRO_I32(I32_LE_MIN);
    TEST_BXI_MACRO_I32(I32_BE_MIN);

    TEST_BXI_MACRO_U32(U8_LE_MAX);
    TEST_BXI_MACRO_U32(U8_BE_MAX);
    TEST_BXI_MACRO_U32(U16_LE_MAX);
    TEST_BXI_MACRO_U32(U16_BE_MAX);
    TEST_BXI_MACRO_U32(U32_LE_MAX);
    TEST_BXI_MACRO_U32(U32_BE_MAX);

    TEST_BXI_MACRO_I32(I8_LE_MAX);
    TEST_BXI_MACRO_I32(I8_BE_MAX);
    TEST_BXI_MACRO_I32(I16_LE_MAX);
    TEST_BXI_MACRO_I32(I16_BE_MAX);
    TEST_BXI_MACRO_I32(I32_LE_MAX);
    TEST_BXI_MACRO_I32(I32_BE_MAX);

    TEST_BXI_MACRO_U32(IS_BE);
    TEST_BXI_MACRO_U32(IS_LE);
}

static void test_types_test_bxi_chgend16(void)
{
    printf("        checking: bxi_chgend16\n");
    if (bxi_chgend16(0xFE06) != 0x06FE)
        test_failed();
}

static void test_types_test_bxi_chgend32(void)
{
    printf("        checking: bxi_chgend32\n");
    if (bxi_chgend32(0x78563412ul) != 0x12345678ul)
        test_failed();
}

static void test_types_test_bxi_i16_le2i16(void)
{
    printf("        checking: bxi_i16_le2i16\n");
    if (bxi_i16_le2i16(0x1234) != 0x1234)
        test_failed();
}

static void test_types_test_bxi_i16_be2i16(void)
{
    printf("        checking: bxi_i16_be2i16\n");
    if (bxi_i16_be2i16(0x1234) != 0x3412)
        test_failed();
}


static void test_types_test_bxi_i16_le2i16_be(void)
{
    printf("        checking: bxi_i16_le2i16_be\n");
    if (bxi_i16_le2i16_be(0x1234) != 0x3412)
        test_failed();
}

static void test_types_test_bxi_i16_be2i16_le(void)
{
    printf("        checking: bxi_i16_be2i16_le\n");
    if (bxi_i16_be2i16_le(0x1234) != 0x3412)
        test_failed();
}

static void test_types_test_bxi_i162i16_be(void)
{
    printf("        checking: bxi_i162i16_be\n");
    if (bxi_i162i16_be(0x1234) != 0x3412)
        test_failed();
}

static void test_types_test_bxi_i162i16_le(void)
{
    printf("        checking: bxi_i162i16_le\n");
    if (bxi_i162i16_le(0x1234) != 0x1234)
        test_failed();
}

static void test_types_test_bxi_i32_le2i32(void)
{
    printf("        checking: bxi_i32_le2i32\n");
    if (bxi_i32_le2i32(0x12345678u) != 0x12345678u)
        test_failed();
}

static void test_types_test_bxi_i32_be2i32(void)
{
    printf("        checking: bxi_i32_be2i32\n");
    if (bxi_i32_be2i32(0x12345678u) != 0x78563412u)
        test_failed();
}

static void test_types_test_bxi_i32_le2i32_be(void)
{
    printf("        checking: bxi_i32_le2i32_be\n");
    if (bxi_i32_le2i32_be(0x12345678u) != 0x78563412u)
        test_failed();
}


static void test_types_test_bxi_i32_be2i32_le(void)
{
    printf("        checking: bxi_i32_be2i32_le\n");
    if (bxi_i32_be2i32_le(0x12345678u) != 0x78563412u)
        test_failed();
}

static void test_types_test_bxi_i322i32_be(void)
{
    printf("        checking: bxi_i322i32_be\n");
    if (bxi_i322i32_be(0x12345678u) != 0x78563412u)
        test_failed();
}

static void test_types_test_bxi_i322i32_le(void)
{
    printf("        checking: bxi_i322i32_le\n");
    if (bxi_i322i32_le(0x12345678u) != 0x12345678u)
        test_failed();
}

static void test_types_test_bxi_u16_le2u16(void)
{
    printf("        checking: bxi_u16_le2u16\n");
    if (bxi_u16_le2u16(0x1234) != 0x1234)
        test_failed();
}

static void test_types_test_bxi_u16_be2u16(void)
{
    printf("        checking: bxi_u16_be2u16\n");
    if (bxi_u16_be2u16(0x1234) != 0x3412)
        test_failed();
}

static void test_types_test_bxi_u16_le2u16_be(void)
{
    printf("        checking: bxi_u16_le2u16_be\n");
    if (bxi_u16_le2u16_be(0x1234) != 0x3412)
        test_failed();
}

static void test_types_test_bxi_u16_be2u16_le(void)
{
    printf("        checking: bxi_u16_be2u16_le\n");
    if (bxi_u16_be2u16_le(0x1234) != 0x3412)
        test_failed();
}

static void test_types_test_bxi_u162u16_be(void)
{
    printf("        checking: bxi_u162u16_be\n");
    if (bxi_u162u16_be(0x1234) != 0x3412)
        test_failed();
}

static void test_types_test_bxi_u162u16_le(void)
{
    printf("        checking: bxi_u162u16_le\n");
    if (bxi_u162u16_le(0x1234) != 0x1234)
        test_failed();
}

static void test_types_test_bxi_u32_le2u32(void)
{
    printf("        checking: bxi_u32_le2u32\n");
    if (bxi_u32_le2u32(0x12345678u) != 0x12345678u)
        test_failed();
}

static void test_types_test_bxi_u32_be2u32(void)
{
    printf("        checking: bxi_u32_be2u32\n");
    if (bxi_u32_be2u32(0x12345678) != 0x78563412)
        test_failed();
}

static void test_types_test_bxi_u32_le2u32_be(void)
{
    printf("        checking: bxi_u32_le2u32_be\n");
    if (bxi_u32_le2u32_be(0x12345678) != 0x78563412)
        test_failed();
}

static void test_types_test_bxi_u32_be2u32_le(void)
{
    printf("        checking: bxi_u32_be2u32_le\n");
    if (bxi_u32_be2u32_le(0x12345678) != 0x78563412)
        test_failed();
}

static void test_types_test_bxi_u322u32_be(void)
{
    printf("        checking: bxi_u322u32_be\n");
    if (bxi_u322u32_be(0x12345678) != 0x78563412)
        test_failed();
}

static void test_types_test_bxi_u322u32_le(void)
{
    printf("        checking: bxi_u322u32_le\n");
    if (bxi_u322u32_le(0x12345678) != 0x12345678)
        test_failed();
}

static void test_types_functions(void)
{
    printf("    functions:\n");
    test_types_test_bxi_chgend16();
    test_types_test_bxi_chgend32();

    test_types_test_bxi_i16_le2i16();
    test_types_test_bxi_i16_be2i16();

    test_types_test_bxi_i16_le2i16_be();
    test_types_test_bxi_i16_be2i16_le();

    test_types_test_bxi_i162i16_be();
    test_types_test_bxi_i162i16_le();

    test_types_test_bxi_i32_le2i32();
    test_types_test_bxi_i32_be2i32();

    test_types_test_bxi_i32_le2i32_be();
    test_types_test_bxi_i32_be2i32_le();

    test_types_test_bxi_i322i32_be();
    test_types_test_bxi_i322i32_le();

    test_types_test_bxi_u16_le2u16();
    test_types_test_bxi_u16_be2u16();

    test_types_test_bxi_u16_le2u16_be();
    test_types_test_bxi_u16_be2u16_le();

    test_types_test_bxi_u162u16_be();
    test_types_test_bxi_u162u16_le();

    test_types_test_bxi_u32_le2u32();
    test_types_test_bxi_u32_be2u32();

    test_types_test_bxi_u32_le2u32_be();
    test_types_test_bxi_u32_be2u32_le();

    test_types_test_bxi_u322u32_be();
    test_types_test_bxi_u322u32_le();
}

void test_types_bxiboints(void)
{
    print_info;

    test_types_defines();
    test_types_functions();

    print_passed();
}
