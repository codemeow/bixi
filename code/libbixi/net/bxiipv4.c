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

bool bxi_str2ipv4(const char * str, bxi_ipv4 * ip)
{
    bool alos = false;
    u8 str_ind = 0;
    u8 res_ind = 0;
    u32 data   = 0;

    if ((!ip) || (!str))
        return false;

    while (str_ind < bxi_strlen(str))
    {
        u8 sym = str[str_ind];

        if (bxi_isdigit(sym))
        {
            sym -= '0';
            data = data * 10 + sym;
            if (data > U8_MAX)
                return false; /* 127.0.0.256, OVERFLOW */
            alos = true;
        }
        else if (sym == '.')
        {
            if (res_ind < 3)
            {
                if (alos)
                {
                    (*ip)[res_ind] = (data & 0xff);
                    data = 0;
                    res_ind++;
                    alos = false;
                }
                else
                    return false; /* 127.0..1 NOSYMBOL */
            }
            else
                return false; /* 127.0.0.1.2 TOOMANY */
        }
        else
            return false; /* 127.* INVALID */

        str_ind++;
    }

    if (res_ind == 3)
    {
        if (alos)
        {
            (*ip)[res_ind] = (data & 0xff);
            return true;
        }
        else
            return false; /* 127.0.0. NOSYMBOL */
    }
    else
        return false; /* 127.0 NOSYMBOL */
}

bool bxi_ipv42str(bxi_ipv4 * ip, char * str)
{
    if ((!ip) || (!str))
        return false;

    str += bxi_u82str(str, (*ip)[0]);
    *str++ = '.';
    str += bxi_u82str(str, (*ip)[1]);
    *str++ = '.';
    str += bxi_u82str(str, (*ip)[2]);
    *str++ = '.';
           bxi_u82str(str, (*ip)[3]);

    return true;
}

u32 bxi_ipv42u32(bxi_ipv4 ip)
{
    return (ip[0] << (BITS_IN_BYTE * 3)) |
           (ip[1] << (BITS_IN_BYTE * 2)) |
           (ip[2] << (BITS_IN_BYTE * 1)) |
           (ip[3]                      );
}

void bxi_u322ipv4(u32 pack, bxi_ipv4 ip)
{
    ip[0] = (pack >> (BITS_IN_BYTE * 3)) & 0xff;
    ip[1] = (pack >> (BITS_IN_BYTE * 2)) & 0xff;
    ip[2] = (pack >> (BITS_IN_BYTE * 1)) & 0xff;
    ip[3] = (pack                      ) & 0xff;
}
