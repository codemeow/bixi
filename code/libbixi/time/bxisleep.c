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

#include "../time/bxisleep.h"
#include "../definitions/bximacros.h"

bxi_sleep_int_func bxi_sleep_val  = NULL;
bxi_sleep_int_func bxi_msleep_val = NULL;
bxi_sleep_int_func bxi_usleep_val = NULL;
bxi_sleep_int_func bxi_nsleep_val = NULL;
bxi_sleep_flt_func bxi_fsleep_val = NULL;

void bxi_sleep_set(bxi_sleep_int_func func)
{
    bxi_sleep_val = func;
}

void bxi_msleep_set(bxi_sleep_int_func func)
{
    bxi_msleep_val = func;
}

void bxi_usleep_set(bxi_sleep_int_func func)
{
    bxi_usleep_val = func;
}

void bxi_nsleep_set(bxi_sleep_int_func func)
{
    bxi_nsleep_val = func;
}

void bxi_fsleep_set(bxi_sleep_flt_func func)
{
    bxi_fsleep_val = func;
}

void bxi_fsleep(f64 sec)
{
    if (bxi_fsleep_val)
        bxi_fsleep_val(sec);
    else
    if (bxi_nsleep_val)
        bxi_nsleep_val(sec * BXI_NSEC_IN_SEC);
    else
    if (bxi_usleep_val)
        bxi_usleep_val(sec * BXI_USEC_IN_SEC);
    else
    if (bxi_msleep_val)
        bxi_msleep_val(sec * BXI_MSEC_IN_SEC);
    else
    if (bxi_sleep_val)
        bxi_sleep_val(sec);
}

void bxi_nsleep(u32 nsec)
{
    if (bxi_nsleep_val)
        bxi_nsleep_val(nsec);
    else
    if (bxi_fsleep_val)
        bxi_fsleep_val((f32)nsec / BXI_NSEC_IN_SEC);
    else
    /* Less accurate */
    if (bxi_usleep_val)
        bxi_usleep_val(1);
    else
    if (bxi_msleep_val)
        bxi_msleep_val(1);
    else
    if (bxi_sleep_val)
        bxi_sleep_val(1);
}

void bxi_usleep(u32 usec)
{
    if (bxi_usleep_val)
        bxi_usleep_val(usec);
    else
    if (bxi_nsleep_val)
        bxi_nsleep_val(usec * BXI_NSEC_IN_USEC);
    else
    if (bxi_fsleep_val)
        bxi_fsleep_val((f32)usec / BXI_USEC_IN_SEC);
    else
    /* Less accurate */
    if (bxi_msleep_val)
        bxi_msleep_val(1);
    else
    if (bxi_sleep_val)
        bxi_sleep_val(1);
}

void bxi_msleep(u32 msec)
{
    if (bxi_msleep_val)
        bxi_msleep_val(msec);
    else
    if (bxi_nsleep_val)
        bxi_nsleep_val(msec * BXI_NSEC_IN_MSEC);
    else
    if (bxi_fsleep_val)
        bxi_fsleep_val(msec / BXI_MSEC_IN_SEC);
    else
    if (bxi_usleep_val)
        bxi_usleep_val(msec * BXI_USEC_IN_MSEC);
    else
    /* Less accurate */
    if (bxi_sleep_val)
        bxi_sleep_val(1);
}

void bxi_sleep(u32 sec)
{
    if (bxi_sleep_val)
        bxi_sleep_val(sec);
    else
    if (bxi_nsleep_val)
        bxi_nsleep_val(sec * BXI_NSEC_IN_SEC);
    else
    if (bxi_fsleep_val)
        bxi_fsleep_val(sec);
    else
    if (bxi_usleep_val)
        bxi_usleep_val(sec * BXI_USEC_IN_SEC);
    else
    if (bxi_msleep_val)
        bxi_msleep_val(sec * BXI_MSEC_IN_SEC);
}
