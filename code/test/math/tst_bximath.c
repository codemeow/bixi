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
#include <math.h>
#include <libbixi.h>
#include <time.h>
#include "../test.h"
#include "../math/tst_bximath.h"

#define TEST_SPEED_SQRTI_LOOPS (U32_MAX >> 5)
#define TEST_SPEED_FABS_LOOBS  (U32_MAX >> 3)

static void test_math_bxi_sqrti(void)
{
    u32 i;
    TEST_SPEED_INIT;

    printf("        checking: bxi_sqrti\n");

    TEST_SPEED_START;
    for (i = 0; i < TEST_SPEED_SQRTI_LOOPS; i ++)
        sum_org += round(sqrt(i));
    TEST_SPEED_STOP;
    TEST_SPEED_SAY("     sqrt");

    TEST_SPEED_START;
    for (i = 0; i < TEST_SPEED_SQRTI_LOOPS; i ++)
        sum_new += bxi_sqrti(i);
    TEST_SPEED_STOP;
    TEST_SPEED_SAY("bxi_sqrti");

    printf("                precision: %8.5f%%\n",
           100 - ((sum_new - sum_org) * 100 / sum_org));
}

static void check_fabs_advanced(void)
{
    u32 i;
    double iterator = 1.1;
    double value    = 0.0;
    for (i = 0; i < 1000; i++)
    {
        iterator *= -1.5;
        value += iterator;
        if (bxi_fabs(value) != fabs(value))
            test_failed();
    }
}

static void check_fabs_speed(void)
{
    TEST_SPEED_INIT;
    u32 i;
    double iterator = 1.1;
    double value    = 0.0;
    TEST_SPEED_START;
    for (i = 0; i < TEST_SPEED_FABS_LOOBS; i++)
    {
        iterator *= -1.5;
        value    += iterator;
        sum_org  += fabs(i - 50.0);
    }
    TEST_SPEED_STOP;
    TEST_SPEED_SAY("    fabs");

    iterator = 1.1;
    value    = 0.0;
    TEST_SPEED_START;
    for (i = 0; i < TEST_SPEED_FABS_LOOBS; i++)
    {
        iterator *= -1.5;
        value    += iterator;
        sum_new  += bxi_fabs(i - 50.0);
    }
    TEST_SPEED_STOP;
    TEST_SPEED_SAY("bxi_fabs");
    TEST_SPEED_CHECK;
}

static void test_math_bxi_fabs(void)
{
    printf("        checking: bxi_fabs\n");
    check_fabs_advanced();
    check_fabs_speed();
}

static void check_sin_advanced(void)
{
    double increment = 0.000001;
    double valx      = -BXI_PI;
    double maxerr    = 0.0;
    double maxdiff   = 0.0;
    double avgerr    = 0.0;
    double avgdiff   = 0.0;
    u32    i         = 0;

    while (valx < 1)
    {
        double sin_sys =      sin(valx);
        double sin_bxi = bxi_fsin(valx);
        double diff    = bxi_fabs(sin_sys - sin_bxi);
        double cerr    = sin_sys ? diff * 100.0 / sin_sys : 0;

        if (cerr > maxerr)
        {
            maxerr  = cerr;
            maxdiff = diff;
        }

        avgerr  += cerr;
        avgdiff += diff;

        valx += increment;
        i++;
    }

    avgerr  /= i;
    avgdiff /= i;

    avgerr  = bxi_fabs(avgerr);
    avgdiff = bxi_fabs(avgdiff);

    printf("            precision: maxerr %10.8f%% / %10.8f,\n"
           "                       avgerr %10.8f%% / %10.8f \n",
           maxerr, maxdiff, avgerr, avgdiff);
}

static void check_cos_advanced(void)
{
    double increment = 0.000001;
    double valx      = -BXI_PI;
    double maxerr    = 0.0;
    double maxdiff   = 0.0;
    double avgerr    = 0.0;
    double avgdiff   = 0.0;
    u32    i         = 0;

    while (valx < 1)
    {
        double cos_sys =      cos(valx);
        double cos_bxi = bxi_fcos(valx);
        double diff    = bxi_fabs(cos_sys - cos_bxi);
        double cerr    = cos_sys ? diff * 100.0 / cos_sys : 0;

        if (cerr > maxerr)
        {
            maxerr  = cerr;
            maxdiff = diff;
        }

        avgerr  += cerr;
        avgdiff += diff;

        valx += increment;
        i++;
    }

    avgerr  /= i;
    avgdiff /= i;

    avgerr  = bxi_fabs(avgerr);
    avgdiff = bxi_fabs(avgdiff);

    printf("            precision: maxerr %10.8f%% / %10.8f,\n"
           "                       avgerr %10.8f%% / %10.8f \n",
           maxerr, maxdiff, avgerr, avgdiff);
}

#define TEST_SIN_INCREMENT (0.00000001)
#define TEST_SIN_START     (0.0)
#define TEST_SIN_STOP      (1.0)
static void check_sin_speed(void)
{
    TEST_SPEED_INIT;
    double increment = TEST_SIN_INCREMENT;
    double valx      = TEST_SIN_START;

    TEST_SPEED_START;
    while (valx < TEST_SIN_STOP)
    {
        sum_org += sin(valx);
        valx += increment;
    }
    TEST_SPEED_STOP;
    TEST_SPEED_SAY("     sin");

    increment = TEST_SIN_INCREMENT;
    valx      = TEST_SIN_START;
    TEST_SPEED_START;
    while (valx < TEST_SIN_STOP)
    {
        sum_new += bxi_fsin(valx);
        valx += increment;
    }
    TEST_SPEED_STOP;
    TEST_SPEED_SAY("bxi_fsin");

    printf("            comp     : %10.2f vs %10.2f\n",
           sum_org, sum_new);
}

#define TEST_COS_INCREMENT (0.00000001)
#define TEST_COS_START     (0.0)
#define TEST_COS_STOP      (1.0)
static void check_cos_speed(void)
{
    TEST_SPEED_INIT;
    double increment = TEST_COS_INCREMENT;
    double valx      = TEST_COS_START;

    TEST_SPEED_START;
    while (valx < TEST_COS_STOP)
    {
        sum_org += cos(valx);
        valx += increment;
    }
    TEST_SPEED_STOP;
    TEST_SPEED_SAY("     cos");

    increment = TEST_COS_INCREMENT;
    valx      = TEST_COS_START;
    TEST_SPEED_START;
    while (valx < TEST_COS_STOP)
    {
        sum_new += bxi_fcos(valx);
        valx += increment;
    }
    TEST_SPEED_STOP;
    TEST_SPEED_SAY("bxi_fcos");

    printf("            comp      : %10.2f vs %10.2f\n",
           sum_org, sum_new);
}

static void test_math_bxi_sin(void)
{
    printf("        checking: bxi_sin\n");
    check_sin_advanced();
    check_sin_speed();
}

static void test_math_bxi_cos(void)
{
    printf("        checking: bxi_cos\n");
    check_cos_advanced();
    check_cos_speed();
}



static void test_definitions_bxi_max(void)
{
    if (BXI_MAX(5, 6) != 6)
        test_failed();
    if (BXI_MAX(5, 5) != 5)
        test_failed();
    if (BXI_MAX(6, 5) != 6)
        test_failed();
}

static void test_definitions_bxi_min(void)
{
    if (BXI_MIN(5, 6) != 5)
        test_failed();
    if (BXI_MIN(5, 5) != 5)
        test_failed();
    if (BXI_MIN(6, 5) != 5)
        test_failed();
}

static void test_definitions_bxi_fast_u16div255(void)
{
    u32 i;
    for (i = U16_MIN; i < U16_MAX; i++)
        if (BXI_FAST_U16DIV255(i) != i / 255)
            test_failed();
}

static void test_math_defines(void)
{
    printf("    defines:\n");
    TEST_BXI_MACRO_FLT(BXI_PI);
    TEST_BXI_MACRO_FLT(BXI_PI_DIV_2);
    TEST_BXI_MACRO_FLT(BXI_PI_DIV_4);
    TEST_BXI_MACRO_FLT(BXI_1_DIV_PI);
    TEST_BXI_MACRO_FLT(BXI_2_DIV_PI);
    TEST_BXI_MACRO_FLT(BXI_4_DIV_PI);
    TEST_BXI_MACRO_FLT(BXI_4_DIV_SQR_PI);
    TEST_BXI_MACRO_FLT(BXI_E);
    TEST_BXI_MACRO_FLT(BXI_PHI);
    TEST_BXI_MACRO_FLT(BXI_E_POW_PI);
    TEST_BXI_MACRO_FLT(BXI_LOG2_E);
    TEST_BXI_MACRO_FLT(BXI_LOG10_E);
    TEST_BXI_MACRO_FLT(BXI_LN_E);
    TEST_BXI_MACRO_FLT(BXI_LN_10);
    TEST_BXI_MACRO_FLT(BXI_SQRT_2);
    TEST_BXI_MACRO_FLT(BXI_SQRT_3);
    TEST_BXI_MACRO_FLT(BXI_SQRT_5);
    TEST_BXI_MACRO_FLT(BXI_1_DIV_SQRT_2);
    TEST_BXI_MACRO_FLT(BXI_NAN);
    TEST_BXI_MACRO_FLT(BXI_INF_POS);
    TEST_BXI_MACRO_FLT(BXI_INF_NEG);

    TEST_BXI_MACRO_EXISTS_2(BXI_MAX);
        test_definitions_bxi_max();
    TEST_BXI_MACRO_EXISTS_2(BXI_MIN);
        test_definitions_bxi_min();
    TEST_BXI_MACRO_EXISTS(BXI_FAST_U16DIV255);
        test_definitions_bxi_fast_u16div255();
    TEST_BXI_MACRO_EXISTS(BXI_FAST_DIV_2);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_DIV_4);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_DIV_8);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_DIV_16);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_DIV_32);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_DIV_64);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_DIV_128);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_DIV_256);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_DIV_512);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_DIV_1024);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_DIV_2048);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_DIV_4096);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_DIV_8192);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_DIV_16384);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_DIV_32768);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_DIV_65536);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_DIV_131072);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_DIV_262144);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_DIV_524288);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_DIV_1048576);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_DIV_2097152);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_DIV_4194304);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_DIV_8388608);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_DIV_16777216);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_DIV_33554432);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_DIV_67108864);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_DIV_134217728);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_DIV_268435456);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_DIV_536870912);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_DIV_1073741824);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_DIV_2147483648);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_MUL_2);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_MUL_4);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_MUL_8);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_MUL_16);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_MUL_32);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_MUL_64);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_MUL_128);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_MUL_256);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_MUL_512);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_MUL_1024);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_MUL_2048);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_MUL_4096);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_MUL_8192);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_MUL_16384);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_MUL_32768);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_MUL_65536);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_MUL_131072);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_MUL_262144);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_MUL_524288);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_MUL_1048576);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_MUL_2097152);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_MUL_4194304);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_MUL_8388608);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_MUL_16777216);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_MUL_33554432);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_MUL_67108864);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_MUL_134217728);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_MUL_268435456);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_MUL_536870912);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_MUL_1073741824);
    TEST_BXI_MACRO_EXISTS(BXI_FAST_MUL_2147483648);
}

static void test_math_bxi_abs(void)
{
    printf("        checking: bxi_abs\n");
    if (bxi_abs(-5) != 5)
        print_failed();
    if (bxi_abs(0) != 0)
        print_failed();
    if (bxi_abs(5) != 5)
        print_failed();
}

static void test_math_bxi_sign(void)
{
    printf("        checking: bxi_sign\n");
    if (bxi_sign(-5) != -1)
        print_failed();
    if (bxi_sign(0) != 0)
        print_failed();
    if (bxi_sign(5) != 1)
        print_failed();
}

static void test_math_bxi_gcd(void)
{
    printf("        checking: bxi_gcd\n");
    if (bxi_gcd(28, 17) != 1)
        print_failed();
    if (bxi_gcd(28, 34) != 2)
        print_failed();
    if (bxi_gcd(-17, 34) != 17)
        print_failed();
}

static void test_math_bxi_lcm(void)
{
    printf("        checking: bxi_lcm\n");
    if (bxi_lcm(65, 10) != 130)
        print_failed();
    if (bxi_lcm(17, 34) != 34)
        print_failed();
    if (bxi_lcm(12, 13) != 156)
        print_failed();
}

static void test_math_bxi_ceil(void)
{
    u32 i;
    printf("        checking: bxi_ceil\n");
    for (i = 0; i < 500; i++)
    {
        f64 val = -10.0 + i * 0.1;
        if (    ceil(val) !=
            bxi_ceil(val))
        {
            printf("            ceil(%f) = %f != %f\n",
                   val, ceil(val), bxi_ceil(val));
            test_failed();
        }
    }
}

static void test_math_bxi_floor(void)
{
    u32 i;
    printf("        checking: bxi_floor\n");
    for (i = 0; i < 500; i++)
    {
        f64 val = -10.0 + i * 0.1;
        if (    floor(val) !=
            bxi_floor(val))
        {
            printf("            floor(%f) = %f != %f\n",
                   val, floor(val), bxi_floor(val));
            test_failed();
        }
    }
}

static void test_math_bxi_round(void)
{
    u32 i;
    printf("        checking: bxi_round\n");
    for (i = 0; i < 500; i++)
    {
        f64 val = -10.0 + i * 0.1;
        if (    round(val) !=
            bxi_round(val))
        {
            printf("            round(%f) = %f != %f\n",
                   val, round(val), bxi_round(val));
            test_failed();
        }
    }
}

static void test_math_bxi_trunc(void)
{
    u32 i;
    printf("        checking: bxi_trunc\n");
    for (i = 0; i < 500; i++)
    {
        f64 val = -10.0 + i * 0.1;
        if (    trunc(val) !=
            bxi_trunc(val))
        {
            printf("            trunc(%f) = %f != %f\n",
                   val, trunc(val), bxi_trunc(val));
            test_failed();
        }
    }
}

static void test_math_bxi_isnan(void)
{
    printf("        checking: bxi_isnan\n");
    if (bxi_isnan(5.0) != false)
        test_failed();
    if (bxi_isnan(0.0) != false)
        test_failed();
    if (bxi_isnan(0.0 / 0.0) != true)
        test_failed();
    if (bxi_isnan(NAN) != true)
        test_failed();
}

static void test_math_functions(void)
{
    printf("    functions:\n");
    test_math_bxi_abs();
    test_math_bxi_sign();
    test_math_bxi_gcd();
    test_math_bxi_lcm();
    test_math_bxi_ceil();
    test_math_bxi_floor();
    test_math_bxi_round();
    test_math_bxi_trunc();
    test_math_bxi_isnan();
    test_math_bxi_sqrti();
    test_math_bxi_fabs();
    test_math_bxi_sin();
    test_math_bxi_cos();
}

void test_math_bximath(void)
{
    print_info;

    test_math_defines();
    test_math_functions();

    print_passed();
}
