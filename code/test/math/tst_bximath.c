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
#include <stdio.h>
#include <math.h>
#include <libbixi.h>
#include <time.h>
#include "../test.h"
#include "../math/tst_bximath.h"

#define TEST_SPEED_INIT                \
    struct timespec time_s = { 0, 0 }; \
    struct timespec time_f = { 0, 0 }; \
    double time_n_s = 0;               \
    double time_n_f = 0;               \
    double sum_org = 0;                \
    double sum_new = 0
#define TEST_SPEED_START               \
    clock_gettime(CLOCK_MONOTONIC, &time_s)
#define TEST_SPEED_STOP                \
    clock_gettime(CLOCK_MONOTONIC, &time_f); \
    time_n_s = time_s.tv_nsec + time_s.tv_sec * 1e9; \
    time_n_f = time_f.tv_nsec + time_f.tv_sec * 1e9
#define TEST_SPEED_SAY(name)           \
    printf("            speedtest: %-12s: %8.5f\n", \
        name, (time_n_f - time_n_s) / (f64)1e9)
#define TEST_SPEED_LOOPS (U32_MAX)

static void test_sqrt_speed(void)
{
    u32 i;
    TEST_SPEED_INIT;

    TEST_SPEED_START;
    for (i = 0; i < TEST_SPEED_LOOPS; i++)
        sum_org += round(sqrt(i));
    TEST_SPEED_STOP;
    TEST_SPEED_SAY("     sqrt");

    TEST_SPEED_START;
    for (i = 0; i < TEST_SPEED_LOOPS; i++)
        sum_new += bxi_sqrti(i);
    TEST_SPEED_STOP;
    TEST_SPEED_SAY("bxi_sqrti");

    printf("                precision: %8.5f%%\n",
           100 - ((sum_new - sum_org) * 100 / sum_org));
}

static void test_math_div255(void)
{
#   if defined(BXI_FAST_U16DIV255)
        u32 i;

        printf("        defined : BXI_FAST_U16DIV255\n");
        for (i = U16_MIN; i < U16_MAX; i++)
        {
            if (BXI_FAST_U16DIV255(i) != i / 255)
                print_failed();
        }
#   else
        print_failed();
#   endif
}

static void test_math_rounders(void)
{
    u32 i;
    printf("        checking: bxi_isnan\n");
    if (bxi_isnan(5.0) != false)
        print_failed();
    if (bxi_isnan(0.0) != false)
        print_failed();
    if (bxi_isnan(0.0 / 0.0) != true)
        print_failed();
    if (bxi_isnan(NAN) != true)
        print_failed();

    printf("        checking: bxi_ceil\n");
    for (i = 0; i < 50; i++)
    {
        if (    ceil(1.0 + i * 0.1) !=
            bxi_ceil(1.0 + i * 0.1))
            print_failed();
    }

    printf("        checking: bxi_floor\n");
    for (i = 0; i < 50; i++)
    {
        if (    floor(1.0 + i * 0.1) !=
            bxi_floor(1.0 + i * 0.1))
            print_failed();
    }

    printf("        checking: bxi_round\n");
    for (i = 0; i < 50; i++)
    {
        if (    round(1.0 + i * 0.1) !=
            bxi_round(1.0 + i * 0.1))
            print_failed();
    }
}

void test_math_bximath(void)
{
    print_info;

    printf("    defines:\n");

    /* BXI_MAX */
#   if defined(BXI_MAX)
        printf("        defined : BXI_MAX\n");
        if (BXI_MAX(5, 6) != 6)
            print_failed();
#   else
        print_failed();
#   endif

    /* BXI_MIN */
#   if defined(BXI_MIN)
        printf("        defined : BXI_MIN\n");
        if (BXI_MIN(6, 5) != 5)
            print_failed();
#   else
        print_failed();
        return;
#   endif

    test_math_div255();

    printf("    functions:\n");

    /* bxi_abs */
    printf("        checking: bxi_abs\n");
    if (bxi_abs(-5) != 5)
        print_failed();
    if (bxi_abs(0) != 0)
        print_failed();
    if (bxi_abs(5) != 5)
        print_failed();

    /* bxi_sign */
    printf("        checking: bxi_sign\n");
    if (bxi_sign(-5) != -1)
        print_failed();
    if (bxi_sign(0) != 0)
        print_failed();
    if (bxi_sign(5) != 1)
        print_failed();

    /* bxi_gcd */
    printf("        checking: bxi_gcd\n");
    if (bxi_gcd(28, 17) != 1)
        print_failed();
    if (bxi_gcd(28, 34) != 2)
        print_failed();
    if (bxi_gcd(-17, 34) != 17)
        print_failed();

    /* bxi_lcm */
    printf("        checking: bxi_lcm\n");
    if (bxi_lcm(65, 10) != 130)
        print_failed();
    if (bxi_lcm(17, 34) != 34)
        print_failed();
    if (bxi_lcm(12, 13) != 156)
        print_failed();

    printf("        checking: bxi_sqrti\n");
    test_sqrt_speed();

    test_math_rounders();

    print_passed();
}
