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

#ifndef BXISHA1_H
#define BXISHA1_H

#include "../definitions/bxiexport.h"
#include "../types/bxiints.h"
#include "../hashes/bxihash.h"

EXPORT_FROM
#define SHA1_SIZE (20)

#define SHA1_STEP_COUNT (5)
EXPORT_TO

EXPORT typedef struct
{
    u32     leng;
    u32     totl[2];

    u32     h[SHA1_STEP_COUNT];
    u32     w[16];
    hash_20 hash;
} sha1_t;

EXPORT void sha1_init     (sha1_t * sha1);
EXPORT void sha1_append   (sha1_t * sha1, const u8 * data, u32 len);
EXPORT void sha1_appendstr(sha1_t * sha1, const char * str);
EXPORT void sha1_appendi8 (sha1_t * sha1, i8 num);
EXPORT void sha1_appendu8 (sha1_t * sha1, u8 num);
EXPORT void sha1_appendi16(sha1_t * sha1, i16 num);
EXPORT void sha1_appendu16(sha1_t * sha1, u16 num);
EXPORT void sha1_appendi32(sha1_t * sha1, i32 num);
EXPORT void sha1_appendu32(sha1_t * sha1, u32 num);
EXPORT void sha1_final    (sha1_t * sha1);

EXPORT void sha12str      (sha1_t * sha1, char * out);

#endif /* BXISHA1_H */

