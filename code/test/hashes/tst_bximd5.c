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
#include "../hashes/tst_bximd5.h"

static void test_hashes_empty(void)
{
    md5_t md5;
    char  outp[100];

    printf("        checking: empty  ");

    md5_init(&md5);
    md5_final(&md5);

    uuid2str(md5.hash, outp, UUID_PLAIN);
    printf("(%s)\n", outp);

    if (bxi_strcmp(outp, "d41d8cd98f00b204e9800998ecf8427e"))
        test_failed();
}

static void test_hashes_md5_appendstr(void)
{
    md5_t md5;
    char  outp[100];

    printf("        checking: text   ");

    md5_init(&md5);
    md5_appendstr(&md5, "The quick brown fox jumps over the lazy dog");
    md5_final(&md5);

    uuid2str(md5.hash, outp, UUID_PLAIN);
    printf("(%s)\n", outp);

    if (bxi_strcmp(outp, "9e107d9d372bb6826bd81d3542a419d6"))
        test_failed();
}

static void test_hashes_md5_append(void)
{
    md5_t md5;
    char  outp[100];
    u8    data08[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                        0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };

    printf("        checking: append ");

    md5_init(&md5);
    md5_append(&md5, data08, 16);
    md5_final(&md5);

    uuid2str(md5.hash, outp, UUID_PLAIN);
    printf("(%s)\n", outp);

    if (bxi_strcmp(outp, "1ac1ef01e96caf1be0d329331a4fc2a8"))
        test_failed();
}

static void test_hashes_md5_appendu8(void)
{
    md5_t md5;
    char  outp[100];
    i32   i;
    u8    data08[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                        0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };

    printf("        checking: u8     ");

    md5_init(&md5);
    for (i = 0; i < 16; i++)
        md5_appendu8(&md5, data08[i]);
    md5_final(&md5);

    uuid2str(md5.hash, outp, UUID_PLAIN);
    printf("(%s)\n", outp);

    if (bxi_strcmp(outp, "1ac1ef01e96caf1be0d329331a4fc2a8"))
        test_failed();
}

static void test_hashes_md5_appendu16(void)
{
    md5_t md5;
    char  outp[100];
    i32   i;
    u16   data16[ 8] = {0x0001, 0x0203, 0x0405, 0x0607,
                        0x0809, 0x0a0b, 0x0c0d, 0x0e0f };

    printf("        checking: u16    ");

    md5_init(&md5);
    for (i = 0; i < 8; i++)
        md5_appendu16(&md5, data16[i]);
    md5_final(&md5);

    uuid2str(md5.hash, outp, UUID_PLAIN);
    printf("(%s)\n", outp);

    if (bxi_strcmp(outp, "84011483e9df3fbe3a6efc9bc5503707"))
        test_failed();
}

static void test_hashes_md5_appendu32(void)
{
    md5_t md5;
    char  outp[100];
    i32   i;
    u32   data32[ 4] = {0x00010203, 0x04050607, 0x08090a0b, 0x0c0d0e0f };

    printf("        checking: u32    ");

    md5_init(&md5);
    for (i = 0; i < 4; i++)
        md5_appendu32(&md5, data32[i]);
    md5_final(&md5);

    uuid2str(md5.hash, outp, UUID_PLAIN);
    printf("(%s)\n", outp);

    if (bxi_strcmp(outp, "77c0d5ed7c6f1535e08a8a3176c98ea9"))
        test_failed();
}

static void test_hashes_md5_appendi8(void)
{
    md5_t md5;
    char  outp[100];
    i32   i;
    i8    data08[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                        0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };

    printf("        checking: i8     ");

    md5_init(&md5);
    for (i = 0; i < 16; i++)
        md5_appendi8(&md5, data08[i]);
    md5_final(&md5);

    uuid2str(md5.hash, outp, UUID_PLAIN);
    printf("(%s)\n", outp);

    if (bxi_strcmp(outp, "1ac1ef01e96caf1be0d329331a4fc2a8"))
        test_failed();
}

static void test_hashes_md5_appendi16(void)
{
    md5_t md5;
    char  outp[100];
    i32   i;
    i16   data16[ 8] = {0x0001, 0x0203, 0x0405, 0x0607,
                        0x0809, 0x0a0b, 0x0c0d, 0x0e0f };

    printf("        checking: i16    ");

    md5_init(&md5);
    for (i = 0; i < 8; i++)
        md5_appendi16(&md5, data16[i]);
    md5_final(&md5);

    uuid2str(md5.hash, outp, UUID_PLAIN);
    printf("(%s)\n", outp);

    if (bxi_strcmp(outp, "84011483e9df3fbe3a6efc9bc5503707"))
        test_failed();
}

static void test_hashes_md5_appendi32(void)
{
    md5_t md5;
    char  outp[100];
    i32   i;
    i32   data32[ 4] = {0x00010203, 0x04050607, 0x08090a0b, 0x0c0d0e0f };

    printf("        checking: i32    ");

    md5_init(&md5);
    for (i = 0; i < 4; i++)
        md5_appendi32(&md5, data32[i]);
    md5_final(&md5);

    uuid2str(md5.hash, outp, UUID_PLAIN);
    printf("(%s)\n", outp);

    if (bxi_strcmp(outp, "77c0d5ed7c6f1535e08a8a3176c98ea9"))
        test_failed();
}

static void test_hashes_md5_copy(void)
{
    md5_t md1;
    u8 data[16] = { 0 };

    md5_init(&md1);
    md5_final(&md1);

    md5_copy(&md1, data);


    printf("        checking: copy\n");

    if ((data[ 0] != 0xd4) || (data[ 1] != 0x1d) ||
        (data[ 2] != 0x8c) || (data[ 3] != 0xd9) ||
        (data[ 4] != 0x8f) || (data[ 5] != 0x00) ||
        (data[ 6] != 0xb2) || (data[ 7] != 0x04) ||
        (data[ 8] != 0xe9) || (data[ 9] != 0x80) ||
        (data[10] != 0x09) || (data[11] != 0x98) ||
        (data[12] != 0xec) || (data[13] != 0xf8) ||
        (data[14] != 0x42) || (data[15] != 0x7e))
        test_failed();
}

void test_hashes_bximd5(void)
{
    print_info;

    printf("    hashes:\n");

    test_hashes_empty();
    test_hashes_md5_append();
    test_hashes_md5_appendstr();
    test_hashes_md5_appendu8();
    test_hashes_md5_appendu16();
    test_hashes_md5_appendu32();
    test_hashes_md5_appendi8();
    test_hashes_md5_appendi16();
    test_hashes_md5_appendi32();
    test_hashes_md5_copy();

    print_passed();
}
