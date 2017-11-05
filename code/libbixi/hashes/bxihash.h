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

#ifndef BXIHASH_H
#define BXIHASH_H

#include "../definitions/bxiexport.h"
#include "../types/bxiints.h"

EXPORT typedef u8 hash_4[4];
EXPORT typedef u8 hash_8[8];
EXPORT typedef u8 hash_16[16];
EXPORT typedef u8 hash_32[32];
EXPORT typedef u8 hash_64[64];
EXPORT typedef u8 hash_128[128];
EXPORT typedef u8 hash_256[256];
EXPORT typedef u8 hash_512[512];

#endif /* BXIHASH_H */

