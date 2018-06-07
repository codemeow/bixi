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

#ifndef BXIUUID_H
#define BXIUUID_H

#include "../definitions/bxiexport.h"
#include "../types/bxiints.h"
#include "../types/bxibools.h"
#include "../hashes/bxihash.h"

EXPORT_FROM
#define UUID_SIZE     (16)
#define UUID_STR_SIZE (45 + 1)
EXPORT_TO
EXPORT typedef hash_16 uuid_t;

EXPORT typedef enum
{
    UUID_PLAIN,  /* "00000000000000000000000000000000"              */
    UUID_HYPHEN, /* "00000000-0000-0000-0000-000000000000"          */
    UUID_URN,    /* "urn:uuid:00000000-0000-0000-0000-000000000000" */
    UUID_CURLY   /* "{00000000-0000-0000-0000-000000000000}"        */
} uuid_format;

EXPORT_FROM
#define UUID_STRLEN_PLAIN  (32)
#define UUID_STRLEN_HYPHEN (36)
#define UUID_STRLEN_URN    (45)
#define UUID_STRLEN_CURLY  (38)

#define UUID_URN_PREFIX    ("urn:uuid:")
#define UUID_EMPTY         "00000000-0000-0000-0000-000000000000"
EXPORT_TO

EXPORT void uuidv3(uuid_t out, uuid_t ns, const char * data);
EXPORT void uuidv4(uuid_t out);

EXPORT void uuid2str(uuid_t uuid, char * out, uuid_format format);
EXPORT i32  uuidscmp(uuid_t u1, uuid_t u2);

EXPORT bool str2uuid(const char * str, uuid_t res);

#endif /* BXIUUID_H */

