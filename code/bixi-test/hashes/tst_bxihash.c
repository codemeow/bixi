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
#include "../hashes/tst_bxihash.h"

static void test_hashes_types(void)
{
    printf("    types:\n");

    TEST_BXI_TYPE_SIZE(hash_4,   4);
    TEST_BXI_TYPE_SIZE(hash_8,   8);
    TEST_BXI_TYPE_SIZE(hash_16,  16);
    TEST_BXI_TYPE_SIZE(hash_32,  32);
    TEST_BXI_TYPE_SIZE(hash_64,  64);
    TEST_BXI_TYPE_SIZE(hash_128, 128);
    TEST_BXI_TYPE_SIZE(hash_256, 256);
    TEST_BXI_TYPE_SIZE(hash_512, 512);
}

void test_hashes_bxihash(void)
{
    print_info;

    test_hashes_types();

    print_passed();
}
