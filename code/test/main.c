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
#include "test.h"

i32 main(void)
{
    test_definitions_bxiexport();
    test_definitions_bxiarch();
    test_definitions_bxiassert();
    test_definitions_bximacros();

    test_graph_bxicolour();

    test_hashes_bxihash();
    test_hashes_bximd5();
    test_hashes_bxiuuid();

    test_math_bxigeotypes();
    test_math_bximath();

    test_random_bxirand();

    test_serials_bxiserread();
    test_serials_bxiserwrite();

    test_strings_bxistrconv();
    test_strings_bxistring();

    test_thread_bxithread();

    test_time_bxisleep();
    test_time_bxitime();

    test_types_bxiarrays();
    test_types_bxiboints();
    test_types_bxibools();
    test_types_bxifloats();
    test_types_bxiints();

    test_utils_bxibitutils();
    test_utils_bximemutils();

    return 0;
}
