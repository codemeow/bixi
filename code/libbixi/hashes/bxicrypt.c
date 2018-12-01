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

#include "../hashes/bxicrypt.h"
#include "../strings/bxistrconv.h"
#include "../strings/bxistring.h"
#include "../utils/bximemutils.h"

static void bxi_salt(u32 len, u8 * data, const char * salt) {
    const char * sptr = salt;
    while (len--) {
        *data += (u8)(*sptr);
        data++;
        sptr++;
        if (!sptr)
            sptr = salt;
    }
}

static void bxi_desalt(u32 len, u8 * data, const char * salt) {
    const char * sptr = salt;
    while (len--) {
        *data -= (u8)(*sptr);
        data++;
        sptr++;
        if (!sptr)
            sptr = salt;
    }
}

static void bxi_xor(u32 len, u8 * data, const char * key) {
    const char * kptr = key;
    while (len--) {
        *data ^= (u8)(*kptr);
        data++;
        kptr++;
        if (!kptr)
            kptr = key;
    }
}

void bxi_crypt(const char * string, const char * salt, const char * key, char * out) {
    /* @todo might be rewritten with static buffer
     * appending  to final string to avoid dynamic
     * memory allocation */

    u32  len = bxi_strlen(string);
    u8 * raw = bxi_malloc(len * 2);

    bxi_strcpy((char *)raw, string);

    bxi_salt(len, raw, salt);
    bxi_xor (len, raw, key );

    bxi_raw2hex(out, raw, len, BXI_HEX_CASE_LOW);

    bxi_free(raw);
}

void bxi_decrypt(const char * hexstring, const char * salt, const char * key, char * out) {
    /* Same for this one */
    u32 len = bxi_strlen(hexstring) / 2;
    u8 * raw = bxi_malloc(len + 1);
    raw[len] = '\0';

    bxi_hex2raw(hexstring, raw);

    bxi_desalt(len, raw, salt);
    bxi_xor   (len, raw, key );

    bxi_strcpy(out, (char *)raw);

    bxi_free(raw);
}
