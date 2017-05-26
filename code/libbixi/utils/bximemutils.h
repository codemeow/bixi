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

#ifndef BXIMEMUTILS_H
#define BXIMEMUTILS_H

#include "../definitions/bxiexport.h"
#include "../types/bxiints.h"

/* @todo 4-bytes blocks bxi_memset */
EXPORT void * bxi_memset (      void * ptr,        i32   val, u32 cnt);
/* @todo 4-bytes blocks bxi_memcpy */
EXPORT void * bxi_memcpy (      void * dst, const void * src, u32 cnt);
/* @todo 4-bytes blocks bxi_memmove */
EXPORT void * bxi_memmove(      void * dst, const void * src, u32 cnt);
/* @todo 4-bytes blocks bxi_memcmp */
EXPORT i32    bxi_memcmp (const void * p1,  const void * p2,  u32 cnt);
/* @todo 4-bytes blocks bxi_memfrob */
EXPORT void   bxi_memfrob(      void * ptr,         u8   val, u32 cnt);
EXPORT void * bxi_memchr (const void * ptr,         u8   val, u32 cnt);
EXPORT void * bxi_memrchr(const void * ptr,         u8   val, u32 cnt);

#endif /* BXIMEMUTILS_H */

