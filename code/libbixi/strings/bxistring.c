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

#include "../strings/bxistring.h"
#include "../utils/bxibitutils.h"
#include "../utils/bximemutils.h"

#define FNV_VALUE_START (0x811c9dc5u)
#define FNV_VALUE_STEP  (0x01000193u)

#define ASCII_UPPERLOWER_DIFF ('A' - 'a')

typedef enum
{
    BXI_IS_ASCII_CNTRL, BXI_IS_ASCII_PRINT, BXI_IS_ASCII_SPACE,
    BXI_IS_ASCII_BLANK, BXI_IS_ASCII_GRAPH, BXI_IS_ASCII_PUNCT,
    BXI_IS_ASCII_ALNUM, BXI_IS_ASCII_ALPHA, BXI_IS_ASCII_UPPER,
    BXI_IS_ASCII_LOWER, BXI_IS_ASCII_DIGIT, BXI_IS_ASCII_XDIGIT,

    BXI_IS_ASCII_COUNT
} bxi_isasciifuncs;

static const u32 bxi_isasciitable
    [ BXI_IS_ASCII_COUNT                 ]
    [(BXI_IS_ASCII_MAX + 1) / BITS_IN_U32] = {
    {0xffffffffu, 0x00000000u, 0x00000000u, 0x80000000u}, /* CNTRL  */
    {0x00000000u, 0xffffffffu, 0xffffffffu, 0x7fffffffu}, /* PRINT  */
    {0x00003e00u, 0x00000001u, 0x00000000u, 0x00000000u}, /* SPACE  */
    {0x00000200u, 0x00000001u, 0x00000000u, 0x00000000u}, /* BLANK  */
    {0x00000000u, 0xfffffffeu, 0xffffffffu, 0x7fffffffu}, /* GRAPH  */
    {0x00000000u, 0xfc00fffeu, 0xf8000001u, 0x78000001u}, /* PUNCT  */
    {0x00000000u, 0x03ff0000u, 0x07fffffeu, 0x07fffffeu}, /* ALNUM  */
    {0x00000000u, 0x00000000u, 0x07fffffeu, 0x07fffffeu}, /* ALPHA  */
    {0x00000000u, 0x00000000u, 0x07fffffeu, 0x00000000u}, /* UPPER  */
    {0x00000000u, 0x00000000u, 0x00000000u, 0x07fffffeu}, /* LOWER  */
    {0x00000000u, 0x03ff0000u, 0x00000000u, 0x00000000u}, /* DIGIT  */
    {0x00000000u, 0x03ff0000u, 0x0000007eu, 0x0000007eu}, /* XDIGIT */
};

u32 bxi_strlen(const char * str)
{
    u32 res = 0;

    if (!str)
        return 0;

    while (str[res])
        res++;

    return res;
}

i32 bxi_strcmp(const char * str1, const char * str2)
{
    u8 c1, c2;

    if (!str1 && !str2) return 0;
    if (!str1 &&  str2) return -(*str2);
    if ( str1 && !str2) return +(*str1);

    do
    {
        c1 = (u8)*str1;
        c2 = (u8)*str2;

        if (!c1)
            return c1 - c2;

        str1++;
        str2++;
    }
    while (c1 == c2);

    return c1 - c2;
}

bxi_hash strhash(const char * str)
{
    /* FNV */
    bxi_hash hash = FNV_VALUE_START;

    if (!str)
        return hash;

    while (*str)
    {
        hash ^= (bxi_hash)*str++;
        hash *= (bxi_hash)FNV_VALUE_STEP;
    }

    return hash;
}

char * strtriml(char * str)
{
    u32 first = 0;

    if (!str)
        return str;

    while (isasciispace(str[first])) first++;

    strshiftl(str, first);

    return str;
}

char * strtrimr(char * str)
{
    u32 len = bxi_strlen(str);

    if (!len)
        return str;

    while (isasciispace(str[len - 1])) len--;

    str[len] = '\0';

    return str;
}

char * strtrim(char * str)
{
    strtriml(str);
    strtrimr(str);

    return str;
}

char * strshiftl(char * str, u32 count)
{
    if (!str)
        return str;
    if (!count)
        return str;

    bxi_memmove(str, str + count, bxi_strlen(str) - count + 1);
    return str;
}

const char * strparam(const char * str, i32 * len)
{
    u32 pos = 0;
    u8  qut = 0;

    if (!str)
    {
        if (len) *len = BXI_STRERROR_NOSTRING;
        return str;
    }

    while (isasciispace(*str))
    {
        str++;
    }

    if ((*str == '\'') ||
        (*str == '\"'))
    {
        qut = *str;
        str++;
    }

    while (str[pos])
    {
        if ((!qut) && (isasciispace(str[pos])))
            break;

        if ((qut) && (pos) && (str[pos] == qut) && (str[pos - 1] != '\\'))
            break;

        pos++;
    }

    if ((qut) && (!str[pos]))
    {
        if (len) *len = BXI_STRERROR_NOEND;
        return str;
    }

    if (len) *len = pos;
    return str;
}

static bool isasciigeneric(u32 c, bxi_isasciifuncs type)
{
    return getbit(bxi_isasciitable[type][c / BITS_IN_U32] , c % BITS_IN_U32);
}

bool isasciicntrl(u32 c)
{
    return c <= BXI_IS_ASCII_MAX ? isasciigeneric(c, BXI_IS_ASCII_CNTRL) : 0;
}

bool isasciiprint(u32 c)
{
    return c <= BXI_IS_ASCII_MAX ? isasciigeneric(c, BXI_IS_ASCII_PRINT) : 0;
}

bool isasciispace(u32 c)
{
    return c <= BXI_IS_ASCII_MAX ? isasciigeneric(c, BXI_IS_ASCII_SPACE) : 0;
}

bool isasciiblank(u32 c)
{
    return c <= BXI_IS_ASCII_MAX ? isasciigeneric(c, BXI_IS_ASCII_BLANK) : 0;
}

bool isasciigraph(u32 c)
{
    return c <= BXI_IS_ASCII_MAX ? isasciigeneric(c, BXI_IS_ASCII_GRAPH) : 0;
}

bool isasciipunct(u32 c)
{
    return c <= BXI_IS_ASCII_MAX ? isasciigeneric(c, BXI_IS_ASCII_PUNCT) : 0;
}

bool isasciialnum(u32 c)
{
    return c <= BXI_IS_ASCII_MAX ? isasciigeneric(c, BXI_IS_ASCII_ALNUM) : 0;
}

bool isasciialpha(u32 c)
{
    return c <= BXI_IS_ASCII_MAX ? isasciigeneric(c, BXI_IS_ASCII_ALPHA) : 0;
}

bool isasciiupper(u32 c)
{
    return c <= BXI_IS_ASCII_MAX ? isasciigeneric(c, BXI_IS_ASCII_UPPER) : 0;
}

bool isasciilower(u32 c)
{
    return c <= BXI_IS_ASCII_MAX ? isasciigeneric(c, BXI_IS_ASCII_LOWER) : 0;
}

bool isasciidigit(u32 c)
{
    return c <= BXI_IS_ASCII_MAX ? isasciigeneric(c, BXI_IS_ASCII_DIGIT) : 0;
}

bool isasciixdigit(u32 c)
{
    return c <= BXI_IS_ASCII_MAX ? isasciigeneric(c, BXI_IS_ASCII_XDIGIT) : 0;
}

u32 toasciiupper(u32 c)
{
    if (isasciilower(c))
         return c - ASCII_UPPERLOWER_DIFF;
    else return c;
}

u32 toasciilower(u32 c)
{
    if (isasciilower(c))
         return c + ASCII_UPPERLOWER_DIFF;
    else return c;
}
