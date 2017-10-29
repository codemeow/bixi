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
#include <stdlib.h>
#include <libbixi.h>
#include "../test.h"
#include "../types/bxiarrays.h"

#define TEST_FORMAT(name, flags)                     \
{                                                    \
    bxi_raw2hex(out, raw, 16, flags);                \
    printf("            [%s]: \"%s\"\n", name, out); \
    out[0] = '\0';                                   \
}

void test_types_bxiarrays(void)
{
    u32 i;
    u8 raw[16];
    char out[128];

    print_info;

    for (i = 0; i < 16; i++)
        raw[i] = i * 16;

    printf("    functions:\n");
    printf("        checking: bxi_raw2hex\n");
    TEST_FORMAT(" C ", BXI_HEX_COMBO_C      | BXI_HEX_END_CLOSED);
    TEST_FORMAT("CSS", BXI_HEX_COMBO_CSS    | BXI_HEX_END_CLOSED);
    TEST_FORMAT("INT", BXI_HEX_COMBO_INTEL  | BXI_HEX_END_CLOSED);
    TEST_FORMAT("IP6", BXI_HEX_COMBO_IPv6   | BXI_HEX_END_CLOSED);
    TEST_FORMAT("PAS", BXI_HEX_COMBO_PASCAL | BXI_HEX_END_CLOSED);
    TEST_FORMAT("XML", BXI_HEX_COMBO_XML    | BXI_HEX_END_CLOSED);

    print_passed();
}
