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

/* @todo good tests */

void test_hashes_bxihash(void)
{
    print_info;

    printf("    types:\n");

    printf("        checking: hash_4\n");
    if (sizeof(hash_4  ) != 4  )
        print_failed();

    printf("        checking: hash_8\n");
    if (sizeof(hash_8  ) != 8  )
        print_failed();

    printf("        checking: hash_16\n");
    if (sizeof(hash_16  ) != 16  )
        print_failed();

    printf("        checking: hash_32\n");
    if (sizeof(hash_32  ) != 32  )
        print_failed();

    printf("        checking: hash_64\n");
    if (sizeof(hash_64  ) != 64  )
        print_failed();

    printf("        checking: hash_128\n");
    if (sizeof(hash_128  ) != 128  )
        print_failed();

    printf("        checking: hash_256\n");
    if (sizeof(hash_256  ) != 256  )
        print_failed();

    printf("        checking: hash_512\n");
    if (sizeof(hash_512  ) != 512  )
        print_failed();

    print_passed();
}
