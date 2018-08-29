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

#ifndef BRXALPHA_H
#define BRXALPHA_H

#include <libbixi.h>

EXPORT_FROM
#define BRX_BRAILLE_WIDTH   (2)
#define BRX_BRAILLE_HEIGHT  (4)
#define BRX_BRAILLE_COUNT (256)
EXPORT_TO

#define BRX_BRAILLE_BITS (BRX_BRAILLE_WIDTH * BRX_BRAILLE_HEIGHT)

extern u32 brx_alpha[BRX_BRAILLE_COUNT];

#endif /* BRXALPHA_H */

