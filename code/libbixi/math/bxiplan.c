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

#include "../math/bxiplan.h"
#include "../math/bximath.h"
#include "../definitions/bximacros.h"

bxi_size bxi_size_c(u32 x, u32 y) {
    bxi_size res;
    res.x = x;
    res.y = y;
    return res;
}

bxi_point bxi_point_c(i32 x, i32 y) {
    bxi_point res;
    res.x = x;
    res.y = y;
    return res;
}

bxi_line bxi_line_c(bxi_point p1, bxi_point p2) {
    bxi_line res;
    res.p1 = p1;
    res.p2 = p2;
    return res;
}

bxi_rect bxi_rect_c(bxi_point p1, bxi_point p2) {
    bxi_rect res;
    res.p1 = p1;
    res.p2 = p2;
    return res;
}

bxi_circle bxi_circle_c(bxi_point c, i32 r) {
    bxi_circle res;
    res.c = c;
    res.r = r;
    return res;
}

bxi_triangle bxi_triangle_c(bxi_point p1, bxi_point p2, bxi_point p3) {
    bxi_triangle res;
    res.p1 = p1;
    res.p2 = p2;
    res.p3 = p3;
    return res;
}

bxi_tetragon bxi_tetragon_c(bxi_point p1, bxi_point p2, bxi_point p3, bxi_point p4) {
    bxi_tetragon res;
    res.p1 = p1;
    res.p2 = p2;
    res.p3 = p3;
    res.p4 = p4;
    return res;
}

bool bxi_segment_cross(bxi_line * l1, bxi_line * l2, bxi_point * c) {
    bxi_point crs;
    bool      res;
    i32	dx1;
    i32	dy1;
    i32	dx2;
    i32	dy2;

    if (!l1)
        return false;
    if (!l2)
        return false;

    dx1 = l1->p2.x - l1->p1.x;
    dy1 = l1->p2.y - l1->p1.y;
    dx2 = l2->p2.x - l2->p1.x;
    dy2 = l2->p2.y - l2->p1.y;

    if (dx2 == 0) {
        i32 mx_l1_y = BXI_MAX(l1->p1.y, l1->p2.y);
        i32 mn_l1_y = BXI_MIN(l1->p1.y, l1->p2.y);

        crs.x = l2->p1.x;
        crs.y = l1->p1.y + (dy1 * (dx1 - l2->p1.x + l1->p1.x)) / dx1;

        if ((mn_l1_y <= crs.y) &&
            (mx_l1_y >= crs.y)) {
            if (c)
                *c = crs;
            return true;
        }
        else
            return false;
    }

    crs.x = dy1 * dx2 - dy2 * dx1;
    if (crs.x == 0)
        return false;

    crs.y =   l2->p1.x * l2->p2.y - l2->p1.y * l2->p2.x;
    crs.x = ((l1->p1.x * l1->p2.y - l1->p1.y * l1->p2.x)
              * dx2 - crs.y * dx1) / crs.x;
    crs.y = (dy2 * crs.x - crs.y) / dx2;

    res = ((l1->p1.x <= crs.x && l1->p2.x >= crs.x) ||
           (l1->p2.x <= crs.x && l1->p1.x >= crs.x)) &&
          ((l2->p1.x <= crs.x && l2->p2.x >= crs.x) ||
           (l2->p2.x <= crs.x && l2->p1.x >= crs.x));

    if (c)
        *c = crs;
    return res;
}
