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

#include <stdio.h>

#include <libbixi.h>
#include <braxel/libbraxel.h>
#include "../graph/brxpic.h"
#include "../engine/brxparams.h"
#include "../engine/brxengine.h"

#define POSITION_START_X (0)
#define POSITION_START_Y (0)

#define BRICK_WIDTH  (6)
#define BRICK_HEIGHT (6)

#define GLASS_PT_WIDTH  (GLASS_WIDTH  * BRICK_WIDTH)
#define GLASS_PT_HEIGHT (GLASS_HEIGHT * BRICK_HEIGHT)

static const u8 tbl_brick[2][BRICK_HEIGHT][BRICK_WIDTH] = {
    {{ 0, 0, 0, 0, 0, 0},
     { 0, 0, 0, 0, 0, 0},
     { 0, 0, 0, 0, 0, 0},
     { 0, 0, 0, 0, 0, 0},
     { 0, 0, 0, 0, 0, 0},
     { 0, 0, 0, 0, 0, 0}},

    {{ 1, 1, 1, 1, 1, 0},
     { 1, 0, 0, 0, 1, 0},
     { 1, 0, 0, 1, 1, 0},
     { 1, 0, 1, 1, 1, 0},
     { 1, 1, 1, 1, 1, 0},
     { 0, 0, 0, 0, 0, 0}},
};

brx_pic_t * glass;
brx_pic_t * brick[2];

void brx_pics_init(void)
{
    u32 i;

    glass = brx_pic_create(bxi_size_c(GLASS_PT_WIDTH, GLASS_PT_HEIGHT));

    for (i = 0; i < 2; i++)
    {
        u32 x, y;

        brick[i] = brx_pic_create(bxi_size_c(BRICK_WIDTH, BRICK_HEIGHT));
        for (y = 0; y < BRICK_HEIGHT; y++)
        for (x = 0; x < BRICK_WIDTH ; x++)
            brx_pic_pixel_set(brick[i], bxi_point_c(x, y), tbl_brick[i][y][x]);
    }
}

static void terminal_reset(void)
{
    printf("\033[%u;%uH", POSITION_START_Y, POSITION_START_X);
}

void brx_pics_draw(void)
{
    u32 x, y;
    for (y = 0; y < GLASS_HEIGHT; y++)
    for (x = 0; x < GLASS_WIDTH;  x++)
        brx_pic_map(glass, brick[field[y][x]],
                bxi_point_c(x * BRICK_WIDTH, y * BRICK_HEIGHT), BRX_MODE_FRONT);
    for (y = 0; y < FIGURE_HEIGHT; y++)
    for (x = 0; x < FIGURE_WIDTH;  x++)
        brx_pic_map(glass, brick[figure[y][x]],
                bxi_point_c((x + figure_xy.x) * BRICK_WIDTH, (y + figure_xy.y) * BRICK_HEIGHT), BRX_MODE_OR);

    terminal_reset();
    brx_pic_draw(glass, stdout);
}

void brx_pics_free(void)
{
    brx_pic_free(glass);
    brx_pic_free(brick[0]);
    brx_pic_free(brick[1]);
}
