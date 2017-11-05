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

EXPORT void bxi_sleep (u32  sec);
EXPORT void bxi_msleep(u32 msec);
EXPORT void bxi_usleep(u32 usec);
EXPORT void bxi_nsleep(u32 nsec);
EXPORT void bxi_fsleep(f64  sec);

#endif /* BXISLEEP_H */
