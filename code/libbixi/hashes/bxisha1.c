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

#include "../hashes/bxisha1.h"
#include "../strings/bxistring.h"
#include "../utils/bxibitutils.h"
#include "../utils/bximemutils.h"
#include "../math/bximath.h"
#include "../types/bxiboints.h"
#include "../hashes/bxiuuid.h"

#define SHA1_OPERATIONS (4)
#define SHA1_BLOCK_SIZE_BITS (512)
#define SHA1_BLOCK_PSIZE_BITS (SHA1_BLOCK_SIZE_BITS - 64)
#define SHA1_BLOCK_SIZE_BYTES (SHA1_BLOCK_SIZE_BITS / BITS_IN_U8)
#define SHA1_BLOCK_PSIZE_U32 (SHA1_BLOCK_PSIZE_BITS / BITS_IN_U32)

static const u32 sha1_inits[SHA1_STEP_COUNT] = {
    0x67452301u, 0xefcdab89u, 0x98badcfeu, 0x10325476u, 0xc3d2e1f0u
};

static const u32 sha1_k[SHA1_OPERATIONS] = {
    0x5a827999u, 0x6ed9eba1u, 0x8f1bbcdcu, 0xca62c1d6u
};

typedef u32 (*sha1_func_1234)(u32, u32, u32);

static u32 sha1_1(u32 x, u32 y, u32 z) { return ((x & y) | (~x & z));          }
static u32 sha1_2(u32 x, u32 y, u32 z) { return (x ^ y ^ z);                   }
static u32 sha1_3(u32 x, u32 y, u32 z) { return ((x & y) | (x & z) | (y & z)); }

static const sha1_func_1234 sha1_funcs[SHA1_OPERATIONS] = { sha1_1, sha1_2, sha1_3, sha1_2 };

void sha1_init(sha1_t * sha1)
{
    if (!sha1)
        return;

    bxi_memset(sha1, 0, sizeof(sha1_t));
    bxi_memcpy(sha1->h, sha1_inits, sizeof(sha1->h));
}

static void sha1_enlarge(sha1_t * sha1, u32 len)
{
    if (sha1->totl[0] > (0xffffffffu - len)) sha1->totl[1]++;
    sha1->totl[0] += len;
}

#define sha1_process_org(SHA1, I, ARRAY, F, K, A, B, C, D, E)  \
{                                                              \
    temp = bxi_chgend32(SHA1->w[(I) % 16]);                    \
    ARRAY[(I) % 16] = temp;                                    \
                                                               \
    E += temp + bxi_rotl32(A, 5) + F(B, C, D) + K;             \
    B = bxi_rotl32(B, 30);                                     \
}

#define sha1_process_mix(SHA1, I, ARRAY, F, K, A, B, C, D, E)  \
{                                                              \
    temp = bxi_rotl32(ARRAY[((I) + 13) % 16] ^                 \
                      ARRAY[((I) + 8)  % 16] ^                 \
                      ARRAY[((I) + 2)  % 16] ^                 \
                      ARRAY[ (I)       % 16], 1);              \
    ARRAY[(I) % 16] = temp;                                    \
                                                               \
    E += temp + bxi_rotl32(A, 5) + F(B, C, D) + K;             \
    B = bxi_rotl32(B, 30);                                     \
}

static void sha1_process(sha1_t * sha1)
{
    u32 a, b, c, d, e;

    u32 array[16];
    u32 i = 0;
    u32 ki = 0;
    sha1_func_1234 f = sha1_1;
    u32            k = sha1_k[ki];
    u32 temp;

    a = sha1->h[0];
    b = sha1->h[1];
    c = sha1->h[2];
    d = sha1->h[3];
    e = sha1->h[4];

    for (i = 0; i < 80; i += 5)
    {
        if (i % 20 == 0)
        {
            f = sha1_funcs[ki];
            k = sha1_k[ki];
            ki++;
        }

        if (i < 15)
        {
            sha1_process_org(sha1, (i+0), array, f, k, a, b, c, d, e);
            sha1_process_org(sha1, (i+1), array, f, k, e, a, b, c, d);
            sha1_process_org(sha1, (i+2), array, f, k, d, e, a, b, c);
            sha1_process_org(sha1, (i+3), array, f, k, c, d, e, a, b);
            sha1_process_org(sha1, (i+4), array, f, k, b, c, d, e, a);
        }
        else if (i < 20)
        {
            sha1_process_org(sha1, (i+0), array, f, k, a, b, c, d, e);
            sha1_process_mix(sha1, (i+1), array, f, k, e, a, b, c, d);
            sha1_process_mix(sha1, (i+2), array, f, k, d, e, a, b, c);
            sha1_process_mix(sha1, (i+3), array, f, k, c, d, e, a, b);
            sha1_process_mix(sha1, (i+4), array, f, k, b, c, d, e, a);
        }
        else
        {
            sha1_process_mix(sha1, (i+0), array, f, k, a, b, c, d, e);
            sha1_process_mix(sha1, (i+1), array, f, k, e, a, b, c, d);
            sha1_process_mix(sha1, (i+2), array, f, k, d, e, a, b, c);
            sha1_process_mix(sha1, (i+3), array, f, k, c, d, e, a, b);
            sha1_process_mix(sha1, (i+4), array, f, k, b, c, d, e, a);
        }
    }

    sha1->h[0] += a;
    sha1->h[1] += b;
    sha1->h[2] += c;
    sha1->h[3] += d;
    sha1->h[4] += e;
}

void sha1_append(sha1_t * sha1, const u8 * data, u32 len)
{
    u32 left;
    u32 fprt;

    if (!sha1)
        return;
    if (!data)
        return;

    left = SHA1_BLOCK_SIZE_BYTES - sha1->leng;

    /* preappended */
    fprt = BXI_MIN(left, len);
    bxi_memcpy((u8 *)&sha1->w[sha1->leng / sizeof(u32)] + sha1->leng % sizeof(u32),
               data, fprt);
    sha1->leng += fprt;
    len        -= fprt;
    data       += fprt;
    if (sha1->leng == SHA1_BLOCK_SIZE_BYTES)
    {
        sha1_process(sha1);
        sha1_enlarge(sha1, SHA1_BLOCK_SIZE_BITS);
        sha1->leng = 0;
    }
    /* blocks */
    while (len / SHA1_BLOCK_SIZE_BYTES)
    {
        bxi_memcpy(sha1->w, data, SHA1_BLOCK_SIZE_BYTES);
        sha1_process(sha1);
        sha1_enlarge(sha1, SHA1_BLOCK_SIZE_BITS);
        len  -= SHA1_BLOCK_SIZE_BYTES;
        data += SHA1_BLOCK_SIZE_BYTES;
    }
    /* lefties */
    if (len)
    {
        bxi_memcpy(sha1->w, data, len);
        sha1->leng += len;
    }
}

void sha1_appendstr(sha1_t * sha1, const char * str)
{
    sha1_append(sha1, (const u8 *)str, bxi_strlen(str));
}

void sha1_appendi8(sha1_t * sha1, i8 num)
{
    sha1_append(sha1, (const u8 *)&num, sizeof(num));
}

void sha1_appendu8(sha1_t * sha1, u8 num)
{
    sha1_append(sha1, (const u8 *)&num, sizeof(num));
}

void sha1_appendi16(sha1_t * sha1, i16 num)
{
    sha1_append(sha1, (const u8 *)&num, sizeof(num));
}

void sha1_appendu16(sha1_t * sha1, u16 num)
{
    sha1_append(sha1, (const u8 *)&num, sizeof(num));
}

void sha1_appendi32(sha1_t * sha1, i32 num)
{
    sha1_append(sha1, (const u8 *)&num, sizeof(num));
}

void sha1_final(sha1_t * sha1)
{
    u32 i;
    u32 tp;

    if (!sha1)
        return;

    i = sha1->leng;
    *((u8 *)&sha1->w[i++ / sizeof(u32)] + sha1->leng % sizeof(u32)) = 0x80;

    bxi_memset32((u8 *)sha1->w + i, 0,
               ((sha1->leng < SHA1_BLOCK_PSIZE_BITS / sizeof(u32) ?
                             SHA1_BLOCK_PSIZE_BITS / sizeof(u32) :
                             SHA1_BLOCK_SIZE_BITS  / sizeof(u32)) - i) / sizeof(u32));

    sha1_enlarge(sha1, 8 * sha1->leng);
    tp            = bxi_chgend32(sha1->totl[0]);
    sha1->totl[0] = bxi_chgend32(sha1->totl[1]);
    sha1->totl[1] = tp;
    bxi_memcpy(sha1->w + SHA1_BLOCK_PSIZE_U32, sha1->totl, sizeof(sha1->totl));

    sha1_process(sha1);

    for (i = 0; i < SHA1_STEP_COUNT; i++)
        sha1->h[i] = bxi_chgend32(sha1->h[i]);

    bxi_memcpy(sha1->hash, sha1->h, sizeof(sha1->hash));
}

void sha12str(sha1_t * sha1, char * out)
{
    u32 i;

    if (!sha1)
        return;

    for (i = 0; i < SHA1_SIZE; i++)
        uuid_appendhex(sha1->hash[i], out + i * 2);
    out[i * 2] = '\0';
}
