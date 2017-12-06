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
#include "../serials/tst_bxiserwrite.h"

static const u8 data[4] = { 0xf0, 0xf1, 0xf2, 0xf3 };

static void test_serials_bxi_write_i8(void)
{
    u8 test[4] = { 0 };

    printf("        checking: bxi_write_i8\n");

    bxi_write_i8(-16, test);
    if (bxi_memcmp(data, test, sizeof(i8)))
        test_failed();
}

static void test_serials_bxi_write_u8(void)
{
    u8 test[4] = { 0 };

    printf("        checking: bxi_write_u8\n");

    bxi_write_u8(0xf0u, test);
    if (bxi_memcmp(data, test, sizeof(u8)))
        test_failed();
}

static void test_serials_bxi_write_i16(void)
{
    u8 test[4] = { 0 };

    printf("        checking: bxi_write_i16\n");

    bxi_write_i16(-3600, test);
    if (bxi_memcmp(data, test, sizeof(i16)))
        test_failed();
}

static void test_serials_bxi_write_u16(void)
{
    u8 test[4] = { 0 };

    printf("        checking: bxi_write_u16\n");

    bxi_write_u16(61936, test);
    if (bxi_memcmp(data, test, sizeof(u16)))
        test_failed();
}

static void test_serials_bxi_write_i32(void)
{
    u8 test[4] = { 0 };

    printf("        checking: bxi_write_i32\n");

    bxi_write_i32(-202182160, test);
    if (bxi_memcmp(data, test, sizeof(i32)))
        test_failed();
}

static void test_serials_bxi_write_u32(void)
{
    u8 test[4] = { 0 };

    printf("        checking: bxi_write_u32\n");

    bxi_write_u32(0xf3f2f1f0u, test);
    if (bxi_memcmp(data, test, sizeof(u32)))
        test_failed();
}

static void test_serials_bxi_write_i16_be(void)
{
    u8 test[4] = { 0 };

    printf("        checking: bxi_write_i16_be\n");

    bxi_write_i16_be(-3855, test);
    if (bxi_memcmp(data, test, sizeof(i16_be)))
        test_failed();
}

static void test_serials_bxi_write_u16_be(void)
{
    u8 test[4] = { 0 };

    printf("        checking: bxi_write_u16_be\n");

    bxi_write_u16_be(0xf0f1u, test);
    if (bxi_memcmp(data, test, sizeof(u16_be)))
        test_failed();
}

static void test_serials_bxi_write_i32_be(void)
{
    u8 test[4] = { 0 };

    printf("        checking: bxi_write_i32_be\n");

    bxi_write_i32_be(-252579085, test);
    if (bxi_memcmp(data, test, sizeof(i32_be)))
        test_failed();
}

static void test_serials_bxi_write_u32_be(void)
{
    u8 test[4] = { 0 };

    printf("        checking: bxi_write_u32_be\n");

    bxi_write_u32_be(0xf0f1f2f3u, test);
    if (bxi_memcmp(data, test, sizeof(u32_be)))
        test_failed();
}

static void test_serials_bxi_write_i16_le(void)
{
    u8 test[4] = { 0 };

    printf("        checking: bxi_write_i16_le\n");

    bxi_write_i16_le(-3600, test);
    if (bxi_memcmp(data, test, sizeof(i16_le)))
        test_failed();
}

static void test_serials_bxi_write_u16_le(void)
{
    u8 test[4] = { 0 };

    printf("        checking: bxi_write_u16_le\n");

    bxi_write_u16_le(61936, test);
    if (bxi_memcmp(data, test, sizeof(u16_le)))
        test_failed();
}

static void test_serials_bxi_write_i32_le(void)
{
    u8 test[4] = { 0 };

    printf("        checking: bxi_write_i32_le\n");

    bxi_write_i32_le(-202182160, test);
    if (bxi_memcmp(data, test, sizeof(i32_le)))
        test_failed();
}

static void test_serials_bxi_write_u32_le(void)
{
    u8 test[4] = { 0 };

    printf("        checking: bxi_write_u32_le\n");

    bxi_write_u32_le(0xf3f2f1f0u, test);
    if (bxi_memcmp(data, test, sizeof(u32_le)))
        test_failed();
}

static void test_serials_functions(void)
{
    printf("    functions:\n");

    test_serials_bxi_write_i8();
    test_serials_bxi_write_u8();
    test_serials_bxi_write_i16();
    test_serials_bxi_write_u16();
    test_serials_bxi_write_i32();
    test_serials_bxi_write_u32();

    test_serials_bxi_write_i16_be();
    test_serials_bxi_write_u16_be();
    test_serials_bxi_write_i32_be();
    test_serials_bxi_write_u32_be();

    test_serials_bxi_write_i16_le();
    test_serials_bxi_write_u16_le();
    test_serials_bxi_write_i32_le();
    test_serials_bxi_write_u32_le();
}

void test_serials_bxiserwrite(void)
{
    print_info;

    test_serials_functions();

    print_passed();
}
