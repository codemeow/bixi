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
#include "../serials/bxiserread.h"

void test_serials_bxiserread(void)
{
    u8 data[16] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                    0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7};

    print_info;

    printf("    functions:\n");

    /* bxi_read_i8 */
    printf("        checking: bxi_read_i8\n");
    if (bxi_read_i8(data + 8) != -16)
        print_failed();

    /* bxi_read_u8 */
    printf("        checking: bxi_read_u8\n");
    if (bxi_read_u8(data + 0) != 0)
        print_failed();

    /* bxi_read_i16 */
    printf("        checking: bxi_read_i16\n");
    if (bxi_read_i16(data + 8) != -3600)
        print_failed();

    /* bxi_read_u16 */
    printf("        checking: bxi_read_u16\n");
    if (bxi_read_u16(data + 0) != 256)
        print_failed();

    /* bxi_read_i32 */
    printf("        checking: bxi_read_i32\n");
    if (bxi_read_i32(data + 8) != -202182160)
        print_failed();

    /* bxi_read_u32 */
    printf("        checking: bxi_read_u32\n");
    if (bxi_read_u32(data + 8) != 4092785136)
        print_failed();

    /* bxi_read_i16_be */
    printf("        checking: bxi_read_i16_be\n");
    if (bxi_read_i16_be(data + 8) != -3855)
        print_failed();

    /* bxi_read_u16_be */
    printf("        checking: bxi_read_u16_be\n");
    if (bxi_read_u16_be(data + 8) != 61681)
        print_failed();

    /* bxi_read_i32_be */
    printf("        checking: bxi_read_i32_be\n");
    if (bxi_read_i32_be(data + 8) != -252579085)
        print_failed();

    /* bxi_read_u32_be */
    printf("        checking: bxi_read_u32_be\n");
    if (bxi_read_u32_be(data + 8) != 4042388211)
        print_failed();

    /* bxi_read_u16_le */
    printf("        checking: bxi_read_i16_le\n");
    if (bxi_read_i16_le(data + 8) != -3600)
        print_failed();

    /* bxi_read_u16_le */
    printf("        checking: bxi_read_u16_le\n");
    if (bxi_read_u16_le(data + 8) != 61936)
        print_failed();

    /* bxi_read_i32_le */
    printf("        checking: bxi_read_i32_le\n");
    if (bxi_read_i32_le(data + 8) != -202182160)
        print_failed();

    /* bxi_read_u32_le */
    printf("        checking: bxi_read_u32_le\n");
    if (bxi_read_u32_le(data + 8) != 4092785136)
        print_failed();

    print_passed();
}
