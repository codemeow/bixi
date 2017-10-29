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
#include "../random/bxirand.h"

void test_random_bxirand(void)
{
    i8  mem_i8;
    u8  mem_u8;
    i16 mem_i16;
    u16 mem_u16;
    i32 mem_i32;
    u32 mem_u32;

    print_info;

    printf("    defines:\n");

    /* BXI_RAND8_MAX */
#   if defined(BXI_RAND8_MAX)
        printf("        defined : BXI_RAND8_MAX  (%u)\n", BXI_RAND8_MAX);
#   else
        print_failed();
        return;
#   endif

    /* BXI_RAND16_MAX */
#   if defined(BXI_RAND8_MAX)
        printf("        defined : BXI_RAND16_MAX (%u)\n", BXI_RAND16_MAX);
#   else
        print_failed();
        return;
#   endif

    /* BXI_RAND8_MAX */
#   if defined(BXI_RAND32_MAX)
        printf("        defined : BXI_RAND32_MAX (%u)\n", BXI_RAND32_MAX);
#   else
        print_failed();
        return;
#   endif

    /* bxi_srand   */
    /* bxi_randi8  */
    /* bxi_randu8  */
    /* bxi_randi16 */
    /* bxi_randu16 */
    /* bxi_randi32 */
    /* bxi_randu32 */
    printf("    functions:\n");

    bxi_srand(23);
    mem_i8  = bxi_randi8 ();
    mem_u8  = bxi_randu8 ();
    mem_i16 = bxi_randi16();
    mem_u16 = bxi_randu16();
    mem_i32 = bxi_randi32();
    mem_u32 = bxi_randu32();

    bxi_srand(42);
    printf("        checking: bxi_randi8\n");
    if (mem_i8 == bxi_randi8())
    {
        print_failed();
        return;
    }
    printf("        checking: bxi_randu8\n");
    if (mem_u8 == bxi_randu8())
    {
        print_failed();
        return;
    }
    printf("        checking: bxi_randi16\n");
    if (mem_i16 == bxi_randi16())
    {
        print_failed();
        return;
    }
    printf("        checking: bxi_randu16\n");
    if (mem_u16 == bxi_randu16())
    {
        print_failed();
        return;
    }
    printf("        checking: bxi_randi32\n");
    if (mem_i32 == bxi_randi32())
    {
        print_failed();
        return;
    }
    printf("        checking: bxi_randu32\n");
    if (mem_u32 == bxi_randu32())
    {
        print_failed();
        return;
    }

    printf("        checking: bxi_srand\n");
    bxi_srand(23);
    if ((mem_i8  != bxi_randi8 ()) ||
        (mem_u8  != bxi_randu8 ()) ||
        (mem_i16 != bxi_randi16()) ||
        (mem_u16 != bxi_randu16()) ||
        (mem_i32 != bxi_randi32()) ||
        (mem_u32 != bxi_randu32()))
    {
        print_failed();
        return;
    }

    print_passed();
}
