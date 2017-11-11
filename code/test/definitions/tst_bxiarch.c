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

void test_definitions_bxiarch(void)
{
    print_info;

    printf("    defines:\n");
    printf("        defined : BXI_OS  : \"%s\"\n", BXI_OS);
    printf("        defined : BXI_BITS: %d\n",     BXI_BITS);
    printf("        defined : BXI_ARCH: \"%s\"\n", BXI_ARCH);
#   if defined(BXI_OS_AIX)
    printf("        defined : BXI_OS_AIX\n");
#   endif
#   if defined(BXI_OS_AND)
    printf("        defined : BXI_OS_AND\n");
#   endif
#   if defined(BXI_OS_AMG)
    printf("        defined : BXI_OS_AMG\n");
#   endif
#   if defined(BXI_OS_BOS)
    printf("        defined : BXI_OS_BOS\n");
#   endif
#   if defined(BXI_OS_FBS)
    printf("        defined : BXI_OS_FBS\n");
#   endif
#   if defined(BXI_OS_NBS)
    printf("        defined : BXI_OS_NBS\n");
#   endif
#   if defined(BXI_OS_OBS)
    printf("        defined : BXI_OS_OBS\n");
#   endif
#   if defined(BXI_OS_BSD)
    printf("        defined : BXI_OS_BSD\n");
#   endif
#   if defined(BXI_OS_DFL)
    printf("        defined : BXI_OS_DFL\n");
#   endif
#   if defined(BXI_OS_CYG)
    printf("        defined : BXI_OS_CYG\n");
#   endif
#   if defined(BXI_OS_MSD)
    printf("        defined : BXI_OS_MSD\n");
#   endif
#   if defined(BXI_OS_PAL)
    printf("        defined : BXI_OS_PAL\n");
#   endif
#   if defined(BXI_OS_UNX)
    printf("        defined : BXI_OS_UNX\n");
#   endif
#   if defined(BXI_OS_MNX)
    printf("        defined : BXI_OS_MNX\n");
#   endif
#   if defined(BXI_OS_GHR)
    printf("        defined : BXI_OS_GHR\n");
#   endif
#   if defined(BXI_OS_GLX)
    printf("        defined : BXI_OS_GLX\n");
#   endif
#   if defined(BXI_OS_MAC)
    printf("        defined : BXI_OS_MAC\n");
#   endif
#   if defined(BXI_OS_OS2)
    printf("        defined : BXI_OS_OS2\n");
#   endif
#   if defined(BXI_OS_WIN)
    printf("        defined : BXI_OS_WIN\n");
#   endif
#   if defined(BXI_OS_WCE)
    printf("        defined : BXI_OS_WCE\n");
#   endif
#   if defined(BXI_OS_ZOS)
    printf("        defined : BXI_OS_ZOS\n");
#   endif
#   if defined(BXI_OS_SLR)
    printf("        defined : BXI_OS_SLR\n");
#   endif
#   if defined(BXI_OS_SOS)
    printf("        defined : BXI_OS_SOS\n");
#   endif

#   if defined(BXI_BITS_16)
    printf("        defined : BXI_BITS_16\n");
#   endif
#   if defined(BXI_BITS_32)
    printf("        defined : BXI_BITS_32\n");
#   endif
#   if defined(BXI_BITS_64)
    printf("        defined : BXI_BITS_64\n");
#   endif

#   if defined(BXI_ARCH_P32)
    printf("        defined : BXI_ARCH_P32\n");
#   endif
#   if defined(BXI_ARCH_P64)
    printf("        defined : BXI_ARCH_P64\n");
#   endif
#   if defined(BXI_ARCH_S32)
    printf("        defined : BXI_ARCH_S32\n");
#   endif
#   if defined(BXI_ARCH_S64)
    printf("        defined : BXI_ARCH_S64\n");
#   endif
#   if defined(BXI_ARCH_ALP)
    printf("        defined : BXI_ARCH_ALP\n");
#   endif
#   if defined(BXI_ARCH_A32)
    printf("        defined : BXI_ARCH_A32\n");
#   endif
#   if defined(BXI_ARCH_A64)
    printf("        defined : BXI_ARCH_A64\n");
#   endif
#   if defined(BXI_ARCH_M32)
    printf("        defined : BXI_ARCH_M32\n");
#   endif
#   if defined(BXI_ARCH_M64)
    printf("        defined : BXI_ARCH_M64\n");
#   endif
#   if defined(BXI_ARCH_Z32)
    printf("        defined : BXI_ARCH_Z32\n");
#   endif
#   if defined(BXI_ARCH_Z64)
    printf("        defined : BXI_ARCH_Z64\n");
#   endif
#   if defined(BXI_ARCH_X32)
    printf("        defined : BXI_ARCH_X32\n");
#   endif
#   if defined(BXI_ARCH_X64)
    printf("        defined : BXI_ARCH_X64\n");
#   endif
#   if defined(BXI_ARCH_I64)
    printf("        defined : BXI_ARCH_I64\n");
#   endif

    printf("    functions:\n");
    printf("        checking: bxi_arch: %s\n", bxi_arch());
    printf("        checking: bxi_bits: %d\n", bxi_bits());
    printf("        checking: bxi_os  : %s\n", bxi_os());

    print_passed();
}
