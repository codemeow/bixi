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
#include "../types/bxiints.h"

void test_types_bxiints(void)
{
    print_info;

    printf("    defines\n");

#   if defined(BITS_IN_BYTE)
        printf("        defined: BITS_IN_BYTE: %d\n", BITS_IN_BYTE);
#   else
        print_failed();
#   endif

#   if defined(BITS_IN_U8)
        printf("        defined: BITS_IN_U8  : %d\n", BITS_IN_U8);
#   else
        print_failed();
#   endif

#   if defined(BITS_IN_U16)
        printf("        defined: BITS_IN_U16 : %d\n", BITS_IN_U16);
#   else
        print_failed();
#   endif

#   if defined(BITS_IN_U32)
        printf("        defined: BITS_IN_U32 : %d\n", BITS_IN_U32);
#   else
        print_failed();
#   endif

#   if defined(BITS_IN_I8)
        printf("        defined: BITS_IN_I8  : %d\n", BITS_IN_I8);
#   else
        print_failed();
#   endif

#   if defined(BITS_IN_I16)
        printf("        defined: BITS_IN_I16 : %d\n", BITS_IN_I16);
#   else
        print_failed();
#   endif

#   if defined(BITS_IN_I32)
        printf("        defined: BITS_IN_I32 : %d\n", BITS_IN_I32);
#   else
        print_failed();
#   endif

#   if defined(U8_MIN)
        printf("        defined: U8_MIN      : %d\n", U8_MIN);
#   else
        print_failed();
#   endif

#   if defined(U16_MIN)
        printf("        defined: U16_MIN     : %d\n", U16_MIN);
#   else
        print_failed();
#   endif

#   if defined(U32_MIN)
        printf("        defined: U32_MIN     : %d\n", U32_MIN);
#   else
        print_failed();
#   endif

#   if defined(U8_MAX)
        printf("        defined: U8_MAX      : %d\n", U8_MAX);
#   else
        print_failed();
#   endif

#   if defined(U16_MAX)
        printf("        defined: U16_MAX     : %d\n", U16_MAX);
#   else
        print_failed();
#   endif

#   if defined(U32_MAX)
        printf("        defined: U32_MAX     : %u\n", U32_MAX);
#   else
        print_failed();
#   endif

#   if defined(I8_MIN)
        printf("        defined: I8_MIN      : %d\n", I8_MIN);
#   else
        print_failed();
#   endif

#   if defined(I16_MIN)
        printf("        defined: I16_MIN     : %d\n", I16_MIN);
#   else
        print_failed();
#   endif

#   if defined(I32_MIN)
        printf("        defined: I32_MIN     : %d\n", I32_MIN);
#   else
        print_failed();
#   endif

#   if defined(I8_MAX)
        printf("        defined: I8_MAX      : %d\n", I8_MAX);
#   else
        print_failed();
#   endif

#   if defined(I16_MAX)
        printf("        defined: I16_MAX     : %d\n", I16_MAX);
#   else
        print_failed();
#   endif

#   if defined(I32_MAX)
        printf("        defined: I32_MAX     : %d\n", I32_MAX);
#   else
        print_failed();
#   endif

    print_passed();
}
