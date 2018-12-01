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

bxi_sleep_int_func bxi_nsleep_val = NULL;

void bxi_nsleep_set(bxi_sleep_int_func func) {
    bxi_nsleep_val = func;
}

void bxi_fsleep(f64 sec) {
    if (bxi_nsleep_val)
        bxi_nsleep_val(sec, (sec - (u32)sec) * BXI_NSEC_IN_SEC);
}

void bxi_nsleep(u32 nsec) {
    if (bxi_nsleep_val)
        bxi_nsleep_val(nsec / BXI_NSEC_IN_SEC,
                       nsec % BXI_NSEC_IN_SEC);
}

void bxi_usleep(u32 usec) {
    if (bxi_nsleep_val)
        bxi_nsleep_val(usec / BXI_USEC_IN_SEC,
                      (usec % BXI_USEC_IN_SEC) * BXI_NSEC_IN_USEC);
}

void bxi_msleep(u32 msec) {
    if (bxi_nsleep_val)
        bxi_nsleep_val(msec / BXI_MSEC_IN_SEC,
                      (msec % BXI_MSEC_IN_SEC) * BXI_NSEC_IN_MSEC);
}

void bxi_sleep(u32 sec) {
    if (bxi_nsleep_val)
        bxi_nsleep_val(sec, 0);
}
