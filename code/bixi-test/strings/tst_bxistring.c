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

#define _GNU_SOURCE 1
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <libbixi.h>
#include "../test.h"
#include "../strings/tst_bxistring.h"

static void test_strings_test_bxi_strhash(void)
{
    printf("        checking: bxi_strhash\n");
    if (bxi_strhash("FNV") != 0xf5cfe2b9)
        test_failed();
}

static void test_strings_test_bxi_strshiftl(void)
{
    char shift[] = "abcdef";

    printf("        checking: bxi_strshiftl\n");
    if (bxi_strcmp(bxi_strshiftl(shift, 3), "def"))
        test_failed();
}

static void test_strings_test_bxi_strtriml(void)
{
    char triml[] = "   def";

    printf("        checking: bxi_strtriml\n");
    if (bxi_strcmp(bxi_strtriml(triml), "def"))
        test_failed();
}


static void test_strings_test_bxi_strtrimr(void)
{
    char trimr[] = "abc   ";

    printf("        checking: bxi_strtrimr\n");
    if (bxi_strcmp(bxi_strtrimr(trimr), "abc"))
        test_failed();
}

static void test_strings_test_bxi_strtrim(void)
{
    char trimc[] = "  cd  ";

    printf("        checking: bxi_strtrim\n");
    if (bxi_strcmp(bxi_strtrim(trimc), "cd"))
        test_failed();
}

static void test_strings_test_bxi_strlen(void)
{
    printf("        checking: bxi_strlen\n");
    if (bxi_strlen("abcdef") != 6)
        test_failed();
}

static void test_strings_test_bxi_strcmp(void)
{
    printf("        checking: bxi_strcmp\n");

    if (bxi_strcmp("abc", "abc"))
        test_failed();
    if (bxi_strcmp("", ""))
        test_failed();
    if (!bxi_strcmp("abcd", "abc"))
        test_failed();
}

static void test_strings_test_bxi_strprs(void)
{
    char   parsed[] = "  param1 param2 \"param 3\" \'param \"\\\' 4 \'";
    char * output[5];

    printf("        checking: bxi_strprs\n");
    if (bxi_strprs(parsed, output) != 4)
        test_failed();

    if ((bxi_strcmp(output[0], "param1")) ||
        (bxi_strcmp(output[1], "param2")) ||
        (bxi_strcmp(output[2], "\"param 3\"")) ||
        (bxi_strcmp(output[3], "\'param \"\\\' 4 \'")))
        test_failed();
}

static void test_strings_test_bxi_strchr(void)
{
    printf("        checking: bxi_strchr\n");
    if (bxi_strcmp(bxi_strchr("abcdef", 'c'), "cdef"))
        test_failed();
}

static void test_strings_test_bxi_strcpy(void)
{
    char dst[10];
    char src[]   = "abcdef";

    printf("        checking: bxi_strcpy\n");

    bxi_strcpy(dst, src);
    if (bxi_strcmp(dst, src))
        test_failed();
}

static void test_strings_test_bxi_strstr(void)
{
    const char str[]   = "abcdef";
    const char sub[]   = "cd";

    printf("        checking: bxi_strstr\n");

    if (bxi_strcmp(bxi_strstr(str, sub), "cdef"))
        test_failed();
}

static void test_strings_test_bxi_is(void)
{
#   define TEST_ISCHAR(bxifunc, stdfunc)            \
    {                                               \
        i32 i;                                      \
        printf("        checking: %s\n", #bxifunc); \
                                                    \
        for (i = 0; i < 128; i++);                  \
        if (stdfunc(i) != bxifunc(i))               \
            test_failed();                          \
    }

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
    /* isblank requires c99, no tests here  */
    /* @test add generic isblank            */
    /* TEST_ISCHAR(bxi_isblank , isblank ); */

    TEST_ISCHAR(bxi_2upper, (u32)toupper);
    TEST_ISCHAR(bxi_2lower, (u32)tolower);

#   undef TEST_ISCHAR
}

static void test_strings_test_bxi_str2lower(void)
{
    char buffer[] = "QUICK BROWN FOX JUMPS OVER THE LAZY DOG!";

    printf("        checking: bxi_str2lower\n");
    bxi_str2lower(buffer);
    if (bxi_strcmp(buffer, "quick brown fox jumps over the lazy dog!"))
        test_failed();
}

static void test_strings_test_bxi_str2upper(void)
{
    char buffer[] = "quick brown fox jumps over the lazy dog!";

    printf("        checking: bxi_str2upper\n");
    bxi_str2upper(buffer);
    if (bxi_strcmp(buffer, "QUICK BROWN FOX JUMPS OVER THE LAZY DOG!"))
        test_failed();
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

static void test_strings_test_bxi_strdup(void)
{
    bxi_malloc_set(my_malloc);
    bxi_free_set(my_free);

    printf("        checking: bxi_strdup\n");
    {
        char * str = bxi_strdup("Quick brown dog jumps over the lazy frog\n");
        if (bxi_strcmp(str, "Quick brown dog jumps over the lazy frog\n"))
            test_failed();

        bxi_free(str);
    }
}

static void test_strings_test_bxi_strrchr(void)
{
    char t1[] = "abcdefabcedf";
    char t2[] = "   a   b   a";

    printf("        checking: bxi_strrchr\n");
    if (bxi_strrchr(t1, 'a') != strrchr(t1, 'a'))
        test_failed();
    if (bxi_strrchr(t2, 'a') != strrchr(t2, 'a'))
        test_failed();
    if (bxi_strrchr(t2, 'f') != strrchr(t2, 'f'))
        test_failed();
}

static void test_strings_test_bxi_strcat(void)
{
    char org[100] = "abc";
    char new[100] = "abc";

    char * p1;
    char * p2;

    printf("        checking: bxi_strcat\n");
    p1 =     strcat(org, "def");
    p2 = bxi_strcat(new, "def");

    if (bxi_strcmp(p1, p2))
        test_failed();
}

static void test_strings_test_bxi_strncpy(void)
{
    char org[100] = { 0 };
    char new[100] = { 0 };

    char * p1;
    char * p2;

    printf("        checking: bxi_strncpy\n");
    p1 =     strncpy(org, "abcdef", 3);
    p2 = bxi_strncpy(new, "abcdef", 3);

    if (bxi_strcmp(p1, p2))
        test_failed();
}

static void test_strings_test_bxi_strncmp(void)
{
    const char s1[] = "abcdefghi";
    const char s2[] = "abcde1234";

    u32 i;

    printf("        checking: bxi_strncmp\n");
    for (i = 0; i < bxi_strlen(s1); i++)
    {
        i32 ro =     strncmp(s1, s2, i);
        i32 rn = bxi_strncmp(s1, s2, i);
        if (ro != rn)
            test_failed();
    }
}

static void test_strings_test_bxi_strchrnul(void)
{
    const char s1[] = "abcdefghi";
    char * org;
    char * new;

    printf("        checking: bxi_strchrnul\n");

    new = bxi_strchrnul(s1, 'c');
    org =     strchrnul(s1, 'c');
    if (new != org)
        test_failed();

    new = bxi_strchrnul(s1, 'z');
    org =     strchrnul(s1, 'z');
    if (new != org)
        test_failed();
}

static void test_strings_test_bxi_strncat(void)
{
    char s1[100] = "abc";
    char s2[100] = "abc";

    char * org;
    char * new;

    printf("        checking: bxi_strncat\n");

    org =     strncat(s1, "defghijkl", 5);
    new = bxi_strncat(s2, "defghijkl", 5);

    if (bxi_strcmp(org, new))
        test_failed();
}

static void test_strings_test_bxi_strapp(void)
{
    char * buf;
    char * res;

    printf("        checking: bxi_strapp\n");

    res = bxi_strapp(&buf, "abc");
    if (bxi_strcmp(res, "abc"))
        test_failed();

    res = bxi_strapp(&buf, "def");
    if (bxi_strcmp(res, "abcdef"))
        test_failed();

    res = bxi_strapp(&buf, "ghi");
    if (bxi_strcmp(res, "abcdefghi"))
        test_failed();

    bxi_free(res);
}

static void test_strings_test_bxi_strpbrk(void)
{
    const char str[] = "abcdefghijklmnopqrstuvwxyz";

    char * org;
    char * new;

    printf("        checking: bxi_strpbrk\n");

    org =     strpbrk(str, "ox");
    new = bxi_strpbrk(str, "ox");

    if (bxi_strcmp(org, new))
        test_failed();

    org =     strpbrk(str, "12");
    new = bxi_strpbrk(str, "12");

    if (bxi_strcmp(org, new))
        test_failed();
}

static void test_strings_test_bxi_strspn(void)
{
    const char str[] = "abcdefghijklmnopqrstuvwxyz";

    u32 org = 0;
    u32 new = 0;

    printf("        checking: bxi_strspn\n");

    org =     strspn(str, "abcdefg");
    new = bxi_strspn(str, "abcdefg");

    if (org != new)
        test_failed();

    org =     strspn(str, "123");
    new = bxi_strspn(str, "123");

    if (org != new)
        test_failed();
}

static void test_strings_test_bxi_strcspn(void)
{
    const char str[] = "abcdefghijklmnopqrstuvwxyz";

    u32 org = 0;
    u32 new = 0;

    printf("        checking: bxi_strcspn\n");

    org =     strspn(str, "abcdefg");
    new = bxi_strspn(str, "abcdefg");

    if (org != new)
        test_failed();

    org =     strspn(str, "123");
    new = bxi_strspn(str, "123");

    if (org != new)
        test_failed();
}

static void test_strings_test_bxi_strrep(void)
{
    char str[100] = "abc def ghi abc:abc def ghi";
    const char rep[]    = "abc";
    const char bys[]    = "--=--";

    const char eth[]    = "--=-- def ghi --=--:--=-- def ghi";

    printf("        checking: bxi_strrep\n");

    bxi_strrep(str, rep, bys);

    if (bxi_strcmp(str, eth))
        test_failed();
}

static void test_strings_functions(void)
{
    printf("    functions:\n");

    test_strings_test_bxi_strhash();
    test_strings_test_bxi_strshiftl();
    test_strings_test_bxi_strtriml();
    test_strings_test_bxi_strtrimr();
    test_strings_test_bxi_strtrim();
    test_strings_test_bxi_strlen();
    test_strings_test_bxi_strcmp();
    test_strings_test_bxi_strprs();
    test_strings_test_bxi_strchr();
    test_strings_test_bxi_strcpy();
    test_strings_test_bxi_strstr();
    test_strings_test_bxi_is();
    test_strings_test_bxi_str2lower();
    test_strings_test_bxi_str2upper();
    test_strings_test_bxi_strdup();
    test_strings_test_bxi_strrchr();
    test_strings_test_bxi_strcat();
    test_strings_test_bxi_strncpy();
    test_strings_test_bxi_strncmp();
    test_strings_test_bxi_strchrnul();
    test_strings_test_bxi_strncat();
    test_strings_test_bxi_strapp();
    test_strings_test_bxi_strpbrk();
    test_strings_test_bxi_strspn();
    test_strings_test_bxi_strcspn();
    test_strings_test_bxi_strrep();
}

static void test_strings_defines(void)
{
    printf("    defines\n");

    TEST_BXI_MACRO_U32(BXI_ASCII_MAX);
    TEST_BXI_MACRO_U32(BXI_ASCII_COUNT);
}

void test_strings_bxistring(void)
{
    print_info;

    test_strings_defines();
    test_strings_functions();

    print_passed();
}
