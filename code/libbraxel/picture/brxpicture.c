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

#include "../picture/brxpicture.h"
#include "../alphabet/brxalpha.h"

typedef u8 (*brx_mode_func)(u8 b, u8 f);

static u8 brx_mode_back  (u8 b, u8 f) { UNUSED(f); return   b;      }
static u8 brx_mode_front (u8 b, u8 f) { UNUSED(b); return       f;  }
static u8 brx_mode_nback (u8 b, u8 f) { UNUSED(f); return ! b;      }
static u8 brx_mode_nfront(u8 b, u8 f) { UNUSED(b); return      !f;  }
static u8 brx_mode_or    (u8 b, u8 f) {            return   b | f;  }
static u8 brx_mode_and   (u8 b, u8 f) {            return   b & f;  }
static u8 brx_mode_xor   (u8 b, u8 f) {            return   b ^ f;  }
static u8 brx_mode_nor   (u8 b, u8 f) {            return !(b | f); }
static u8 brx_mode_nand  (u8 b, u8 f) {            return !(b & f); }

brx_mode_func brx_modes[BRX_MODE_COUNT] =
{
    brx_mode_back,
    brx_mode_front,
    brx_mode_nback,
    brx_mode_nfront,
    brx_mode_or,
    brx_mode_and,
    brx_mode_xor,
    brx_mode_nor,
    brx_mode_nand
};

static u8 brx_data_get(brx_pic_t * pic, u32 x, u32 y)
{
    u32 Bi, bi;
    Bi = (x + y * pic->size.x) / BRX_BRAILLE_BITS;
    bi = (x + y * pic->size.x) % BRX_BRAILLE_BITS;

    return 1 & (pic->data.data[Bi] >> bi);
}

static void brx_data_set(brx_pic_t * pic, u32 x, u32 y, u8 value)
{
    u32 Bi, bi;
    Bi = (x + y * pic->size.x) / BRX_BRAILLE_BITS;
    bi = (x + y * pic->size.x) % BRX_BRAILLE_BITS;

    if (value) pic->data.data[Bi] |=  (1 << bi);
          else pic->data.data[Bi] &= ~(1 << bi);
}

static u8 brx_char_get(brx_pic_t * pic, u32 x, u32 y)
{
    return (brx_data_get(pic, x + 0, y + 0) << 0) |
           (brx_data_get(pic, x + 0, y + 1) << 1) |
           (brx_data_get(pic, x + 0, y + 2) << 2) |
           (brx_data_get(pic, x + 1, y + 0) << 3) |
           (brx_data_get(pic, x + 1, y + 1) << 4) |
           (brx_data_get(pic, x + 1, y + 2) << 5) |
           (brx_data_get(pic, x + 0, y + 3) << 6) |
           (brx_data_get(pic, x + 1, y + 3) << 7) ;
}

brx_pic_t * brx_pic_create(bxi_size size)
{
    brx_pic_t * pic = bxi_malloc(sizeof(brx_pic_t));

    pic->size.x = size.x + size.x % BRX_BRAILLE_WIDTH;
    pic->size.y = size.y + size.y % BRX_BRAILLE_HEIGHT;
    pic->data.size = (pic->size.x * pic->size.y) / BRX_BRAILLE_BITS + 1;
    pic->data.data = bxi_malloc(pic->data.size);

    return pic;
}

void brx_pic_free(brx_pic_t * pic)
{
    if (!pic)
        return;

    bxi_free(pic->data.data);
    bxi_free(pic);
}

void brx_pic_draw(brx_pic_t * pic, FILE * file)
{
    u32 x, y;

    if ((!pic) || (!file))
        return;

    for (y = 0; y < pic->size.y; y += BRX_BRAILLE_HEIGHT, fprintf(file, "\n"))
    for (x = 0; x < pic->size.x; x += BRX_BRAILLE_WIDTH)
        fprintf(file, "%s", (char *)&brx_alpha[brx_char_get(pic, x, y)]);
}

void brx_pic_pixel_set(brx_pic_t * pic, bxi_point pt, u8 value)
{
    if (!pic)
        return;

    if ((pt.x < 0) || pt.y < 0)
        return;

    if ((pt.x >= (i32)pic->size.x) ||
        (pt.y >= (i32)pic->size.y))
        return;

    brx_data_set(pic, pt.x, pt.y, !!value);
}

u8 brx_pic_pixel_get(brx_pic_t * pic, bxi_point pt)
{
    if (!pic)
        return 0;

    if ((pt.x < 0) || pt.y < 0)
        return 0;

    if ((pt.x >= (i32)pic->size.x) ||
        (pt.y >= (i32)pic->size.y))
        return 0;

    return brx_data_get(pic, pt.x, pt.y);
}

void brx_pic_map(brx_pic_t * back, brx_pic_t * front, bxi_point pt, brx_mode mode)
{
    i32 yb, ye;
    i32 xb, xf;
    i32 c;
    i32 lx, ly;

    yb = BXI_MAX(pt.y, 0);
    ye = front->size.y + pt.y >  back->size.y ?
          back->size.y : pt.y + front->size.y;
    xb = BXI_MAX(pt.x, 0);
    xf = pt.x < 0 ? -pt.x : 0;

    if (pt.x < 0)
    {
        if ((pt.x + front->size.x) > back->size.x) c =  back->size.x;
                                              else c = front->size.x + pt.x;
    }
    else
    {
        if ((pt.x + front->size.x) > back->size.x) c =  back->size.x - pt.x;
                                              else c = front->size.x;
    }

    for (ly = yb; ly < ye; ly++)
    for (lx = 0;  lx < c;  lx++)
    {
        u8 vb, vf;
        vf = brx_data_get(front, lx + xf, ly - yb);
        vb = brx_data_get( back, lx + xb, ly);
        brx_data_set(back, lx + xb, ly, brx_modes[mode](vb, vf));
    }
}

