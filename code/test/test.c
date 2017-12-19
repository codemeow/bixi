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
#include <stdlib.h>
#include <time.h>

#include "test.h"

struct timespec time_s = { 0, 0 };
struct timespec time_f = { 0, 0 };
double time_diff = 0.0;

void print_macro_failed(const char * file, i32 line)
{
    printf("\033[1;FAILED at %s:%d\033[0m\n", file, line);
    exit(1);
}

void print_macro_name(const char * name)
{
    printf("        checking: %-25s: ", name);
}

void print_macro_undefined_exit(void)
{
    printf("\033[1;31mUNDEFINED\033[0m\n");
    exit(1);
}

void print_macro_defined(void)
{
    printf("\033[1;32mDEFINED\033[0m\n");
}

void print_macro_undefined(void)
{
    printf("\033[1;33mUNDEFINED\033[0m\n");
}

void print_macro_value_string(const char * value)
{
    printf("\"%s\"\n", value);
}

void print_macro_value_signed(i32 value)
{
    printf("%d\n", value);
}

void print_macro_value_float(f64 value)
{
    printf("%25.18f\n", value);
}

void print_macro_value_unsigned(u32 value)
{
    printf("%u\n", value);
}

void print_passed(void)
{
    printf("\033[1;32mPASSED\033[0m\n\n");
}

void test_failed_call(const char * file, i32 line)
{
    printf("\033[1;31mFAILED at %s:%d\033[0m\n\n", file, line);
    exit(1);
}

void test_time_start(void)
{
    clock_gettime(CLOCK_MONOTONIC, &time_s);
}

void test_time_finish(void)
{
    double time_n_s;
    double time_n_f;

    clock_gettime(CLOCK_MONOTONIC, &time_f);
    time_n_s = time_s.tv_nsec + time_s.tv_sec * (f64)1e9;
    time_n_f = time_f.tv_nsec + time_f.tv_sec * (f64)1e9;

    time_diff = time_n_f - time_n_s;
}

void test_time_print(const char * text)
{
    printf("            speedtest: %12s: %8.5f\n", text,
           time_diff / BXI_NSEC_IN_SEC);
}
