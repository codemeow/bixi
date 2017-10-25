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
#include "../serials/bxiserwrite.h"

void test_serials_bxiserwrite(void)
{
    u8 data[4] = { 0xf0, 0xf1, 0xf2, 0xf3 };
    u8 test[4];

    print_info;

    printf("    functions:\n");

    /* bxi_write_i8 */
    printf("        checking: bxi_write_i8\n");
    bxi_write_i8(-16, test);
    if (bxi_memcmp(data, test, sizeof(i8)))
    {
        print_failed();
        return;
    }

    /* bxi_write_u8 */
    printf("        checking: bxi_write_u8\n");
    bxi_write_u8(0xf0u, test);
    if (bxi_memcmp(data, test, sizeof(u8)))
    {
        print_failed();
        return;
    }

    /* bxi_write_i16 */
    printf("        checking: bxi_write_i16\n");
    bxi_write_i16(-3600, test);
    if (bxi_memcmp(data, test, sizeof(i16)))
    {
        print_failed();
        return;
    }

    /* bxi_write_u16 */
    printf("        checking: bxi_write_u16\n");
    bxi_write_u16(61936, test);
    if (bxi_memcmp(data, test, sizeof(u16)))
    {
        print_failed();
        return;
    }

    /* bxi_write_i32 */
    printf("        checking: bxi_write_i32\n");
    bxi_write_i32(-202182160, test);
    if (bxi_memcmp(data, test, sizeof(i32)))
    {
        print_failed();
        return;
    }

    /* bxi_write_u32 */
    printf("        checking: bxi_write_u32\n");
    bxi_write_u32(0xf3f2f1f0u, test);
    if (bxi_memcmp(data, test, sizeof(u32)))
    {
        print_failed();
        return;
    }

    /* bxi_write_i16_be */
    printf("        checking: bxi_write_i16_be\n");
    bxi_write_i16_be(-3855, test);
    if (bxi_memcmp(data, test, sizeof(i16_be)))
    {
        print_failed();
        return;
    }

    /* bxi_write_u16_be */
    printf("        checking: bxi_write_u16_be\n");
    bxi_write_u16_be(0xf0f1u, test);
    if (bxi_memcmp(data, test, sizeof(u16_be)))
    {
        print_failed();
        return;
    }

    /* bxi_write_i32_be */
    printf("        checking: bxi_write_i32_be\n");
    bxi_write_i32_be(-252579085, test);
    if (bxi_memcmp(data, test, sizeof(i32_be)))
    {
        print_failed();
        return;
    }

    /* bxi_write_u32_be */
    printf("        checking: bxi_write_u32_be\n");
    bxi_write_u32_be(0xf0f1f2f3u, test);
    if (bxi_memcmp(data, test, sizeof(u32_be)))
    {
        print_failed();
        return;
    }

    /* bxi_write_i16 */
    printf("        checking: bxi_write_i16_le\n");
    bxi_write_i16_le(-3600, test);
    if (bxi_memcmp(data, test, sizeof(i16_le)))
    {
        print_failed();
        return;
    }

    /* bxi_write_u16_le */
    printf("        checking: bxi_write_u16_le\n");
    bxi_write_u16_le(61936, test);
    if (bxi_memcmp(data, test, sizeof(u16_le)))
    {
        print_failed();
        return;
    }

    /* bxi_write_i32_le */
    printf("        checking: bxi_write_i32_le\n");
    bxi_write_i32_le(-202182160, test);
    if (bxi_memcmp(data, test, sizeof(i32_le)))
    {
        print_failed();
        return;
    }

    /* bxi_write_u32_le */
    printf("        checking: bxi_write_u32_le\n");
    bxi_write_u32_le(0xf3f2f1f0u, test);
    if (bxi_memcmp(data, test, sizeof(u32_le)))
    {
        print_failed();
        return;
    }

    print_passed();
}
