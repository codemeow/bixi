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

#include "./definitions/bxiexport.h"
#include "./definitions/bxiarch.h"
#include "./definitions/bxiassert.h"
#include "./definitions/bximacros.h"
#include "./graph/bxicolour.h"
#include "./hashes/bxihash.h"
#include "./hashes/bximd5.h"
#include "./hashes/bxiuuid.h"
#include "./math/bxigeotypes.h"
#include "./math/bximath.h"
#include "./random/bxirand.h"
#include "./serials/bxiserread.h"
#include "./serials/bxiserwrite.h"
#include "./strings/bxistrconv.h"
#include "./strings/bxistring.h"
#include "./thread/bxithread.h"
#include "./time/bxisleep.h"
#include "./time/bxitime.h"
#include "./types/bxiarrays.h"
#include "./types/bxiboints.h"
#include "./types/bxibools.h"
#include "./types/bxifloats.h"
#include "./types/bxiints.h"
#include "./utils/bxibitutils.h"
#include "./utils/bximemutils.h"

#define print_info  printf("\033[1;33m%s\033[0m\n", __FILE__)

void print_passed(void);
void print_failed(void);

#endif /* TEST_H */

