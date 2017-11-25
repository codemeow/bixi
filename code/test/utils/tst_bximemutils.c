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
#include <math.h>
#include "../test.h"
#include "../utils/tst_bximemutils.h"

/* @todo good tests */

#define TEST_SPEED_LOOPS (1000000)
#define TEST_SPEED_SIZE  (5000)

#define TEST_ADVANCE_MEM16_SIZE (50)
#define TEST_ADVANCE_MEM32_SIZE (50)

/* Not sure how to do it better */
#if defined(BXI_OS_MNX) || defined(BXI_OS_FBS)
#define memfrob(s, n) bxi_memfrob(s, 42, n)
#endif

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

static void check_memset_speed(void)
{
    TEST_SPEED_INIT;

    u8  data[TEST_SPEED_SIZE];
    u32 i;

    TEST_SPEED_START;
    for (i = 0; i < TEST_SPEED_LOOPS; i++)
    {
        memset(data, 0xFF, TEST_SPEED_SIZE);
        sum_org += data[42];
    }
    TEST_SPEED_STOP;
    TEST_SPEED_SAY("    memset");

    TEST_SPEED_START;
    for (i = 0; i < TEST_SPEED_LOOPS; i++)
    {
        bxi_memset(data, 0xFF, TEST_SPEED_SIZE);
        sum_new += data[42];
    }
    TEST_SPEED_STOP;
    TEST_SPEED_SAY("bxi_memset");

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

static void check_memcmp_advance()
{
    u8 data[10] = { 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0xa0 };
    u8 eth1[10] = { 0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90 };
    u8 eth2[10] = { 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0xa0 };

    if (bxi_memcmp(data, eth2, 10))
        print_failed();
    if (!bxi_memcmp(data, eth1, 10))
        print_failed();
    if (bxi_memcmp(data, eth1 + 1, 9))
        print_failed();
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

static void check_memcpy_speed()
{
    TEST_SPEED_INIT;

    u8 data[TEST_SPEED_SIZE];
    u8 src [TEST_SPEED_SIZE];
    u32 i;

    bxi_memset(data, 0x42, TEST_SPEED_SIZE);
    bxi_memset(src, 0x12, TEST_SPEED_SIZE);
    TEST_SPEED_START;
    for (i = 0; i < TEST_SPEED_LOOPS; i++)
    {
        memcpy(data, src + (i % TEST_SPEED_SIZE),
                TEST_SPEED_SIZE - (i % TEST_SPEED_SIZE));
        sum_org += data[42];
    }
    TEST_SPEED_STOP;
    TEST_SPEED_SAY("    memcpy");

    bxi_memset(data, 0x42, TEST_SPEED_SIZE);
    TEST_SPEED_START;
    for (i = 0; i < TEST_SPEED_LOOPS; i++)
    {
        bxi_memcpy(data, src + (i % TEST_SPEED_SIZE),
                TEST_SPEED_SIZE - (i % TEST_SPEED_SIZE));
        sum_new += data[42];
    }
    TEST_SPEED_STOP;
    TEST_SPEED_SAY("bxi_memcpy");

    TEST_SPEED_CHECK;
}

static void check_memcmp_speed()
{
    TEST_SPEED_INIT;

    u8 data[TEST_SPEED_SIZE*100];
    u8 src [TEST_SPEED_SIZE*100];
    u32 i;

    bxi_memset(data, 0x42, TEST_SPEED_SIZE*10);
    bxi_memset(src, 0x42, TEST_SPEED_SIZE*10);
    TEST_SPEED_START;
    for (i = 0; i < TEST_SPEED_LOOPS; i++)
    {
        if (memcmp(data, src,TEST_SPEED_SIZE*10 - (i % (TEST_SPEED_SIZE*10))))
            sum_org++;
    }
    TEST_SPEED_STOP;
    TEST_SPEED_SAY("    memcmp");

    TEST_SPEED_START;
    for (i = 0; i < TEST_SPEED_LOOPS; i++)
    {
        if (bxi_memcmp(data, src,(TEST_SPEED_SIZE*10) - (i % (TEST_SPEED_SIZE*10))))
            sum_new++;
    }
    TEST_SPEED_STOP;
    TEST_SPEED_SAY("bxi_memcmp");

    TEST_SPEED_CHECK;
}

static void check_memcpy_advance()
{
    u8 data[10] = { 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0xa0 };
    u8 src1[10] = { 0xa0, 0x90, 0x80, 0x70, 0x60, 0x50, 0x40, 0x30, 0x20, 0x10 };
    u8 src2[10] = { 0x0f, 0x0e, 0x0d, 0x0e, 0x0d, 0x0c, 0x0b, 0x0a, 0x09, 0x08 };
    u8 eth1[10] = { 0x10, 0x20, 0x30, 0x80, 0x70, 0x60, 0x50, 0x40, 0x30, 0x20 };
    u8 eth2[10] = { 0x0e, 0x0d, 0x0e, 0x0d, 0x0c, 0x60, 0x50, 0x40, 0x30, 0x20 };

    bxi_memcpy(data + 3, src1 + 2, 7);
    if (memcmp(data, eth1, 10))
        print_failed();

    bxi_memcpy(data, src2 + 1, 5);
    if (memcmp(data, eth2, 10))
        print_failed();
}

static void * system_memset16(void * ptr, i32 val, u32 cnt)
{
    u32 bs   = 1;

    if (!cnt)
       return ptr;

    memcpy(ptr, &val, 2);

    while (cnt > (bs << 1))
    {
        memcpy((u8 *)ptr + (bs << 1), ptr, (bs << 1));
        bs   <<= 1;
    }

    cnt -= bs;

    while (cnt)
    {
        memcpy((u8 *)ptr + (bs << 1) + ((cnt - 1) << 1), ptr, 2);
        cnt--;
    }

    return ptr;
}


static void * system_memset32(void * ptr, i32 val, u32 cnt)
{
    u32 bs = 1;

    if (!cnt)
       return ptr;

    memcpy(ptr, &val, 4);

    while (cnt > (bs << 1))
    {
        memcpy((u8 *)ptr + (bs << 2), ptr, (bs << 2));
        bs   <<= 1;
    }

    cnt -= bs;

    while (cnt)
    {
        memcpy((u8 *)ptr + (bs << 2) + ((cnt - 1) << 2), ptr, 4);
        cnt--;
    }

    return ptr;
}

static void check_memset16_speed()
{
    TEST_SPEED_INIT;

    u8 data[TEST_SPEED_SIZE];
    u32 i;

    bxi_memset(data, 0x42, TEST_SPEED_SIZE);
    TEST_SPEED_START;
    for (i = 0; i < TEST_SPEED_LOOPS; i++)
    {
        system_memset16(data, i,
                   (TEST_SPEED_SIZE - (i % TEST_SPEED_SIZE)) / 2);
        sum_org += data[42];
    }
    TEST_SPEED_STOP;
    TEST_SPEED_SAY("    memset16");

    bxi_memset(data, 0x42, TEST_SPEED_SIZE);
    TEST_SPEED_START;
    for (i = 0; i < TEST_SPEED_LOOPS; i++)
    {
        bxi_memset16(data, i,
                   (TEST_SPEED_SIZE - (i % TEST_SPEED_SIZE)) / 2);
        sum_new += data[42];
    }
    TEST_SPEED_STOP;
    TEST_SPEED_SAY("bxi_memset16");

    TEST_SPEED_CHECK;
}

static void check_memset16_advance()
{
    u32 i;
    u8 data[TEST_ADVANCE_MEM16_SIZE] = { 0 };
    bxi_memset16(data + 1, 0x1020, TEST_ADVANCE_MEM16_SIZE / 2 - 1);

    for (i = 1; i < TEST_ADVANCE_MEM16_SIZE - 1; i++)
        if (data[i] != ((i % 2) ? 0x20 : 0x10))
            print_failed();
    if ((data[0] != 0) || (data[TEST_ADVANCE_MEM16_SIZE - 1] != 0))
            print_failed();
}

static void check_memset32_speed()
{
    TEST_SPEED_INIT;

    u8 data[TEST_SPEED_SIZE];
    u32 i;

    bxi_memset(data, 0x42, TEST_SPEED_SIZE);
    TEST_SPEED_START;
    for (i = 0; i < TEST_SPEED_LOOPS; i++)
    {
        system_memset32(data, i,
                   (TEST_SPEED_SIZE - (i % TEST_SPEED_SIZE)) / 4);
        sum_org += data[42];
    }
    TEST_SPEED_STOP;
    TEST_SPEED_SAY("    memset32");

    bxi_memset(data, 0x42, TEST_SPEED_SIZE);
    TEST_SPEED_START;
    for (i = 0; i < TEST_SPEED_LOOPS; i++)
    {
        bxi_memset32(data, i,
                   (TEST_SPEED_SIZE - (i % TEST_SPEED_SIZE)) / 4);
        sum_new += data[42];
    }
    TEST_SPEED_STOP;
    TEST_SPEED_SAY("bxi_memset32");

    TEST_SPEED_CHECK;
}

static void check_memset32_advance()
{
    u32 i;
    u8 data[TEST_ADVANCE_MEM32_SIZE] = { 0 };
    bxi_memset32(data + 1, 0x10203040, TEST_ADVANCE_MEM32_SIZE / 4);

    for (i = 1; i < TEST_ADVANCE_MEM32_SIZE - 1; i++)
        if (data[i] != (i % 4 == 1 ? 0x40 :
                        i % 4 == 2 ? 0x30 :
                        i % 4 == 3 ? 0x20 :
                                     0x10))
            print_failed();
    if ((data[0] != 0) || (data[TEST_ADVANCE_MEM32_SIZE - 1] != 0))
            print_failed();
}

void test_utils_bximemutils(void)
{
    u8   test[10] = { 0x12, 0x13, 0x14, 0x15, 0x16,
                      0x17, 0x18, 0x19, 0x1a, 0x1b };
    u8 * data;
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
    check_memcpy_advance();
    check_memcpy_speed();

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
    check_memcmp_advance();
    check_memcmp_speed();

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

    printf("        checking: bxi_memset16\n");
    check_memset16_advance();
    check_memset16_speed();

    printf("        checking: bxi_memset32\n");
    check_memset32_advance();
    check_memset32_speed();

    print_passed();
}
