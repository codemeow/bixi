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

#ifndef TEST_H
#define TEST_H

#include "./definitions/tst_bxiexport.h"
#include "./definitions/tst_bxiarch.h"
#include "./definitions/tst_bxiassert.h"
#include "./definitions/tst_bximacros.h"
#include "./graph/tst_bxicolour.h"
#include "./hashes/tst_bxihash.h"
#include "./hashes/tst_bximd5.h"
#include "./hashes/tst_bxiuuid.h"
#include "./math/tst_bxigeotypes.h"
#include "./math/tst_bximath.h"
#include "./random/tst_bxirand.h"
#include "./serials/tst_bxiserread.h"
#include "./serials/tst_bxiserwrite.h"
#include "./strings/tst_bxistrconv.h"
#include "./strings/tst_bxistring.h"
#include "./thread/tst_bxithread.h"
#include "./time/tst_bxisleep.h"
#include "./time/tst_bxitime.h"
#include "./types/tst_bxiarrays.h"
#include "./types/tst_bxiboints.h"
#include "./types/tst_bxibools.h"
#include "./types/tst_bxifloats.h"
#include "./types/tst_bxiints.h"
#include "./utils/tst_bxibitutils.h"
#include "./utils/tst_bximemutils.h"

#define print_info  printf("\033[1;33m%s\033[0m\n", __FILE__)

void print_passed(void);
void print_failed(void);

#endif /* TEST_H */

