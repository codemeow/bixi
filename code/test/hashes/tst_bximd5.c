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

void test_hashes_bximd5(void)
{
    md5_t md5;
    char  outp[100];
    i32   i;
    u8    data08[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                        0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };
    u16   data16[ 8] = {0x0001, 0x0203, 0x0405, 0x0607,
                        0x0809, 0x0a0b, 0x0c0d, 0x0e0f };
    u32   data32[ 4] = {0x00010203, 0x04050607, 0x08090a0b, 0x0c0d0e0f };

    print_info;

    printf("    hashes:\n");

    printf("        checking: empty  (");
    md5_init(&md5);
    md5_final(&md5);
    uuid2str(md5.hash, outp, UUID_PLAIN);
    printf("%s)\n", outp);

    if (bxi_strcmp(outp, "d41d8cd98f00b204e9800998ecf8427e"))
        print_failed();

    printf("        checking: phrase (");
    md5_init(&md5);
    md5_appendstr(&md5, "The quick brown fox jumps over the lazy dog");
    md5_final(&md5);
    uuid2str(md5.hash, outp, UUID_PLAIN);
    printf("%s)\n", outp);

    if (bxi_strcmp(outp, "9e107d9d372bb6826bd81d3542a419d6"))
        print_failed();

    printf("        checking: u8     (");
    md5_init(&md5);
    for (i = 0; i < 16; i++)
        md5_appendu8(&md5, data08[i]);
    md5_final(&md5);
    uuid2str(md5.hash, outp, UUID_PLAIN);
    printf("%s)\n", outp);

    if (bxi_strcmp(outp, "1ac1ef01e96caf1be0d329331a4fc2a8"))
        print_failed();

    printf("        checking: u16    (");
    md5_init(&md5);
    for (i = 0; i < 8; i++)
        md5_appendu16(&md5, data16[i]);
    md5_final(&md5);
    uuid2str(md5.hash, outp, UUID_PLAIN);
    printf("%s)\n", outp);

    if (bxi_strcmp(outp, "84011483e9df3fbe3a6efc9bc5503707"))
        print_failed();

    printf("        checking: u32    (");
    md5_init(&md5);
    for (i = 0; i < 4; i++)
        md5_appendu32(&md5, data32[i]);
    md5_final(&md5);
    uuid2str(md5.hash, outp, UUID_PLAIN);
    printf("%s)\n", outp);

    if (bxi_strcmp(outp, "77c0d5ed7c6f1535e08a8a3176c98ea9"))
        print_failed();

    print_passed();
}
