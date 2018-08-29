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
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <libbixi.h>
#include "../init/brxinit.h"

static void my_memerr(u32 req, const char * file, u32 line)
{
    printf("[E]: [my_memerr] on %s:%u while requesting %u bytes\n",
           file, line, req);
    exit(1);
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

static void nsleep(u32 sec, u32 nsec)
{
    struct timespec ts;
    ts.tv_sec  = sec;
    ts.tv_nsec = nsec;

    nanosleep(&ts, NULL);
}

static void brx_init_memory(void)
{
    bxi_memerr_set (my_memerr);
    bxi_malloc_set (my_malloc);
    bxi_realloc_set(my_realloc);
    bxi_free_set   (my_free);
}

static void brx_init_sleep (void)
{
    bxi_nsleep_set(nsleep);
}

void brx_bixi_init(void)
{
    brx_init_memory();
    brx_init_sleep();
}
