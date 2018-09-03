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
#include "../definitions/tst_bxiarch.h"

static void test_definitions_defines(void)
{
    printf("    defines:\n");
    TEST_BXI_MACRO_STRING(BXI_OS);
    TEST_BXI_MACRO_STRING(BXI_ARCH);
    TEST_BXI_MACRO_I32   (BXI_BITS);

    TEST_BXI_MACRO_EXISTS_WEAK(BXI_OS_AIX);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_OS_AND);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_OS_AMG);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_OS_BOS);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_OS_FBS);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_OS_OBS);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_OS_BSD);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_OS_DFL);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_OS_CYG);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_OS_MSD);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_OS_PAL);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_OS_UNX);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_OS_MNX);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_OS_GHR);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_OS_GLX);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_OS_MAC);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_OS_OS2);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_OS_WIN);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_OS_WCE);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_OS_ZOS);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_OS_SLR);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_OS_SOS);

    TEST_BXI_MACRO_EXISTS_WEAK(BXI_BITS_16);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_BITS_32);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_BITS_64);

    TEST_BXI_MACRO_EXISTS_WEAK(BXI_ARCH_P32);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_ARCH_P64);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_ARCH_S32);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_ARCH_S64);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_ARCH_ALP);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_ARCH_A32);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_ARCH_A64);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_ARCH_M32);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_ARCH_M64);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_ARCH_Z32);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_ARCH_Z64);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_ARCH_X32);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_ARCH_X64);
    TEST_BXI_MACRO_EXISTS_WEAK(BXI_ARCH_I64);
}

static void test_definitions_functions(void)
{
    printf("    functions:\n");
    printf("        checking: bxi_arch: %s\n", bxi_arch());
    printf("        checking: bxi_bits: %d\n", bxi_bits());
    printf("        checking: bxi_os  : %s\n", bxi_os());
}

void test_definitions_bxiarch(void)
{
    print_info;

    test_definitions_defines();
    test_definitions_functions();

    print_passed();
}
