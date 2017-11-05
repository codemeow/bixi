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
#define _GNU_SOURCE 1
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libbixi.h>
#include "../test.h"
#include "../utils/bximemutils.h"

/* Not sure how to do it better */
#if defined(BXI_OS_MNX)
#define memfrob(s, n) bxi_memfrob(s, 42, n)
#endif

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

#define TEST_SPEED_INIT                \
    struct timespec time_s = { 0, 0 }; \
    struct timespec time_f = { 0, 0 }; \
    u32 time_n_s = 0;                  \
    u32 time_n_f = 0;                  \
    u32 sum_org = 0;                   \
    u32 sum_new = 0
#define TEST_SPEED_START               \
    clock_gettime(CLOCK_MONOTONIC, &time_s)
#define TEST_SPEED_STOP                \
    clock_gettime(CLOCK_MONOTONIC, &time_f); \
    time_n_s = time_s.tv_nsec + time_s.tv_sec * 1e9; \
    time_n_f = time_f.tv_nsec + time_f.tv_sec * 1e9
#define TEST_SPEED_SAY(name)           \
    printf("            speedtest: %-12s: %8.5f\n", \
        name, (time_n_f - time_n_s) / (f64)1e9)
#define TEST_SPEED_CHECK    \
    if (sum_org != sum_new) \
        print_failed()
#define TEST_SPEED_LOOPS (100000)
#define TEST_SPEED_SIZE  (5000)

static void check_memset_speed(void)
{
    TEST_SPEED_INIT;

    u8  data[TEST_SPEED_SIZE];
    u32 i;

    TEST_SPEED_START;
    for (i = 0; i < TEST_SPEED_LOOPS; i++)
    {
        memset(data, i & 0xFF, TEST_SPEED_SIZE);
        sum_org += data[42];
    }
    TEST_SPEED_STOP;
    TEST_SPEED_SAY("    memcpy");

    TEST_SPEED_START;
    for (i = 0; i < TEST_SPEED_LOOPS; i++)
    {
        bxi_memset(data, i & 0xFF, TEST_SPEED_SIZE);
        sum_new += data[42];
    }
    TEST_SPEED_STOP;
    TEST_SPEED_SAY("bxi_memcpy");

    TEST_SPEED_CHECK;
}

static void check_memfrob_speed(void)
{
    TEST_SPEED_INIT;

    u8  data[TEST_SPEED_SIZE] = { 0 };
    u32 i;

    TEST_SPEED_START;
    for (i = 0; i < TEST_SPEED_LOOPS; i++)
    {
        memfrob(data, TEST_SPEED_SIZE);
        sum_org += data[42];
    }
    TEST_SPEED_STOP;
    TEST_SPEED_SAY("    memfrob");

    bxi_memset(data, 0, TEST_SPEED_SIZE);
    TEST_SPEED_START;
    for (i = 0; i < TEST_SPEED_LOOPS; i++)
    {
        bxi_memfrob(data, 42, TEST_SPEED_SIZE);
        sum_new += data[42];
    }
    TEST_SPEED_STOP;
    TEST_SPEED_SAY("bxi_memfrob");

    TEST_SPEED_CHECK;
}

static void check_memmove_speed()
{
    TEST_SPEED_INIT;

    u8 data[TEST_SPEED_SIZE];
    u32 i;

    bxi_memset(data, 0x42, TEST_SPEED_SIZE);
    TEST_SPEED_START;
    for (i = 0; i < TEST_SPEED_LOOPS; i++)
    {
        memmove(data, data + (i % TEST_SPEED_SIZE),
                TEST_SPEED_SIZE - (i % TEST_SPEED_SIZE));
        sum_org += data[42];
    }
    TEST_SPEED_STOP;
    TEST_SPEED_SAY("    memmove");

    bxi_memset(data, 0x42, TEST_SPEED_SIZE);
    TEST_SPEED_START;
    for (i = 0; i < TEST_SPEED_LOOPS; i++)
    {
        bxi_memmove(data, data + (i % TEST_SPEED_SIZE),
                    TEST_SPEED_SIZE - (i % TEST_SPEED_SIZE));
        sum_new += data[42];
    }
    TEST_SPEED_STOP;
    TEST_SPEED_SAY("bxi_memmove");

    TEST_SPEED_CHECK;
}

static void check_memmove_advance()
{
    u8 data[10] = { 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0xa0 };
    u8 eth1[10] = { 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0x70, 0x80, 0x90, 0xa0 };
    u8 eth2[10] = { 0x40, 0x50, 0x60, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0xa0 };

    bxi_memmove(data, data + 3, 6);
    if (memcmp(data, eth1, 10))
        print_failed();

    bxi_memmove(data + 3, data, 6);
    if (memcmp(data, eth2, 10))
        print_failed();
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
    check_memset_speed();

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
    check_memmove_advance();
    check_memmove_speed();

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
    check_memfrob_speed();

    printf("        checking: bxi_memchr\n");
    if (bxi_memchr(data, 0x58, 10) != data + 3)
        print_failed();

    printf("        checking: bxi_memrchr\n");
    if (bxi_memrchr(data, 0x58, 10) != data + 3)
        print_failed();

    print_passed();
}
