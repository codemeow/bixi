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

#ifndef BXIARRAYS_H
#define BXIARRAYS_H

#include "../definitions/bxiexport.h"
#include "../types/bxiints.h"
#include "../strings/bxistrconv.h"

EXPORT_FROM
#define BXI_HEX_CASE_LOW    (1 << 0x00)
#define BXI_HEX_CASE_UP     (1 << 0x01)
#define BXI_HEX_PREFIX_AMP  (1 << 0x02)
#define BXI_HEX_PREFIX_HASH (1 << 0x03)
#define BXI_HEX_PREFIX_DOL  (1 << 0x04)
#define BXI_HEX_PREFIX_0    (1 << 0x05)
#define BXI_HEX_PREFIX_x    (1 << 0x06)
#define BXI_HEX_SUFFIX_h    (1 << 0x07)
#define BXI_HEX_SUFFIX_u    (1 << 0x08)
#define BXI_HEX_SUFFIX_l    (1 << 0x09)
#define BXI_HEX_DELIM_COMMA (1 << 0x0a)
#define BXI_HEX_DELIM_SEMIC (1 << 0x0b)
#define BXI_HEX_DELIM_COLON (1 << 0x0c)
#define BXI_HEX_DELIM_SPACE (1 << 0x0d)
#define BXI_HEX_GROUP_2     (1 << 0x0e)
#define BXI_HEX_GROUP_3     (1 << 0x0f)
#define BXI_HEX_GROUP_4     (1 << 0x10)
#define BXI_HEX_GROUP_8     (1 << 0x11)
#define BXI_HEX_END_CLOSED  (1 << 0x12)

#define BXI_HEX_COMBO_C      (BXI_HEX_PREFIX_0    | \
                              BXI_HEX_PREFIX_x    | \
                              BXI_HEX_CASE_LOW    | \
                              BXI_HEX_DELIM_COMMA | \
                              BXI_HEX_DELIM_SPACE )
#define BXI_HEX_COMBO_XML    (BXI_HEX_PREFIX_AMP  | \
                              BXI_HEX_PREFIX_HASH | \
                              BXI_HEX_PREFIX_x    | \
                              BXI_HEX_CASE_LOW    | \
                              BXI_HEX_DELIM_SEMIC )
#define BXI_HEX_COMBO_PASCAL (BXI_HEX_PREFIX_DOL  | \
                              BXI_HEX_CASE_LOW    | \
                              BXI_HEX_DELIM_COMMA | \
                              BXI_HEX_DELIM_SPACE )
#define BXI_HEX_COMBO_INTEL  (BXI_HEX_PREFIX_0    | \
                              BXI_HEX_CASE_UP     | \
                              BXI_HEX_SUFFIX_h    | \
                              BXI_HEX_DELIM_COMMA | \
                              BXI_HEX_DELIM_SPACE )
#define BXI_HEX_COMBO_IPv6   (BXI_HEX_CASE_LOW    | \
                              BXI_HEX_DELIM_COLON | \
                              BXI_HEX_GROUP_2     )
#define BXI_HEX_COMBO_CSS    (BXI_HEX_PREFIX_HASH | \
                              BXI_HEX_CASE_UP     | \
                              BXI_HEX_DELIM_COMMA | \
                              BXI_HEX_DELIM_SPACE | \
                              BXI_HEX_GROUP_3     )

EXPORT_TO
EXPORT typedef u32 bxi_hex_format;

EXPORT typedef struct
{
    u8 * byte;
    u32  size;
} bxi_bytes;

/* @todo array control functions */
/* @todo assigning *alloc/free functions */

/* @todo move it to conv */
EXPORT u32 bxi_raw2hex(char * out, u8 * raw, u32 count, bxi_hex_format format);

#endif /* BXIARRAYS_H */

