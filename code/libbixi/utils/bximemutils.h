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

#ifndef BXIMEMUTILS_H
#define BXIMEMUTILS_H

#include "../definitions/bxiexport.h"
#include "../types/bxiints.h"

EXPORT_FROM
#define BXI_MEM_NONE (0 << 0)
#define BXI_MEM_ZERO (1 << 0)
EXPORT_TO

EXPORT typedef u32 bxi_memopt_t;

extern bxi_memopt_t bxi_memopt_val;

EXPORT typedef void * (* bxi_malloc_t )(            u32 size, const char * file, u32 line);
EXPORT typedef void   (* bxi_free_t   )(void * ptr,           const char * file, u32 line);
EXPORT typedef void * (* bxi_realloc_t)(void * ptr, u32 size, const char * file, u32 line);
EXPORT typedef void   (* bxi_memerr_t )(            u32 size, const char * file, u32 line);

EXPORT void   bxi_memopt_set (bxi_memopt_t memopt);

EXPORT void   bxi_malloc_set (bxi_malloc_t  func);
EXPORT void   bxi_free_set   (bxi_free_t    func);
EXPORT void   bxi_realloc_set(bxi_realloc_t func);
EXPORT void   bxi_memerr_set (bxi_memerr_t  func);

EXPORT void * bxi_malloc_call (            u32 size, const char * file, u32 line);
EXPORT void   bxi_free_call   (void * ptr          , const char * file, u32 line);
EXPORT void * bxi_realloc_call(void * ptr, u32 size, const char * file, u32 line);

EXPORT_FROM
#if defined(__FILE__) && defined(__LINE__)
#define bxi_malloc(size)       bxi_malloc_call (     size, __FILE__, __LINE__)
#define bxi_realloc(ptr, size) bxi_realloc_call(ptr, size, __FILE__, __LINE__)
#else
#define bxi_malloc(size)       bxi_malloc_call (     size,       "",        0)
#define bxi_realloc(ptr, size) bxi_realloc_call(ptr, size, __FILE__, __LINE__)
#endif

#define bxi_free(ptr)          bxi_free_call(ptr, __FILE__, __LINE__);
EXPORT_TO

EXPORT void * bxi_memset  (      void * ptr,        i32   val, u32 cnt);
EXPORT void * bxi_memset16(      void * ptr,        u32   val, u32 cnt);
EXPORT void * bxi_memset32(      void * ptr,        u32   val, u32 cnt);
EXPORT void * bxi_memcpy  (      void * dst, const void * src, u32 cnt);
EXPORT void * bxi_memmove (      void * dst, const void * src, u32 cnt);
EXPORT i32    bxi_memcmp  (const void * p1,  const void * p2,  u32 cnt);
EXPORT void * bxi_memfrob (      void * ptr,         u8   val, u32 cnt);
EXPORT void * bxi_memchr  (const void * ptr,         u8   val, u32 cnt);
EXPORT void * bxi_memrchr (const void * ptr,         u8   val, u32 cnt);

#endif /* BXIMEMUTILS_H */

