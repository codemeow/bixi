#include "../graph/bxicolour.h"

bxi_argb bxi_colour2argb(bxi_colour col) {
    bxi_argb res;
    res.a = (col >> (BITS_IN_BYTE * 3)) & 0xff;
    res.r = (col >> (BITS_IN_BYTE * 2)) & 0xff;
    res.g = (col >> (BITS_IN_BYTE * 1)) & 0xff;
    res.b = (col >> (BITS_IN_BYTE * 0)) & 0xff;
    return res;
}

bxi_colour bxi_argb2colour(bxi_argb  argb) {
    return (argb.a << (BITS_IN_BYTE * 3)) |
           (argb.r << (BITS_IN_BYTE * 2)) |
           (argb.g << (BITS_IN_BYTE * 1)) |
           (argb.b << (BITS_IN_BYTE * 0));
}

