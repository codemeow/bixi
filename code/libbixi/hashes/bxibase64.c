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

#include "../hashes/bxibase64.h"
#include "../math/bximath.h"
#include "../definitions/bximacros.h"
#include "../utils/bximemutils.h"
#include "../strings/bxistring.h"

#define BASE64_PAD (64)

static const u8 rfc_map[BXI_BASE64_COUNT][BASE64_PAD + 1] = {
    /* BXI_BASE64_RFC1421  */ "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=",
    /* BXI_BASE64_RFC2045  */ "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=",
    /* BXI_BASE64_RFC3548  */ "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=",
    /* BXI_BASE64_Y64      */ "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789._-",
    /* BXI_BASE64_XMLTOKEN */ "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789.-\0",
    /* BXI_BASE64_XMLNAME  */ "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_:\0",
    /* BXI_BASE64_PIDENT1  */ "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_-\0",
    /* BXI_BASE64_PIDENT2  */ "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789._\0",
    /* BXI_BASE64_FREENET  */ "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789~-=",
    /* BXI_BASE64_RFC4880  */ "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=",
    /* BXI_BASE64_RFC1642  */ "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/\0",
    /* BXI_BASE64_RFC3501  */ "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+,\0"
};

void bxi_bin2base64(u8 * in, u32 len, char * out, bxi_base64_rfc rfc)
{
    if (!out)
        return;

    if ((!in) || (!len) || (rfc >= BXI_BASE64_COUNT))
    {
        out[0] = '\0';
        return;
    }

    while (len)
    {
        out[0] = rfc_map[rfc][in[0] >> 2];
        out[1] = rfc_map[rfc][((in[0] & 3) << 4) | (len > 1 ? (in[1] >> 4) : 0)];
        out[2] = len > 1 ? rfc_map[rfc][(((in[1] & 0xf) << 2) | (len > 2 ? (in[2] >> 6) : 0))] : rfc_map[rfc][BASE64_PAD];
        out[3] = len > 2 ? rfc_map[rfc][in[2] & 0x3f] : rfc_map[rfc][BASE64_PAD];

        out += BXI_BASE64_ENC_SIZE;
        in  += BXI_BASE64_DEC_SIZE;
        len -= BXI_MIN(BXI_BASE64_DEC_SIZE, len);
    }

    *out = '\0';
}

bxi_bts * bxi_base642bin(const char * in, bxi_base64_rfc rfc) {
    bxi_bts * res;
    char decoder[BXI_ASCII_MAX + 1];
    u32 i;
    u32 count = 0;
    u32 pad = 0;
    u8  quad[4];
    const char * buff = in;

    if (!in)
        return NULL;

    bxi_memset(decoder, -1, BXI_ASCII_MAX + 1);
    for (i = 0; i < BASE64_PAD + 1; i++)
        decoder[rfc_map[rfc][i]] = (char)i;
    decoder[rfc_map[rfc][BASE64_PAD]] = 0;

    while (*buff)
        if (decoder[(u8)*buff++] != -1)
            count++;

    if ((count == 0) || (count % 4))
        return NULL;

    res = bxi_bts_create(count / BXI_BASE64_ENC_SIZE * BXI_BASE64_DEC_SIZE);
    res->size = 0;

    count = 0;
    while (*in) {
        if (decoder[(u8)*in] == -1)
            continue;

        if (*in == rfc_map[rfc][BASE64_PAD])
            pad++;

        quad[count] = decoder[(u8)*in];
        count++;

        if (count == 4) {
            res->data[res->size++] = (quad[0] << 2) | (quad[1] >> 4);
            res->data[res->size++] = (quad[1] << 4) | (quad[2] >> 2);
            res->data[res->size++] = (quad[2] << 6) | (quad[3]);

            count = 0;

            if (pad) {
                if (pad == 1)
                    res->size--;
                else if (pad == 2)
                    res->size -= 2;
                else {
                    bxi_bts_free(res);
                    return NULL;
                }
                break;
            }
        }

        in++;
    }

    /* Append \0, to be able to process res.data as string */
    bxi_bts_append_u8(res, 0);
    return res;
}
