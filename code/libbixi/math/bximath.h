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

#ifndef BXI_MATH_H
#define BXI_MATH_H

#include "../types/bxiints.h"

EXPORT u32 bxi_abs(i32 val);
EXPORT i32 bxi_sign(i32 val);

/* @todo add gcd & lcm */

EXPORT_FROM
#define BXI_MAX(a, b) (a > b ? a : b)
#define BXI_MIN(a, b) (a > b ? b : a)
EXPORT_TO

#endif /* BXI_MATH_H */

