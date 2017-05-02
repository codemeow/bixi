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

#ifndef BXITHREAD_H
#define BXITHREAD_H

#include "../definitions/bxiexport.h"
#include "../types/bxiints.h"

EXPORT typedef u32 bxi_mutex;
EXPORT typedef enum
{
    BXI_MUTEX_UNLOCKED,
    BXI_MUTEX_LOCKED,
    BXI_MUTEX_UNDEFINED
} bxi_mutex_state;

EXPORT_FROM
#define BXI_MUTEX_INITIALIZER (0)
EXPORT_TO

EXPORT void            bxi_mutex_init  (volatile bxi_mutex * mutex);
EXPORT void            bxi_mutex_lock  (volatile bxi_mutex * mutex);
EXPORT void            bxi_mutex_unlock(volatile bxi_mutex * mutex);
EXPORT bxi_mutex_state bxi_mutex_test  (volatile bxi_mutex * mutex);

#endif /* BXITHREAD_H */
