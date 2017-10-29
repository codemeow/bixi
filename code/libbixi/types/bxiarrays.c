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

#include "../math/bximath.h"
#include "../types/bxiarrays.h"
#include "../strings/bxistrconv.h"

u32 bxi_raw2hex(char * out, u8 * raw, u32 count, bxi_hex_format format)
{
    u32 i = 0;
    u32 pos = 0;
    u32 group = 0;

    if (!out)
        return 0;
    if (!raw)
        return 0;

    if (((bxi_sign(format & BXI_HEX_CASE_LOW)) +
         (bxi_sign(format & BXI_HEX_CASE_UP ))) != 1)
        return 0;

    if (((bxi_sign(format & BXI_HEX_GROUP_2)) +
         (bxi_sign(format & BXI_HEX_GROUP_3)) +
         (bxi_sign(format & BXI_HEX_GROUP_4)) +
         (bxi_sign(format & BXI_HEX_GROUP_8))) > 1)
        return 0;

    group = (format & BXI_HEX_GROUP_2) ? 2 :
            (format & BXI_HEX_GROUP_3) ? 3 :
            (format & BXI_HEX_GROUP_4) ? 4 :
            (format & BXI_HEX_GROUP_8) ? 8 : 1;

    for (i = 0; i < count; i++)
    {
        if (i % group == 0)
        {
            if (format & BXI_HEX_PREFIX_AMP ) out[pos++] = '&';
            if (format & BXI_HEX_PREFIX_HASH) out[pos++] = '#';
            if (format & BXI_HEX_PREFIX_DOL ) out[pos++] = '$';
            if (format & BXI_HEX_PREFIX_0   ) out[pos++] = '0';
            if (format & BXI_HEX_PREFIX_x   ) out[pos++] = 'x';
        }

        if (format & BXI_HEX_CASE_UP)
        {
            out[pos++] = bxi_hexes_high[(raw[i] >> 4) & 0xf];
            out[pos++] = bxi_hexes_high[(raw[i]     ) & 0xf];
        }
        else if (format & BXI_HEX_CASE_LOW)
        {
            out[pos++] = bxi_hexes_low[(raw[i] >> 4) & 0xf];
            out[pos++] = bxi_hexes_low[(raw[i]     ) & 0xf];
        }


        if (i % group == (group - 1))
        {
            if (format & BXI_HEX_SUFFIX_h   ) out[pos++] = 'h';
            if (format & BXI_HEX_SUFFIX_u   ) out[pos++] = 'u';
            if (format & BXI_HEX_SUFFIX_l   ) out[pos++] = 'l';
        }

        if ((i % group == (group - 1)) &&
            (!((format & BXI_HEX_END_CLOSED) && (i == count - 1))))
        {
            if (format & BXI_HEX_DELIM_COMMA) out[pos++] = ',';
            if (format & BXI_HEX_DELIM_SEMIC) out[pos++] = ';';
            if (format & BXI_HEX_DELIM_COLON) out[pos++] = ':';
            if (format & BXI_HEX_DELIM_SPACE) out[pos++] = ' ';
        }
    }

    out[pos] = '\0';
    return pos;
}
