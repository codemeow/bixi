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

#ifndef BXIBITUTILS_H
#define BXIBITUTILS_H

#include "../definitions/bxiexport.h"
#include "../types/bxiints.h"

EXPORT u8  rotl8 (u8  val, u32 n);
EXPORT u8  rotr8 (u8  val, u32 n);
EXPORT u16 rotl16(u16 val, u32 n);
EXPORT u16 rotr16(u16 val, u32 n);
EXPORT u32 rotl32(u32 val, u32 n);
EXPORT u32 rotr32(u32 val, u32 n);

EXPORT u8  getbit(u32 val, u8 n);
EXPORT u32 setbit(u32 val, u8 n);
EXPORT u32 tglbit(u32 val, u8 n);
EXPORT u32 clrbit(u32 val, u8 n);
EXPORT u32 chgbit(u32 val, u8 n, u8 bit);

#endif /* BXIBITUTILS_H */

