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

#ifndef BRXPICTURE_H
#define BRXPICTURE_H

#include <stdio.h>

#include <libbixi.h>

EXPORT typedef struct
{
    bxi_size size;
    bxi_bts  data;
} brx_pic_t;

EXPORT typedef enum
{
    BRX_MODE_BACK,
    BRX_MODE_FRONT,
    BRX_MODE_NOT_BACK,
    BRX_MODE_NOT_FRONT,

    BRX_MODE_OR,
    BRX_MODE_AND,
    BRX_MODE_XOR,
    BRX_MODE_NOR,
    BRX_MODE_NAND,

    BRX_MODE_COUNT
} brx_mode;

EXPORT brx_pic_t * brx_pic_create   (bxi_size   size);
EXPORT void        brx_pic_free     (brx_pic_t * pic);
EXPORT void        brx_pic_draw     (brx_pic_t * pic, FILE * file);
EXPORT void        brx_pic_pixel_set(brx_pic_t * pic, bxi_point pt, u8 value);
EXPORT u8          brx_pic_pixel_get(brx_pic_t * pic, bxi_point pt);
EXPORT void        brx_pic_map(brx_pic_t * back, brx_pic_t * front, bxi_point pt, brx_mode mode);

#endif /* BRXPICTURE_H */

