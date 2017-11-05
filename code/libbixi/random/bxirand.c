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

#include "../random/bxirand.h"

#define BXI_RAND_MULTIPLIER (1103515245)
#define BXI_RAND_INCREMENT  (12345)

static u32 global_next = 1;

static void nextrand(void)
{
    global_next = global_next * BXI_RAND_MULTIPLIER + BXI_RAND_INCREMENT;
}

void bxi_srand(u32 seed)
{
    global_next = seed;
}

u32 bxi_randu32(void)
{
    nextrand();
    return global_next;
}

u16 bxi_randu16(void)
{
    nextrand();
    return (global_next >> BITS_IN_U16) % (U16_MAX + 1);
}

u8 bxi_randu8 (void)
{
    nextrand();
    return (global_next >> BITS_IN_U8) % (U8_MAX + 1);
}

i32 bxi_randi32(void)
{
    nextrand();
    return (i32)global_next;
}

i16 bxi_randi16(void)
{
    nextrand();
    return (i16)((global_next >> BITS_IN_U16) % (U16_MAX + 1));
}

i8 bxi_randi8 (void)
{
    nextrand();
    return (i8)((global_next >> BITS_IN_U8) % (U8_MAX + 1));
}
