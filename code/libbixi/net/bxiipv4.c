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

#include "../net/bxiipv4.h"
#include "../strings/bxistrconv.h"
#include "../strings/bxistring.h"

u32 bxi_str2ipv4(const char * str) {
    u32  pos = 0;
    u32 data = 0;
    u32  blk = 0;
    bool alos = false;
    bxi_ipv4 res = BXI_IPV4_ZERO;
    const u32 len = bxi_strlen(str);

    if (!str)
        return BXI_IPV4_ZERO;

    while (pos < len) {
        char sym = str[pos++];

        if (bxi_isdigit(sym)) {
            data = data * 10 + sym - '0';
            if (data > U8_MAX)
                return BXI_IPV4_ZERO; /* 127.0.0.256 */
            alos = true;
        } else if (sym == '.') {
            if (blk < 3) {
                if (alos) {
                    res += (data << (BITS_IN_U8 * blk++));
                    data = 0;
                    alos = false;
                } else
                    return BXI_IPV4_ZERO; /* 127.0..1 */
            } else
                return BXI_IPV4_ZERO; /* 127.0.0.1.8 */
        } else
            return BXI_IPV4_ZERO; /* 127.0.0.G */
    }

    if (blk == 3)
         return res + (data << (BITS_IN_U8 * blk)); /* 127.0.0.1 */
    else return BXI_IPV4_ZERO; /* 127.0 */
}

char * bxi_ipv42str(bxi_ipv4 ip, char * str) {
    char * ptr = str;

    if (!str)
        return str;

    str += bxi_u82str(str, (ip >> (BITS_IN_U8 * 0)) & 0xff); *str++ = '.';
    str += bxi_u82str(str, (ip >> (BITS_IN_U8 * 1)) & 0xff); *str++ = '.';
    str += bxi_u82str(str, (ip >> (BITS_IN_U8 * 2)) & 0xff); *str++ = '.';
    str += bxi_u82str(str, (ip >> (BITS_IN_U8 * 3)) & 0xff); *str++ = '\0';

    return ptr;
}
