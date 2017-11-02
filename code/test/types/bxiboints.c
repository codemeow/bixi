/*
* «Bixi» - Basic types management C89 library
*
*  Copyright (C) Alexey Shishkin 2017
*
*  This file is part of Project «Bixi».
*
*  Project «Bixi» is free software: you can redistribute it and/or modify
*  it under the terms of the GNU Lesser General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  Project «Bixi» is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*  GNU Lesser General Public License for more details.
*
*  You should have received a copy of the GNU Lesser General Public License
*  along with Project «Bixi». If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <libbixi.h>
#include "../test.h"
#include "../types/bxiboints.h"

void test_types_bxiboints(void)
{
    print_info;

    printf("    defines:\n");

#   if defined(BITS_IN_U16_LE)
        printf("        defined: BITS_IN_U16_LE : %d\n", BITS_IN_U16_LE);
#   else
        print_failed();
        return;
#   endif

#   if defined(BITS_IN_U32_LE)
        printf("        defined: BITS_IN_U32_LE : %d\n", BITS_IN_U32_LE);
#   else
        print_failed();
        return;
#   endif

#   if defined(BITS_IN_I16_LE)
        printf("        defined: BITS_IN_I16_LE : %d\n", BITS_IN_I16_LE);
#   else
        print_failed();
        return;
#   endif

#   if defined(BITS_IN_I32_LE)
        printf("        defined: BITS_IN_I32_LE : %d\n", BITS_IN_I32_LE);
#   else
        print_failed();
        return;
#   endif

#   if defined(BITS_IN_U16_BE)
        printf("        defined: BITS_IN_U16_BE : %d\n", BITS_IN_U16_BE);
#   else
        print_failed();
        return;
#   endif

#   if defined(BITS_IN_U32_BE)
        printf("        defined: BITS_IN_U32_BE : %d\n", BITS_IN_U32_BE);
#   else
        print_failed();
        return;
#   endif

#   if defined(BITS_IN_I16_BE)
        printf("        defined: BITS_IN_I16_BE : %d\n", BITS_IN_I16_BE);
#   else
        print_failed();
        return;
#   endif

#   if defined(BITS_IN_I32_BE)
        printf("        defined: BITS_IN_I32_BE : %d\n", BITS_IN_I32_BE);
#   else
        print_failed();
        return;
#   endif

#   if defined(U8_LE_MIN)
        printf("        defined:      U8_LE_MIN : %d\n", U8_LE_MIN);
#   else
        print_failed();
        return;
#   endif

#   if defined(U8_BE_MIN)
        printf("        defined:      U8_BE_MIN : %d\n", U8_BE_MIN);
#   else
        print_failed();
        return;
#   endif

#   if defined(U16_LE_MIN)
        printf("        defined:     U16_LE_MIN : %d\n", U16_LE_MIN);
#   else
        print_failed();
        return;
#   endif

#   if defined(U16_BE_MIN)
        printf("        defined:     U16_BE_MIN : %d\n", U16_BE_MIN);
#   else
        print_failed();
        return;
#   endif

#   if defined(U32_LE_MIN)
        printf("        defined:     U32_LE_MIN : %d\n", U32_LE_MIN);
#   else
        print_failed();
        return;
#   endif

#   if defined(U32_BE_MIN)
        printf("        defined:     U32_BE_MIN : %d\n", U32_BE_MIN);
#   else
        print_failed();
        return;
#   endif

#   if defined(I8_LE_MIN)
        printf("        defined:      I8_LE_MIN : %d\n", I8_LE_MIN);
#   else
        print_failed();
        return;
#   endif

#   if defined(I8_BE_MIN)
        printf("        defined:      I8_BE_MIN : %d\n", I8_BE_MIN);
#   else
        print_failed();
        return;
#   endif

#   if defined(I16_LE_MIN)
        printf("        defined:     I16_LE_MIN : %d\n", I16_LE_MIN);
#   else
        print_failed();
        return;
#   endif

#   if defined(I16_BE_MIN)
        printf("        defined:     I16_BE_MIN : %d\n", I16_BE_MIN);
#   else
        print_failed();
        return;
#   endif

#   if defined(I32_LE_MIN)
        printf("        defined:     I32_LE_MIN : %d\n", I32_LE_MIN);
#   else
        print_failed();
        return;
#   endif

#   if defined(I32_BE_MIN)
        printf("        defined:     I32_BE_MIN : %d\n", I32_BE_MIN);
#   else
        print_failed();
        return;
#   endif

#   if defined(U8_LE_MAX)
        printf("        defined:      U8_LE_MAX : %d\n", U8_LE_MAX);
#   else
        print_failed();
        return;
#   endif

#   if defined(U8_BE_MAX)
        printf("        defined:      U8_BE_MAX : %d\n", U8_BE_MAX);
#   else
        print_failed();
        return;
#   endif

#   if defined(U16_LE_MAX)
        printf("        defined:     U16_LE_MAX : %d\n", U16_LE_MAX);
#   else
        print_failed();
        return;
#   endif

#   if defined(U16_BE_MAX)
        printf("        defined:     U16_BE_MAX : %d\n", U16_BE_MAX);
#   else
        print_failed();
        return;
#   endif

#   if defined(U32_LE_MAX)
        printf("        defined:     U32_LE_MAX : %u\n", U32_LE_MAX);
#   else
        print_failed();
        return;
#   endif

#   if defined(U32_BE_MAX)
        printf("        defined:     U32_BE_MAX : %u\n", U32_BE_MAX);
#   else
        print_failed();
        return;
#   endif

#   if defined(I8_LE_MAX)
        printf("        defined:      I8_LE_MAX : %d\n", I8_LE_MAX);
#   else
        print_failed();
        return;
#   endif

#   if defined(I8_BE_MAX)
        printf("        defined:      I8_BE_MAX : %d\n", I8_BE_MAX);
#   else
        print_failed();
        return;
#   endif

#   if defined(I16_LE_MAX)
        printf("        defined:     I16_LE_MAX : %d\n", I16_LE_MAX);
#   else
        print_failed();
        return;
#   endif

#   if defined(I16_BE_MAX)
        printf("        defined:     I16_BE_MAX : %d\n", I16_BE_MAX);
#   else
        print_failed();
        return;
#   endif

#   if defined(I32_LE_MAX)
        printf("        defined:     I32_LE_MAX : %d\n", I32_LE_MAX);
#   else
        print_failed();
        return;
#   endif

#   if defined(I32_BE_MAX)
        printf("        defined:     I32_BE_MAX : %d\n", I32_BE_MAX);
#   else
        print_failed();
        return;
#   endif


#   if defined(IS_BE)
        printf("        defined: IS_BE: %d\n", IS_BE);
#   else
        print_failed();
        return;
#   endif

#   if defined(IS_LE)
        printf("        defined: IS_LE: %d\n", IS_LE);
#   else
        print_failed();
        return;
#   endif

    printf("    functions:\n");
    printf("        checking: chgend16\n");
    if (chgend16(0xFE06) != 0x06FE)
    {
        print_failed();
        return;
    }
    printf("        checking: chgend32\n");
    if (chgend32(0x78563412ul) != 0x12345678ul)
    {
        print_failed();
        return;
    }

    printf("        checking: i16_le2i16\n");
    if (i16_le2i16(0x1234) != 0x1234)
    {
        print_failed();
        return;
    }

    printf("        checking: i16_be2i16\n");
    if (i16_be2i16(0x1234) != 0x3412)
    {
        print_failed();
        return;
    }

    printf("        checking: i16_le2i16_be\n");
    if (i16_le2i16_be(0x1234) != 0x3412)
    {
        print_failed();
        return;
    }

    printf("        checking: i16_be2i16_le\n");
    if (i16_be2i16_le(0x1234) != 0x3412)
    {
        print_failed();
        return;
    }

    printf("        checking: i162i16_be\n");
    if (i162i16_be(0x1234) != 0x3412)
    {
        print_failed();
        return;
    }

    printf("        checking: i162i16_le\n");
    if (i162i16_le(0x1234) != 0x1234)
    {
        print_failed();
        return;
    }

    printf("        checking: i32_le2i32\n");
    if (i32_le2i32(0x12345678) != 0x12345678)
    {
        print_failed();
        return;
    }

    printf("        checking: i32_be2i32\n");
    if (i32_be2i32(0x12345678) != 0x78563412)
    {
        print_failed();
        return;
    }

    printf("        checking: i32_le2i32_be\n");
    if (i32_le2i32_be(0x12345678) != 0x78563412)
    {
        print_failed();
        return;
    }

    printf("        checking: i32_be2i32_le\n");
    if (i32_be2i32_le(0x12345678) != 0x78563412)
    {
        print_failed();
        return;
    }

    printf("        checking: i322i32_be\n");
    if (i322i32_be(0x12345678) != 0x78563412)
    {
        print_failed();
        return;
    }

    printf("        checking: i322i32_le\n");
    if (i322i32_le(0x12345678) != 0x12345678)
    {
        print_failed();
        return;
    }

    printf("        checking: u16_le2u16\n");
    if (u16_le2u16(0x1234u) != 0x1234u)
    {
        print_failed();
        return;
    }

    printf("        checking: u16_be2u16\n");
    if (u16_be2u16(0x1234u) != 0x3412u)
    {
        print_failed();
        return;
    }

    printf("        checking: u16_le2u16_be\n");
    if (u16_le2u16_be(0x1234u) != 0x3412u)
    {
        print_failed();
        return;
    }

    printf("        checking: u16_be2u16_le\n");
    if (u16_be2u16_le(0x1234u) != 0x3412u)
    {
        print_failed();
        return;
    }

    printf("        checking: u162u16_be\n");
    if (u162u16_be(0x1234u) != 0x3412u)
    {
        print_failed();
        return;
    }

    printf("        checking: u162u16_le\n");
    if (u162u16_le(0x1234u) != 0x1234u)
    {
        print_failed();
        return;
    }

    printf("        checking: u32_le2u32\n");
    if (u32_le2u32(0x12345678u) != 0x12345678u)
    {
        print_failed();
        return;
    }

    printf("        checking: u32_be2u32\n");
    if (u32_be2u32(0x12345678u) != 0x78563412u)
    {
        print_failed();
        return;
    }

    printf("        checking: u32_le2u32_be\n");
    if (u32_le2u32_be(0x12345678u) != 0x78563412u)
    {
        print_failed();
        return;
    }

    printf("        checking: u32_be2u32_le\n");
    if (u32_be2u32_le(0x12345678u) != 0x78563412u)
    {
        print_failed();
        return;
    }

    printf("        checking: u322u32_be\n");
    if (u322u32_be(0x12345678u) != 0x78563412u)
    {
        print_failed();
        return;
    }

    printf("        checking: u322u32_le\n");
    if (u322u32_le(0x12345678u) != 0x12345678u)
    {
        print_failed();
        return;
    }

    print_passed();
}
