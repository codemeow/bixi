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

#ifndef BXIPLAN_H
#define BXIPLAN_H

#include "../definitions/bxiexport.h"
#include "../types/bxiints.h"
#include "../types/bxibools.h"
#include "../types/bxifloats.h"

EXPORT_FROM
#define MM_PER_INCH (25.4)
EXPORT_TO

EXPORT typedef struct
{
    f32 x;
    f32 y;
} bxi_pointf;

EXPORT typedef struct
{
    i32 x;
    i32 y;
} bxi_pointi;

EXPORT typedef struct
{
    u32 x;
    u32 y;
} bxi_pointu;

EXPORT typedef struct
{
    bxi_pointu p1;
    bxi_pointu p2;
} bxi_lineu;

EXPORT typedef struct
{
    bxi_pointi p1;
    bxi_pointi p2;
} bxi_linei;

EXPORT typedef struct
{
    bxi_pointf p1;
    bxi_pointf p2;
} bxi_linef;

EXPORT typedef bxi_linei bxi_recti;
EXPORT typedef bxi_lineu bxi_rectu;
EXPORT typedef bxi_linef bxi_rectf;

EXPORT typedef struct
{
    bxi_pointu p1;
    bxi_pointu p2;
    bxi_pointu p3;
} bxi_triangleu;

EXPORT typedef struct
{
    bxi_pointi p1;
    bxi_pointi p2;
    bxi_pointi p3;
} bxi_trianglei;

EXPORT typedef struct
{
    bxi_pointf p1;
    bxi_pointf p2;
    bxi_pointf p3;
} bxi_trianglef;

EXPORT typedef struct
{
    bxi_pointu p1;
    bxi_pointu p2;
    bxi_pointu p3;
    bxi_pointu p4;
} bxi_tetragonu;

EXPORT typedef struct
{
    bxi_pointi p1;
    bxi_pointi p2;
    bxi_pointi p3;
    bxi_pointi p4;
} bxi_tetragoni;

EXPORT typedef struct
{
    bxi_pointf p1;
    bxi_pointf p2;
    bxi_pointf p3;
    bxi_pointf p4;
} bxi_tetragonf;

EXPORT typedef struct
{
    bxi_pointi c;
    i32        r;
} bxi_circlei;

EXPORT typedef struct
{
    bxi_pointu c;
    u32        r;
} bxi_circleu;

EXPORT typedef struct
{
    bxi_pointf c;
    f32        r;
} bxi_circlef;

EXPORT typedef bxi_pointi    bxi_point;
EXPORT typedef bxi_linei     bxi_line;
EXPORT typedef bxi_recti     bxi_rect;
EXPORT typedef bxi_circlei   bxi_circle;
EXPORT typedef bxi_trianglei bxi_triangle;
EXPORT typedef bxi_tetragoni bxi_tetragon;

EXPORT typedef bxi_pointu    bxi_size;

EXPORT bxi_size     bxi_size_c    (u32 x,  u32 y);
EXPORT bxi_point    bxi_point_c   (i32 x,  i32 y);
EXPORT bxi_line     bxi_line_c    (bxi_point p1, bxi_point p2);
EXPORT bxi_rect     bxi_rect_c    (bxi_point p1, bxi_point p2);
EXPORT bxi_circle   bxi_circle_c  (bxi_point c,  i32 r);
EXPORT bxi_triangle bxi_triangle_c(bxi_point p1, bxi_point p2, bxi_point p3);
EXPORT bxi_tetragon bxi_tetragon_c(bxi_point p1, bxi_point p2, bxi_point p3, bxi_point p4);

EXPORT bool bxi_segment_cross(bxi_line * l1, bxi_line * l2, bxi_point * c);

#endif /* BXIPLAN_H */

