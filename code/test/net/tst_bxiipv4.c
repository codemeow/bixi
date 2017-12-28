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
#include <libbixi.h>
#include "../test.h"
#include "../net/tst_bxiipv4.h"

static void test_net_test_bxi_str2ipv4(void)
{
    bxi_ipv4 ip = { 0 };
    char str[100];

    printf("        checking: bxi_str2ipv4\n");

    bxi_strcpy(str, "");
    if (bxi_str2ipv4(str, &ip))
        test_failed();

    bxi_strcpy(str, "127.0.0.256");
    if (bxi_str2ipv4(str, &ip))
        test_failed();

    bxi_strcpy(str, "127.0..1");
    if (bxi_str2ipv4(str, &ip))
        test_failed();

    bxi_strcpy(str, "127.0.0.1.2");
    if (bxi_str2ipv4(str, &ip))
        test_failed();

    bxi_strcpy(str, "127.*");
    if (bxi_str2ipv4(str, &ip))
        test_failed();

    bxi_strcpy(str, "127.0.0.");
    if (bxi_str2ipv4(str, &ip))
        test_failed();

    bxi_strcpy(str, "127.0");
    if (bxi_str2ipv4(str, &ip))
        test_failed();

    bxi_strcpy(str, "10.0.0.24");
    if (!bxi_str2ipv4(str, &ip))
        test_failed();
    if ((ip[0] != 10) || (ip[1] != 0) || (ip[2] != 0) || (ip[3] != 24))
        test_failed();

    bxi_strcpy(str, "127.0.0.1");
    if (!bxi_str2ipv4(str, &ip))
        test_failed();
    if ((ip[0] != 127) || (ip[1] != 0) || (ip[2] != 0) || (ip[3] != 1))
        test_failed();

    bxi_strcpy(str, "255.255.255.0");
    if (!bxi_str2ipv4(str, &ip))
        test_failed();
    if ((ip[0] != 255) || (ip[1] != 255) || (ip[2] != 255) || (ip[3] != 0))
        test_failed();

    bxi_strcpy(str, "0.0.0.0");
    if (!bxi_str2ipv4(str, &ip))
        test_failed();
    if ((ip[0] != 0) || (ip[1] != 0) || (ip[2] != 0) || (ip[3] != 0))
        test_failed();

    bxi_strcpy(str, "120.121.122.123");
    if (!bxi_str2ipv4(str, &ip))
        test_failed();
    if ((ip[0] != 120) || (ip[1] != 121) || (ip[2] != 122) || (ip[3] != 123))
        test_failed();
}

static void test_net_test_bxi_ipv42str(void)
{
    bxi_ipv4 ip = { 127, 0, 0, 1};
    char str[100];

    printf("        checking: bxi_ipv42str\n");

    if (!bxi_ipv42str(&ip, str))
        test_failed();
    if (bxi_strcmp(str, "127.0.0.1"))
        test_failed();

    if (bxi_ipv42str(NULL, str))
        test_failed();

    if (bxi_ipv42str(&ip, NULL))
        test_failed();

    if (bxi_ipv42str(NULL, NULL))
        test_failed();
}

static void test_net_functions(void)
{
    printf("    functions:\n");

    test_net_test_bxi_str2ipv4();
    test_net_test_bxi_ipv42str();
}

void test_net_bxiipv4(void)
{
    print_info;

    test_net_functions();

    print_passed();
}
