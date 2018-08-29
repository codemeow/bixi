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

#include "./init/brxinit.h"
#include "./graph/brxpic.h"
#include "./engine/brxengine.h"



static void terminal_init(void)
{
    bxi_sleep(1);
}


int main(void)
{
    brx_bixi_init();
    brx_pics_init();

    terminal_init();

    game_loop();

    brx_pics_free();

    return 0;
}
