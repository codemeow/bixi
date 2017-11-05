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

#ifndef BXISTRCONV_H
#define BXISTRCONV_H

#include "../definitions/bxiexport.h"
#include "../types/bxiboints.h"

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

extern const char bxi_hexes_high[];
extern const char bxi_hexes_low [];

EXPORT u32 bxi_hex2u32end(const char * str, i32 * len, bxi_ends end);

EXPORT i8     bxi_str2i8    (const char * str, i32 * len);
EXPORT u8     bxi_str2u8    (const char * str, i32 * len);
EXPORT i16    bxi_str2i16   (const char * str, i32 * len);
EXPORT u16    bxi_str2u16   (const char * str, i32 * len);
EXPORT i32    bxi_str2i32   (const char * str, i32 * len);
EXPORT u32    bxi_str2u32   (const char * str, i32 * len);

EXPORT i8     bxi_hex2i8    (const char * str, i32 * len);
EXPORT u8     bxi_hex2u8    (const char * str, i32 * len);
EXPORT i16    bxi_hex2i16   (const char * str, i32 * len);
EXPORT u16    bxi_hex2u16   (const char * str, i32 * len);
EXPORT i32    bxi_hex2i32   (const char * str, i32 * len);
EXPORT u32    bxi_hex2u32   (const char * str, i32 * len);

EXPORT i16_le bxi_hex2i16_le(const char * str, i32 * len);
EXPORT u16_le bxi_hex2u16_le(const char * str, i32 * len);
EXPORT i32_le bxi_hex2i32_le(const char * str, i32 * len);
EXPORT u32_le bxi_hex2u32_le(const char * str, i32 * len);

EXPORT i16_be bxi_hex2i16_be(const char * str, i32 * len);
EXPORT u16_be bxi_hex2u16_be(const char * str, i32 * len);
EXPORT i32_be bxi_hex2i32_be(const char * str, i32 * len);
EXPORT u32_be bxi_hex2u32_be(const char * str, i32 * len);

EXPORT u32 bxi_hex2raw(const char * hex, u8 * raw);
EXPORT u32 bxi_raw2hex(      char * out, u8 * raw, u32 count, bxi_hex_format format);

EXPORT u32 bxi_i82raw    (i8     val, u8 * raw);
EXPORT u32 bxi_u82raw    (u8     val, u8 * raw);
EXPORT u32 bxi_i162raw   (i16    val, u8 * raw);
EXPORT u32 bxi_i16_le2raw(i16_le val, u8 * raw);
EXPORT u32 bxi_i16_be2raw(i16_be val, u8 * raw);
EXPORT u32 bxi_u162raw   (u16    val, u8 * raw);
EXPORT u32 bxi_u16_le2raw(u16_le val, u8 * raw);
EXPORT u32 bxi_u16_be2raw(u16_be val, u8 * raw);
EXPORT u32 bxi_i322raw   (i32    val, u8 * raw);
EXPORT u32 bxi_i32_le2raw(i32_le val, u8 * raw);
EXPORT u32 bxi_i32_be2raw(i32_be val, u8 * raw);
EXPORT u32 bxi_u322raw   (u32    val, u8 * raw);
EXPORT u32 bxi_u32_le2raw(u32_le val, u8 * raw);
EXPORT u32 bxi_u32_be2raw(u32_be val, u8 * raw);

EXPORT u32 bxi_i82hex    (char * out, i8     val);
EXPORT u32 bxi_i82str    (char * out, i8     val);
EXPORT u32 bxi_i162hex   (char * out, i16    val);
EXPORT u32 bxi_i162str   (char * out, i16    val);
EXPORT u32 bxi_i16_be2hex(char * out, i16_be val);
EXPORT u32 bxi_i16_be2str(char * out, i16_be val);
EXPORT u32 bxi_i16_le2hex(char * out, i16_le val);
EXPORT u32 bxi_i16_le2str(char * out, i16_le val);
EXPORT u32 bxi_i322hex   (char * out, i32    val);
EXPORT u32 bxi_i322str   (char * out, i32    val);
EXPORT u32 bxi_i32_be2hex(char * out, i32_be val);
EXPORT u32 bxi_i32_be2str(char * out, i32_be val);
EXPORT u32 bxi_i32_le2hex(char * out, i32_le val);
EXPORT u32 bxi_i32_le2str(char * out, i32_le val);

EXPORT u32 bxi_u82hex    (char * out, u8     val);
EXPORT u32 bxi_u82str    (char * out, u8     val);
EXPORT u32 bxi_u162hex   (char * out, u16    val);
EXPORT u32 bxi_u162str   (char * out, u16    val);
EXPORT u32 bxi_u16_be2hex(char * out, u16_be val);
EXPORT u32 bxi_u16_be2str(char * out, u16_be val);
EXPORT u32 bxi_u16_le2hex(char * out, u16_le val);
EXPORT u32 bxi_u16_le2str(char * out, u16_le val);
EXPORT u32 bxi_u322hex   (char * out, u32    val);
EXPORT u32 bxi_u322str   (char * out, u32    val);
EXPORT u32 bxi_u32_be2hex(char * out, u32_be val);
EXPORT u32 bxi_u32_be2str(char * out, u32_be val);
EXPORT u32 bxi_u32_le2hex(char * out, u32_le val);
EXPORT u32 bxi_u32_le2str(char * out, u32_le val);

#endif /* BXISTRCONV_H */

