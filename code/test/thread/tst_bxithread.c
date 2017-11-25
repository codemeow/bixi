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

#include <libbixi.h>
#include <stdio.h>
#include "../test.h"
#include "../thread/tst_bxithread.h"

/* @todo good tests */

#if !defined(BXI_OS_MNX)
#include <pthread.h>
#include <stdlib.h>

volatile bxi_mutex printer_mutex = BXI_MUTEX_INITIALIZER;
volatile bxi_mutex rainbow_mutex  [7];
volatile bxi_mutex rainbow_opener [7];
               u32 rainbow_results    = 0;
               u32 rainbow_counter    = 0;
        const char rainbow_string [ ] = "        printing: %d [\x1b[48;5;%dm             \x1b[0m]\n";
const          u32 rainbow_colours[7] =
{
    BXI_COLOUR_A256_RED,
    BXI_COLOUR_A256_YELLOW,
    BXI_COLOUR_A256_BRIGHT_YELLOW,
    BXI_COLOUR_A256_GREEN,
    BXI_COLOUR_A256_BRIGHT_CYAN,
    BXI_COLOUR_A256_BLUE,
    BXI_COLOUR_A256_MAGENTA,
};

static void * thread_job(void * arg)
{
    i32 index = *(i32 *)arg;

    free(arg);

    bxi_mutex_lock(&rainbow_mutex[index]);

    printf(rainbow_string, index, rainbow_colours[index]);

    rainbow_results += rainbow_counter << index;
    rainbow_counter++;

    bxi_mutex_unlock(&rainbow_opener[index]);

    pthread_exit(0);
}

void test_thread_bxithread(void)
{
    i32 i;
    i32 pthread_result;
    pthread_t pthread;

    print_info;

    printf("    functions: bxi_mutex_*\n");

    for (i = 0; i < 7; i++)
    {
        bxi_mutex_init(&rainbow_mutex[i]);
        bxi_mutex_lock(&rainbow_mutex[i]);

        bxi_mutex_init(&rainbow_opener[i]);
        bxi_mutex_lock(&rainbow_opener[i]);
    }

    for (i = 0; i < 7; i++)
    {
        i32 * index = malloc(sizeof(i32));
        *index = i;
        pthread_result = pthread_create(&pthread, NULL, thread_job, (void *)index);
        if (pthread_result != 0)
            print_failed();

    }

    for (i = 0; i < 7; i++)
    {
        bxi_mutex_unlock(&rainbow_mutex[i]);
        bxi_mutex_lock(&rainbow_opener[i]);
    }

    if (rainbow_results != 642)
        print_failed();

    print_passed();
}
#else
void test_thread_bxithread(void)
{
    print_info;
    print_passed();
}
#endif
