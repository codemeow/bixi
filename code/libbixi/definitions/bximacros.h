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

#ifndef BXIMACROS_H
#define BXIMACROS_H

#include "../definitions/bxiexport.h"
#include "../types/bxiints.h"

EXPORT_FROM
#ifndef   UNUSED
#define   UNUSED(x) ((void)x)
#endif /* UNUSED */
EXPORT_TO

EXPORT_FROM
#ifndef   NULL
#define   NULL ((void *)0)
#endif /* NULL */
EXPORT_TO

EXPORT_FROM
#define BXI_IN(    value, high, low) (((high) >  (value)) && ((value) >  (low)))
#define BXI_IN_INC(value, high, low) (((high) >= (value)) && ((value) >= (low)))
EXPORT_TO

EXPORT_FROM
#define forever while(1)
EXPORT_TO

EXPORT_FROM
#define BXI_ARRAY_SIZE(static_arr) ((u32)(sizeof(static_arr) / sizeof(static_arr[0])))
EXPORT_TO

EXPORT_FROM
#define BXI_KB(b) ((u32)(b) << 10ul)
#define BXI_MB(b) ((u32)(b) << 20ul)
#define BXI_GB(b) ((u32)(b) << 30ul)
EXPORT_TO

#endif /* BXIMACROS_H */

