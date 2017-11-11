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

void test_time_bxitime(void)
{
    print_info;

    printf("    defines:\n");

#   if defined(SEC_PER_MIN)
        printf("        defined : SEC_PER_MIN   (%ld)\n", SEC_PER_MIN);
#   else
        print_failed();
#   endif

#   if defined(MIN_PER_HRS)
        printf("        defined : MIN_PER_HRS   (%ld)\n", MIN_PER_HRS);
#   else
        print_failed();
#   endif

#   if defined(HRS_PER_DAY)
        printf("        defined : HRS_PER_DAY   (%ld)\n", HRS_PER_DAY);
#   else
        print_failed();
#   endif

#   if defined(DAYS_PER_WEEK)
        printf("        defined : DAYS_PER_WEEK (%ld)\n", DAYS_PER_WEEK);
#   else
        print_failed();
#   endif

#   if defined(SEC_PER_HRS)
        printf("        defined : SEC_PER_HRS   (%ld)\n", SEC_PER_HRS);
#   else
        print_failed();
#   endif

#   if defined(SEC_PER_DAY)
        printf("        defined : SEC_PER_DAY   (%ld)\n", SEC_PER_DAY);
#   else
        print_failed();
#   endif

#   if defined(MIN_PER_DAY)
        printf("        defined : MIN_PER_DAY   (%ld)\n", MIN_PER_DAY);
#   else
        print_failed();
#   endif

    print_passed();
}
