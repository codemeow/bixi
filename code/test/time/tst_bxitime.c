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
#include "../time/tst_bxitime.h"

static void test_time_defines(void)
{
    printf("    defines:\n");
    TEST_BXI_MACRO_U32(SEC_PER_MIN);
    TEST_BXI_MACRO_U32(MIN_PER_HRS);
    TEST_BXI_MACRO_U32(HRS_PER_DAY);
    TEST_BXI_MACRO_U32(DAYS_PER_WEEK);
    TEST_BXI_MACRO_U32(SEC_PER_HRS);
    TEST_BXI_MACRO_U32(SEC_PER_DAY);
    TEST_BXI_MACRO_U32(MIN_PER_DAY);
}

void test_time_bxitime(void)
{
    print_info;

    test_time_defines();

    print_passed();
}
