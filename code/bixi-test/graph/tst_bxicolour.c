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
#include "../test.h"
#include "../graph/tst_bxicolour.h"

static void test_graph_mode_8(void)
{
    printf("        checking: 8-colours mode\n\n");
    printf("                   NORMAL  BRIGHT\n");
    printf("          %s \x1b[4%dm        \x1b[10%dm        \x1b[0m\n",
           "  BLACK", BXI_COLOUR_A8_BLACK,   BXI_COLOUR_A8_BLACK);
    printf("          %s \x1b[4%dm        \x1b[10%dm        \x1b[0m\n",
           "    RED", BXI_COLOUR_A8_RED,     BXI_COLOUR_A8_RED);
    printf("          %s \x1b[4%dm        \x1b[10%dm        \x1b[0m\n",
           "  GREEN", BXI_COLOUR_A8_GREEN,   BXI_COLOUR_A8_GREEN);
    printf("          %s \x1b[4%dm        \x1b[10%dm        \x1b[0m\n",
           " YELLOW", BXI_COLOUR_A8_YELLOW,  BXI_COLOUR_A8_YELLOW);
    printf("          %s \x1b[4%dm        \x1b[10%dm        \x1b[0m\n",
           "   BLUE", BXI_COLOUR_A8_BLUE,    BXI_COLOUR_A8_BLUE);
    printf("          %s \x1b[4%dm        \x1b[10%dm        \x1b[0m\n",
           "MAGENTA", BXI_COLOUR_A8_MAGENTA, BXI_COLOUR_A8_MAGENTA);
    printf("          %s \x1b[4%dm        \x1b[10%dm        \x1b[0m\n",
           "   CYAN", BXI_COLOUR_A8_CYAN,    BXI_COLOUR_A8_CYAN);
    printf("          %s \x1b[4%dm        \x1b[10%dm        \x1b[0m\n\n",
           "  WHITE", BXI_COLOUR_A8_WHITE,   BXI_COLOUR_A8_WHITE);
}

static void test_graph_mode_256(void)
{
    printf("        checking: 256-colours mode\n\n");
    printf("            \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
                   "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_000000, BXI_COLOUR_A256_00005F, BXI_COLOUR_A256_000087,
        BXI_COLOUR_A256_0000AF, BXI_COLOUR_A256_0000D7, BXI_COLOUR_A256_0000FF);
    printf("  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
             "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_5F0000, BXI_COLOUR_A256_5F005F, BXI_COLOUR_A256_5F0087,
        BXI_COLOUR_A256_5F00AF, BXI_COLOUR_A256_5F00D7, BXI_COLOUR_A256_5F00FF);
    printf("  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
             "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_870000, BXI_COLOUR_A256_87005F, BXI_COLOUR_A256_870087,
        BXI_COLOUR_A256_8700AF, BXI_COLOUR_A256_8700D7, BXI_COLOUR_A256_8700FF);
    printf("\n");
    printf("            \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
                   "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_005F00, BXI_COLOUR_A256_005F5F, BXI_COLOUR_A256_005F87,
        BXI_COLOUR_A256_005FAF, BXI_COLOUR_A256_005FD7, BXI_COLOUR_A256_005FFF);
    printf("  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
             "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_5F5F00, BXI_COLOUR_A256_5F5F5F, BXI_COLOUR_A256_5F5F87,
        BXI_COLOUR_A256_5F5FAF, BXI_COLOUR_A256_5F5FD7, BXI_COLOUR_A256_5F5FFF);
    printf("  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
             "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_875F00, BXI_COLOUR_A256_875F5F, BXI_COLOUR_A256_875F87,
        BXI_COLOUR_A256_875FAF, BXI_COLOUR_A256_875FD7, BXI_COLOUR_A256_875FFF);
    printf("\n");
    printf("            \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
                   "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_008700, BXI_COLOUR_A256_00875F, BXI_COLOUR_A256_008787,
        BXI_COLOUR_A256_0087AF, BXI_COLOUR_A256_0087D7, BXI_COLOUR_A256_0087FF);
    printf("  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
             "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_5F8700, BXI_COLOUR_A256_5F875F, BXI_COLOUR_A256_5F8787,
        BXI_COLOUR_A256_5F87AF, BXI_COLOUR_A256_5F87D7, BXI_COLOUR_A256_5F87FF);
    printf("  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
             "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_878700, BXI_COLOUR_A256_87875F, BXI_COLOUR_A256_878787,
        BXI_COLOUR_A256_8787AF, BXI_COLOUR_A256_8787D7, BXI_COLOUR_A256_8787FF);
    printf("\n");
    printf("            \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
                   "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_00AF00, BXI_COLOUR_A256_00AF5F, BXI_COLOUR_A256_00AF87,
        BXI_COLOUR_A256_00AFAF, BXI_COLOUR_A256_00AFD7, BXI_COLOUR_A256_00AFFF);
    printf("  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
             "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_5FAF00, BXI_COLOUR_A256_5FAF5F, BXI_COLOUR_A256_5FAF87,
        BXI_COLOUR_A256_5FAFAF, BXI_COLOUR_A256_5FAFD7, BXI_COLOUR_A256_5FAFFF);
    printf("  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
             "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_87AF00, BXI_COLOUR_A256_87AF5F, BXI_COLOUR_A256_87AF87,
        BXI_COLOUR_A256_87AFAF, BXI_COLOUR_A256_87AFD7, BXI_COLOUR_A256_87AFFF);
    printf("\n");
    printf("            \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
                   "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_00D700, BXI_COLOUR_A256_00D75F, BXI_COLOUR_A256_00D787,
        BXI_COLOUR_A256_00D7AF, BXI_COLOUR_A256_00D7D7, BXI_COLOUR_A256_00D7FF);
    printf("  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
             "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_5FD700, BXI_COLOUR_A256_5FD75F, BXI_COLOUR_A256_5FD787,
        BXI_COLOUR_A256_5FD7AF, BXI_COLOUR_A256_5FD7D7, BXI_COLOUR_A256_5FD7FF);
    printf("  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
             "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_87D700, BXI_COLOUR_A256_87D75F, BXI_COLOUR_A256_87D787,
        BXI_COLOUR_A256_87D7AF, BXI_COLOUR_A256_87D7D7, BXI_COLOUR_A256_87D7FF);
    printf("\n");
    printf("            \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
                   "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_00FF00, BXI_COLOUR_A256_00FF5F, BXI_COLOUR_A256_00FF87,
        BXI_COLOUR_A256_00FFAF, BXI_COLOUR_A256_00FFD7, BXI_COLOUR_A256_00FFFF);
    printf("  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
             "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_5FFF00, BXI_COLOUR_A256_5FFF5F, BXI_COLOUR_A256_5FFF87,
        BXI_COLOUR_A256_5FFFAF, BXI_COLOUR_A256_5FFFD7, BXI_COLOUR_A256_5FFFFF);
    printf("  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
             "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_87FF00, BXI_COLOUR_A256_87FF5F, BXI_COLOUR_A256_87FF87,
        BXI_COLOUR_A256_87FFAF, BXI_COLOUR_A256_87FFD7, BXI_COLOUR_A256_87FFFF);

    printf("\n");
    printf("\n");

    printf("            \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
                   "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_AF0000, BXI_COLOUR_A256_AF005F, BXI_COLOUR_A256_AF0087,
        BXI_COLOUR_A256_AF00AF, BXI_COLOUR_A256_AF00D7, BXI_COLOUR_A256_AF00FF);
    printf("  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
             "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_D70000, BXI_COLOUR_A256_D7005F, BXI_COLOUR_A256_D70087,
        BXI_COLOUR_A256_D700AF, BXI_COLOUR_A256_D700D7, BXI_COLOUR_A256_D700FF);
    printf("  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
             "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_FF0000, BXI_COLOUR_A256_FF005F, BXI_COLOUR_A256_FF0087,
        BXI_COLOUR_A256_FF00AF, BXI_COLOUR_A256_FF00D7, BXI_COLOUR_A256_FF00FF);
    printf("\n");
    printf("            \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
                   "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_AF5F00, BXI_COLOUR_A256_AF5F5F, BXI_COLOUR_A256_AF5F87,
        BXI_COLOUR_A256_AF5FAF, BXI_COLOUR_A256_AF5FD7, BXI_COLOUR_A256_AF5FFF);
    printf("  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
             "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_D75F00, BXI_COLOUR_A256_D75F5F, BXI_COLOUR_A256_D75F87,
        BXI_COLOUR_A256_D75FAF, BXI_COLOUR_A256_D75FD7, BXI_COLOUR_A256_D75FFF);
    printf("  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
             "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_FF5F00, BXI_COLOUR_A256_FF5F5F, BXI_COLOUR_A256_FF5F87,
        BXI_COLOUR_A256_FF5FAF, BXI_COLOUR_A256_FF5FD7, BXI_COLOUR_A256_FF5FFF);
    printf("\n");
    printf("            \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
                   "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_AF8700, BXI_COLOUR_A256_AF875F, BXI_COLOUR_A256_AF8787,
        BXI_COLOUR_A256_AF87AF, BXI_COLOUR_A256_AF87D7, BXI_COLOUR_A256_AF87FF);
    printf("  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
             "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_D78700, BXI_COLOUR_A256_D7875F, BXI_COLOUR_A256_D78787,
        BXI_COLOUR_A256_D787AF, BXI_COLOUR_A256_D787D7, BXI_COLOUR_A256_D787FF);
    printf("  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
             "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_FF8700, BXI_COLOUR_A256_FF875F, BXI_COLOUR_A256_FF8787,
        BXI_COLOUR_A256_FF87AF, BXI_COLOUR_A256_FF87D7, BXI_COLOUR_A256_FF87FF);
    printf("\n");
    printf("            \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
                   "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_AFAF00, BXI_COLOUR_A256_AFAF5F, BXI_COLOUR_A256_AFAF87,
        BXI_COLOUR_A256_AFAFAF, BXI_COLOUR_A256_AFAFD7, BXI_COLOUR_A256_AFAFFF);
    printf("  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
             "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_D7AF00, BXI_COLOUR_A256_D7AF5F, BXI_COLOUR_A256_D7AF87,
        BXI_COLOUR_A256_D7AFAF, BXI_COLOUR_A256_D7AFD7, BXI_COLOUR_A256_D7AFFF);
    printf("  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
             "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_FFAF00, BXI_COLOUR_A256_FFAF5F, BXI_COLOUR_A256_FFAF87,
        BXI_COLOUR_A256_FFAFAF, BXI_COLOUR_A256_FFAFD7, BXI_COLOUR_A256_FFAFFF);
    printf("\n");
    printf("            \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
                   "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_AFD700, BXI_COLOUR_A256_AFD75F, BXI_COLOUR_A256_AFD787,
        BXI_COLOUR_A256_AFD7AF, BXI_COLOUR_A256_AFD7D7, BXI_COLOUR_A256_AFD7FF);
    printf("  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
             "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_D7D700, BXI_COLOUR_A256_D7D75F, BXI_COLOUR_A256_D7D787,
        BXI_COLOUR_A256_D7D7AF, BXI_COLOUR_A256_D7D7D7, BXI_COLOUR_A256_D7D7FF);
    printf("  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
             "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_FFD700, BXI_COLOUR_A256_FFD75F, BXI_COLOUR_A256_FFD787,
        BXI_COLOUR_A256_FFD7AF, BXI_COLOUR_A256_FFD7D7, BXI_COLOUR_A256_FFD7FF);
    printf("\n");
    printf("            \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
                   "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_AFFF00, BXI_COLOUR_A256_AFFF5F, BXI_COLOUR_A256_AFFF87,
        BXI_COLOUR_A256_AFFFAF, BXI_COLOUR_A256_AFFFD7, BXI_COLOUR_A256_AFFFFF);
    printf("  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
             "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_D7FF00, BXI_COLOUR_A256_D7FF5F, BXI_COLOUR_A256_D7FF87,
        BXI_COLOUR_A256_D7FFAF, BXI_COLOUR_A256_D7FFD7, BXI_COLOUR_A256_D7FFFF);
    printf("  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
             "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_FFFF00, BXI_COLOUR_A256_FFFF5F, BXI_COLOUR_A256_FFFF87,
        BXI_COLOUR_A256_FFFFAF, BXI_COLOUR_A256_FFFFD7, BXI_COLOUR_A256_FFFFFF);

    printf("\n");
    printf("\n");

    printf("            \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
                   "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_080808, BXI_COLOUR_A256_121212, BXI_COLOUR_A256_1C1C1C,
        BXI_COLOUR_A256_262626, BXI_COLOUR_A256_303030, BXI_COLOUR_A256_3A3A3A);
    printf("  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
             "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_444444, BXI_COLOUR_A256_4E4E4E, BXI_COLOUR_A256_585858,
        BXI_COLOUR_A256_626262, BXI_COLOUR_A256_6C6C6C, BXI_COLOUR_A256_767676);
    printf("\n");
    printf("            \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
                   "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_808080, BXI_COLOUR_A256_8A8A8A, BXI_COLOUR_A256_949494,
        BXI_COLOUR_A256_9E9E9E, BXI_COLOUR_A256_A8A8A8, BXI_COLOUR_A256_B2B2B2);
    printf("  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  "
             "\x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[48;5;%dm  \x1b[0m",
        BXI_COLOUR_A256_BCBCBC, BXI_COLOUR_A256_C6C6C6, BXI_COLOUR_A256_D0D0D0,
        BXI_COLOUR_A256_DADADA, BXI_COLOUR_A256_E4E4E4, BXI_COLOUR_A256_EEEEEE);
    printf("\n\n");
}

static void test_graph_modes(void)
{
    printf("    modes:\n");
    test_graph_mode_8();
    test_graph_mode_256();
}

static void test_graph_test_bxi_colour_a(void)
{
    if (BXI_COLOUR_A(0x10203040u) != 0x10)
        test_failed();
    if (BXI_COLOUR_A(0xffffffffu) != 0xff)
        test_failed();
    if (BXI_COLOUR_A(0xabcdef01u) != 0xab)
        test_failed();
}

static void test_graph_test_bxi_colour_r(void)
{
    if (BXI_COLOUR_R(0x10203040u) != 0x20)
        test_failed();
    if (BXI_COLOUR_R(0xffffffffu) != 0xff)
        test_failed();
    if (BXI_COLOUR_R(0xabcdef01u) != 0xcd)
        test_failed();
}

static void test_graph_test_bxi_colour_g(void)
{
    if (BXI_COLOUR_G(0x10203040u) != 0x30)
        test_failed();
    if (BXI_COLOUR_G(0xffffffffu) != 0xff)
        test_failed();
    if (BXI_COLOUR_G(0xabcdef01u) != 0xef)
        test_failed();
}

static void test_graph_test_bxi_colour_b(void)
{
    if (BXI_COLOUR_B(0x10203040u) != 0x40)
        test_failed();
    if (BXI_COLOUR_B(0xffffffffu) != 0xff)
        test_failed();
    if (BXI_COLOUR_B(0xabcdef01u) != 0x01)
        test_failed();
}

static void test_graph_test_bxi_colour_argb(void)
{
    if (BXI_COLOUR_ARGB(0x10, 0x20, 0x30, 0x40) != 0x10203040u)
        test_failed();
    if (BXI_COLOUR_ARGB(0xff, 0xff, 0xff, 0xff) != 0xffffffffu)
        test_failed();
    if (BXI_COLOUR_ARGB(0xab, 0xcd, 0xef, 0x01) != 0xabcdef01u)
        test_failed();
}

static void test_graph_test_bxi_colour_mix(void)
{
    if (BXI_COLOUR_MIX(0x10203040u, 0x40302010u, 0x80) != 0x28282727u)
        test_failed();
    if (BXI_COLOUR_MIX(0x10203040u, 0x10203040u, 0x12) != 0x10203040u)
        test_failed();
    if (BXI_COLOUR_MIX(0xffffffffu, 0x00000000u, 0x80) != 0x7f7f7f7fu)
        test_failed();
}

static void test_graph_defines(void)
{
    printf("    defines:\n");
    TEST_BXI_MACRO_EXISTS(BXI_COLOUR_A);
        test_graph_test_bxi_colour_a();
    TEST_BXI_MACRO_EXISTS(BXI_COLOUR_R);
        test_graph_test_bxi_colour_r();
    TEST_BXI_MACRO_EXISTS(BXI_COLOUR_G);
        test_graph_test_bxi_colour_g();
    TEST_BXI_MACRO_EXISTS(BXI_COLOUR_B);
        test_graph_test_bxi_colour_b();
    TEST_BXI_MACRO_EXISTS_4(BXI_COLOUR_ARGB);
        test_graph_test_bxi_colour_argb();
    /* As the test macro requires to stringify the
     * macro value we can't check it as it generates
     * the string, longer than 509 characters.    */
    /*TEST_BXI_MACRO_EXISTS_3(BXI_COLOUR_MIX);*/
        test_graph_test_bxi_colour_mix();
    TEST_BXI_MACRO_EXISTS(BXI_COLOUR_RANDOM);
}

static void test_graph_test_bxi_colour2argb(void)
{
    bxi_argb argb;
    printf("        checking: bxi_colour2argb\n");

    argb = bxi_colour2argb(0x10203040u);
    if ((argb.a != 0x10) || (argb.r != 0x20) ||
        (argb.g != 0x30) || (argb.b != 0x40))
        test_failed();

    argb = bxi_colour2argb(0xffffffffu);
    if ((argb.a != 0xff) || (argb.r != 0xff) ||
        (argb.g != 0xff) || (argb.b != 0xff))
        test_failed();

    argb = bxi_colour2argb(0xabcdef01u);
    if ((argb.a != 0xab) || (argb.r != 0xcd) ||
        (argb.g != 0xef) || (argb.b != 0x01))
        test_failed();
}

static void test_graph_test_bxi_argb2colours(void)
{
    bxi_colour col;
    bxi_argb argb;

    printf("        checking: bxi_argb2colour\n");

    argb.a = 0x10; argb.r = 0x20;
    argb.g = 0x30; argb.b = 0x40;
    col = bxi_argb2colour(argb);
    if (col != 0x10203040u)
        test_failed();

    argb.a = 0xff; argb.r = 0xff;
    argb.g = 0xff; argb.b = 0xff;
    col = bxi_argb2colour(argb);
    if (col != 0xffffffffu)
        test_failed();

    argb.a = 0xab; argb.r = 0xcd;
    argb.g = 0xef; argb.b = 0x01;
    col = bxi_argb2colour(argb);
    if (col != 0xabcdef01u)
        test_failed();
}

static void test_graph_functions(void)
{
    printf("    functions:\n");
    test_graph_test_bxi_colour2argb();
    test_graph_test_bxi_argb2colours();
}

void test_graph_bxicolour(void)
{
    print_info;

    test_graph_defines();
    test_graph_functions();
    test_graph_modes();

    print_passed();
}
