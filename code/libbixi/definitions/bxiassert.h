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

#ifndef BXIASSERT_H
#define BXIASSERT_H

#include "../definitions/bxiexport.h"

EXPORT_FROM
#ifdef NDEBUG
#define COMPILE_ASSERT(expr)
#else /* NDEBUG */
#define COMPILE_ASSERT(expr) \
    extern char _compile_time_assertion_[(expr) ? 1 : -1]
#endif /* NDEBUG */
EXPORT_TO

#endif /* BXIASSERT_H */

