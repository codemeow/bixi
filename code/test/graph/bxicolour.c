/*
 * «Bixi» - Basic types management C89 library
 *
 *  Copyright (C) Alexey Shishkin 2017
 *
 *  This file is part of Project «Bixi».
 *
 *  Project «Bixi» is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Project «Bixi» is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with Project «Bixi». If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <libbixi.h>
#include "../test.h"
#include "../graph/bxicolour.h"

void test_graph_bxicolour(void)
{
    print_info;

    printf("            NORMAL  BRIGHT\n");
    printf("   %s \x1b[48;5;%dm        \x1b[48;5;%dm        \x1b[0m\n",
           "  BLACK", BXI_COLOUR_A256_BLACK,   BXI_COLOUR_A256_B_BLACK);
    printf("   %s \x1b[48;5;%dm        \x1b[48;5;%dm        \x1b[0m\n",
           "    RED", BXI_COLOUR_A256_RED,     BXI_COLOUR_A256_B_RED);
    printf("   %s \x1b[48;5;%dm        \x1b[48;5;%dm        \x1b[0m\n",
           "  GREEN", BXI_COLOUR_A256_GREEN,   BXI_COLOUR_A256_B_GREEN);
    printf("   %s \x1b[48;5;%dm        \x1b[48;5;%dm        \x1b[0m\n",
           " YELLOW", BXI_COLOUR_A256_YELLOW,  BXI_COLOUR_A256_B_YELLOW);
    printf("   %s \x1b[48;5;%dm        \x1b[48;5;%dm        \x1b[0m\n",
           "   BLUE", BXI_COLOUR_A256_BLUE,    BXI_COLOUR_A256_B_BLUE);
    printf("   %s \x1b[48;5;%dm        \x1b[48;5;%dm        \x1b[0m\n",
           "MAGENTA", BXI_COLOUR_A256_MAGENTA, BXI_COLOUR_A256_B_MAGENTA);
    printf("   %s \x1b[48;5;%dm        \x1b[48;5;%dm        \x1b[0m\n",
           "   CYAN", BXI_COLOUR_A256_CYAN,    BXI_COLOUR_A256_B_CYAN);
    printf("   %s \x1b[48;5;%dm        \x1b[48;5;%dm        \x1b[0m\n",
           "  WHITE", BXI_COLOUR_A256_WHITE,   BXI_COLOUR_A256_B_WHITE);

    print_passed();
}
