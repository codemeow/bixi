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

#include "../hashes/bxiuuid.h"
#include "../hashes/bximd5.h"
#include "../random/bxirand.h"
#include "../utils/bximemutils.h"
#include "../strings/bxistring.h"

typedef enum {
    UUID_V1 = 1,
    UUID_V2,
    UUID_V3,
    UUID_V4,
    UUID_V5
} uuid_version;

static void uuidversionset(bxi_uuid_t out, uuid_version ver) {
    out[6] = ((out[6] & 0x0F) | (ver << 4));
    out[8] = ((out[8] & 0x3F) | 0x80);
}

void uuidv3(bxi_uuid_t out, bxi_uuid_t ns, const char * data) {
 /*   u32 i;*/
    md5_t md5;
    md5_init     (&md5);
    md5_append   (&md5, ns, UUID_SIZE);
    md5_appendstr(&md5, data);
    md5_final    (&md5);

    md5_copy(&md5, out);

    uuidversionset(out, UUID_V3);
}

void uuidv4(bxi_uuid_t out) {
    u32 i;
    for (i = 0; i < UUID_SIZE; i += sizeof(u32))     {
        u32 r = bxi_randu32();
        bxi_memcpy(&out[i], &r, sizeof(u32));
    }

    uuidversionset(out, UUID_V4);
}

void uuid_appendhex(u8 value, char * out) {
    out[0] = (value >> 4) > 9 ? 'a' + (value >> 4) - 10 : '0' + (value >> 4);
    out[1] = (value & 15) > 9 ? 'a' + (value & 15) - 10 : '0' + (value & 15);
}

void uuid2str(bxi_uuid_t uuid, char * out, uuid_format format) {
    u32 strpos = 0;
    u32 i = 0;

    if (!out)
        return;

    switch (format) {
    case UUID_PLAIN:
        for (i = 0; i < UUID_SIZE; i++, strpos += 2)
            uuid_appendhex(uuid[i], out + strpos);
        break;
    case UUID_CURLY:
        out[strpos++] = '{';
        for (i = 0; i < UUID_SIZE; i++, strpos += 2) {
            if ((i == 4) || (i == 6) || (i == 8) || (i == 10))
                out[strpos++] = '-';
            uuid_appendhex(uuid[i], out + strpos);
        }
        out[strpos++] = '}';
        break;
    case UUID_HYPHEN:
        for (i = 0; i < UUID_SIZE; i++, strpos += 2) {
            if ((i == 4) || (i == 6) || (i == 8) || (i == 10))
                out[strpos++] = '-';
            uuid_appendhex(uuid[i], out + strpos);
        }
        break;
    case UUID_URN:
        out[strpos++] = 'u'; out[strpos++] = 'r'; out[strpos++] = 'n';
        out[strpos++] = ':'; out[strpos++] = 'u'; out[strpos++] = 'u';
        out[strpos++] = 'i'; out[strpos++] = 'd'; out[strpos++] = ':';
        for (i = 0; i < UUID_SIZE; i++, strpos += 2) {
            if ((i == 4) || (i == 6) || (i == 8) || (i == 10))
                out[strpos++] = '-';
            uuid_appendhex(uuid[i], out + strpos);
        }
        break;
    default: ;
    }

    out[strpos] = '\0';
}

i32 uuidscmp(bxi_uuid_t u1, bxi_uuid_t u2) {
    return bxi_memcmp(u1, u2, sizeof(bxi_uuid_t));
}

static bool ascii2u8(const char * str, u8 * res) {
    *res = 0;

    if ((*str >= '0') && (*str <= '9'))
        *res = (*str - '0') << 4;
    else if ((*str >= 'a') && (*str <= 'f'))
        *res = (*str - 'a' + 10) << 4;
    else if ((*str >= 'A') && (*str <= 'F'))
        *res = (*str - 'A' + 10) << 4;
    else
        return false;

    str++;

    if ((*str >= '0') && (*str <= '9'))
        *res += (*str - '0');
    else if ((*str >= 'a') && (*str <= 'f'))
        *res += (*str - 'a' + 10);
    else if ((*str >= 'A') && (*str <= 'F'))
        *res += (*str - 'A' + 10);
    else
        return false;

    return true;
}

static bool ascii2u8s(const char * str, bxi_uuid_t res, u8 count, u8 shift) {
    u32 i;
    for (i = 0; i < count; i++) {
        if (!ascii2u8(str, res + i + shift))
            return false;
        str += 2;
    }

    return true;
}

static bool hyphen2uuid(const char * str, bxi_uuid_t res) {
    /* 00000000...*/
    if (!ascii2u8s(str, res, 4, 0))
        return false;
    str += 8;

    /* ...-... */
    if (*str != '-')
        return false;
    str++;

    /* ...0000... */
    if (!ascii2u8s(str, res, 2, 4))
        return false;
    str += 4;

    /* ...-... */
    if (*str != '-')
        return false;
    str++;

    /* ...0000... */
    if (!ascii2u8s(str, res, 2, 6))
        return false;
    str += 4;

    /* ...-... */
    if (*str != '-')
        return false;
    str++;

    /* ...0000... */
    if (!ascii2u8s(str, res, 2, 8))
        return false;
    str += 4;

    /* ...-... */
    if (*str != '-')
        return false;
    str++;

    /* ...000000000000 */
    if (!ascii2u8s(str, res, 6, 10))
        return false;

    return true;
}

bool str2uuid(const char * str, bxi_uuid_t res) {
    if (!str)
        return false;

    if (bxi_strlen(str) == UUID_STRLEN_PLAIN) {
        if (!ascii2u8s(str, res, sizeof(bxi_uuid_t), 0))
            return false;
    }
    else if (bxi_strlen(str) == UUID_STRLEN_HYPHEN) {
        if (!hyphen2uuid(str, res))
            return false;
    }
    else if (bxi_strlen(str) == UUID_STRLEN_URN) {
        if (bxi_strstr(str, UUID_URN_PREFIX) != str)
            return false;

        str += bxi_strlen(UUID_URN_PREFIX);

        if (!hyphen2uuid(str, res))
            return false;
    }
    else if (bxi_strlen(str) == UUID_STRLEN_CURLY) {
        if ((str[0] != '{') || (str[UUID_STRLEN_CURLY - 1] != '}'))
            return false;

        str++;

        if (!hyphen2uuid(str, res))
            return false;
    }
    else
        return false;

    return true;
}

char * uuidremurn(char * uuid) {
    if (bxi_strlen(uuid) < bxi_strlen(UUID_URN_PREFIX))
        return uuid;

    if (!bxi_strstr(uuid, UUID_URN_PREFIX))
        return uuid;

    bxi_memmove(uuid, uuid + bxi_strlen(UUID_URN_PREFIX),
            bxi_strlen(uuid) - bxi_strlen(UUID_URN_PREFIX) + 1);

    return uuid;
}

