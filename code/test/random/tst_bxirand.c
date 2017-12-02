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
#include "../random/tst_bxirand.h"

static void test_random_definitions(void)
{
    printf("    defines:\n");
    TEST_BXI_MACRO_U32(BXI_RAND8_MAX);
    TEST_BXI_MACRO_U32(BXI_RAND16_MAX);
    TEST_BXI_MACRO_U32(BXI_RAND32_MAX);
}

void test_random_functions(void)
{
    i8  mem_i8;
    u8  mem_u8;
    i16 mem_i16;
    u16 mem_u16;
    i32 mem_i32;
    u32 mem_u32;

    f64 sum_i8  = 0;
    f64 sum_u8  = 0;
    f64 sum_i16 = 0;
    f64 sum_u16 = 0;
    f64 sum_i32 = 0;
    f64 sum_u32 = 0;

    u32 i;

    printf("    functions:\n");

    printf("        checking: bxi_srand\n");
    bxi_srand(23);

    /* Remember first values */
    mem_i8  = bxi_randi8 ();
    mem_u8  = bxi_randu8 ();
    mem_i16 = bxi_randi16();
    mem_u16 = bxi_randu16();
    mem_i32 = bxi_randi32();
    mem_u32 = bxi_randu32();

    /* Skip elements. Make sure the
     * compiler won't remove it */
    for (i = 0; i < U16_MAX; i++)
    {
        sum_i8  += (f64)bxi_randi8 () / U16_MAX;
        sum_u8  += (f64)bxi_randu8 () / U16_MAX;
        sum_i16 += (f64)bxi_randi16() / U16_MAX;
        sum_u16 += (f64)bxi_randu16() / U16_MAX;
        sum_i32 += (f64)bxi_randi32() / U16_MAX;
        sum_u32 += (f64)bxi_randu32() / U16_MAX;
    }

    /* Now reset the sequence and check */
    bxi_srand(23);

    printf("        checking: bxi_randi8  (avg %14.2f)\n", sum_i8);
    if (mem_i8 != bxi_randi8())
        test_failed();
    printf("        checking: bxi_randu8  (avg %14.2f)\n", sum_u8);
    if (mem_u8 != bxi_randu8())
        test_failed();
    printf("        checking: bxi_randi16 (avg %14.2f)\n", sum_i16);
    if (mem_i16 != bxi_randi16())
        test_failed();
    printf("        checking: bxi_randu16 (avg %14.2f)\n", sum_u16);
    if (mem_u16 != bxi_randu16())
        test_failed();
    printf("        checking: bxi_randi32 (avg %14.2f)\n", sum_i32);
    if (mem_i32 != bxi_randi32())
        test_failed();
    printf("        checking: bxi_randu32 (avg %14.2f)\n", sum_u32);
    if (mem_u32 != bxi_randu32())
        test_failed();
}

void test_random_bxirand(void)
{
    print_info;

    test_random_definitions();
    test_random_functions();

    print_passed();
}
