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

void test_definitions_bximacros(void)
{
    u32 i;
    u32 test_array[20] = { 0 };

    print_info;

    printf("    defines:\n");
#   if defined(UNUSED)
        printf("        defined : UNUSED\n");
#   else
        print_failed();
#   endif

#   if defined(NULL)
        printf("        defined : NULL\n");
#   else
        print_failed();
#   endif

#   if defined(IN)
        printf("        defined : IN\n");
#   else
        print_failed();
#   endif

#   if defined(IN_INC)
        printf("        defined : IN_INC\n");
#   else
        print_failed();
#   endif

#   if defined(forever)
        printf("        defined : forever\n");
#   else
        print_failed();
#   endif

#   if defined(BXI_ARRAY_SIZE)
        printf("        defined : BXI_ARRAY_SIZE\n");
#   else
        print_failed();
#   endif

#   if defined(BXI_KB)
        printf("        defined : BXI_KB : 3 KB = %lu B\n", BXI_KB(3));
#   else
        print_failed();
#   endif

#   if defined(BXI_MB)
        printf("        defined : BXI_MB : 3 MB = %lu B\n", BXI_MB(3));
#   else
        print_failed();
#   endif

#   if defined(BXI_GB)
        printf("        defined : BXI_GB : 3 GB = %lu B\n", BXI_GB(3));
#   else
        print_failed();
#   endif

    printf("    functions:\n");
    printf("        checking: %s\n", "IN");
    for (i = 0;  i < 10; i++)
        if (IN(i, 8, 2) != ((8 > i) && (i > 2)))
            print_failed();

    printf("        checking: %s\n", "IN_INC");
    for (i = 0;  i < 10; i++)
        if (IN_INC(i, 8, 2) != ((8 >= i) && (i >= 2)))
            print_failed();

    printf("        checking: %s\n", "BXI_ARRAY_SIZE");
    if (BXI_ARRAY_SIZE(test_array) != (sizeof(test_array) / sizeof(test_array[0])))
        print_failed();

    print_passed();
}
