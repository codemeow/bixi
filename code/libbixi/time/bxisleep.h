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

#ifndef BXISLEEP_H
#define BXISLEEP_H

#include "../definitions/bxiexport.h"
#include "../types/bxiints.h"
#include "../types/bxifloats.h"

EXPORT_FROM
#define BXI_MSEC_IN_SEC  (1000)
#define BXI_USEC_IN_SEC  (1000 * BXI_MSEC_IN_SEC)
#define BXI_NSEC_IN_SEC  (1000 * BXI_USEC_IN_SEC)
#define BXI_NSEC_IN_USEC (1000)
#define BXI_NSEC_IN_MSEC (1000 * BXI_NSEC_IN_USEC)
#define BXI_USEC_IN_MSEC (1000)
EXPORT_TO

EXPORT typedef void (*bxi_sleep_int_func)(u32);
EXPORT typedef void (*bxi_sleep_flt_func)(f32);

EXPORT void bxi_sleep_set (bxi_sleep_int_func func);
EXPORT void bxi_msleep_set(bxi_sleep_int_func func);
EXPORT void bxi_usleep_set(bxi_sleep_int_func func);
EXPORT void bxi_nsleep_set(bxi_sleep_int_func func);
EXPORT void bxi_fsleep_set(bxi_sleep_flt_func func);

EXPORT void bxi_sleep (u32  sec);
EXPORT void bxi_msleep(u32 msec);
EXPORT void bxi_usleep(u32 usec);
EXPORT void bxi_nsleep(u32 nsec);
EXPORT void bxi_fsleep(f64  sec);

#endif /* BXISLEEP_H */
