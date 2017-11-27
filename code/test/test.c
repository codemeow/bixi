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

#include "test.h"

void print_macro_failed(const char * file, i32 line)
{
    printf("\033[1;FAILED at %s:%d\033[0m\n", file, line);
    exit(1);
}

void print_macro_name(const char * name)
{
    printf("        checking: %-20s: ", name);
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

void print_failed(void)
{
    printf("\033[1;31mFAILED\033[0m\n\n");
    exit(1);
}
