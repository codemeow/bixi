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

#ifndef BXIBASE64_H
#define BXIBASE64_H

#include "../types/bxiints.h"

EXPORT typedef enum
{
    BXI_BASE64_RFC1421,
    BXI_BASE64_RFC2045,
    BXI_BASE64_RFC3548,
    BXI_BASE64_Y64,
    BXI_BASE64_XMLTOKEN,
    BXI_BASE64_XMLNAME,
    BXI_BASE64_PIDENT1,
    BXI_BASE64_PIDENT2,
    BXI_BASE64_FREENET,
    BXI_BASE64_RFC4880,
    BXI_BASE64_RFC1642,
    BXI_BASE64_RFC3501,

    BXI_BASE64_COUNT,

    BXI_BASE64_RFC4648  = BXI_BASE64_RFC3548,
    BXI_BASE64_RFC7515  = BXI_BASE64_RFC4648,
    BXI_BASE64_RFC2152  = BXI_BASE64_RFC1642,

    BXI_BASE64_STANDARD = BXI_BASE64_RFC4648,
    BXI_BASE64_MIME     = BXI_BASE64_RFC2045,
    BXI_BASE64_PEM      = BXI_BASE64_RFC1421,
    BXI_BASE64_RADIX64  = BXI_BASE64_RFC4880,
    BXI_BASE64_UTF7     = BXI_BASE64_RFC1642,
    BXI_BASE64_IMAP     = BXI_BASE64_RFC3501,
    BXI_BASE64_URL      = BXI_BASE64_RFC4648,
    BXI_BASE64_OPENPGP  = BXI_BASE64_RFC4880

} bxi_base64_rfc;

EXPORT_FROM
#define BXI_BASE64_ENC_SIZE (4)
#define BXI_BASE64_DEC_SIZE (3)

#define BXI_STR2BASE64_OUT_SIZE(IN) (((IN) + (BXI_BASE64_DEC_SIZE - 1)) / BXI_BASE64_DEC_SIZE * BXI_BASE64_ENC_SIZE + 1)
#define BXI_BASE642STR_OUT_SIZE(IN) (((IN) + (BXI_BASE64_ENC_SIZE - 1)) / BXI_BASE64_ENC_SIZE * BXI_BASE64_DEC_SIZE + 1)
EXPORT_TO

EXPORT void bxi_bin2base64(u8 * in, u32 len, char * out, bxi_base64_rfc rfc);
/* @todo bxi_bas642bin */

#endif /* BXIBASE64_H */

