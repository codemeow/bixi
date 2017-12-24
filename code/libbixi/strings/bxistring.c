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

#include "../strings/bxistring.h"
#include "../utils/bxibitutils.h"
#include "../utils/bximemutils.h"
#include "../definitions/bximacros.h"
#include "../math/bximath.h"

#define FNV_VALUE_START (0x811c9dc5u)
#define FNV_VALUE_STEP  (0x01000193u)

#define ASCII_UPPERLOWER_DIFF ('a' - 'A')

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
            return c2;
        if (!c2)
            return c1;

        str1++;
        str2++;
    }
    while (c1 == c2);

    return c1 - c2;
}

i32 bxi_strncmp(const char * str1, const char * str2, u32 n)
{
    u8 c1, c2;

    if (!n)             return 0;
    if (!str1 && !str2) return 0;
    if (!str1 &&  str2) return -(*str2);
    if ( str1 && !str2) return +(*str1);

    do
    {
        c1 = (u8)*str1;
        c2 = (u8)*str2;

        if (!c1)
            return c1 - c2;

        n--;
        if (!n)
            break;

        if (!c1)
            return c1 - c2;

        str1++;
        str2++;
    }
    while (c1 == c2);

    return c1 - c2;
}

char * bxi_strcpy(char * dst, const char * src)
{
    if (!dst)
        return NULL;
    if (!src)
        return dst;

    while (*src)
    {
        *dst = *src;
        src++;
        dst++;
    }

    *dst = '\0';
    return dst;
}

char * bxi_strncpy(char * dst, const char * src, u32 n)
{
    u32 i;

    for (i = 0; (i < n) && (src[i] != '\0'); i++)
        dst[i] = src[i];

    while (i < n)
        dst[i++] = '\0';

    return dst;
}

char * bxi_strdup(const char * str)
{
    char * res;

    if (!str)
        return NULL;

    res = bxi_malloc(bxi_strlen(str) + 1);
    bxi_strcpy(res, str);

    return res;
}

char * bxi_strchr(const char * str, i32 c)
{
    if (!str)
        return NULL;

    while (*str)
    {
        if (*str == c)
            return (char *)str;

        str++;
    }

    return NULL;
}

char * bxi_strrchr(const char * str, i32 c)
{
    char * res = NULL;

    if (!str)
        return NULL;

    while (*str)
    {
        if (*str == c)
            res = (char *)str;

        str++;
    }

    return res;
}

char * bxi_strchrnul(const char * str, i32 c)
{
    if (!str)
        return NULL;

    while (*str)
    {
        if (*str == c)
            return (char *)str;

        str++;
    }

    return (char *)str;
}

bxi_hash bxi_strhash(const char * str)
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

char * bxi_strtriml(char * str)
{
    u32 first = 0;

    if (!str)
        return str;

    while (bxi_isspace(str[first])) first++;

    bxi_strshiftl(str, first);

    return str;
}

char * bxi_strtrimr(char * str)
{
    u32 len = bxi_strlen(str);

    if (!len)
        return str;

    while (bxi_isspace(str[len - 1])) len--;

    str[len] = '\0';

    return str;
}

char * bxi_strtrim(char * str)
{
    bxi_strtriml(str);
    bxi_strtrimr(str);

    return str;
}

char * bxi_strshiftl(char * str, u32 count)
{
    if (!str)
        return str;
    if (!count)
        return str;

    bxi_memmove(str, str + count, bxi_strlen(str) - count + 1);
    return str;
}

static bool isasciigeneric(u32 c, bxi_isasciifuncs type)
{
    return bxi_getbit(bxi_isasciitable[type][c / BITS_IN_U32] , c % BITS_IN_U32);
}

bool bxi_iscntrl(u32 c)
{
    return c <= BXI_IS_ASCII_MAX ? isasciigeneric(c, BXI_IS_ASCII_CNTRL) : 0;
}

bool bxi_isprint(u32 c)
{
    return c <= BXI_IS_ASCII_MAX ? isasciigeneric(c, BXI_IS_ASCII_PRINT) : 0;
}

bool bxi_isspace(u32 c)
{
    return c <= BXI_IS_ASCII_MAX ? isasciigeneric(c, BXI_IS_ASCII_SPACE) : 0;
}

bool bxi_isblank(u32 c)
{
    return c <= BXI_IS_ASCII_MAX ? isasciigeneric(c, BXI_IS_ASCII_BLANK) : 0;
}

bool bxi_isgraph(u32 c)
{
    return c <= BXI_IS_ASCII_MAX ? isasciigeneric(c, BXI_IS_ASCII_GRAPH) : 0;
}

bool bxi_ispunct(u32 c)
{
    return c <= BXI_IS_ASCII_MAX ? isasciigeneric(c, BXI_IS_ASCII_PUNCT) : 0;
}

bool bxi_isalnum(u32 c)
{
    return c <= BXI_IS_ASCII_MAX ? isasciigeneric(c, BXI_IS_ASCII_ALNUM) : 0;
}

bool bxi_isalpha(u32 c)
{
    return c <= BXI_IS_ASCII_MAX ? isasciigeneric(c, BXI_IS_ASCII_ALPHA) : 0;
}

bool bxi_isupper(u32 c)
{
    return c <= BXI_IS_ASCII_MAX ? isasciigeneric(c, BXI_IS_ASCII_UPPER) : 0;
}

bool bxi_islower(u32 c)
{
    return c <= BXI_IS_ASCII_MAX ? isasciigeneric(c, BXI_IS_ASCII_LOWER) : 0;
}

bool bxi_isdigit(u32 c)
{
    return c <= BXI_IS_ASCII_MAX ? isasciigeneric(c, BXI_IS_ASCII_DIGIT) : 0;
}

bool bxi_isxdigit(u32 c)
{
    return c <= BXI_IS_ASCII_MAX ? isasciigeneric(c, BXI_IS_ASCII_XDIGIT) : 0;
}

u32 bxi_2upper(u32 c)
{
    if (bxi_islower(c))
         return c - ASCII_UPPERLOWER_DIFF;
    else return c;
}

u32 bxi_2lower(u32 c)
{
    if (bxi_isupper(c))
         return c + ASCII_UPPERLOWER_DIFF;
    else return c;
}

void bxi_str2upper(char * str)
{
    if (!str)
        return;

    while (*str)
    {
        *str = (char)bxi_2upper(*str);
        str++;
    }
}

void bxi_str2lower(char * str)
{
    if (!str)
        return;

    while (*str)
    {
        *str = (char)bxi_2lower(*str);
        str++;
    }
}

/* Parses input string and fills output array by
 * substrings, separating by ' '. Escaping and quoting
 * is accepted. The original string is being changed */
/* Ex.:
 * Input:
 * str = aaa "b b b" ccc \'ddd eee\'
 * Output:
 * count = 5
 * output[0] = aaa
 * output[1] = "b b b"
 * output[2] = ccc
 * output[3] = 'ddd
 * output[4] = eee'
 */
/* @todo remove *count, only return */
u32 bxi_strprs(char * str, u32 * count, char ** output)
{
    u32 i = 0;
    u32 l = bxi_strlen(str);
    u32 escaped = 0;
    u32 quoted  = 0;
    char quote = ' ';

    if (!str)
        return 0;
    if (!count)
        return 0;

    while (bxi_isspace(str[i]))
        i++;
    if (i == l)
    {
        *count = 0;
        return 0;
    }

    *count = 1;
    if (output) output[0] = str + i;

    for (; i < l; i++)
    {
        switch (str[i])
        {
        case '\\':
            if (!escaped) escaped = 1;
                     else escaped = 0;
            break;
        case '\'':
        case '\"':
            if (!escaped)
            {
                if (!quoted)
                {
                    quoted = 1;
                    quote  = str[i];
                }
                else if (quote == str[i])
                    quoted = 0;
            }
            else
                escaped = 0;
            break;
        case ' ':
            if (!escaped)
            {
                if (!quoted)
                {
                    str[i] = '\0';
                    if ((!bxi_isspace(str[i + 1])) && (str[i + 1] != '\0'))
                    {
                        if (output) output[*count] = str + i + 1;
                        *count = *count + 1;
                    }
                }
            }
            else
                escaped = 0;
            break;
        default:
            escaped = 0;
        }
    }

    return *count;
}

char * bxi_strstr(const char * str, const char * sub)
{
    if (!str)
        return NULL;
    if (!sub)
        return NULL;

    while (*str)
    {
        const char * beg = str;
        const char * pat = sub;

        while (*str && *pat && *str == *pat)
        {
            str++;
            pat++;
        }

        if (!*pat)
            return (char *)beg;

        str = beg + 1;
    }
    return NULL;
}

char * bxi_strapp(char * dst, const char * src)
{
    u32 dst_len = 0;
    u32 src_len = 0;

    if (!src)
        return dst;
    if (!dst)
        return bxi_strdup(src);

    dst_len = bxi_strlen(dst);
    src_len = bxi_strlen(src);

    dst = bxi_realloc(dst, dst_len + src_len + 1);
    bxi_memcpy(dst + dst_len, src, src_len + 1);

    return dst;
}

char * bxi_strcat(char * dst, const char * src)
{
    u32 dst_l = 0;

    if (!dst)
        return NULL;
    if (!src)
        return dst;

    dst_l = bxi_strlen(dst);

    return (char *)bxi_memcpy(dst + dst_l, src, bxi_strlen(src) + 1) - dst_l;
}

char * bxi_strncat(char * dst, const char * src, u32 n)
{
    u32 src_len;
    u32 dst_len;

    if (!dst)
        return NULL;
    if (!src)
        return dst;

    src_len = bxi_strlen(src);
    dst_len = bxi_strlen(dst);

    if (src_len > n)
    {
        bxi_memcpy(dst + dst_len, src, n);
        dst[n + dst_len] = '\0';
        return dst;
    }
    else
        return bxi_memcpy(dst + dst_len, src, src_len + 1);
}

u32 bxi_strspn(const char * str, const char * lst)
{
    u32 res = 1;
    char map[BXI_FAST_DIV_8(BXI_ASCII_COUNT)] = { 0 };

    while (*lst)
        map[BXI_FAST_DIV_8(*lst)] |= 1 << (*lst % 8);

    while (*str)
    {
        if (!((map[BXI_FAST_DIV_8(*str)] >> (*str % 8)) & 1))
            break;
        res++;
        str++;
    }

    return res - 1;
}

u32 bxi_strcspn(const char * str, const char * lst)
{
    u32 res = 1;
    char map[BXI_FAST_DIV_8(BXI_ASCII_COUNT)] = { 0 };

    while (*lst)
        map[BXI_FAST_DIV_8(*lst)] |= 1 << (*lst % 8);

    while (*str)
    {
        if ((map[BXI_FAST_DIV_8(*str)] >> (*str % 8)) & 1)
            break;
        res++;
        str++;
    }

    return res - 1;
}

char * bxi_strpbrk(const char * str, const char * lst)
{
    char map[BXI_FAST_DIV_8(BXI_ASCII_COUNT)] = { 0 };

    while (*lst)
        map[BXI_FAST_DIV_8(*lst)] |= 1 << (*lst % 8);

    while (*str)
    {
        if ((map[BXI_FAST_DIV_8(*str)] >> (*str % 8)) & 1)
            return (char * )str;
        str++;
    }

    return NULL;
}
