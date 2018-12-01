#include "../strings/bxistrconv.h"
#include "../strings/bxistring.h"
#include "../types/bxiboints.h"
#include "../math/bximath.h"
#include "../utils/bximemutils.h"

const char bxi_hexes_high[] = "0123456789ABCDEF";
const char bxi_hexes_low [] = "0123456789abcdef";

i32 bxi_str2i32(const char * str, i32 * len) {
    i32 sign = 0;
    u32 ures = 0;
    u32 pos  = 0;
    u32 skp  = 0;

    if (!str) {
       if (len) *len = BXI_STRERROR_NOSTRING;
       return 0;
    }

    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        sign = +1;
        str++;
    }

    while(bxi_isspace(str[pos])) {
        str++;
        skp++;
    }

    if (!sign) {
        if (*str == '-') {
            sign = -1;
            str++;
        } else if (*str == '+') {
            sign = +1;
            str++;
        }
    }

    while (str[pos]) {
        if ((str[pos] >= '0') && (str[pos] <= '9')) {
            if (ures > U32_MAX / 10) {
                if (len) *len = BXI_STRERROR_CONVOVERFLOW;
                return 0;
            }
            ures *= 10;

            if ((u32)(ures + str[pos] - '0') < ures) {
                if (len) *len = BXI_STRERROR_CONVOVERFLOW;
                return 0;
            }
            ures += str[pos] - '0';
        } else {
            if (pos && (sign != 0))
                break;

            if (len) *len = BXI_STRERROR_BADSTRING;
            return 0;
        }

        pos++;
    }

    if (!pos) {
        if (len) *len = BXI_STRERROR_BADSTRING;
        return 0;
    }

    if (((ures >      I32_MAX    )  && (!sign || (sign ==  1))) ||
        ((ures > (u32)I32_MAX + 1)  && (sign == -1))) {
        if (len) *len = BXI_STRERROR_CONVOVERFLOW;
        return 0;
    }

    if (len) *len = pos + (sign ? 1 : 0) + skp;

    return (i32)ures * (sign ? sign : 1);
}

i8 bxi_str2i8(const char * str, i32 * len) {
    i32 lloc = 0;
    i32 res32 = bxi_str2i32(str, &lloc);
    if (lloc < BXI_STRERROR_SUCCESS) {
        if (len) *len = lloc;
        return 0;
    }

    if ((res32 > I8_MAX) || (res32 < I8_MIN)) {
        if (len) *len = BXI_STRERROR_CONVOVERFLOW;
        return 0;
    }

    if (len) *len = lloc;
    return res32;
}

i16 bxi_str2i16(const char * str, i32 * len) {
    i32 lloc = 0;
    i32 res32 = bxi_str2i32(str, &lloc);
    if (lloc < BXI_STRERROR_SUCCESS) {
        if (len) *len = lloc;
        return 0;
    }

    if ((res32 > I16_MAX) || (res32 < I16_MIN)) {
        if (len) *len = BXI_STRERROR_CONVOVERFLOW;
        return 0;
    }

    if (len) *len = lloc;
    return res32;
}

u32 bxi_str2u32(const char * str, i32 * len) {
    u32 ures = 0;
    u32 pos  = 0;
    u32 skp  = 0;

    if (!str) {
       if (len) *len = BXI_STRERROR_NOSTRING;
       return 0;
    }

    while(bxi_isspace(str[pos])) {
        str++;
        skp++;
    }

    if (*str == '+') {
        str++;
        skp++;
    }

    while (str[pos]) {
        if ((str[pos] >= '0') && (str[pos] <= '9')) {
            if (ures > U32_MAX / 10) {
                if (len) *len = BXI_STRERROR_CONVOVERFLOW;
                return 0;
            }
            ures *= 10;

            if ((u32)(ures + str[pos] - '0') < ures) {
                if (len) *len = BXI_STRERROR_CONVOVERFLOW;
                return 0;
            }
            ures += str[pos] - '0';
        } else {
            if (len) *len = BXI_STRERROR_BADSTRING;
            return 0;
        }

        pos++;
    }

    if (!pos) {
        if (len) *len = BXI_STRERROR_BADSTRING;
        return 0;
    }

    if (len) *len = pos + skp;
    return ures;
}

u8 bxi_str2u8(const char * str, i32 * len) {
    i32 lloc = 0;
    u32 res32 = bxi_str2u32(str, &lloc);
    if (lloc < BXI_STRERROR_SUCCESS) {
        if (len) *len = lloc;
        return 0;
    }

    if (res32 > U8_MAX) {
        if (len) *len = BXI_STRERROR_CONVOVERFLOW;
        return 0;
    }

    if (len) *len = lloc;
    return res32;
}

u16 bxi_str2u16(const char * str, i32 * len) {
    i32 lloc = 0;
    u32 res32 = bxi_str2u32(str, &lloc);
    if (lloc < BXI_STRERROR_SUCCESS) {
        if (len) *len = lloc;
        return 0;
    }

    if (res32 > U16_MAX) {
        if (len) *len = BXI_STRERROR_CONVOVERFLOW;
        return 0;
    }

    if (len) *len = lloc;
    return res32;
}

u32 bxi_hex2raw(const char * hex, u8 * raw) {
    u8 c = 0;
    u32 pos = 0;

    if (!hex)
        return 0;
    if (!raw)
        return 0;

    if (bxi_strlen(hex) % 2)
        pos++;

    while (*hex) {
        if      ((*hex >= '0') && (*hex <= '9'))
           c += ( *hex -  '0'     ) << (4 * (1 - (pos % 2)));
        else if ((*hex >= 'A') && (*hex <= 'F'))
           c += ( *hex -  'A' + 10) << (4 * (1 - (pos % 2)));
        else if ((*hex >= 'a') && (*hex <= 'f'))
           c += ( *hex -  'a' + 10) << (4 * (1 - (pos % 2)));
        else
            return 0;

        if (pos % 2) {
            raw[pos / 2] = c;
            c = 0;
        }

        pos++;
        hex++;
    }

    return pos >> 1;
}

u32 bxi_hex2u32end(const char * str, i32 * len, bxi_ends end) {
    i32 llen = 0;
    u8 raw[sizeof(u32)];
    u32 result = 0;
    bool hexed = false;

    if (!str)
        return 0;

    if (bxi_strlen(str) > bxi_strlen("0xffffffff")) {
        if (len) *len = BXI_STRERROR_CONVOVERFLOW;
        return 0;
    }

    if ((bxi_strlen(str) > 2) && (str[0] == '0') && (str[1] == 'x')) {
        hexed = true;
        str += 2;
    }

    llen = bxi_hex2raw(str, raw);
    if (llen == 0) {
        if (len) *len = BXI_STRERROR_BADSTRING;
        return 0;
    }

    if (llen > (i32)sizeof(u32)) {
        if (len) *len = BXI_STRERROR_CONVOVERFLOW;
        return 0;
    }

    if (end == BXI_END_LE) {
        u32 dl = llen;
        u32 i;
        for (i = 0; i < dl; i++) {
             result <<= BITS_IN_BYTE;
             result += raw[i];
        }
    } else {
        u32 dl = llen - 1;
        do {
             result <<= BITS_IN_BYTE;
             result += raw[dl];
        }
        while (dl--);
    }

    if (len) *len = (llen * 2) + (i32)(hexed * 2);
    return result;
}

u32 bxi_hex2u32(const char * str, i32 * len) {
    return bxi_hex2u32end(str, len, IS_BE ? BXI_END_BE : BXI_END_LE);
}

u16 bxi_hex2u16(const char * str, i32 * len) {
    i32 llen = 0;
    u32 result = bxi_hex2u32end(str, &llen, IS_BE ? BXI_END_BE : BXI_END_LE);
    if (llen < BXI_STRERROR_SUCCESS) {
        if (len) *len = llen;
        return 0;
    }

    if (result > U16_MAX) {
        if (len) *len = BXI_STRERROR_CONVOVERFLOW;
        return 0;
    }

    if (len) *len = llen;
    return result;
}

u8 bxi_hex2u8(const char * str, i32 * len) {
    i32 llen = 0;
    u32 result = bxi_hex2u32end(str, &llen, IS_BE ? BXI_END_BE : BXI_END_LE);
    if (llen < BXI_STRERROR_SUCCESS) {
        if (len) *len = llen;
        return 0;
    }

    if (result > U8_MAX) {
        if (len) *len = BXI_STRERROR_CONVOVERFLOW;
        return 0;
    }

    if (len) *len = llen;
    return result;
}

i8 bxi_hex2i8(const char * str, i32 * len) {
    i32 llen = 0;
    i8 res;
    u8 buf = bxi_hex2u8(str, &llen);
    if (llen < BXI_STRERROR_SUCCESS) {
        if (len) *len = llen;
        return 0;
    }

    res = (i8)buf;

    if (len) *len = llen;
    return res;
}

i16 bxi_hex2i16(const char * str, i32 * len) {
    i32 llen = 0;
    i16 res;
    u16 buf = bxi_hex2u16(str, &llen);
    if (llen < BXI_STRERROR_SUCCESS) {
        if (len) *len = llen;
        return 0;
    }

    res = (i16)buf;

    if (len) *len = llen;
    return res;
}

i32 bxi_hex2i32(const char * str, i32 * len) {
    i32 llen = 0;
    i32 res;
    u32 buf = bxi_hex2u32(str, &llen);
    if (llen < BXI_STRERROR_SUCCESS) {
        if (len) *len = llen;
        return 0;
    }

    res = (i32)buf;

    if (len) *len = llen;
    return res;
}

u16_le bxi_hex2u16_le(const char * str, i32 * len) {
    i32 llen = 0;
    u32 result = bxi_hex2u32end(str, &llen, BXI_END_LE);
    if (llen < BXI_STRERROR_SUCCESS) {
        if (len) *len = llen;
        return 0;
    }

    if (result > U16_LE_MAX) {
        if (len) *len = BXI_STRERROR_CONVOVERFLOW;
        return 0;
    }

    if (len) *len = llen;
    return result;
}

i16_le bxi_hex2i16_le(const char * str, i32 * len) {
    i32 llen = 0;
    i16_le res;
    u16_le buf = bxi_hex2u16_le(str, &llen);
    if (llen < BXI_STRERROR_SUCCESS) {
        if (len) *len = llen;
        return 0;
    }

    res = (i16_le)buf;

    if (len) *len = llen;
    return res;
}

u32_le bxi_hex2u32_le(const char * str, i32 * len)
{
    return bxi_hex2u32end(str, len, BXI_END_LE);
}

i32_le bxi_hex2i32_le(const char * str, i32 * len) {
    i32 llen = 0;
    i32_le res;
    u32_le buf = bxi_hex2u32_le(str, &llen);
    if (llen < BXI_STRERROR_SUCCESS) {
        if (len) *len = llen;
        return 0;
    }

    res = (i32_le)buf;

    if (len) *len = llen;
    return res;
}

u16_be bxi_hex2u16_be(const char * str, i32 * len) {
    i32 llen = 0;
    u32 result = bxi_hex2u32end(str, &llen, BXI_END_BE);
    if (llen < BXI_STRERROR_SUCCESS) {
        if (len) *len = llen;
        return 0;
    }

    if (result > U16_BE_MAX) {
        if (len) *len = BXI_STRERROR_CONVOVERFLOW;
        return 0;
    }

    if (len) *len = llen;
    return result;
}

i16_be bxi_hex2i16_be(const char * str, i32 * len) {
    i32 llen = 0;
    i16_be res;
    u16_be buf = bxi_hex2u16_be(str, &llen);
    if (llen < BXI_STRERROR_SUCCESS) {
        if (len) *len = llen;
        return 0;
    }

    res = (i16_be)buf;

    if (len) *len = llen;
    return res;
}

u32_be bxi_hex2u32_be(const char * str, i32 * len) {
    return bxi_hex2u32end(str, len, BXI_END_BE);
}

i32_be bxi_hex2i32_be(const char * str, i32 * len) {
    i32 llen = 0;
    i32_be res;
    u32_be buf = bxi_hex2u32_be(str, &llen);
    if (llen < BXI_STRERROR_SUCCESS) {
        if (len) *len = llen;
        return 0;
    }

    res = (i32_be)buf;

    if (len) *len = llen;
    return res;
}

static u32 i2str(char * str, i32 val) {
    u32 pos = 0;
    u32 len = 1;
    u32 ttl = 0;
    i32 tmp = val;

    if (!str)
        return 0;

    if (val < 0)
        str[pos++] = '-';

    while (tmp / 10 != 0) {
        len++;
        tmp /= 10;
    }

    str[len + pos] = '\0';
    ttl = len + pos;

    while (len--) {
        str[len + pos] = bxi_abs(val % 10) + '0';
        val /= 10;
    }

    return ttl;
}

static u32 u2str(char * str, u32 val) {
    u32 len = 1;
    u32 ttl = 0;
    u32 tmp = val;

    if (!str)
        return 0;

    while (tmp / 10 != 0) {
        len++;
        tmp /= 10;
    }

    str[len] = '\0';
    ttl = len;

    while (len--) {
        str[len] = val % 10 + '0';
        val /= 10;
    }

    return ttl;
}

static u32 u2hex_doublelowhex(char * str, u32 val, u32 len) {
    const u32 w = 2;
    u32 ttl;

    len += len % w;
    str[len] = '\0';
    ttl = len;

    while (len--) {
        str[len] = bxi_hexes_low[val % 16];

        val /= 16;
    }

    return ttl;
}

static u32 u2hex(char * str, u32 val) {
    u32 len = 1;
    u32 tmp = val;

    if (!str)
        return 0;

    while ((tmp >> 4) != 0) {
        len++;
        tmp >>= 4;
    }

    return u2hex_doublelowhex(str, val, len);
}

static u32 i2hex(char * str, i32 val, u32 size) {
    u32 uval = 0;
    bxi_memcpy(&uval, &val, size);

    return u2hex(str, uval);
}

u32 bxi_i82str(char * out, i8 val) {
    return i2str(out, val);
}

u32 bxi_u82str (char * out, u8 val) {
    return u2str(out, val);
}

u32 bxi_i162str(char * out, i16 val) {
    return i2str(out, val);
}

u32 bxi_u162str(char * out, u16 val) {
    return u2str(out, val);
}

u32 bxi_i322str(char * out, i32 val) {
    return i2str(out, val);
}

u32 bxi_u322str(char * out, u32 val) {
    return u2str(out, val);
}

u32 bxi_i16_le2str(char * out, i16_le val) {
    return i2str(out, IS_LE ? val : (i16)bxi_chgend16(val));
}

u32 bxi_u16_le2str(char * out, u16_le val) {
    return u2str(out, IS_LE ? val : (u16)bxi_chgend16(val));
}

u32 bxi_i32_le2str(char * out, i32_le val) {
    return i2str(out, IS_LE ? val : (i32)bxi_chgend32(val));
}

u32 bxi_u32_le2str(char * out, u32_le val) {
    return u2str(out, IS_LE ? val : (u32)bxi_chgend32(val));
}

u32 bxi_i16_be2str(char * out, i16_be val) {
    return i2str(out, IS_BE ? val : (i16)bxi_chgend16(val));
}

u32 bxi_u16_be2str(char * out, u16_be val) {
    return u2str(out, IS_BE ? val : (u16)bxi_chgend16(val));
}

u32 bxi_i32_be2str(char * out, i32_be val) {
    return i2str(out, IS_BE ? val : (i32)bxi_chgend32(val));
}

u32 bxi_u32_be2str(char * out, u32_be val) {
    return u2str(out, IS_BE ? val : (u32)bxi_chgend32(val));
}

u32 bxi_i82hex (char * out, i8  val) {
    return i2hex(out, val, sizeof(i8));
}

u32 bxi_u82hex (char * out, u8 val) {
    return u2hex(out, val);
}

u32 bxi_i162hex(char * out, i16 val) {
    return i2hex(out, val, sizeof(i16));
}

u32 bxi_u162hex(char * out, u16 val) {
    return u2hex(out, val);
}

u32 bxi_i322hex(char * out, i32 val) {
    return i2hex(out, val, sizeof(i32));
}

u32 bxi_u322hex(char * out, u32 val) {
    return u2hex(out, val);
}

u32 bxi_i16_le2hex(char * out, i16_le val) {
    return i2hex(out, IS_LE ? val : (i16)bxi_chgend16(val), sizeof(i16_le));
}

u32 bxi_u16_le2hex(char * out, u16_le val) {
    return u2hex(out, IS_LE ? val : (u16)bxi_chgend16(val));
}

u32 bxi_i32_le2hex(char * out, i32_le val) {
    return i2hex(out, IS_LE ? val : (i32)bxi_chgend32(val), sizeof(i32_le));
}

u32 bxi_u32_le2hex(char * out, u32_le val) {
    return u2hex(out, IS_LE ? val : (u32)bxi_chgend32(val));
}

u32 bxi_i16_be2hex(char * out, i16_be val) {
    return i2hex(out, IS_BE ? val : (i16)bxi_chgend16(val), sizeof(i16_be));
}

u32 bxi_u16_be2hex(char * out, u16_be val) {
    return u2hex(out, IS_BE ? val : (u16)bxi_chgend16(val));
}

u32 bxi_i32_be2hex(char * out, i32_be val) {
    return i2hex(out, IS_BE ? val : (i32)bxi_chgend32(val), sizeof(i32_be));
}

u32 bxi_u32_be2hex(char * out, u32_be val) {
    return u2hex(out, IS_BE ? val : (u32)bxi_chgend32(val));
}

u32 bxi_raw2hex(char * out, u8 * raw, u32 count, bxi_hex_format format) {
    u32 i = 0;
    u32 pos = 0;
    u32 group = 0;

    if (!out)
        return 0;
    if (!raw) {
        out[pos] = '\0';
        return 0;
    }

    if (((bxi_sign(format & BXI_HEX_CASE_LOW)) +
         (bxi_sign(format & BXI_HEX_CASE_UP ))) != 1) {
        out[pos] = '\0';
        return 0;
    }

    if (((bxi_sign(format & BXI_HEX_GROUP_2)) +
         (bxi_sign(format & BXI_HEX_GROUP_3)) +
         (bxi_sign(format & BXI_HEX_GROUP_4)) +
         (bxi_sign(format & BXI_HEX_GROUP_8))) > 1) {
        out[pos] = '\0';
        return 0;
    }

    group = (format & BXI_HEX_GROUP_2) ? 2 :
            (format & BXI_HEX_GROUP_3) ? 3 :
            (format & BXI_HEX_GROUP_4) ? 4 :
            (format & BXI_HEX_GROUP_8) ? 8 : 1;

    for (i = 0; i < count; i++) {
        if (i % group == 0) {
            if (format & BXI_HEX_PREFIX_AMP ) out[pos++] = '&';
            if (format & BXI_HEX_PREFIX_HASH) out[pos++] = '#';
            if (format & BXI_HEX_PREFIX_DOL ) out[pos++] = '$';
            if (format & BXI_HEX_PREFIX_0   ) out[pos++] = '0';
            if (format & BXI_HEX_PREFIX_x   ) out[pos++] = 'x';
        }

        if (format & BXI_HEX_CASE_UP) {
            out[pos++] = bxi_hexes_high[(raw[i] >> 4) & 0xf];
            out[pos++] = bxi_hexes_high[(raw[i]     ) & 0xf];
        } else if (format & BXI_HEX_CASE_LOW) {
            out[pos++] = bxi_hexes_low[(raw[i] >> 4) & 0xf];
            out[pos++] = bxi_hexes_low[(raw[i]     ) & 0xf];
        }


        if (i % group == (group - 1)) {
            if (format & BXI_HEX_SUFFIX_h   ) out[pos++] = 'h';
            if (format & BXI_HEX_SUFFIX_u   ) out[pos++] = 'u';
            if (format & BXI_HEX_SUFFIX_l   ) out[pos++] = 'l';
        }

        if ((i % group == (group - 1)) &&
            (!((format & BXI_HEX_END_CLOSED) && (i == count - 1)))) {
            if (format & BXI_HEX_DELIM_COMMA) out[pos++] = ',';
            if (format & BXI_HEX_DELIM_SEMIC) out[pos++] = ';';
            if (format & BXI_HEX_DELIM_COLON) out[pos++] = ':';
            if (format & BXI_HEX_DELIM_SPACE) out[pos++] = ' ';
        }
    }

    out[pos] = '\0';
    return pos;
}

static u32 generic2raw(void * val, u8 * raw, u32 size) {
    bxi_memcpy(raw, val, size);
    return size;
}

u32 bxi_i82raw(i8 val, u8 * raw) {
    return generic2raw(&val, raw, sizeof(i8));
}

u32 bxi_u82raw(u8 val, u8 * raw) {
    return generic2raw(&val, raw, sizeof(u8));
}

u32 bxi_i162raw(i16 val, u8 * raw) {
    return generic2raw(&val, raw, sizeof(i16));
}

u32 bxi_i16_le2raw(i16_le val, u8 * raw) {
    if (IS_LE)
        return generic2raw(&val, raw, sizeof(i16_le));
    else {
        val = (i16_le)bxi_chgend16((u16)val);
        return generic2raw(&val, raw, sizeof(i16_le));
    }
}

u32 bxi_i16_be2raw(i16_be val, u8 * raw) {
    if (IS_BE)
        return generic2raw(&val, raw, sizeof(i16_be));
    else {
        val = (i16_be)bxi_chgend16((u16)val);
        return generic2raw(&val, raw, sizeof(i16_be));
    }
}

u32 bxi_u162raw(u16 val, u8 * raw) {
    return generic2raw(&val, raw, sizeof(u16));
}

u32 bxi_u16_le2raw(u16_le val, u8 * raw) {
    if (IS_LE)
        return generic2raw(&val, raw, sizeof(u16_le));
    else {
        val = bxi_chgend16(val);
        return generic2raw(&val, raw, sizeof(u16_le));
    }
}

u32 bxi_u16_be2raw(u16_be val, u8 * raw) {
    if (IS_BE)
        return generic2raw(&val, raw, sizeof(u16_be));
    else {
        val = bxi_chgend16(val);
        return generic2raw(&val, raw, sizeof(u16_be));
    }
}

u32 bxi_i322raw(i32 val, u8 * raw) {
    return generic2raw(&val, raw, sizeof(i32));
}

u32 bxi_i32_le2raw(i32_le val, u8 * raw) {
    if (IS_LE)
        return generic2raw(&val, raw, sizeof(i32_le));
    else {
        val = (i32_le)bxi_chgend32((u32)val);
        return generic2raw(&val, raw, sizeof(i32_le));
    }
}

u32 bxi_i32_be2raw(i32_be val, u8 * raw) {
    if (IS_BE)
        return generic2raw(&val, raw, sizeof(i32_be));
    else {
        val = (i32_be)bxi_chgend32((u32)val);
        return generic2raw(&val, raw, sizeof(i32_be));
    }
}

u32 bxi_u322raw(u32 val, u8 * raw) {
    return generic2raw(&val, raw, sizeof(u32));
}

u32 bxi_u32_le2raw(u32_le val, u8 * raw) {
    if (IS_LE)
        return generic2raw(&val, raw, sizeof(u32_le));
    else {
        val = bxi_chgend32(val);
        return generic2raw(&val, raw, sizeof(u32_le));
    }
}

u32 bxi_u32_be2raw(u32_be val, u8 * raw) {
    if (IS_BE)
        return generic2raw(&val, raw, sizeof(u32_be));
    else {
        val = bxi_chgend32(val);
        return generic2raw(&val, raw, sizeof(u32_be));
    }
}
