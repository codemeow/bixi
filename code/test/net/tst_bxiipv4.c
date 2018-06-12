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
#include <arpa/inet.h>
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

static void test_net_test_bxi_ipv42u32(void)
{
    bxi_ipv4 ipv4_1 = { 127,   0,   0,   1 };
    bxi_ipv4 ipv4_2 = { 255, 255, 255, 255 };
    bxi_ipv4 ipv4_3 = { 173, 194, 222, 101 }; /* google.com */

    u32 u32_1_s, u32_1_b = bxi_ipv42u32(ipv4_1);
    u32 u32_2_s, u32_2_b = bxi_ipv42u32(ipv4_2);
    u32 u32_3_s, u32_3_b = bxi_ipv42u32(ipv4_3);

    inet_pton(AF_INET, "127.0.0.1",       &u32_1_s);
    inet_pton(AF_INET, "255.255.255.255", &u32_2_s);
    inet_pton(AF_INET, "173.194.222.101", &u32_3_s);

    if ((htonl(u32_1_s) != u32_1_b) ||
        (htonl(u32_2_s) != u32_2_b) ||
        (htonl(u32_3_s) != u32_3_b))
        test_failed();
}

static void test_net_test_bxi_u322ipv4(void)
{
    const char ipv4_local[]  = "127.0.0.1";
    const char ipv4_mask[]   = "255.255.255.255";
    const char ipv4_google[] = "173.194.222.101";

    char ipv4_1_b[100];
    char ipv4_2_b[100];
    char ipv4_3_b[100];

    u32 u32_1_s;
    u32 u32_2_s;
    u32 u32_3_s;

    bxi_ipv4 ipv4_1;
    bxi_ipv4 ipv4_2;
    bxi_ipv4 ipv4_3;

    inet_pton(AF_INET, ipv4_local,  &u32_1_s);
    inet_pton(AF_INET, ipv4_mask,   &u32_2_s);
    inet_pton(AF_INET, ipv4_google, &u32_3_s);

    bxi_u322ipv4(u32_1_s, ipv4_1);
    bxi_u322ipv4(u32_2_s, ipv4_2);
    bxi_u322ipv4(u32_3_s, ipv4_3);

    sprintf(ipv4_1_b, "%u.%u.%u.%u", ipv4_1[3], ipv4_1[2], ipv4_1[1], ipv4_1[0]);
    sprintf(ipv4_2_b, "%u.%u.%u.%u", ipv4_2[3], ipv4_2[2], ipv4_2[1], ipv4_2[0]);
    sprintf(ipv4_3_b, "%u.%u.%u.%u", ipv4_3[3], ipv4_3[2], ipv4_3[1], ipv4_3[0]);

    if ((bxi_strcmp(ipv4_1_b, ipv4_local  )) ||
        (bxi_strcmp(ipv4_2_b, ipv4_mask   )) ||
        (bxi_strcmp(ipv4_3_b, ipv4_google)))
        test_failed();
}

static void test_net_functions(void)
{
    printf("    functions:\n");

    test_net_test_bxi_str2ipv4();
    test_net_test_bxi_ipv42str();
    test_net_test_bxi_ipv42u32();
    test_net_test_bxi_u322ipv4();
}

void test_net_bxiipv4(void)
{
    print_info;

    test_net_functions();

    print_passed();
}
