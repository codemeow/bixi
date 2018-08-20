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

#include "../utils/bxibitutils.h"

/* DISCLAIMER:
 *     I'm aware of "magic constants" in this file,
 *     but they stay here because of strange gcc behaviour:
 *
 *     return val >> n | val << (32 - n);
 *
 *     unrolls to
 *
 *     mov     eax, DWORD PTR [rbp-8]
 *     mov     edx, DWORD PTR [rbp-4]
 *     mov     ecx, eax
 *     ror     edx, cl                 ← fast ror here
 *     mov     eax, edx
 *
 *     (x86-64 gcc 5.3, -O0),
 *
 *     but
 *
 *     return val >> n | val << (sizeof(val) * 8 - n);
 *
 *     unrolls to
 *
 *     mov     eax, DWORD PTR [rbp-8] ─┐
 *     mov     edx, DWORD PTR [rbp-4]  │
 *     mov     esi, edx                │
 *     mov     ecx, eax                │
 *     shr     esi, cl                 │
 *     mov     eax, 32                 ├─ no ror
 *     sub     eax, DWORD PTR [rbp-8]  │
 *     mov     edx, DWORD PTR [rbp-4]  │
 *     mov     ecx, eax                │
 *     sal     edx, cl                 │
 *     mov     eax, edx                │
 *     or      eax, esi               ─┘
 */

u8 bxi_rotl8(u8 val, u32 n)
{
    return val << n | val >> (8 - n);
}

u8 bxi_rotr8(u8 val, u32 n)
{
    return val >> n | val << (8 - n);
}

u16 bxi_rotl16(u16 val, u32 n)
{
    return val << n | val >> (16 - n);
}

u16 bxi_rotr16(u16 val, u32 n)
{
    return val >> n | val << (16 - n);
}

u32 bxi_rotl32(u32 val, u32 n)
{
    return val << n | val >> (32 - n);
}

u32 bxi_rotr32(u32 val, u32 n)
{
    return val >> n | val << (32 - n);
}

u8 bxi_getbit(u32 val, u8 n)
{
    return (val >> n) & 1;
}

u32 bxi_setbit(u32 val, u8 n)
{
    return (val | (1 << n));
}

u32 bxi_tglbit(u32 val, u8 n)
{
    return (val ^ (1 << n));
}

u32 bxi_clrbit(u32 val, u8 n)
{
    return (val & ~(1 << n));
}

u32 bxi_chgbit(u32 val, u8 n, u8 bit)
{
    return ((val & ~(1 << n)) | ((bit & 1) << n));
}

u8 bxi_cntbit(u32 val)
{
    val =     val               - ((val >> 1)  & 0x55555555);
    val =    (val & 0x33333333) + ((val >> 2)  & 0x33333333);
    return (((val               +  (val >> 4)) & 0xF0F0F0F) * 0x1010101) >> 24;
}

