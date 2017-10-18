#include "../strings/bxistrconv.h"
#include "../strings/bxistring.h"
#include "../types/bxiboints.h"
#include "../math/bximath.h"

const char bxi_hexes_high[] = "0123456789ABCDEF";
const char bxi_hexes_low [] = "0123456789abcdef";

i32 str2i32(const char * str, i32 * len)
{
    i32 sign = 0;
    u32 ures = 0;
    i32 pos  = 0;
    u32 skp  = 0;

    if (!str)
    {
       if (len) *len = BXI_STRERROR_NOSTRING;
       return 0;
    }

    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    else if (*str == '+')
    {
        sign = +1;
        str++;
    }

    while(isasciispace(str[pos]))
    {
        str++;
        skp++;
    }

    if (!sign)
    {
        if (*str == '-')
        {
            sign = -1;
            str++;
        }
        else if (*str == '+')
        {
            sign = +1;
            str++;
        }
    }
    else
    {
        if (len) *len = BXI_STRERROR_CONVOVERFLOW;
        return 0;
    }

    while (str[pos])
    {
        if ((str[pos] >= '0') && (str[pos] <= '9'))
        {
            if (ures > U32_MAX / 10)
            {
                if (len) *len = BXI_STRERROR_CONVOVERFLOW;
                return 0;
            }
            ures *= 10;

            if ((u32)(ures + str[pos] - '0') < ures)
            {
                if (len) *len = BXI_STRERROR_CONVOVERFLOW;
                return 0;
            }
            ures += str[pos] - '0';
        }
        else
        {
            if (pos && !sign)
                break;

            if (len) *len = BXI_STRERROR_BADSTRING;
            return 0;
        }

        pos++;
    }

    if (!pos)
    {
        if (len) *len = BXI_STRERROR_BADSTRING;
        return 0;
    }

    if (((ures >      I32_MAX    )  && (!sign || (sign ==  1))) ||
        ((ures > (u32)I32_MAX + 1)  && (sign == -1)))
    {
        if (len) *len = BXI_STRERROR_CONVOVERFLOW;
        return 0;
    }

    if (len) *len = pos + (sign ? 1 : 0) + skp;

    return (i32)ures * (sign ? sign : 1);
}

i8 str2i8(const char * str, i32 * len)
{
    i32 lloc = 0;
    i32 res32 = str2i32(str, &lloc);
    if (lloc)
    {
        if (len) *len = lloc;
        return 0;
    }

    if ((res32 > I8_MAX) || (res32 < I8_MIN))
    {
        if (len) *len = BXI_STRERROR_CONVOVERFLOW;
        return 0;
    }

    if (len) *len = lloc;
    return res32;
}

i16 str2i16(const char * str, i32 * len)
{
    i32 lloc = 0;
    i32 res32 = str2i32(str, &lloc);
    if (lloc)
    {
        if (len) *len = lloc;
        return 0;
    }

    if ((res32 > I16_MAX) || (res32 < I16_MIN))
    {
        if (len) *len = BXI_STRERROR_CONVOVERFLOW;
        return 0;
    }

    if (len) *len = lloc;
    return res32;
}

u32 str2u32(const char * str, i32 * len)
{
    u32 ures = 0;
    i32 pos  = 0;
    u32 skp  = 0;

    if (!str)
    {
       if (len) *len = BXI_STRERROR_NOSTRING;
       return 0;
    }

    while(isasciispace(str[pos]))
    {
        str++;
        skp++;
    }

    if (*str == '+')
    {
        str++;
        skp++;
    }

    while (str[pos])
    {
        if ((str[pos] >= '0') && (str[pos] <= '9'))
        {
            if (ures > U32_MAX / 10)
            {
                if (len) *len = BXI_STRERROR_CONVOVERFLOW;
                return 0;
            }
            ures *= 10;

            if ((u32)(ures + str[pos] - '0') < ures)
            {
                if (len) *len = BXI_STRERROR_CONVOVERFLOW;
                return 0;
            }
            ures += str[pos] - '0';
        }
        else
        {
            if (len) *len = BXI_STRERROR_BADSTRING;
            return 0;
        }

        pos++;
    }

    if (!pos)
    {
        if (len) *len = BXI_STRERROR_BADSTRING;
        return 0;
    }

    if (len) *len = pos + skp;
    return ures;
}

u8 str2u8(const char * str, i32 * len)
{
    i32 lloc = 0;
    u32 res32 = str2u32(str, &lloc);
    if (lloc)
    {
        if (len) *len = lloc;
        return 0;
    }

    if (res32 > U8_MAX)
    {
        if (len) *len = BXI_STRERROR_CONVOVERFLOW;
        return 0;
    }

    if (len) *len = lloc;
    return res32;
}

u16 str2u16(const char * str, i32 * len)
{
    i32 lloc = 0;
    u32 res32 = str2u32(str, &lloc);
    if (lloc)
    {
        if (len) *len = lloc;
        return 0;
    }

    if (res32 > U16_MAX)
    {
        if (len) *len = BXI_STRERROR_CONVOVERFLOW;
        return 0;
    }

    if (len) *len = lloc;
    return res32;
}

u32 hex2raw(const char * hex, u8 * raw)
{
    u8 c = 0;
    u32 pos = 0;

    if (!hex)
        return 0;
    if (!raw)
        return 0;

    while (hex[pos])
    {
        if      ((hex[pos] >= '0') && (hex[pos] <= '9'))
           c += ( hex[pos] -  '0') << (4 * (1 - (pos % 2)));
        else if ((hex[pos] >= 'A') && (hex[pos] <= 'F'))
           c += ( hex[pos] -  'A' + 10) << (4 * (1 - (pos % 2)));
        else if ((hex[pos] >= 'a') && (hex[pos] <= 'f'))
           c += ( hex[pos] -  'a' + 10) << (4 * (1 - (pos % 2)));
        else
        {
            return 0;
        }

        if (pos % 2)
        {
            raw[pos / 2] = c;
            c = 0;
        }

        pos++;
    }

    /* @todo what if FFF */

    return pos / 2;
}

u32 hex2u32end(char * str, i32 * len, bxi_ends end)
{
    i32 llen = 0;
    i32 i;
    u8 raw[sizeof(u32)];
    u32 result = 0;

    if (!str)
        return 0;

    if (bxi_strlen(str) > bxi_strlen("0xffffffff"))
    {
        if (len) *len = BXI_STRERROR_CONVOVERFLOW;
        return 0;
    }

    if ((bxi_strlen(str) > 2) &&
        ((str[0] == '0') && (str[1] == 'x')))
    {
        str += 2;
    }

    llen = hex2raw(str, raw);
    if (llen == 0)
    {
        if (len) *len = BXI_STRERROR_BADSTRING;
        return 0;
    }

    if (llen > (i32)sizeof(u32))
    {
        if (len) *len = BXI_STRERROR_CONVOVERFLOW;
        return 0;
    }

    if (end == BXI_ENDIANNESS_LE)
    {
        for (i = 0; i < llen; i++)
        {
            result <<= BITS_IN_BYTE;
            result += raw[i];
        }
    }
    else
    {
        for (i = llen - 1; i >= 0; i--)
        {
            result <<= 8;
            result += raw[i];
        }
    }

    if (len) *len = llen;
    return result;
}

u32 hex2u32(char * str, i32 * len)
{
    return hex2u32end(str, len, IS_BE ? BXI_ENDIANNESS_BE : BXI_ENDIANNESS_LE);
}

u16 hex2u16(char * str, i32 * len)
{
    i32 llen = 0;
    u32 result = hex2u32end(str, &llen, IS_BE ? BXI_ENDIANNESS_BE : BXI_ENDIANNESS_LE);
    if (llen < BXI_STRERROR_SUCCESS)
    {
        if (len) *len = llen;
    }

    if (result > U16_MAX)
    {
        if (len) *len = BXI_STRERROR_CONVOVERFLOW;
        return 0;
    }

    return result;
}

u8 hex2u8(char * str, i32 * len)
{
    i32 llen = 0;
    u32 result = hex2u32end(str, &llen, IS_BE ? BXI_ENDIANNESS_BE : BXI_ENDIANNESS_LE);
    if (llen < BXI_STRERROR_SUCCESS)
    {
        if (len) *len = llen;
    }

    if (result > U8_MAX)
    {
        if (len) *len = BXI_STRERROR_CONVOVERFLOW;
        return 0;
    }

    return result;
}

u16_le hex2u16_le(char * str, i32 * len)
{
    i32 llen = 0;
    u32 result = hex2u32end(str, &llen, BXI_ENDIANNESS_LE);
    if (llen < BXI_STRERROR_SUCCESS)
    {
        if (len) *len = llen;
    }

    if (result > U16_LE_MAX)
    {
        if (len) *len = BXI_STRERROR_CONVOVERFLOW;
        return 0;
    }

    return result;
}

u32_le hex2u32_le(char * str, i32 * len)
{
    return hex2u32end(str, len, BXI_ENDIANNESS_LE);
}

u16_be hex2u16_be(char * str, i32 * len)
{
    i32 llen = 0;
    u32 result = hex2u32end(str, &llen, BXI_ENDIANNESS_BE);
    if (llen < BXI_STRERROR_SUCCESS)
    {
        if (len) *len = llen;
    }

    if (result > U16_BE_MAX)
    {
        if (len) *len = BXI_STRERROR_CONVOVERFLOW;
        return 0;
    }

    return result;
}

u32_be hex2u32_be(char * str, i32 * len)
{
    return hex2u32end(str, len, BXI_ENDIANNESS_BE);
}

u32 i2str(char * str, i32 val)
{
    u32 pos = 0;
    u32 len = 1;
    u32 ttl = 0;
    i32 tmp = val;

    if (!str)
        return 0;

    if (val < 0)
        str[pos++] = '-';

    while (tmp / 10 != 0)
    {
        len++;
        tmp /= 10;
    }

    str[len + pos] = '\0';
    ttl = len + pos;

    while (len--)
    {
        str[len + pos] = bxi_abs(val % 10) + '0';
        val /= 10;
    }

    return ttl;
}

u32 u2str(char * str, u32 val)
{
    u32 len = 1;
    u32 ttl = 0;
    u32 tmp = val;

    if (!str)
        return 0;

    while (tmp / 10 != 0)
    {
        len++;
        tmp /= 10;
    }

    str[len] = '\0';
    ttl = len;

    while (len--)
    {
        str[len] = val % 10 + '0';
        val /= 10;
    }

    return ttl;
}
/*
u32 i2hex(char * str, i32 val)
{

} */

u32 u2hex_doublelowhex(char * str, u32 val, u32 len)
{
    const u32 w = 2;
    u32 ttl;

    len += len % w;
    str[len] = '\0';
    ttl = len;

    while (len--)
    {
        str[len] = bxi_hexes_low[val % 16];

        val /= 16;
    }

    return ttl;
}

u32 u2hex(char * str, u32 val, bxi_hex_format fmt)
{
    u32 len = 1;
    u32 tmp = val;

    if (!str)
        return 0;

    while (tmp / 16 != 0)
    {
        len++;
        tmp /= 16;
    }

    switch (fmt)
    {
    case BXI_HEX_DOUBLELOWHEX : return u2hex_doublelowhex(str, val, len);
    default: ;
    }

    return 0;
}

u32 i2hex(char * str, i32 val, bxi_hex_format fmt)
{
    bool minus = false;

    if (!str)
        return 0;

    if (val < 0)
    {
        *str++ = '-';
        val = -(u32)val;
        minus = true;
    }

    return u2hex(str, (u32)val, fmt) + minus;
}

u32 i82str(char * str, i8 val)
{
    return i2str(str, val);
}

u32 u82str (char * str, u8 val)
{
    return u2str(str, val);
}

u32 i162str(char * str, i16 val)
{
    return i2str(str, val);
}

u32 u162str(char * str, u16 val)
{
    return u2str(str, val);
}

u32 i322str(char * str, i32 val)
{
    return i2str(str, val);
}

u32 u322str(char * str, u32 val)
{
    return u2str(str, val);
}

u32 i16_le2str(char * str, i16_le val)
{
    return i2str(str, IS_LE ? val : (i16)chgend16(val));
}

u32 u16_le2str(char * str, u16_le val)
{
    return u2str(str, IS_LE ? val : (u16)chgend16(val));
}

u32 i32_le2str(char * str, i32_le val)
{
    return i2str(str, IS_LE ? val : (i32)chgend32(val));
}

u32 u32_le2str(char * str, u32_le val)
{
    return u2str(str, IS_LE ? val : (u32)chgend32(val));
}

u32 i16_be2str(char * str, i16_be val)
{
    return i2str(str, IS_BE ? val : (i16)chgend16(val));
}

u32 u16_be2str(char * str, u16_be val)
{
    return u2str(str, IS_BE ? val : (u16)chgend16(val));
}

u32 i32_be2str(char * str, i32_be val)
{
    return i2str(str, IS_BE ? val : (i32)chgend32(val));
}

u32 u32_be2str(char * str, u32_be val)
{
    return u2str(str, IS_BE ? val : (u32)chgend32(val));
}

u32 i82hex (char * str, i8  val)
{
    return i2hex(str, val, BXI_HEX_DEFAULT);
}

u32 u82hex (char * str, u8 val)
{
    return u2hex(str, val, BXI_HEX_DEFAULT);
}

u32 i162hex(char * str, i16 val)
{
    return i2hex(str, val, BXI_HEX_DEFAULT);
}

u32 u162hex(char * str, u16 val)
{
    return u2hex(str, val, BXI_HEX_DEFAULT);
}

u32 i322hex(char * str, i32 val)
{
    return i2hex(str, val, BXI_HEX_DEFAULT);
}

u32 u322hex(char * str, u32 val)
{
    return u2hex(str, val, BXI_HEX_DEFAULT);
}

u32 i16_le2hex(char * str, i16_le val)
{
    return i2hex(str, IS_LE ? val : (i16)chgend16(val), BXI_HEX_DEFAULT);
}

u32 u16_le2hex(char * str, u16_le val)
{
    return u2hex(str, IS_LE ? val : (u16)chgend16(val), BXI_HEX_DEFAULT);
}

u32 i32_le2hex(char * str, i32_le val)
{
    return i2hex(str, IS_LE ? val : (i32)chgend32(val), BXI_HEX_DEFAULT);
}

u32 u32_le2hex(char * str, u32_le val)
{
    return u2hex(str, IS_LE ? val : (u32)chgend32(val), BXI_HEX_DEFAULT);
}

u32 i16_be2hex(char * str, i16_be val)
{
    return i2hex(str, IS_BE ? val : (i16)chgend16(val), BXI_HEX_DEFAULT);
}

u32 u16_be2hex(char * str, u16_be val)
{
    return u2hex(str, IS_BE ? val : (u16)chgend16(val), BXI_HEX_DEFAULT);
}

u32 i32_be2hex(char * str, i32_be val)
{
    return i2hex(str, IS_BE ? val : (i32)chgend32(val), BXI_HEX_DEFAULT);
}

u32 u32_be2hex(char * str, u32_be val)
{
    return u2hex(str, IS_BE ? val : (u32)chgend32(val), BXI_HEX_DEFAULT);
}
