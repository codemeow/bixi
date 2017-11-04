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
#include "../utils/bximemutils.h"

static void my_memerr(u32 req, const char * file, u32 line)
{
    printf("            called: [my_memerr] on %s:%u while requesting %u bytes\n",
           file, line, req);
}

static void * my_malloc(u32 size)
{
    return calloc(size, 1);
}

static void my_free(void * ptr)
{
    free(ptr);
}

static void * my_realloc(void * ptr, u32 size)
{
    return realloc(ptr, size);
}

void test_utils_bximemutils(void)
{
    u8   test[10] = { 0x12, 0x13, 0x14, 0x15, 0x16,
                      0x17, 0x18, 0x19, 0x1a, 0x1b };
    u8 * data = NULL;
    u32  i;

    print_info;

    printf("    defines:\n");
#   if defined(BXI_MEM_NONE)
        printf("        defined: BX_MEM_NONE: 0x%06x\n", BXI_MEM_NONE);
#   else
        print_failed();
#   endif

#   if defined(BXI_MEM_ZERO)
        printf("        defined: BX_MEM_ZERO: 0x%06x\n", BXI_MEM_ZERO);
#   else
        print_failed();
#   endif

    printf("    functions:\n");
    printf("        checking: bxi_memopt_set\n");
    bxi_memopt_set(BXI_MEM_ZERO);

    printf("        checking: bxi_memerr_set\n");
    bxi_memerr_set(my_memerr);

    printf("        checking: bxi_malloc_set\n");
    bxi_malloc_set(my_malloc);

    printf("        checking: bxi_malloc\n");
#   if defined(bxi_malloc)
        data = bxi_malloc(10);
        if (!data)
            print_failed();
        else
        {
            data[0] = 0x12;
            if (data[0] != 0x12)
                print_failed();
        }
#   else
        print_failed();
#   endif

    printf("        checking: bxi_realloc_set\n");
    bxi_realloc_set(my_realloc);

    printf("        checking: bxi_realloc\n");
#   if defined(bxi_realloc)
        data = bxi_realloc(data, 15);
        if (!data)
            print_failed();
        else
        {
            if (data[0] != 0x12)
                print_failed();
        }
#   else
        print_failed();
#   endif

    printf("        checking: bxi_free_set\n");
    bxi_free_set(my_free);

    printf("        checking: bxi_free\n");
#   if defined(bxi_free)
        bxi_free(data);
#   else
        print_failed();
#   endif

    printf("        checking: bxi_memset\n");
    data = bxi_malloc(10);
    bxi_memset(data, 0x12, 10);
    for (i = 0; i < 10; i++)
    {
        if (data[i] != 0x12)
            print_failed();
    }

    printf("        checking: bxi_memcpy\n");
    bxi_memcpy(data, test, 10);
    for (i = 0; i < 10; i++)
    {
        if (data[i] != test[i])
            print_failed();
    }

    printf("        checking: bxi_memmove\n");
    bxi_memmove(data, data + 5, 5);
    for (i = 0; i < 5; i++)
    {
        if (data[i] != test[i + 5])
            print_failed();
    }

    printf("        checking: bxi_memcmp\n");
    if (bxi_memcmp(data, test+5, 5))
        print_failed();

    printf("        checking: bxi_memfrob\n");
    bxi_memfrob(data, 0x42, 5);
    if ((data[0] != 0x55) ||
        (data[1] != 0x5a) ||
        (data[2] != 0x5b) ||
        (data[3] != 0x58) ||
        (data[4] != 0x59))
        print_failed();

    printf("        checking: bxi_memchr\n");
    if (bxi_memchr(data, 0x58, 10) != data + 3)
        print_failed();

    printf("        checking: bxi_memrchr\n");
    if (bxi_memrchr(data, 0x58, 10) != data + 3)
        print_failed();

    print_passed();
}
