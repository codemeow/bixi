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

#include "../alphabet/brxalpha.h"

u32 brx_alpha[BRX_BRAILLE_COUNT];

static void brxinit(void) __attribute__ ((constructor));

static void brxinit(void)
{
    u32 i;
    for (i = 0; i < BRX_BRAILLE_COUNT; i++)
        brx_alpha[i] =
            0xe2 | ((0xa0 + (i >> 6)) << 8) |
            (((i & 0xf) + ((i % 0x40) & 0xf0) + 0x80) << 0x10);
}
