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

#ifndef BXIBOOLS_H
#define BXIBOOLS_H

#include "../definitions/bxiexport.h"
#include "../types/bxiints.h"

EXPORT typedef u8   b8;
EXPORT typedef u16  b16;
EXPORT typedef u32  b32;

EXPORT_FROM
#define BITS_IN_B8   ( 8)
#define BITS_IN_B16  (16)
#define BITS_IN_B32  (32)
EXPORT_TO

EXPORT_FROM
#ifndef __cplusplus
typedef enum
{
    false,
    true
} bool;
#endif /* __cplusplus */
EXPORT_TO

#endif /* BXIBOOLS_H */

