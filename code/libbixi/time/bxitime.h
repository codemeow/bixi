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

#ifndef BXITIME_H
#define BXITIME_H

#include "../definitions/bxiexport.h"

EXPORT_FROM
#define SEC_PER_MIN (60L)
#define MIN_PER_HRS (60L)
#define HRS_PER_DAY (24L)

#define DAYS_PER_WEEK (7L)

#define SEC_PER_HRS (SEC_PER_MIN * MIN_PER_HRS)
#define SEC_PER_DAY (SEC_PER_HRS * HRS_PER_DAY)
#define MIN_PER_DAY (MIN_PER_HRS * HRS_PER_DAY)
EXPORT_TO

EXPORT typedef enum
/* days are numbered by the order
 * they've appeared in unixtime
 * to simplify unixtime date math */
{
    BXI_MONDAY    = (4),
    BXI_TUESDAY   = (5),
    BXI_WEDNESDAY = (6),
    BXI_THURSDAY  = (0),
    BXI_FRIDAY    = (1),
    BXI_SATURDAY  = (2),
    BXI_SUNDAY    = (3)
} bxi_weekdays;

#endif /* BXITIME_H */

