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

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <libbixi.h>
#include "../test.h"
#include "../strings/tst_bxistring.h"

/* @todo good tests */

#define TEST_ISCHAR(bxifunc, stdfunc)            \
{                                                \
    i32 i;                                       \
    printf("        checking: %s\n", #bxifunc);  \
                                                 \
    for (i = 0; i < 128; i++);                   \
    if (stdfunc(i) != bxifunc(i))                \
        print_failed();                          \
}

#define TEST_STR2(func, src, trg)                \
{                                                \
    char buffer[64] = src;                       \
                                                 \
    printf("        checking: %s\n", #func);     \
    func(buffer);                                \
    if (bxi_strcmp(buffer, trg))                 \
        print_failed();                          \
}

static void * my_malloc(u32 size, const char * file, u32 line)
{
    UNUSED(file);
    UNUSED(line);
    return calloc(size, 1);
}

static void my_free(void * ptr, const char * file, u32 line)
{
    UNUSED(file);
    UNUSED(line);
    free(ptr);
}

void test_strings_bxistring(void)
{
    char dst[10];
    char src[]   = "abcdef";
    char str[]   = "abcdef";
    char sub[]   = "cd";
    char shift[] = "abcdef";
    char triml[] = "   def";
    char trimr[] = "abc   ";
    char trimc[] = "  cd  ";
    char * output[5];
    char parsed[] = "  param1 param2 \"param 3\" \'param \"\\\' 4 \'";
    u32  count;

    print_info;

    printf("    functions:\n");

    printf("        checking: bxi_strhash\n");
    if (bxi_strhash("FNV") != 0xf5cfe2b9)
        print_failed();

    printf("        checking: bxi_strshiftl\n");
    if (bxi_strcmp(bxi_strshiftl(shift, 3), "def"))
        print_failed();

    printf("        checking: bxi_strtriml\n");
    if (bxi_strcmp(bxi_strtriml(triml), "def"))
        print_failed();

    printf("        checking: bxi_strtrimr\n");
    if (bxi_strcmp(bxi_strtrimr(trimr), "abc"))
        print_failed();

    printf("        checking: bxi_strtrim\n");
    if (bxi_strcmp(bxi_strtrim(trimc), "cd"))
        print_failed();

    printf("        checking: bxi_strlen\n");
    if (bxi_strlen("abcdef") != 6)
        print_failed();

    printf("        checking: bxi_strcmp\n");
    if (bxi_strcmp("abc", "abc"))
        print_failed();

    printf("        checking: bxi_strprs\n");
    bxi_strprs(parsed, &count, output);
    if ((bxi_strcmp(output[0], "param1")) ||
        (bxi_strcmp(output[1], "param2")) ||
        (bxi_strcmp(output[2], "\"param 3\"")) ||
        (bxi_strcmp(output[3], "\'param \"\\\' 4 \'")))
        print_failed();

    printf("        checking: bxi_strchr\n");
    if (bxi_strcmp(bxi_strchr("abcdef", 'c'), "cdef"))
        print_failed();

    printf("        checking: bxi_strcpy\n");
    bxi_strcpy(dst, src);
    if (bxi_strcmp(dst, src))
        print_failed();

    printf("        checking: bxi_strstr\n");
    if (bxi_strcmp(bxi_strstr(str, sub), "cdef"))
        print_failed();

    TEST_ISCHAR(bxi_iscntrl , iscntrl );
    TEST_ISCHAR(bxi_isprint , isprint );
    TEST_ISCHAR(bxi_isspace , isspace );
    TEST_ISCHAR(bxi_isgraph , isgraph );
    TEST_ISCHAR(bxi_ispunct , ispunct );
    TEST_ISCHAR(bxi_isalnum , isalnum );
    TEST_ISCHAR(bxi_isalpha , isalpha );
    TEST_ISCHAR(bxi_isupper , isupper );
    TEST_ISCHAR(bxi_islower , islower );
    TEST_ISCHAR(bxi_isdigit , isdigit );
    TEST_ISCHAR(bxi_isxdigit, isxdigit);
    /* c99 req, no tests for you, buddy     */
    /* TEST_ISCHAR(bxi_isblank , isblank ); */

    TEST_ISCHAR(bxi_2upper, (u32)toupper);
    TEST_ISCHAR(bxi_2lower, (u32)tolower);

    TEST_STR2(bxi_str2lower, "QUICK BROWN FOX JUMPS OVER THE LAZY DOG!",
                             "quick brown fox jumps over the lazy dog!");
    TEST_STR2(bxi_str2upper, "quick brown fox jumps over the lazy dog!",
                             "QUICK BROWN FOX JUMPS OVER THE LAZY DOG!");

    bxi_malloc_set(my_malloc);
    bxi_free_set(my_free);
    printf("        checking: bxi_strdup\n");
    {
        char * str = bxi_strdup("Quick brown dog jumps over the lazy frog\n");
        if (bxi_strcmp(str, "Quick brown dog jumps over the lazy frog\n"))
            print_failed();
        bxi_free(str);
    }

    print_passed();
}
