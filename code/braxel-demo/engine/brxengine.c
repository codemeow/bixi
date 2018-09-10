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

#include "../engine/brxengine.h"
#include "../graph/brxpic.h"

#define FIGURES_NUMBER (7)

u8 field [GLASS_HEIGHT ][GLASS_WIDTH ];
u8 figure[FIGURE_HEIGHT][FIGURE_WIDTH];

static const u8 figures[FIGURES_NUMBER][FIGURE_HEIGHT][FIGURE_WIDTH] = {
    {{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}},
    {{1, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}},
    {{0, 1, 0, 0}, {1, 1, 0, 0}, {1, 0, 0, 0}, {0, 0, 0, 0}},
    {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
    {{1, 1, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {0, 0, 0, 0}},
    {{1, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}},
    {{1, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
};

bxi_point figure_xy;
bxi_size  figure_wh;

static u8 figure_width(void)
{
    i32 x, y;
    for (y = 0; y < FIGURE_HEIGHT; y++)
    for (x = FIGURE_WIDTH - 1; x >= 0; x--)
        if (figure[y][x])
            return x;
    return 0;
}

static u8 figure_height(void)
{
    i32 x, y;
    for (y = FIGURE_HEIGHT - 1; y >= 0; y--)
    for (x = 0; x < FIGURE_WIDTH;  x++)
        if (figure[y][x])
            return y;
    return 0;
}

static void figure_spawn(void)
{
    u8 index = bxi_randu8() % FIGURES_NUMBER;
    i32 x, y;

    for (y = 0; y < FIGURE_HEIGHT; y++)
    for (x = 0; x < FIGURE_WIDTH; x++)
        figure[y][x] = figures[index][y][x];

    /* rotate */

    figure_wh.x = figure_width();
    figure_wh.y = figure_height();

    figure_xy.y = 0;
    figure_xy.x = bxi_randu8() % (GLASS_WIDTH - figure_wh.x);
}

static void figure_move(void)
{
    figure_xy.y++;
}

static bool figure_is_touched(void)
{
    i32 x, y;

    if ((figure_xy.y + figure_wh.y) == GLASS_HEIGHT - 1)
        return true;

    for (y = 0; y < FIGURE_HEIGHT; y++)
    for (x = 0; x < FIGURE_WIDTH;  x++)
        if (figure[y][x])
            if (field[figure_xy.y + y + 1]
                     [figure_xy.x + x])
                return true;

    return false;
}

static void field_recalc(void)
{
    i32 x, y;
    for (y = 0; y < FIGURE_HEIGHT; y++)
    for (x = 0; x < FIGURE_WIDTH;  x++)
        if (figure[y][x])
            field[figure_xy.y + y][figure_xy.x + x] = figure[y][x];
}

static bool field_is_full(void)
{
    i32 x;
    for (x = 0; x < GLASS_WIDTH; x++)
        if (field[0][x])
            return true;
    return false;
}

void game_loop(void)
{
    bxi_memset(field, 0, BXI_ARRAY_SIZE(field));

    forever
    {
        figure_spawn();
        forever
        {
            brx_pics_draw();
            if (figure_is_touched())
            {
                field_recalc();
                if (field_is_full())
                    return;
                break;
            }
            figure_move();

            bxi_msleep(100);
        }
    }
}
