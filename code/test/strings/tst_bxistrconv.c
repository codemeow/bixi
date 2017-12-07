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
#include "../strings/tst_bxistrconv.h"

static void test_strings_test_str2xxx(void)
{
#   define TEST_STR2(func, v1, v2, v3)           \
    {                                            \
        i32 len = 0;                             \
        printf("        checking: %s\n", #func); \
        if (func(#v1, &len) != v1)               \
            test_failed();                       \
        else if (len != (i32)bxi_strlen(#v1))    \
            test_failed();                       \
        if (func(#v2, NULL) != v2)               \
            test_failed();                       \
        if (func(#v3, &len) != v3)               \
            test_failed();                       \
        else if (len != (i32)bxi_strlen(#v3))    \
            test_failed();                       \
    }

    TEST_STR2(bxi_str2i8,         -128,          0,         127);
    TEST_STR2(bxi_str2u8,            0,        128,         255);
    TEST_STR2(bxi_str2i16,      -32000,          0,       32000);
    TEST_STR2(bxi_str2u16,           0,      32000,       65000);
    TEST_STR2(bxi_str2i32, -2000000000,          0, +2000000000);
    TEST_STR2(bxi_str2u32,           0,  200000000,   400000000);

#   undef TEST_STR2
}

static void test_strings_test_hex2xxx(void)
{
#   define TEST_HEX2(func, hex, val)             \
    {                                            \
        i32 len = 0;                             \
        printf("        checking: %s\n", #func); \
        if (func(hex, &len) != val)              \
            test_failed();                       \
        if (len != (i32)bxi_strlen(hex))         \
            test_failed();                       \
    }

    TEST_HEX2(bxi_hex2i8    ,   "f0",              -16);
    TEST_HEX2(bxi_hex2u8    ,   "f0",              240);
    TEST_HEX2(bxi_hex2i16   ,   "f0f1",          -3855);
    TEST_HEX2(bxi_hex2u16   ,   "f0f1",          61681);
    TEST_HEX2(bxi_hex2i32   , "0xf0f1f2f3", -252579085);
    TEST_HEX2(bxi_hex2u32   , "0x181831e5",  404238821);
    TEST_HEX2(bxi_hex2i16_le,   "f0f1",          -3855);
    TEST_HEX2(bxi_hex2u16_le,   "f0f1",          61681);
    TEST_HEX2(bxi_hex2i32_le,   "f0f1f2f3", -252579085);
    TEST_HEX2(bxi_hex2u32_le,   "181831e5",  404238821);
    TEST_HEX2(bxi_hex2i16_be,   "f0f1",          -3600);
    TEST_HEX2(bxi_hex2u16_be,   "f0f1",          61936);
    TEST_HEX2(bxi_hex2i32_be,   "f0f1f2f3", -202182160);
    TEST_HEX2(bxi_hex2u32_be,   "10000000",         16);

#   undef TEST_HEX2
}

static void test_strings_test_xxx2str(void)
{
#   define TEST_2STR(func, str, val)             \
    {                                            \
        char buf[32];                            \
        printf("        checking: %s\n", #func); \
        if (func(buf, val) != bxi_strlen(str))   \
            test_failed();                       \
        if (bxi_strcmp(buf, str))                \
            test_failed();                       \
    }

    TEST_2STR(    bxi_i82hex, "f0"        ,         -16);
    TEST_2STR(    bxi_i82str, "-16"       ,         -16);
    TEST_2STR(   bxi_i162hex, "f0f1"      ,       -3855);
    TEST_2STR(   bxi_i162str, "-3855"     ,       -3855);
    TEST_2STR(bxi_i16_be2hex, "f0f1"      ,       -3600);
    TEST_2STR(bxi_i16_be2str, "-3855"     ,       -3600);
    TEST_2STR(bxi_i16_le2hex, "f0f1"      ,       -3855);
    TEST_2STR(bxi_i16_le2str, "-3855"     ,       -3855);
    TEST_2STR(   bxi_i322hex, "f0f1f2f3"  ,  -252579085);
    TEST_2STR(   bxi_i322str, "-252579085",  -252579085);
    TEST_2STR(bxi_i32_be2hex, "f0f1f2f3"  ,  -202182160);
    TEST_2STR(bxi_i32_be2str, "-252579085",  -202182160);
    TEST_2STR(bxi_i32_le2hex, "f0f1f2f3"  ,  -252579085);
    TEST_2STR(bxi_i32_le2str, "-252579085",  -252579085);
    TEST_2STR(    bxi_u82hex, "f0"        ,         240);
    TEST_2STR(    bxi_u82str, "240"       ,         240);
    TEST_2STR(   bxi_u162hex, "f0f1"      ,       61681);
    TEST_2STR(   bxi_u162str, "61681"     ,       61681);
    TEST_2STR(bxi_u16_be2hex, "f0f1"      ,       61936);
    TEST_2STR(bxi_u16_be2str, "61681"     ,       61936);
    TEST_2STR(bxi_u16_le2hex, "f0f1"      ,       61681);
    TEST_2STR(bxi_u16_le2str, "61681"     ,       61681);
    TEST_2STR(   bxi_u322hex, "f0f1f2f3"  , 4042388211u);
    TEST_2STR(   bxi_u322str, "4042388211", 4042388211u);
    TEST_2STR(bxi_u32_be2hex, "f0f1f2f3"  , 4092785136u);
    TEST_2STR(bxi_u32_be2str, "4042388211", 4092785136u);
    TEST_2STR(bxi_u32_le2hex, "f0f1f2f3"  , 4042388211u);
    TEST_2STR(bxi_u32_le2str, "4042388211", 4042388211u);

#   undef TEST_2STR
}

static void test_strings_test_xxx2raw(void)
{
#   define TEST_2RAW(func, val, size)            \
    {                                            \
        u8 eth[4] = { 0x12, 0x34, 0x56, 0x78 };  \
        u8 raw[4] = { 0 };                       \
        printf("        checking: %s\n", #func); \
        if (func(val, raw) != size)              \
            test_failed();                       \
        if (bxi_memcmp(raw, eth, size))          \
            test_failed();                       \
    }

    TEST_2RAW(bxi_i82raw,     0x12,       1);
    TEST_2RAW(bxi_u82raw,     0x12,       1);
    TEST_2RAW(bxi_i162raw,    0x3412,     2);
    TEST_2RAW(bxi_i16_le2raw, 0x3412,     2);
    TEST_2RAW(bxi_i16_be2raw, 0x1234,     2);
    TEST_2RAW(bxi_u162raw,    0x3412,     2);
    TEST_2RAW(bxi_u16_le2raw, 0x3412,     2);
    TEST_2RAW(bxi_u16_be2raw, 0x1234,     2);
    TEST_2RAW(bxi_i322raw,    0x78563412, 4);
    TEST_2RAW(bxi_i32_le2raw, 0x78563412, 4);
    TEST_2RAW(bxi_i32_be2raw, 0x12345678, 4);
    TEST_2RAW(bxi_u322raw,    0x78563412, 4);
    TEST_2RAW(bxi_u32_le2raw, 0x78563412, 4);
    TEST_2RAW(bxi_u32_be2raw, 0x12345678, 4);

#   undef TEST_2RAW
}

static void test_strings_bxi_raw2hex(void)
{
#   define TEST_FORMAT(name, flags)                      \
    {                                                    \
        char out[128];                                   \
        bxi_raw2hex(out, raw, 16, flags);                \
        printf("            [%s]: \"%s\"\n", name, out); \
    }

    u32  i;
    u8   raw[16] = { 0 };
    for (i = 0; i < 16; i++)
        raw[i] = i * 16;

    printf("        checking: bxi_raw2hex\n");
    TEST_FORMAT(" C ", BXI_HEX_COMBO_C      | BXI_HEX_END_CLOSED);
    TEST_FORMAT("CSS", BXI_HEX_COMBO_CSS    | BXI_HEX_END_CLOSED);
    TEST_FORMAT("INT", BXI_HEX_COMBO_INTEL  | BXI_HEX_END_CLOSED);
    TEST_FORMAT("IP6", BXI_HEX_COMBO_IPv6   | BXI_HEX_END_CLOSED);
    TEST_FORMAT("PAS", BXI_HEX_COMBO_PASCAL | BXI_HEX_END_CLOSED);
    TEST_FORMAT("XML", BXI_HEX_COMBO_XML    | BXI_HEX_END_CLOSED);

#   undef TEST_FORMAT
}

static void test_strings_bxi_hex2raw(void)
{
    u8   data[8] = { 0 };
    u8   etha[8] = { 0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7 };

    printf("        checking: bxi_hex2raw\n");
    if (bxi_hex2raw("f0f1f2f3f4f5f6f7", data) != 8)
        test_failed();
    if (bxi_memcmp(data, etha, sizeof(data)))
        test_failed();
}

static void test_strings_functions(void)
{
    printf("    functions:\n");

    test_strings_test_str2xxx();
    test_strings_test_hex2xxx();
    test_strings_test_xxx2str();
    test_strings_test_xxx2raw();

    test_strings_bxi_raw2hex();
    test_strings_bxi_hex2raw();
}

void test_strings_bxistrconv(void)
{
    print_info;

    test_strings_functions();

    print_passed();
}
