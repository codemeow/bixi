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

#ifndef BXIARRAYS_H
#define BXIARRAYS_H

#include "../definitions/bxiexport.h"
#include "../types/bxiints.h"

EXPORT typedef struct
{
    u8 * data;
    u32  size;
} bxi_bts;

EXPORT typedef void (*bxi_bts_trav_t)(bxi_bts * bts, u32 pos, u8 * val);

EXPORT BXI_USES_MEM bxi_bts * bxi_bts_create(               u32 size);
EXPORT BXI_USES_MEM void      bxi_bts_free  (bxi_bts * bts          );

/* @todo sort   */
EXPORT bxi_bts * bxi_bts_walk  (bxi_bts * bts, bxi_bts_trav_t func);
EXPORT i32       bxi_bts_search(bxi_bts * bts, u8 value);
EXPORT bxi_bts * bxi_bts_resize(bxi_bts * bts, u32 size);
EXPORT bxi_bts * bxi_bts_insert(bxi_bts * dst, bxi_bts * src, u32 pos);
EXPORT bxi_bts * bxi_bts_append(bxi_bts * dst, bxi_bts * src);
EXPORT bxi_bts * bxi_bts_delete(bxi_bts * dst, u32 pos, u32 cnt);
EXPORT bxi_bts * bxi_bts_lshift(bxi_bts * dst, u32 c);

#endif /* BXIARRAYS_H */

