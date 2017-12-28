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
#include <libbixi.h>
#include "test.h"

i32 main(i32 argc, char * argv[])
{
    bool stop = false;
    if (argc == 2)
        stop = atoi(argv[1]);

    test_definitions_bxiexport();
    if (stop) getchar();
    test_definitions_bxiarch();
    if (stop) getchar();
    test_definitions_bxiassert();
    if (stop) getchar();
    test_definitions_bximacros();
    if (stop) getchar();

    test_graph_bxicolour();
    if (stop) getchar();

    test_hashes_bxihash();
    if (stop) getchar();
    test_hashes_bximd5();
    if (stop) getchar();
    test_hashes_bxiuuid();
    if (stop) getchar();

    test_math_bxigeotypes();
    if (stop) getchar();
    test_math_bximath();
    if (stop) getchar();

    test_net_bxiipv4();
    if (stop) getchar();

    test_random_bxirand();
    if (stop) getchar();

    test_serials_bxiserread();
    if (stop) getchar();
    test_serials_bxiserwrite();
    if (stop) getchar();

    test_strings_bxistrconv();
    if (stop) getchar();
    test_strings_bxistring();
    if (stop) getchar();

    test_thread_bxithread();
    if (stop) getchar();

    test_time_bxisleep();
    if (stop) getchar();
    test_time_bxitime();
    if (stop) getchar();

    test_types_bxiarrays();
    if (stop) getchar();
    test_types_bxiboints();
    if (stop) getchar();
    test_types_bxibools();
    if (stop) getchar();
    test_types_bxifloats();
    if (stop) getchar();
    test_types_bxiints();
    if (stop) getchar();

    test_utils_bxibitutils();
    if (stop) getchar();
    test_utils_bximemutils();
    if (stop) getchar();

    getchar();

    return 0;
}
