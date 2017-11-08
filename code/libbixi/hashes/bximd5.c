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

#include "../hashes/bximd5.h"
#include "../utils/bximemutils.h"
#include "../utils/bxibitutils.h"
#include "../strings/bxistring.h"

#define STEP_COUNT (4)

static const u8 md5_shifts[MD5_SIZE * STEP_COUNT] = {
    7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,
    5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,
    4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,
    6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21
};

static const u32 md5_sins[MD5_SIZE * STEP_COUNT] = {
    0xd76aa478u, 0xe8c7b756u, 0x242070dbu, 0xc1bdceeeu,
    0xf57c0fafu, 0x4787c62au, 0xa8304613u, 0xfd469501u,
    0x698098d8u, 0x8b44f7afu, 0xffff5bb1u, 0x895cd7beu,
    0x6b901122u, 0xfd987193u, 0xa679438eu, 0x49b40821u,
    0xf61e2562u, 0xc040b340u, 0x265e5a51u, 0xe9b6c7aau,
    0xd62f105du, 0x02441453u, 0xd8a1e681u, 0xe7d3fbc8u,
    0x21e1cde6u, 0xc33707d6u, 0xf4d50d87u, 0x455a14edu,
    0xa9e3e905u, 0xfcefa3f8u, 0x676f02d9u, 0x8d2a4c8au,
    0xfffa3942u, 0x8771f681u, 0x6d9d6122u, 0xfde5380cu,
    0xa4beea44u, 0x4bdecfa9u, 0xf6bb4b60u, 0xbebfbc70u,
    0x289b7ec6u, 0xeaa127fau, 0xd4ef3085u, 0x04881d05u,
    0xd9d4d039u, 0xe6db99e5u, 0x1fa27cf8u, 0xc4ac5665u,
    0xf4292244u, 0x432aff97u, 0xab9423a7u, 0xfc93a039u,
    0x655b59c3u, 0x8f0ccc92u, 0xffeff47du, 0x85845dd1u,
    0x6fa87e4fu, 0xfe2ce6e0u, 0xa3014314u, 0x4e0811a1u,
    0xf7537e82u, 0xbd3af235u, 0x2ad7d2bbu, 0xeb86d391u
};

static const u32 md5_inits[STEP_COUNT] = {
    0x67452301u, 0xefcdab89u, 0x98badcfeu, 0x10325476u
};

typedef u32 (*md5_func_fghi)(u32, u32, u32);
typedef u32 (*md5_func_1234)(u32);

static u32 md5_F(u32 x, u32 y, u32 z) { return ((x & y) | (~x & z)); }
static u32 md5_G(u32 x, u32 y, u32 z) { return ((x & z) | (y & ~z)); }
static u32 md5_H(u32 x, u32 y, u32 z) { return (x ^ y ^ z);          }
static u32 md5_I(u32 x, u32 y, u32 z) { return (y ^ (x | ~z));       }

static u32 md5_1(u32 i) { return      i                ; }
static u32 md5_2(u32 i) { return (5 * i + 1) % MD5_SIZE; }
static u32 md5_3(u32 i) { return (3 * i + 5) % MD5_SIZE; }
static u32 md5_4(u32 i) { return (7 * i    ) % MD5_SIZE; }

static const md5_func_fghi md5_fghi[STEP_COUNT] = { md5_F, md5_G, md5_H, md5_I };
static const md5_func_1234 md5_1234[STEP_COUNT] = { md5_1, md5_2, md5_3, md5_4 };

static void md5_enlarge(md5_t * md5, u32 len)
{
    if (md5->totl[0] > (0xffffffffu - len)) md5->totl[1]++;
    md5->totl[0] += len;
}

static void md5_process(md5_t * md5)
{
    u32 abcd[4];
    u32 block[16];
    u32 i;

    bxi_memcpy(block, md5->data, MD5_SIZE * sizeof(u32));
    bxi_memcpy( abcd, md5->abcd, MD5_SIZE);

    for (i = 0; i < MD5_SIZE * STEP_COUNT; i++)
    {
        u32 dt, F;
        F = md5_fghi[i / MD5_SIZE](abcd[1], abcd[2], abcd[3]);

        dt = abcd[3];
        abcd[3] = abcd[2];
        abcd[2] = abcd[1];
        abcd[1] = abcd[1] + bxi_rotl32(abcd[0] + F + md5_sins[i] +
                  block[md5_1234[i / MD5_SIZE](i)], md5_shifts[i]);
        abcd[0] = dt;
    }

    for (i = 0; i < 4; i++)
        md5->abcd[i] += abcd[i];
}

void md5_init(md5_t * md5)
{
    bxi_memset(md5, 0, sizeof(md5_t));
    bxi_memcpy(md5->abcd, md5_inits, STEP_COUNT * sizeof(u32));
}

void md5_appendstr(md5_t * md5, const char * str)
{
    md5_append(md5, (const u8 *)str, bxi_strlen(str));
}

void md5_appendi8(md5_t * md5, i8 num)
{
    md5_append(md5, (const u8 *)&num, sizeof(num));
}

void md5_appendu8(md5_t * md5, u8 num)
{
    md5_append(md5, (const u8 *)&num, sizeof(num));
}

void md5_appendi16(md5_t * md5, i16 num)
{
    md5_append(md5, (const u8 *)&num, sizeof(num));
}

void md5_appendu16(md5_t * md5, u16 num)
{
    md5_append(md5, (const u8 *)&num, sizeof(num));
}

void md5_appendi32(md5_t * md5, i32 num)
{
    md5_append(md5, (const u8 *)&num, sizeof(num));
}

void md5_appendu32(md5_t * md5, u32 num)
{
    md5_append(md5, (const u8 *)&num, sizeof(num));
}

void md5_append(md5_t * md5, const u8 * data, u32 length)
{
    u32 i;
    for (i = 0; i < length; i++)
    {
        md5->data[md5->leng++] = data[i];
        if (md5->leng == (MD5_SIZE * sizeof(u32)))
        {
            md5_process(md5);
            md5_enlarge(md5, 0x200);
            md5->leng = 0;
        }
    }
}

void md5_final(md5_t * md5)
{
    u32 i = md5->leng;
    md5->data[i++] = 0x80;

    bxi_memset(md5->data + i, 0,
               (md5->leng < (MD5_SIZE * 4 - sizeof(u32) * 2) ?
                            (MD5_SIZE * 4 - sizeof(u32) * 2) :
                            (MD5_SIZE * 4)) - i);

    if (md5->leng >= (MD5_SIZE * STEP_COUNT - sizeof(u32) * 2))
    {
        md5_process(md5);
        bxi_memset(md5->data, 0, (MD5_SIZE * STEP_COUNT - sizeof(u32) * 2));
    }

    md5_enlarge(md5, 8 * md5->leng);
    bxi_memcpy(md5->data + (MD5_SIZE * STEP_COUNT - sizeof(u32) * 2), md5->totl, 8);
    md5_process(md5);

    bxi_memcpy(md5->hash, md5->abcd, STEP_COUNT * sizeof(u32));
}

void md5_copy(md5_t * md5, u8 * out)
{
    if ((!md5) || (!out))
        return;

    bxi_memcpy(out, md5->abcd, MD5_SIZE);
}
