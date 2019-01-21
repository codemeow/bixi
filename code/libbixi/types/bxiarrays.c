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

#include "../types/bxiarrays.h"
#include "../utils/bximemutils.h"
#include "../definitions/bximacros.h"
#include "../serials/bxiserwrite.h"
#include "../strings/bxistring.h"
#include "../math/bximath.h"

bxi_bts * bxi_bts_create(u32 size) {
    bxi_bts * res = bxi_malloc(sizeof(bxi_bts));
    if (!res)
        return NULL;
    res->data = bxi_malloc(size);
    res->size = size;

    return res;
}

bxi_bts * bxi_bts_resize(bxi_bts * bts, u32 size) {
    if (!bts)
        return NULL;

    if (bts->size == size)
        return bts;

    bts->data = bxi_realloc(bts->data, size);
    if (bts->size < size)
        bxi_memset(bts->data + bts->size, 0, size - bts->size);
    bts->size = size;
    return bts;
}

void bxi_bts_free(bxi_bts * bts) {
    if (!bts)
        return;

    bxi_free(bts->data);
    bts->data = NULL;
    bts->size = 0;
    bxi_free(bts);
}

bxi_bts * bxi_bts_append(bxi_bts * dst, bxi_bts * src) {
    return bxi_bts_insert(dst, src, dst->size);
}

bxi_bts * bxi_bts_walk(bxi_bts * bts, bxi_bts_trav_t func) {
    u32 i;
    if (!bts)
        return NULL;

    for (i = 0; i < bts->size; i++)
        func(bts, i, &bts->data[i]);

    return bts;
}

i32 bxi_bts_search(bxi_bts * bts, u8 value) {
    u32 i;

    if (!bts)
        return -1;

    for (i = 0; i < bts->size; i++)
        if (bts->data[i] == value)
            return i;

    return -1;
}

bxi_bts * bxi_bts_insert(bxi_bts * dst, bxi_bts * src, u32 pos) {
    u32 os;
    if (!dst)
        return NULL;
    if (!src)
        return dst;

    os = dst->size;
    if (os < pos)
        bxi_bts_resize(dst, pos + src->size);
    else
        bxi_bts_resize(dst, os + src->size);

    bxi_memmove(dst->data + pos + src->size, dst->data + pos, os - pos);
    bxi_memcpy (dst->data + pos, src->data, src->size);

    return dst;
}

bxi_bts * bxi_bts_delete(bxi_bts * dst, u32 pos, u32 cnt) {
    if (!dst)
        return NULL;

    if (!cnt)
        return dst;
    if (pos > dst->size)
        return dst;

    if (pos + cnt > dst->size)
        bxi_bts_resize(dst, pos);
    else {
        bxi_memmove(dst->data + pos, dst->data + pos + cnt, dst->size - pos - cnt);
        bxi_bts_resize(dst, dst->size - cnt);
    }

    return dst;
}

bxi_bts * bxi_bts_lshift(bxi_bts * dst, u32 c) {
    if (!dst)
        return NULL;

    if (c >= dst->size) {
        dst->size = 0;
        return dst;
    }

    bxi_memmove(dst->data, dst->data + c, dst->size - c);
    dst->size -= c;
    return dst;
}

bxi_bts * bxi_bts_append_u8(bxi_bts * bts, u8 value) {
    if (!bts)
        return NULL;

    bxi_bts_resize(bts, bts->size + sizeof(value));
    bxi_write_u8(value, bts->data + bts->size - sizeof(value));

    return bts;
}

bxi_bts * bxi_bts_append_i8(bxi_bts * bts, i8 value) {
    if (!bts)
        return NULL;

    bxi_bts_resize(bts, bts->size + sizeof(value));
    bxi_write_i8(value, bts->data + bts->size - sizeof(value));

    return bts;
}

bxi_bts * bxi_bts_append_u16(bxi_bts * bts, u16 value) {
    if (!bts)
        return NULL;

    bxi_bts_resize(bts, bts->size + sizeof(value));
    bxi_write_u16(value, bts->data + bts->size - sizeof(value));

    return bts;
}

bxi_bts * bxi_bts_append_i16(bxi_bts * bts, i16 value) {
    if (!bts)
        return NULL;

    bxi_bts_resize(bts, bts->size + sizeof(value));
    bxi_write_i16(value, bts->data + bts->size - sizeof(value));

    return bts;
}

bxi_bts * bxi_bts_append_u32(bxi_bts * bts, u32 value) {
    if (!bts)
        return NULL;

    bxi_bts_resize(bts, bts->size + sizeof(value));
    bxi_write_u32(value, bts->data + bts->size - sizeof(value));

    return bts;
}

bxi_bts * bxi_bts_append_i32(bxi_bts * bts, i32 value) {
    if (!bts)
        return NULL;

    bxi_bts_resize(bts, bts->size + sizeof(value));
    bxi_write_i32(value, bts->data + bts->size - sizeof(value));

    return bts;
}

bxi_bts * bxi_bts_append_u16_le(bxi_bts * bts, u16_le value) {
    if (!bts)
        return NULL;

    bxi_bts_resize(bts, bts->size + sizeof(value));
    bxi_write_u16_le(value, bts->data + bts->size - sizeof(value));

    return bts;
}

bxi_bts * bxi_bts_append_i16_le(bxi_bts * bts, i16_le value) {
    if (!bts)
        return NULL;

    bxi_bts_resize(bts, bts->size + sizeof(value));
    bxi_write_i16_le(value, bts->data + bts->size - sizeof(value));

    return bts;
}

bxi_bts * bxi_bts_append_u16_be(bxi_bts * bts, u16_be value) {
    if (!bts)
        return NULL;

    bxi_bts_resize(bts, bts->size + sizeof(value));
    bxi_write_u16_be(value, bts->data + bts->size - sizeof(value));

    return bts;
}

bxi_bts * bxi_bts_append_i16_be(bxi_bts * bts, i16_be value) {
    if (!bts)
        return NULL;

    bxi_bts_resize(bts, bts->size + sizeof(value));
    bxi_write_i16_le(value, bts->data + bts->size - sizeof(value));

    return bts;
}

bxi_bts * bxi_bts_append_u32_le(bxi_bts * bts, u32_le value) {
    if (!bts)
        return NULL;

    bxi_bts_resize(bts, bts->size + sizeof(value));
    bxi_write_u32_le(value, bts->data + bts->size - sizeof(value));

    return bts;
}

bxi_bts * bxi_bts_append_i32_le(bxi_bts * bts, i32_le value) {
    if (!bts)
        return NULL;

    bxi_bts_resize(bts, bts->size + sizeof(value));
    bxi_write_i32_le(value, bts->data + bts->size - sizeof(value));

    return bts;
}

bxi_bts * bxi_bts_append_u32_be(bxi_bts * bts, u32_be value) {
    if (!bts)
        return NULL;

    bxi_bts_resize(bts, bts->size + sizeof(value));
    bxi_write_u32_be(value, bts->data + bts->size - sizeof(value));

    return bts;
}

bxi_bts * bxi_bts_append_i32_be(bxi_bts * bts, i32_be value) {
    if (!bts)
        return NULL;

    bxi_bts_resize(bts, bts->size + sizeof(value));
    bxi_write_i32_be(value, bts->data + bts->size - sizeof(value));

    return bts;
}

bxi_bts * bxi_bts_append_string(bxi_bts * bts, const char * value) {
    u32 len = bxi_strlen(value);

    if (!bts)
        return NULL;

    bxi_bts_resize(bts, bts->size + len);
    bxi_memcpy(bts->data + bts->size - len, value, len);

    return bts;
}

bxi_bts * bxi_bts_append_string_fixed(bxi_bts * bts, const char * value, u32 size, char filler) {
    u32 len = bxi_strlen(value);

    if (!bts)
        return NULL;

    bxi_bts_resize(bts, bts->size + size);
    bxi_memset(bts->data + bts->size - size, filler, size);
    bxi_memcpy(bts->data + bts->size - size, value, BXI_MIN(len, size));

    return bts;
}

bxi_bts * bxi_bts_append_uuid(bxi_bts * bts, bxi_uuid_t value) {
    if (!bts)
        return NULL;

    bxi_bts_resize(bts, bts->size + UUID_SIZE);
    bxi_memcpy(bts->data + bts->size - UUID_SIZE, value, UUID_SIZE);

    return bts;
}

bxi_bts * bxi_uuid2bts(bxi_uuid_t uuid) {
    bxi_bts * result = bxi_bts_create(sizeof(bxi_uuid_t));
    u32 i;
    if (!result)
        return NULL;

    for (i = 0; i < sizeof(bxi_uuid_t); i++)
        result->data[i] = uuid[i];
    return result;
}

