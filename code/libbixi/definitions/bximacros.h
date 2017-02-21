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

#ifndef BXIMACROS_H
#define BXIMACROS_H

#include "../definitions/bxiexport.h"

EXPORT_FROM
#ifndef   UNUSED
#define   UNUSED(x) ((void)x)
#endif /* UNUSED */
EXPORT_TO

EXPORT_FROM
#define IN(    value, high, low) ((high >  value) && (value <  low))
#define IN_INC(value, high, low) ((high >= value) && (value <= low))
EXPORT_TO

#endif /* BXIMACROS_H */

