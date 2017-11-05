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
#include "../utils/bxibitutils.h"

void test_utils_bxibitutils(void)
{
    print_info;

    printf("    functions:\n");

    printf("        checking: rotl8\n");
    if (rotl8(0x4c, 5) != 0x89)
        print_failed();

    printf("        checking: rotr8\n");
    if (rotr8(0x89, 5) != 0x4c)
        print_failed();

    printf("        checking: rotl16\n");
    if (rotl16(0x1122, 4) != 0x1221)
        print_failed();

    printf("        checking: rotl16\n");
    if (rotr16(0x1221, 4) != 0x1122)
        print_failed();

    printf("        checking: rotl32\n");
    if (rotl32(0x12345678, 8) != 0x34567812)
        print_failed();

    printf("        checking: rotl32\n");
    if (rotr32(0x34567812, 8) != 0x12345678)
        print_failed();

    printf("        checking: getbit\n");
    if (getbit(0x12345678, 9) != 1)
        print_failed();

    printf("        checking: setbit\n");
    if (setbit(0x12345678, 1) != 0x1234567A)
        print_failed();

    printf("        checking: tglbit\n");
    if (tglbit(0x12345678, 9) != 0x12345478)
        print_failed();

    printf("        checking: clrbit\n");
    if (clrbit(0x12345678, 9) != 0x12345478)
        print_failed();

    printf("        checking: chgbit\n");
    if (chgbit(0x12345678, 9, 0) != 0x12345478)
        print_failed();

    print_passed();
}
