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

#ifndef BXIMD5_H
#define BXIMD5_H

#include "../definitions/bxiexport.h"
#include "../types/bxiints.h"

typedef struct
{
    u32 abcd[4];
    u32 leng;
    u32 totl[2];
    u8  data[64];
    u8  hash[16];
} md5_t;

EXPORT void md5_init  (md5_t * md5);
EXPORT void md5_append(md5_t * md5, u8 * data, u32 len);
EXPORT void md5_final (md5_t * md5);

#endif /* BXIMD5_H */

