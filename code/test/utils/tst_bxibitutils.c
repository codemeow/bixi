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
#include "../utils/tst_bxibitutils.h"

/* @todo good tests */

void test_utils_bxibitutils(void)
{
    print_info;

    printf("    defines:\n");
#   if defined(BXI_SWAP)
        printf("        checking: BXI_SWAP\n");
        {
            i32 a = 3;
            i32 b = 4;
            BXI_SWAP(a, b);
            if ((a != 4) || (b != 3))
                print_failed();
            BXI_SWAP(a, a);
            if ((a != 4))
                print_failed();
        }
#   else
        print_failed();
#   endif

    printf("    functions:\n");

    printf("        checking: bxi_rotl8\n");
    if (bxi_rotl8(0x4c, 5) != 0x89)
        print_failed();

    printf("        checking: bxi_rotr8\n");
    if (bxi_rotr8(0x89, 5) != 0x4c)
        print_failed();

    printf("        checking: bxi_rotl16\n");
    if (bxi_rotl16(0x1122, 4) != 0x1221)
        print_failed();

    printf("        checking: bxi_rotl16\n");
    if (bxi_rotr16(0x1221, 4) != 0x1122)
        print_failed();

    printf("        checking: bxi_rotl32\n");
    if (bxi_rotl32(0x12345678, 8) != 0x34567812)
        print_failed();

    printf("        checking: bxi_rotl32\n");
    if (bxi_rotr32(0x34567812, 8) != 0x12345678)
        print_failed();

    printf("        checking: bxi_getbit\n");
    if (bxi_getbit(0x12345678, 9) != 1)
        print_failed();

    printf("        checking: bxi_setbit\n");
    if (bxi_setbit(0x12345678, 1) != 0x1234567A)
        print_failed();

    printf("        checking: bxi_tglbit\n");
    if (bxi_tglbit(0x12345678, 9) != 0x12345478)
        print_failed();

    printf("        checking: bxi_clrbit\n");
    if (bxi_clrbit(0x12345678, 9) != 0x12345478)
        print_failed();

    printf("        checking: bxi_chgbit\n");
    if (bxi_chgbit(0x12345678, 9, 0) != 0x12345478)
        print_failed();

    printf("        checking: bxi_cntbit\n");
    if (bxi_cntbit(0x80000000u) != 1)
        print_failed();
    if (bxi_cntbit(0x89100) != 4)
        print_failed();

    print_passed();
}
