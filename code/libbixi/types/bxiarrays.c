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

#include "../types/bxiarrays.h"
#include "../strings/bxistrconv.h"

u32 bytes2hex(char * buffer, bxi_bytes * bytes, bxi_hex_format fmt)
{
    u32 i;
    u32 pos = 0;

    if (!buffer)
        return 0;
    if (!bytes)
        return 0;
    if (fmt >= BXI_HEX_COUNT)
        return 0;

    switch (fmt)
    {
    case BXI_HEX_ASCII:
        for (i = 0; i < bytes->size; i++)
            buffer[pos++] = bytes->byte[i];
        break;
    case BXI_HEX_DOUBLEHEX:
        for (i = 0; i < bytes->size; i++)
        {
            buffer[pos++] = bxi_hexes_high[(bytes->byte[i] >> 4) & 0xf];
            buffer[pos++] = bxi_hexes_high[(bytes->byte[i]     ) & 0xf];
        }
        break;
    case BXI_HEX_DOUBLEHEXWITHSPACE:
        for (i = 0; i < bytes->size; i++)
        {
            buffer[pos++] = bxi_hexes_high[(bytes->byte[i] >> 4) & 0xf];
            buffer[pos++] = bxi_hexes_high[(bytes->byte[i]     ) & 0xf];
            buffer[pos++] = ' ';
        }
        break;
    case BXI_HEX_DOUBLEHEXWITHCOMMAANDSPACE:
        for (i = 0; i < bytes->size; i++)
        {
            buffer[pos++] = bxi_hexes_high[(bytes->byte[i] >> 4) & 0xf];
            buffer[pos++] = bxi_hexes_high[(bytes->byte[i]     ) & 0xf];
            buffer[pos++] = ',';
            buffer[pos++] = ' ';
        }
        break;
    case BXI_HEX_DOUBLELOWHEX:
        for (i = 0; i < bytes->size; i++)
        {
            buffer[pos++] = bxi_hexes_low[(bytes->byte[i] >> 4) & 0xf];
            buffer[pos++] = bxi_hexes_low[(bytes->byte[i]     ) & 0xf];
        }
        break;
    case BXI_HEX_DOUBLELOWHEXWITHSPACE:
        for (i = 0; i < bytes->size; i++)
        {
            buffer[pos++] = bxi_hexes_low[(bytes->byte[i] >> 4) & 0xf];
            buffer[pos++] = bxi_hexes_low[(bytes->byte[i]     ) & 0xf];
            buffer[pos++] = ' ';
        }
        break;
    case BXI_HEX_DOUBLELOWHEXWITHCOMMAANDSPACE:
        for (i = 0; i < bytes->size; i++)
        {
            buffer[pos++] = bxi_hexes_low[(bytes->byte[i] >> 4) & 0xf];
            buffer[pos++] = bxi_hexes_low[(bytes->byte[i]     ) & 0xf];
            buffer[pos++] = ',';
            buffer[pos++] = ' ';
        }
        break;
    default: ;
    }

    buffer[pos++] = '\0';
    return pos;
}
