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
#include <stdlib.h>
#include <libbixi.h>
#include "../test.h"
#include "../types/tst_bxiarrays.h"

/* @todo good tests */

#define TEST_ARRAY_SIZE (8)

static void my_memerr(u32 req, const char * file, u32 line)
{
    printf("            called: [my_memerr] on %s:%u while requesting %u bytes\n",
           file, line, req);
}

static void * my_malloc(u32 size, const char * file, u32 line)
{
    UNUSED(file);
    UNUSED(line);
    return calloc(size, 1);
}

static void my_free(void * ptr, const char * file, u32 line)
{
    UNUSED(file);
    UNUSED(line);
    free(ptr);
}

static void * my_realloc(void * ptr, u32 size, const char * file, u32 line)
{
    UNUSED(file);
    UNUSED(line);
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

static void test_array_create(bxi_bts ** b1, bxi_bts ** b2)
{
    i32 i;
    printf("        checking: bxi_bts_create\n");

    *b1 = bxi_bts_create(TEST_ARRAY_SIZE);
    *b2 = bxi_bts_create(TEST_ARRAY_SIZE);

    if ((!(*b1)) || (!(*b2)))
        print_failed();
    if (((*b1)->size != TEST_ARRAY_SIZE) ||
        ((*b2)->size != TEST_ARRAY_SIZE))
        print_failed();
    if ((!(*b1)->data) || (!(*b2)->data))
        print_failed();

    for (i = 0; i < TEST_ARRAY_SIZE; i++)
    {
        (*b1)->data[i] = i * TEST_ARRAY_SIZE;
        if ((*b1)->data[i] != i * TEST_ARRAY_SIZE)
            print_failed();
        (*b2)->data[i] = i * TEST_ARRAY_SIZE;
        if ((*b2)->data[i] != i * TEST_ARRAY_SIZE)
            print_failed();
    }
}

static void test_array_append(bxi_bts * b1, bxi_bts * b2)
{
    i32 i;

    printf("        checking: bxi_bts_append\n");
    bxi_bts_append(b1, b2);
    if (b1->size != TEST_ARRAY_SIZE * 2)
        print_failed();

    for (i = TEST_ARRAY_SIZE; i < TEST_ARRAY_SIZE * 2; i++)
        if (b1->data[i] != b2->data[i - TEST_ARRAY_SIZE])
            print_failed();
}

static void test_array_walk(bxi_bts * b1)
{
    u32 i;

    printf("        checking: bxi_bts_walk\n");
    bxi_bts_walk(b1, traverser);

    for (i = 0; i < b1->size; i++)
    {
        if (i < 2)
        {
            if (b1->data[i] != 1)
                print_failed();
        }
        else
        {
            if (b1->data[i] != ((b1->data[i - 1] + b1->data[i - 2]) & 0xFF))
                print_failed();
        }
    }
}

static void test_array_search(bxi_bts * b1)
{
    UNUSED(b1);
    printf("        checking: bxi_bts_search\n");
    if (bxi_bts_search(b1, 0x77) != -1)
        print_failed();
    if (bxi_bts_search(b1, 0x05) != 4)
        print_failed();
}

static void test_array_resize(bxi_bts * b1, bxi_bts * b2)
{
    printf("        checking: bxi_bts_resize\n");
    bxi_bts_resize(b1, 2);
    bxi_bts_resize(b2, 2);

    if (b1->size != 2)
        print_failed();
    if (b2->size != 2)
        print_failed();

    if ((b1->data[0] != 1) || (b1->data[1] != 1))
        print_failed();
    if ((b2->data[0] != 0) || (b2->data[1] != 8))
        print_failed();
}

static void test_array_insert(bxi_bts * b1, bxi_bts * b2)
{
    printf("        checking: bxi_bts_insert\n");
    b1->data[0] = 0x10;
    b1->data[1] = 0x20;
    b2->data[0] = 0x01;
    b2->data[1] = 0x02;

    bxi_bts_insert(b1, b2, 2);
    bxi_bts_insert(b1, b2, 1);
    bxi_bts_insert(b1, b2, 0);

    if (b1->size != b2->size * 3 + 2)
        print_failed();
    if ((b1->data[0] != 0x01) ||
        (b1->data[1] != 0x02) ||
        (b1->data[2] != 0x10) ||
        (b1->data[3] != 0x01) ||
        (b1->data[4] != 0x02) ||
        (b1->data[5] != 0x20) ||
        (b1->data[6] != 0x01) ||
        (b1->data[7] != 0x02))
        print_failed();
}

static void test_array_delete(bxi_bts * b1)
{
    printf("        checking: bxi_bts_delete\n");

    bxi_bts_delete(b1, 6, 2);
    bxi_bts_delete(b1, 3, 2);
    bxi_bts_delete(b1, 0, 2);

    if (b1->size != 2)
        print_failed();
    if ((b1->data[0] != 0x10) ||
        (b1->data[1] != 0x20))
        print_failed();
}

static void test_array_free(bxi_bts * b1, bxi_bts * b2)
{
    printf("        checking: bxi_bts_free\n");
    bxi_bts_free(b1);
    bxi_bts_free(b2);
}

static void test_array_lshift(bxi_bts * b1)
{
    printf("        checking: bxi_bts_lshift\n");
    bxi_bts_resize(b1, 4);
    b1->data[2] = 0x66;
    b1->data[3] = 0x55;

    bxi_bts_lshift(b1, 2);
    if (b1->size != 2)
        print_failed();
    if ((b1->data[0] != 0x66) || (b1->data[1] != 0x55))
        print_failed();
}

void test_types_bxiarrays(void)
{
    bxi_bts * b1 = NULL;
    bxi_bts * b2 = NULL;

    print_info;

    bxi_malloc_set (my_malloc );
    bxi_free_set   (my_free   );
    bxi_realloc_set(my_realloc);
    bxi_memerr_set (my_memerr );

    printf("    functions:\n");

    test_array_create(&b1, &b2);
    test_array_append( b1,  b2);
    test_array_walk  ( b1     );
    test_array_search( b1     );
    test_array_resize( b1,  b2);
    test_array_insert( b1,  b2);
    test_array_delete( b1     );
    test_array_lshift( b1     );
    test_array_free  ( b1,  b2);

    print_passed();
}
