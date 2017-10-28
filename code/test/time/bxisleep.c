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
#define _GNU_SOURCE 1
#include <stdio.h>
#include <time.h>
#include <libbixi.h>
#include "../test.h"
#include "../time/bxisleep.h"

#define TEST_SLEEP_N (100)
#define TEST_SLEEP_U (100)
#define TEST_SLEEP_M (100)
#define TEST_SLEEP_S (1)
#define TEST_SLEEP_F (1.0)

#define TEST_SLEEP(func, time, mult)                 \
{                                                    \
    struct timespec time_s = { 0, 0 };               \
    struct timespec time_f = { 0, 0 };               \
    u32 time_n_s = 0;                                \
    u32 time_n_f = 0;                                \
                                                     \
    printf("        checking: %10s (exp. ", #func);  \
    clock_gettime(CLOCK_MONOTONIC, &time_s);         \
    func(time);                                      \
    clock_gettime(CLOCK_MONOTONIC, &time_f);         \
                                                     \
    time_n_s = time_s.tv_nsec + time_s.tv_sec * 1e9; \
    time_n_f = time_f.tv_nsec + time_f.tv_sec * 1e9; \
                                                     \
    printf("%3u, rl. %3u)\n", (u32)time,             \
           (u32)((time_n_f - time_n_s) / mult));     \
}

void test_time_bxisleep(void)
{
    print_info;

    printf("    functions:\n");

#   if defined(BXI_OS_GLX)
        TEST_SLEEP(bxi_nsleep, TEST_SLEEP_N, 1);
        TEST_SLEEP(bxi_usleep, TEST_SLEEP_U, 1e3);
        TEST_SLEEP(bxi_msleep, TEST_SLEEP_M, 1e6);
        TEST_SLEEP(bxi_sleep,  TEST_SLEEP_S, 1e9);
        TEST_SLEEP(bxi_fsleep, TEST_SLEEP_F, 1e9);
#   else
        print_failed();
        return;
#   endif

    print_passed();
}
