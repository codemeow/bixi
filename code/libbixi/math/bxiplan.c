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

bool bxi_line_cross(bxi_line * l1, bxi_line * l2, bxi_point * c)
{
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

    crs.x = dy1 * dx2 - dy2 * dx1;
    if(!crs.x || !dx2)
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
