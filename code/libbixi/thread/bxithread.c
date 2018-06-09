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

#include "../thread/bxithread.h"
#include "../time/bxisleep.h"
#include "../definitions/bximacros.h"
#include "../definitions/bxienv.h"

static bxi_mutex atomic_xchg(volatile bxi_mutex * ptr, bxi_mutex val)
{
#   if !defined(BXI_ARCH_A32) && !defined(BXI_ARCH_A64)
        bxi_mutex tmp = val;
        __asm__ __volatile__ (
            "xchgl %0, %1;\n"
            : "=r"(tmp), "+m"(*ptr)
            : "0"(tmp)
            :"memory");
        return tmp;
#   else
        /* @todo as there is no xchgl command on ARM
         *       we need to rewrite it */
        UNUSED(ptr);
        UNUSED(val);
        return BXI_MUTEX_UNDEFINED;
#   endif
}

static bxi_mutex bxi_test_and_set(volatile bxi_mutex * val)
{
    return atomic_xchg(val, BXI_MUTEX_LOCKED);
}

void bxi_mutex_init(volatile bxi_mutex * mutex)
{
    if (!mutex)
        return;

    *mutex = BXI_MUTEX_INITIALIZER;
}

void bxi_mutex_lock(volatile bxi_mutex * mutex)
{
    if (!mutex)
        return;

    while (bxi_test_and_set(mutex))
        bxi_usleep(BXI_MUTEX_PERIOD);
}

void bxi_mutex_unlock(volatile bxi_mutex * mutex)
{
    if (!mutex)
        return;

    *mutex = BXI_MUTEX_UNLOCKED;
}

bxi_mutex_st bxi_mutex_test(volatile bxi_mutex * mutex)
{
    bxi_mutex_st state;
    if (!mutex)
        return BXI_MUTEX_UNDEFINED;

    state = *mutex;

    if ((state == BXI_MUTEX_LOCKED  ) ||
        (state == BXI_MUTEX_UNLOCKED))
        return state;

    return BXI_MUTEX_UNDEFINED;
}
