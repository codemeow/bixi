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
#include <time.h>
#include <libbixi.h>
#include "../test.h"
#include "../time/tst_bxisleep.h"

#define TEST_FMT_SLEEP_TEMPLATE "            (ex. %10.2f, rl %10.2f)\n"

#if defined(BXI_OS_GLX) || defined(BXI_OS_MNX)

    static void nsleep(u32 sec, u32 nsec)
    {
        struct timespec ts;
        ts.tv_sec  = sec;
        ts.tv_nsec = nsec;

        nanosleep(&ts, NULL);
    }

#endif

static struct timespec time_s = { 0, 0 };
static struct timespec time_f = { 0, 0 };
static double time_diff = 0.0;

static void test_time_start(void)
{
    clock_gettime(CLOCK_MONOTONIC, &time_s);
}

static void test_time_finish(void)
{
    double time_n_s;
    double time_n_f;

    clock_gettime(CLOCK_MONOTONIC, &time_f);
    time_n_s = time_s.tv_nsec + time_s.tv_sec * (f64)1e9;
    time_n_f = time_f.tv_nsec + time_f.tv_sec * (f64)1e9;

    time_diff = time_n_f - time_n_s;
}

static void test_time_bxi_nsleep_set(void)
{
#   if defined(BXI_OS_GLX) || defined(BXI_OS_MNX)
        printf("        checking: bxi_nsleep_set\n");
        bxi_nsleep_set(nsleep);
#   endif
}

static void test_time_bxi_nsleep(void)
{
    printf("        checking: bxi_nsleep\n");

    test_time_start();
    bxi_nsleep(100);
    test_time_finish();
    printf(TEST_FMT_SLEEP_TEMPLATE, 100.0, time_diff);

    test_time_start();
    bxi_nsleep(5000);
    test_time_finish();
    printf(TEST_FMT_SLEEP_TEMPLATE, 5000.0, time_diff);

    test_time_start();
    bxi_nsleep(100000);
    test_time_finish();
    printf(TEST_FMT_SLEEP_TEMPLATE, 100000.0, time_diff);
}

static void test_time_bxi_usleep(void)
{
    printf("        checking: bxi_usleep\n");

    test_time_start();
    bxi_usleep(100);
    test_time_finish();
    printf(TEST_FMT_SLEEP_TEMPLATE, 100.0, time_diff / BXI_NSEC_IN_USEC);

    test_time_start();
    bxi_usleep(5000);
    test_time_finish();
    printf(TEST_FMT_SLEEP_TEMPLATE, 5000.0, time_diff / BXI_NSEC_IN_USEC);

    test_time_start();
    bxi_usleep(100000);
    test_time_finish();
    printf(TEST_FMT_SLEEP_TEMPLATE, 100000.0, time_diff / BXI_NSEC_IN_USEC);
}

static void test_time_bxi_msleep(void)
{
    printf("        checking: bxi_msleep\n");

    test_time_start();
    bxi_msleep(10);
    test_time_finish();
    printf(TEST_FMT_SLEEP_TEMPLATE, 10.0, time_diff / BXI_NSEC_IN_MSEC);

    test_time_start();
    bxi_msleep(500);
    test_time_finish();
    printf(TEST_FMT_SLEEP_TEMPLATE, 500.0, time_diff / BXI_NSEC_IN_MSEC);

    test_time_start();
    bxi_msleep(1000);
    test_time_finish();
    printf(TEST_FMT_SLEEP_TEMPLATE, 1000.0, time_diff / BXI_NSEC_IN_MSEC);
}

static void test_time_bxi_sleep(void)
{
    printf("        checking: bxi_sleep\n");

    test_time_start();
    bxi_sleep(1);
    test_time_finish();
    printf(TEST_FMT_SLEEP_TEMPLATE, 1.0, time_diff / BXI_NSEC_IN_SEC);

    test_time_start();
    bxi_sleep(2);
    test_time_finish();
    printf(TEST_FMT_SLEEP_TEMPLATE, 2.0, time_diff / BXI_NSEC_IN_SEC);

    test_time_start();
    bxi_sleep(3);
    test_time_finish();
    printf(TEST_FMT_SLEEP_TEMPLATE, 3.0, time_diff / BXI_NSEC_IN_SEC);
}

static void test_time_bxi_fsleep(void)
{
    printf("        checking: bxi_fsleep\n");

    test_time_start();
    bxi_fsleep(0.01);
    test_time_finish();
    printf(TEST_FMT_SLEEP_TEMPLATE, 0.01, time_diff / BXI_NSEC_IN_SEC);

    test_time_start();
    bxi_fsleep(1.5);
    test_time_finish();
    printf(TEST_FMT_SLEEP_TEMPLATE, 1.5, time_diff / BXI_NSEC_IN_SEC);

    test_time_start();
    bxi_fsleep(1.01);
    test_time_finish();
    printf(TEST_FMT_SLEEP_TEMPLATE, 1.01, time_diff / BXI_NSEC_IN_SEC);
}

static void test_time_functions(void)
{
    printf("    functions:\n");

    test_time_bxi_nsleep_set();

    test_time_bxi_nsleep();
    test_time_bxi_usleep();
    test_time_bxi_msleep();
    test_time_bxi_fsleep();
    test_time_bxi_sleep();
}

static void test_time_defines(void)
{
    printf("    defines:\n");

    TEST_BXI_MACRO_U32(BXI_MSEC_IN_SEC);
    TEST_BXI_MACRO_U32(BXI_USEC_IN_SEC);
    TEST_BXI_MACRO_U32(BXI_NSEC_IN_SEC);
    TEST_BXI_MACRO_U32(BXI_NSEC_IN_USEC);
    TEST_BXI_MACRO_U32(BXI_NSEC_IN_MSEC);
    TEST_BXI_MACRO_U32(BXI_USEC_IN_MSEC);
}

void test_time_bxisleep(void)
{
    print_info;

    test_time_defines();
    test_time_functions();

    print_passed();
}
