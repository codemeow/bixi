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

static u8 * data = NULL;
static u8   test[10] = { 0x12, 0x13, 0x14, 0x15, 0x16,
                         0x17, 0x18, 0x19, 0x1a, 0x1b };

#define TEST_SPEED_LOOPS (1000000)
#define TEST_SPEED_SIZE  (5000)

#define TEST_ADVANCE_MEM16_SIZE (50)
#define TEST_ADVANCE_MEM32_SIZE (50)

/* As Minix & FreeBSD doesn't have memfrob
   We need to workaround it              */
#if defined(BXI_OS_MNX) || defined(BXI_OS_FBS)
void * memfrob(void * s, size_t n)
{
    u8 * p8 = s;
    while (n)
        p8[n--] ^= 42;
    return s;
}
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
    u8  data[TEST_SPEED_SIZE];
    u32 i;
    double sum_org = 0;
    double sum_new = 0;

    test_time_start();
    {
        for (i = 0; i < TEST_SPEED_LOOPS; i++)
        {
            memset(data, 0xFF, TEST_SPEED_SIZE);
            sum_org += data[42];
        }
    }
    test_time_finish();
    test_time_print("memset");

    test_time_start();
    {
        for (i = 0; i < TEST_SPEED_LOOPS; i++)
        {
            bxi_memset(data, 0xFF, TEST_SPEED_SIZE);
            sum_new += data[42];
        }
    }
    test_time_finish();
    test_time_print("bxi_memset");

    if (sum_org != sum_new)
        test_failed();
}

static void check_memfrob_speed(void)
{
    u8  data[TEST_SPEED_SIZE] = { 0 };
    u32 i;
    double sum_org = 0;
    double sum_new = 0;

    test_time_start();
    {
        for (i = 0; i < TEST_SPEED_LOOPS; i++)
        {
            memfrob(data, TEST_SPEED_SIZE);
            sum_org += data[42];
        }
    }
    test_time_finish();
    test_time_print("memfrob");

    bxi_memset(data, 0, TEST_SPEED_SIZE);
    test_time_start();
    {
        for (i = 0; i < TEST_SPEED_LOOPS; i++)
        {
            bxi_memfrob(data, 42, TEST_SPEED_SIZE);
            sum_new += data[42];
        }
    }
    test_time_finish();
    test_time_print("bxi_memfrob");

    if (sum_org != sum_new)
        test_failed();
}

static void check_memmove_speed()
{
    u8 data[TEST_SPEED_SIZE];
    u32 i;
    double sum_org = 0;
    double sum_new = 0;

    bxi_memset(data, 0x42, TEST_SPEED_SIZE);
    test_time_start();
    {
        for (i = 0; i < TEST_SPEED_LOOPS; i++)
        {
            memmove(data, data + (i % TEST_SPEED_SIZE),
                    TEST_SPEED_SIZE - (i % TEST_SPEED_SIZE));
            sum_org += data[42];
        }
    }
    test_time_finish();
    test_time_print("memmove");

    bxi_memset(data, 0x42, TEST_SPEED_SIZE);
    test_time_start();
    {
        for (i = 0; i < TEST_SPEED_LOOPS; i++)
        {
            bxi_memmove(data, data + (i % TEST_SPEED_SIZE),
                        TEST_SPEED_SIZE - (i % TEST_SPEED_SIZE));
            sum_new += data[42];
        }
    }
    test_time_finish();
    test_time_print("bxi_memmove");

    if (sum_org != sum_new)
        test_failed();
}

static void check_memcmp_advance()
{
    u8 data[10] = { 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0xa0 };
    u8 eth1[10] = { 0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90 };
    u8 eth2[10] = { 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0xa0 };

    if (bxi_memcmp(data, eth2, 10))
        test_failed();
    if (!bxi_memcmp(data, eth1, 10))
        test_failed();
    if (bxi_memcmp(data, eth1 + 1, 9))
        test_failed();
}

static void check_memmove_advance()
{
    u8 data[10] = { 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0xa0 };
    u8 eth1[10] = { 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0x70, 0x80, 0x90, 0xa0 };
    u8 eth2[10] = { 0x40, 0x50, 0x60, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0xa0 };

    bxi_memmove(data, data + 3, 6);
    if (memcmp(data, eth1, 10))
        test_failed();

    bxi_memmove(data + 3, data, 6);
    if (memcmp(data, eth2, 10))
        test_failed();
}

static void check_memcpy_speed()
{
    u8 data[TEST_SPEED_SIZE];
    u8 src [TEST_SPEED_SIZE];
    u32 i;
    double sum_org = 0;
    double sum_new = 0;

    bxi_memset(data, 0x42, TEST_SPEED_SIZE);
    bxi_memset(src, 0x12, TEST_SPEED_SIZE);
    test_time_start();
    {
        for (i = 0; i < TEST_SPEED_LOOPS; i++)
        {
            memcpy(data, src + (i % TEST_SPEED_SIZE),
                   TEST_SPEED_SIZE - (i % TEST_SPEED_SIZE));
            sum_org += data[42];
        }
    }
    test_time_finish();
    test_time_print("memcpy");

    bxi_memset(data, 0x42, TEST_SPEED_SIZE);
    test_time_start();
    {
        for (i = 0; i < TEST_SPEED_LOOPS; i++)
        {
            bxi_memcpy(data, src + (i % TEST_SPEED_SIZE),
                       TEST_SPEED_SIZE - (i % TEST_SPEED_SIZE));
            sum_new += data[42];
        }
    }
    test_time_finish();
    test_time_print("bxi_memcpy");

    if (sum_org != sum_new)
        test_failed();
}

static void check_memcmp_speed()
{
    u8 data[TEST_SPEED_SIZE*100];
    u8 src [TEST_SPEED_SIZE*100];
    u32 i;
    double sum_org = 0;
    double sum_new = 0;

    bxi_memset(data, 0x42, TEST_SPEED_SIZE*10);
    bxi_memset(src, 0x42, TEST_SPEED_SIZE*10);
    test_time_start();
    {
        for (i = 0; i < TEST_SPEED_LOOPS; i++)
        {
            if (memcmp(data, src,TEST_SPEED_SIZE*10 - (i % (TEST_SPEED_SIZE*10))))
                sum_org++;
        }
    }
    test_time_finish();
    test_time_print("memcmp");

    test_time_start();
    {
        for (i = 0; i < TEST_SPEED_LOOPS; i++)
        {
            if (bxi_memcmp(data, src,(TEST_SPEED_SIZE*10) - (i % (TEST_SPEED_SIZE*10))))
                sum_new++;
        }
    }
    test_time_finish();
    test_time_print("bxi_memcmp");

    if (sum_org != sum_new)
        test_failed();
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
        test_failed();

    bxi_memcpy(data, src2 + 1, 5);
    if (memcmp(data, eth2, 10))
        test_failed();
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
    u8 data[TEST_SPEED_SIZE];
    u32 i;
    double sum_org = 0;
    double sum_new = 0;

    bxi_memset(data, 0x42, TEST_SPEED_SIZE);
    test_time_start();
    {
        for (i = 0; i < TEST_SPEED_LOOPS; i++)
        {
            system_memset16(data, i,
                            (TEST_SPEED_SIZE - (i % TEST_SPEED_SIZE)) / 2);
            sum_org += data[42];
        }
    }
    test_time_finish();
    test_time_print("memset16");

    bxi_memset(data, 0x42, TEST_SPEED_SIZE);
    test_time_start();
    {
        for (i = 0; i < TEST_SPEED_LOOPS; i++)
        {
            bxi_memset16(data, i,
                         (TEST_SPEED_SIZE - (i % TEST_SPEED_SIZE)) / 2);
            sum_new += data[42];
        }
    }
    test_time_finish();
    test_time_print("bxi_memset16");

    if (sum_org != sum_new)
        test_failed();
}

static void check_memset16_advance()
{
    u32 i;
    u8 data[TEST_ADVANCE_MEM16_SIZE] = { 0 };
    bxi_memset16(data + 1, 0x1020, TEST_ADVANCE_MEM16_SIZE / 2 - 1);

    for (i = 1; i < TEST_ADVANCE_MEM16_SIZE - 1; i++)
        if (data[i] != ((i % 2) ? 0x20 : 0x10))
            test_failed();
    if ((data[0] != 0) || (data[TEST_ADVANCE_MEM16_SIZE - 1] != 0))
        test_failed();
}

static void check_memset32_speed()
{
    u8 data[TEST_SPEED_SIZE];
    u32 i;
    double sum_org = 0;
    double sum_new = 0;

    bxi_memset(data, 0x42, TEST_SPEED_SIZE);
    test_time_start();
    {
        for (i = 0; i < TEST_SPEED_LOOPS; i++)
        {
            system_memset32(data, i,
                            (TEST_SPEED_SIZE - (i % TEST_SPEED_SIZE)) / 4);
            sum_org += data[42];
        }
    }
    test_time_finish();
    test_time_print("memset32");

    bxi_memset(data, 0x42, TEST_SPEED_SIZE);
    test_time_start();
    {
        for (i = 0; i < TEST_SPEED_LOOPS; i++)
        {
            bxi_memset32(data, i,
                         (TEST_SPEED_SIZE - (i % TEST_SPEED_SIZE)) / 4);
            sum_new += data[42];
        }
    }
    test_time_finish();
    test_time_print("bxi_memset32");

    if (sum_org != sum_new)
        test_failed();
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
            test_failed();
    if ((data[0] != 0) || (data[TEST_ADVANCE_MEM32_SIZE - 1] != 0))
        test_failed();
}

static void test_utils_defines(void)
{
    printf("    defines:\n");

    TEST_BXI_MACRO_U32(BXI_MEM_NONE);
    TEST_BXI_MACRO_U32(BXI_MEM_ZERO);
}

static void test_utils_test_bxi_memopt_set(void)
{
    printf("        checking: bxi_memopt_set\n");
    bxi_memopt_set(BXI_MEM_ZERO);
}

static void test_utils_test_bxi_memerr_set(void)
{
    printf("        checking: bxi_memerr_set\n");
    bxi_memerr_set(my_memerr);
}

static void test_utils_test_bxi_malloc_set(void)
{
    printf("        checking: bxi_malloc_set\n");
    bxi_malloc_set(my_malloc);

    printf("        checking: bxi_malloc\n");

#   if defined(bxi_malloc)
    data = bxi_malloc(10);
    if (!data)
        test_failed();
    else
    {
        data[0] = 0x12;
        if (data[0] != 0x12)
            test_failed();
    }
#   else
    test_failed();
#   endif
}

static void test_utils_test_bxi_realloc_set(void)
{
    printf("        checking: bxi_realloc_set\n");
    bxi_realloc_set(my_realloc);

    printf("        checking: bxi_realloc\n");
#   if defined(bxi_realloc)
    data = bxi_realloc(data, 15);
    if (!data)
        test_failed();
    else
    {
        if (data[0] != 0x12)
            test_failed();
    }
#   else
    test_failed();
#   endif
}

static void test_utils_test_bxi_free_set(void)
{
    printf("        checking: bxi_free_set\n");
    bxi_free_set(my_free);

    printf("        checking: bxi_free\n");
#   if defined(bxi_free)
    bxi_free(data);
#   else
    test_failed();
#   endif
}

static void test_utils_test_bxi_memset(void)
{
    u32  i;
    printf("        checking: bxi_memset\n");
    data = bxi_malloc(10);
    bxi_memset(data, 0x12, 10);
    for (i = 0; i < 10; i++)
    {
        if (data[i] != 0x12)
            test_failed();
    }
    check_memset_speed();
}

static void test_utils_test_bxi_memcpy(void)
{
    u32  i;
    printf("        checking: bxi_memcpy\n");
    bxi_memcpy(data, test, 10);
    for (i = 0; i < 10; i++)
    {
        if (data[i] != test[i])
            test_failed();
    }
    check_memcpy_advance();
    check_memcpy_speed();
}

static void test_utils_test_bxi_memmove(void)
{
    u32  i;
    printf("        checking: bxi_memmove\n");
    bxi_memmove(data, data + 5, 5);
    for (i = 0; i < 5; i++)
    {
        if (data[i] != test[i + 5])
            test_failed();
    }
    check_memmove_advance();
    check_memmove_speed();
}

static void test_utils_test_bxi_memcmp(void)
{
    printf("        checking: bxi_memcmp\n");
    if (bxi_memcmp(data, test+5, 5))
        test_failed();
    check_memcmp_advance();
    check_memcmp_speed();
}

static void test_utils_test_bxi_memfrob(void)
{
    printf("        checking: bxi_memfrob\n");
    bxi_memfrob(data, 0x42, 5);
    if ((data[0] != 0x55) ||
        (data[1] != 0x5a) ||
        (data[2] != 0x5b) ||
        (data[3] != 0x58) ||
        (data[4] != 0x59))
        test_failed();
    check_memfrob_speed();
}

static void test_utils_test_bxi_memchr(void)
{
    printf("        checking: bxi_memchr\n");
    if (bxi_memchr(data, 0x58, 10) != data + 3)
        test_failed();
}

static void test_utils_test_bxi_memrchr(void)
{
    printf("        checking: bxi_memrchr\n");
    if (bxi_memrchr(data, 0x58, 10) != data + 3)
        test_failed();
}

static void test_utils_test_bxi_memset16(void)
{
    printf("        checking: bxi_memset16\n");
    check_memset16_advance();
    check_memset16_speed();
}

static void test_utils_test_bxi_memset32(void)
{
    printf("        checking: bxi_memset32\n");
    check_memset32_advance();
    check_memset32_speed();
}

static void test_utils_functions(void)
{
    printf("    functions:\n");

    test_utils_test_bxi_memopt_set();
    test_utils_test_bxi_memerr_set();
    test_utils_test_bxi_malloc_set();
    test_utils_test_bxi_realloc_set();
    test_utils_test_bxi_free_set();

    test_utils_test_bxi_memset();
    test_utils_test_bxi_memcpy();
    test_utils_test_bxi_memmove();
    test_utils_test_bxi_memcmp();
    test_utils_test_bxi_memfrob();
    test_utils_test_bxi_memchr();
    test_utils_test_bxi_memrchr();
    test_utils_test_bxi_memset16();
    test_utils_test_bxi_memset32();
}

void test_utils_bximemutils(void)
{
    print_info;

    test_utils_defines();
    test_utils_functions();

    print_passed();
}
