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

#include <stdio.h>
#include <libbixi.h>
#include "../test.h"
#include "../math/bxigeotypes.h"

void test_math_bxigeotypes(void)
{
    print_info;

#   if defined(UUID_SIZE)
        printf("        defined: MM_PER_INCH    (%f)\n", MM_PER_INCH);
#   else
        print_failed();
        return;
#   endif

    print_passed();
}
