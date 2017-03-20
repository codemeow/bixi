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

#include "../time/bxisleep.h"

#define BXI_MSEC_IN_SEC (1000)
#define BXI_USEC_IN_SEC (1000 * BXI_MSEC_IN_SEC)
#define BXI_NSEC_IN_SEC (1000 * BXI_USEC_IN_SEC)

/* @todo arches to separate file */
#if defined(linux) || defined(__linux) || defined(__linux__) || \
    defined(unix)  || defined(__unix)  || defined(__unix__)
#define _POSIX_C_SOURCE	199309L
#include <time.h>
static void nsleep(f64 sec)
{
    struct timespec ts;
    ts.tv_sec  = (u32)sec;
    ts.tv_nsec = (sec - (u32)sec) * BXI_NSEC_IN_SEC;

    nanosleep(&ts, NULL);
}
#elif defined(WIN32) || defined(_WIN32)
#include <time.h>
#include <windows.h>
/* @fixme needs tests */
static void nsleep(f64 sec)
{
    HANDLE timer;
    LARGE_INTEGER li;
    if(!(timer = CreateWaitableTimer(NULL, true, NULL)))
        return;

    li.QuadPart = -(u32)(sec * BXI_NSEC_IN_SEC);
    if(!SetWaitableTimer(timer, &li, 0, NULL, NULL, false))
    {
        CloseHandle(timer);
        return;
    }
    WaitForSingleObject(timer, INFINITE);
    CloseHandle(timer);
}
#else
#error unsupported architecture
#endif

void bxi_sleep(u32 sec)
{
    bxi_fsleep(sec);
}

void bxi_msleep(u32 msec)
{
    bxi_fsleep(msec * (1.0 / BXI_MSEC_IN_SEC));
}

void bxi_usleep(u32 usec)
{
    bxi_fsleep(usec * (1.0 / BXI_USEC_IN_SEC));
}

void bxi_nsleep(u32 nsec)
{
    bxi_fsleep(nsec * (1.0 / BXI_NSEC_IN_SEC));
}

void bxi_fsleep(f64 sec)
{
    nsleep(sec);

    /* Busy wait-implementation, C89-compatible
    const clock_t str = clock();
          clock_t cur;
    do
    {
        cur = clock();
    }
    while (((f64)(cur - str) / CLOCKS_PER_SEC) < sec);
    */
}
