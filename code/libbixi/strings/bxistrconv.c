#include "../strings/bxistrconv.h"
#include "../strings/bxistring.h"

i32 str2i32(const char * str, i32 * len)
{
    i32 sign = 0;
    u32 ures = 0;
    i32 res  = 0;
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
    res = ures;

    return res * (sign ? sign : 1);
}
