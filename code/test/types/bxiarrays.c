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

#define TEST_ARRAY_SIZE (8)

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

static void traverser(bxi_bts * bts, u32 pos, u8 * val)
{
    if (pos < 2)
    {
        *val = 1;
        return;
    }
    *val = bts->data[pos - 2] + bts->data[pos - 1];
}

void test_types_bxiarrays(void)
{
    /* @todo do good tests */

    i32       i;
    bxi_bts * b1 = NULL;
    bxi_bts * b2 = NULL;
    char      buffer[TEST_ARRAY_SIZE * 32];

    print_info;

    printf("    settings:\n");
    printf("        function: bxi_malloc_set\n");
    bxi_malloc_set(my_malloc);
    printf("        function: bxi_free_set\n");
    bxi_free_set(my_free);
    printf("        function: bxi_realloc_set\n");
    bxi_realloc_set(my_realloc);
    printf("        function: bxi_memerr_set\n");
    bxi_memerr_set(my_memerr);

    printf("    functions:\n");
    printf("        checking: bxi_bts_create:");
    b1 = bxi_bts_create(TEST_ARRAY_SIZE);
    if (!b1 || !(b1->data) || !(b1->size == TEST_ARRAY_SIZE))
        print_failed();

    for (i = 0; i < TEST_ARRAY_SIZE; i++)
        b1->data[i] = i * TEST_ARRAY_SIZE;
    bxi_raw2hex(buffer, b1->data, b1->size, BXI_HEX_COMBO_C | BXI_HEX_END_CLOSED);
    printf("(b1)[%s]\n", buffer);
    b2 = bxi_bts_create(TEST_ARRAY_SIZE);
    if (!b2 || !(b2->data) || !(b2->size == TEST_ARRAY_SIZE))
        print_failed();

    for (i = 0; i < TEST_ARRAY_SIZE; i++)
        b2->data[i] = i << 4 | i;
    bxi_raw2hex(buffer, b2->data, b2->size, BXI_HEX_COMBO_C | BXI_HEX_END_CLOSED);
    printf("                                 (b2)[%s]\n", buffer);

    printf("        checking: bxi_bts_append:");
    bxi_bts_append(b1, b2);
    bxi_raw2hex(buffer, b1->data, b1->size, BXI_HEX_COMBO_C | BXI_HEX_END_CLOSED);
    printf("(b1)[%s]\n", buffer);

    printf("        checking: bxi_bts_walk  :");
    bxi_bts_walk(b1, traverser);
    bxi_raw2hex(buffer, b1->data, b1->size, BXI_HEX_COMBO_C | BXI_HEX_END_CLOSED);
    printf("(b1)[%s]\n", buffer);

    printf("        checking: bxi_bts_search: ");
    printf("0x%02x at %d\n", 0x77, bxi_bts_search(b1, 0x77));
    printf("                                  0x%02x at %d\n",
           0x05, bxi_bts_search(b1, 0x05));

    printf("        checking: bxi_bts_insert:");
    bxi_bts_resize(b1, 5);
    bxi_bts_resize(b2, 5);
    for (i = 0; i < 5; i++)
    {
        b1->data[i] = (i + 1) << 4;
        b2->data[i] = (i + 1);
    }
    bxi_bts_insert(b1, b2, 2);
    bxi_bts_insert(b1, b2, 12);
    bxi_raw2hex(buffer, b1->data, b1->size, BXI_HEX_COMBO_C | BXI_HEX_END_CLOSED);
    printf("(b1)[%s]\n", buffer);

    printf("        checking: bxi_bts_delete:");
    bxi_bts_delete(b1, 2, 2);
    bxi_raw2hex(buffer, b1->data, b1->size, BXI_HEX_COMBO_C | BXI_HEX_END_CLOSED);
    printf("(b1)[%s]\n", buffer);
    bxi_bts_delete(b1, 5, 11);
    bxi_raw2hex(buffer, b1->data, b1->size, BXI_HEX_COMBO_C | BXI_HEX_END_CLOSED);
    printf("                                 (b1)[%s]\n", buffer);

    printf("        checking: bxi_bts_resize:");
    bxi_bts_resize(b1, 0);
    bxi_raw2hex(buffer, b1->data, b1->size, BXI_HEX_COMBO_C | BXI_HEX_END_CLOSED);
    printf("(b1)[%s]\n", buffer);
    bxi_memopt_set(BXI_MEM_NONE);
    bxi_bts_resize(b1, TEST_ARRAY_SIZE);
    bxi_raw2hex(buffer, b1->data, b1->size, BXI_HEX_COMBO_C | BXI_HEX_END_CLOSED);
    printf("                                 (b1)[%s]\n", buffer);
    bxi_bts_resize(b1, 0);
    bxi_raw2hex(buffer, b1->data, b1->size, BXI_HEX_COMBO_C | BXI_HEX_END_CLOSED);
    printf("                                 (b1)[%s]\n", buffer);
    bxi_memopt_set(BXI_MEM_ZERO);
    bxi_bts_resize(b1, TEST_ARRAY_SIZE);
    bxi_raw2hex(buffer, b1->data, b1->size, BXI_HEX_COMBO_C | BXI_HEX_END_CLOSED);
    printf("                                 (b1)[%s]\n", buffer);

    printf("        checking: bxi_bts_free  :");
    bxi_bts_free(b1);
    bxi_raw2hex(buffer, b1->data, b1->size, BXI_HEX_COMBO_C | BXI_HEX_END_CLOSED);
    printf("(b1)[%s]\n", buffer);
    bxi_bts_free(b2);
    bxi_raw2hex(buffer, b2->data, b2->size, BXI_HEX_COMBO_C | BXI_HEX_END_CLOSED);
    printf("                                 (b2)[%s]\n", buffer);

    print_passed();
}
