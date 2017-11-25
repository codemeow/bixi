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
#include "../types/tst_bxibools.h"

/* @todo good tests */

void test_types_bxibools(void)
{
    print_info;

    printf("    defined:\n");

#   if defined(BITS_IN_B8)
        printf("        defined: BITS_IN_B8 : %d\n", BITS_IN_B8);
#   else
        print_failed();
#   endif

#   if defined(BITS_IN_B16)
        printf("        defined: BITS_IN_B16: %d\n", BITS_IN_B16);
#   else
        print_failed();
#   endif


#   if defined(BITS_IN_B32)
        printf("        defined: BITS_IN_B32: %d\n", BITS_IN_B32);
#   else
        print_failed();
#   endif

    print_passed();
}
