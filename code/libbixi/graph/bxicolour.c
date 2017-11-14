#include "../graph/bxicolour.h"

bxi_argb bxi_colour2argb(bxi_colour col)
{
    bxi_argb res;
    res.a = (col >> 24) & 0xff;
    res.r = (col >> 16) & 0xff;
    res.g = (col >>  8) & 0xff;
    res.b = (col      ) & 0xff;
    return res;
}

bxi_colour bxi_argb2colour(bxi_argb  argb)
{
    return (argb.a << 24) |
           (argb.r << 16) |
           (argb.g <<  8) |
           (argb.b      );
}
