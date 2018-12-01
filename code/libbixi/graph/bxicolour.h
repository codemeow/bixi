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

#ifndef BXICOLOUR_H
#define BXICOLOUR_H

#include "../definitions/bxiexport.h"
#include "../types/bxiints.h"
#include "../random/bxirand.h"

EXPORT enum bxi_colours_ansi8 {
    BXI_COLOUR_A8_BLACK   = (0),
    BXI_COLOUR_A8_RED     = (1),
    BXI_COLOUR_A8_GREEN   = (2),
    BXI_COLOUR_A8_YELLOW  = (3),
    BXI_COLOUR_A8_BLUE    = (4),
    BXI_COLOUR_A8_MAGENTA = (5),
    BXI_COLOUR_A8_CYAN    = (6),
    BXI_COLOUR_A8_WHITE   = (7)
};

EXPORT enum bxi_colours_ansi256 {
    /* Widely supported */
    BXI_COLOUR_A256_BLACK          = (  0),
    BXI_COLOUR_A256_RED            = (  1),
    BXI_COLOUR_A256_GREEN          = (  2),
    BXI_COLOUR_A256_YELLOW         = (  3),
    BXI_COLOUR_A256_BLUE           = (  4),
    BXI_COLOUR_A256_MAGENTA        = (  5),
    BXI_COLOUR_A256_CYAN           = (  6),
    BXI_COLOUR_A256_WHITE          = (  7),
    BXI_COLOUR_A256_BRIGHT_BLACK   = (  8),
    BXI_COLOUR_A256_BRIGHT_RED     = (  9),
    BXI_COLOUR_A256_BRIGHT_GREEN   = ( 10),
    BXI_COLOUR_A256_BRIGHT_YELLOW  = ( 11),
    BXI_COLOUR_A256_BRIGHT_BLUE    = ( 12),
    BXI_COLOUR_A256_BRIGHT_MAGENTA = ( 13),
    BXI_COLOUR_A256_BRIGHT_CYAN    = ( 14),
    BXI_COLOUR_A256_BRIGHT_WHITE   = ( 15),
    /* Not widely supported */
    BXI_COLOUR_A256_000000 = ( 16), /* Black                */
    BXI_COLOUR_A256_00005F = ( 17), /* Navy                 */
    BXI_COLOUR_A256_000087 = ( 18), /* Dark Blue            */
    BXI_COLOUR_A256_0000AF = ( 19), /* New Midnight Blue    */
    BXI_COLOUR_A256_0000D7 = ( 20), /* Medium Blue          */
    BXI_COLOUR_A256_0000FF = ( 21), /* Blue                 */
    BXI_COLOUR_A256_005F00 = ( 22), /* Green                */
    BXI_COLOUR_A256_005F5F = ( 23), /* Mosque               */
    BXI_COLOUR_A256_005F87 = ( 24), /* Blue Lagoon          */
    BXI_COLOUR_A256_005FAF = ( 25), /* Denim                */
    BXI_COLOUR_A256_005FD7 = ( 26), /* Navy Blue            */
    BXI_COLOUR_A256_005FFF = ( 27), /* Navy Blue            */
    BXI_COLOUR_A256_008700 = ( 28), /* Green                */
    BXI_COLOUR_A256_00875F = ( 29), /* Tropical Rain Forest */
    BXI_COLOUR_A256_008787 = ( 30), /* Dark Cyan            */
    BXI_COLOUR_A256_0087AF = ( 31), /* Cerulean             */
    BXI_COLOUR_A256_0087D7 = ( 32), /* Pacific Blue         */
    BXI_COLOUR_A256_0087FF = ( 33), /* Dodger Blue          */
    BXI_COLOUR_A256_00AF00 = ( 34), /* Islamic Green        */
    BXI_COLOUR_A256_00AF5F = ( 35), /* Jade                 */
    BXI_COLOUR_A256_00AF87 = ( 36), /* Persian Green        */
    BXI_COLOUR_A256_00AFAF = ( 37), /* Iris Blue            */
    BXI_COLOUR_A256_00AFD7 = ( 38), /* Iris Blue            */
    BXI_COLOUR_A256_00AFFF = ( 39), /* Deep Sky Blue        */
    BXI_COLOUR_A256_00D700 = ( 40), /* Free Speech Green    */
    BXI_COLOUR_A256_00D75F = ( 41), /* Malachite            */
    BXI_COLOUR_A256_00D787 = ( 42), /* Caribbean Green      */
    BXI_COLOUR_A256_00D7AF = ( 43), /* Caribbean Green      */
    BXI_COLOUR_A256_00D7D7 = ( 44), /* Dark Turquoise       */
    BXI_COLOUR_A256_00D7FF = ( 45), /* Deep Sky Blue        */
    BXI_COLOUR_A256_00FF00 = ( 46), /* Lime                 */
    BXI_COLOUR_A256_00FF5F = ( 47), /* Spring Green         */
    BXI_COLOUR_A256_00FF87 = ( 48), /* Spring Green         */
    BXI_COLOUR_A256_00FFAF = ( 49), /* Medium Spring Green  */
    BXI_COLOUR_A256_00FFD7 = ( 50), /* Bright Turquoise     */
    BXI_COLOUR_A256_00FFFF = ( 51), /* Aqua                 */
    BXI_COLOUR_A256_5F0000 = ( 52), /* Maroon               */
    BXI_COLOUR_A256_5F005F = ( 53), /* Palatinate Purple    */
    BXI_COLOUR_A256_5F0087 = ( 54), /* Indigo               */
    BXI_COLOUR_A256_5F00AF = ( 55), /* Indigo               */
    BXI_COLOUR_A256_5F00D7 = ( 56), /* Electric Indigo      */
    BXI_COLOUR_A256_5F00FF = ( 57), /* Electric Indigo      */
    BXI_COLOUR_A256_5F5F00 = ( 58), /* Fiji Green           */
    BXI_COLOUR_A256_5F5F5F = ( 59), /* Zambezi              */
    BXI_COLOUR_A256_5F5F87 = ( 60), /* Comet                */
    BXI_COLOUR_A256_5F5FAF = ( 61), /* Rich Blue            */
    BXI_COLOUR_A256_5F5FD7 = ( 62), /* Slate Blue           */
    BXI_COLOUR_A256_5F5FFF = ( 63), /* Neon Blue            */
    BXI_COLOUR_A256_5F8700 = ( 64), /* Olive Drab           */
    BXI_COLOUR_A256_5F875F = ( 65), /* Hippie Green         */
    BXI_COLOUR_A256_5F8787 = ( 66), /* Half Baked           */
    BXI_COLOUR_A256_5F87AF = ( 67), /* Air Force Blue       */
    BXI_COLOUR_A256_5F87D7 = ( 68), /* Havelock Blue        */
    BXI_COLOUR_A256_5F87FF = ( 69), /* Cornflower Blue      */
    BXI_COLOUR_A256_5FAF00 = ( 70), /* Christi              */
    BXI_COLOUR_A256_5FAF5F = ( 71), /* Fern                 */
    BXI_COLOUR_A256_5FAF87 = ( 72), /* Silver Tree          */
    BXI_COLOUR_A256_5FAFAF = ( 73), /* Fountain Blue        */
    BXI_COLOUR_A256_5FAFD7 = ( 74), /* Malibu               */
    BXI_COLOUR_A256_5FAFFF = ( 75), /* Maya Blue            */
    BXI_COLOUR_A256_5FD700 = ( 76), /* Bright Green         */
    BXI_COLOUR_A256_5FD75F = ( 77), /* Pastel Green         */
    BXI_COLOUR_A256_5FD787 = ( 78), /* Emerald              */
    BXI_COLOUR_A256_5FD7AF = ( 79), /* Medium Aquamarine    */
    BXI_COLOUR_A256_5FD7D7 = ( 80), /* Turquoise Blue       */
    BXI_COLOUR_A256_5FD7FF = ( 81), /* Turquoise Blue       */
    BXI_COLOUR_A256_5FFF00 = ( 82), /* Bright Green         */
    BXI_COLOUR_A256_5FFF5F = ( 83), /* Screamin' Green      */
    BXI_COLOUR_A256_5FFF87 = ( 84), /* Screamin' Green      */
    BXI_COLOUR_A256_5FFFAF = ( 85), /* Aquamarine           */
    BXI_COLOUR_A256_5FFFD7 = ( 86), /* Aquamarine           */
    BXI_COLOUR_A256_5FFFFF = ( 87), /* Baby Blue            */
    BXI_COLOUR_A256_870000 = ( 88), /* Dark Red             */
    BXI_COLOUR_A256_87005F = ( 89), /* Eggplant             */
    BXI_COLOUR_A256_870087 = ( 90), /* Dark Magenta         */
    BXI_COLOUR_A256_8700AF = ( 91), /* Dark Violet          */
    BXI_COLOUR_A256_8700D7 = ( 92), /* Dark Violet          */
    BXI_COLOUR_A256_8700FF = ( 93), /* Electric Indigo      */
    BXI_COLOUR_A256_875F00 = ( 94), /* Golden Brown         */
    BXI_COLOUR_A256_875F5F = ( 95), /* Light Wood           */
    BXI_COLOUR_A256_875F87 = ( 96), /* Trendy Pink          */
    BXI_COLOUR_A256_875FAF = ( 97), /* Ce Soir              */
    BXI_COLOUR_A256_875FD7 = ( 98), /* Medium Purple        */
    BXI_COLOUR_A256_875FFF = ( 99), /* Light Slate Blue     */
    BXI_COLOUR_A256_878700 = (100), /* Olive                */
    BXI_COLOUR_A256_87875F = (101), /* Bandicoot            */
    BXI_COLOUR_A256_878787 = (102), /* Grey                 */
    BXI_COLOUR_A256_8787AF = (103), /* Manatee              */
    BXI_COLOUR_A256_8787D7 = (104), /* Portage              */
    BXI_COLOUR_A256_8787FF = (105), /* Light Slate Blue     */
    BXI_COLOUR_A256_87AF00 = (106), /* Citrus               */
    BXI_COLOUR_A256_87AF5F = (107), /* Chelsea Cucumber     */
    BXI_COLOUR_A256_87AF87 = (108), /* Dark Sea Green       */
    BXI_COLOUR_A256_87AFAF = (109), /* Ziggurat             */
    BXI_COLOUR_A256_87AFD7 = (110), /* Polo Blue            */
    BXI_COLOUR_A256_87AFFF = (111), /* Maya Blue            */
    BXI_COLOUR_A256_87D700 = (112), /* Lawn Green           */
    BXI_COLOUR_A256_87D75F = (113), /* Mantis               */
    BXI_COLOUR_A256_87D787 = (114), /* De York              */
    BXI_COLOUR_A256_87D7AF = (115), /* Vista Blue           */
    BXI_COLOUR_A256_87D7D7 = (116), /* Spray                */
    BXI_COLOUR_A256_87D7FF = (117), /* Light Sky Blue       */
    BXI_COLOUR_A256_87FF00 = (118), /* Chartreuse           */
    BXI_COLOUR_A256_87FF5F = (119), /* Screamin' Green      */
    BXI_COLOUR_A256_87FF87 = (120), /* Light Green          */
    BXI_COLOUR_A256_87FFAF = (121), /* Mint Green           */
    BXI_COLOUR_A256_87FFD7 = (122), /* Aquamarine           */
    BXI_COLOUR_A256_87FFFF = (123), /* Electric Blue        */
    BXI_COLOUR_A256_AF0000 = (124), /* Free Speech Red      */
    BXI_COLOUR_A256_AF005F = (125), /* Jazzberry Jam        */
    BXI_COLOUR_A256_AF0087 = (126), /* Medium Violet Red    */
    BXI_COLOUR_A256_AF00AF = (127), /* Deep Magenta         */
    BXI_COLOUR_A256_AF00D7 = (128), /* Dark Violet          */
    BXI_COLOUR_A256_AF00FF = (129), /* Electric Purple      */
    BXI_COLOUR_A256_AF5F00 = (130), /* Golden Brown         */
    BXI_COLOUR_A256_AF5F5F = (131), /* Coral Tree           */
    BXI_COLOUR_A256_AF5F87 = (132), /* Tapestry             */
    BXI_COLOUR_A256_AF5FAF = (133), /* Violet Blue          */
    BXI_COLOUR_A256_AF5FD7 = (134), /* Medium Orchid        */
    BXI_COLOUR_A256_AF5FFF = (135), /* Medium Purple        */
    BXI_COLOUR_A256_AF8700 = (136), /* Dark Goldenrod       */
    BXI_COLOUR_A256_AF875F = (137), /* Medium Wood          */
    BXI_COLOUR_A256_AF8787 = (138), /* Rosy Brown           */
    BXI_COLOUR_A256_AF87AF = (139), /* London Hue           */
    BXI_COLOUR_A256_AF87D7 = (140), /* Biloba Flower        */
    BXI_COLOUR_A256_AF87FF = (141), /* Biloba Flower        */
    BXI_COLOUR_A256_AFAF00 = (142), /* Citrus               */
    BXI_COLOUR_A256_AFAF5F = (143), /* Olive Green          */
    BXI_COLOUR_A256_AFAF87 = (144), /* Neutral Green        */
    BXI_COLOUR_A256_AFAFAF = (145), /* Dark Gray            */
    BXI_COLOUR_A256_AFAFD7 = (146), /* Lavender Grey        */
    BXI_COLOUR_A256_AFAFFF = (147), /* Perano               */
    BXI_COLOUR_A256_AFD700 = (148), /* Inch Worm            */
    BXI_COLOUR_A256_AFD75F = (149), /* Conifer              */
    BXI_COLOUR_A256_AFD787 = (150), /* Feijoa               */
    BXI_COLOUR_A256_AFD7AF = (151), /* Moss Green           */
    BXI_COLOUR_A256_AFD7D7 = (152), /* Sinbad               */
    BXI_COLOUR_A256_AFD7FF = (153), /* Pale Cornflower Blue */
    BXI_COLOUR_A256_AFFF00 = (154), /* Spring Bud           */
    BXI_COLOUR_A256_AFFF5F = (155), /* Conifer              */
    BXI_COLOUR_A256_AFFF87 = (156), /* Mint Green           */
    BXI_COLOUR_A256_AFFFAF = (157), /* Celadon              */
    BXI_COLOUR_A256_AFFFD7 = (158), /* Magic Mint           */
    BXI_COLOUR_A256_AFFFFF = (159), /* Pale Turquoise       */
    BXI_COLOUR_A256_D70000 = (160), /* Free Speech Red      */
    BXI_COLOUR_A256_D7005F = (161), /* Razzmatazz           */
    BXI_COLOUR_A256_D70087 = (162), /* Medium Violet Red    */
    BXI_COLOUR_A256_D700AF = (163), /* Hollywood Cerise     */
    BXI_COLOUR_A256_D700D7 = (164), /* Deep Magenta         */
    BXI_COLOUR_A256_D700FF = (165), /* Psychedelic Purple   */
    BXI_COLOUR_A256_D75F00 = (166), /* Tenne (Tawny)        */
    BXI_COLOUR_A256_D75F5F = (167), /* Roman                */
    BXI_COLOUR_A256_D75F87 = (168), /* Dark Pink            */
    BXI_COLOUR_A256_D75FAF = (169), /* Hopbush              */
    BXI_COLOUR_A256_D75FD7 = (170), /* Free Speech Magenta  */
    BXI_COLOUR_A256_D75FFF = (171), /* Heliotrope           */
    BXI_COLOUR_A256_D78700 = (172), /* Tangerine            */
    BXI_COLOUR_A256_D7875F = (173), /* Copper               */
    BXI_COLOUR_A256_D78787 = (174), /* Sea Pink             */
    BXI_COLOUR_A256_D787AF = (175), /* Kobi                 */
    BXI_COLOUR_A256_D787D7 = (176), /* Orchid               */
    BXI_COLOUR_A256_D787FF = (177), /* Heliotrope           */
    BXI_COLOUR_A256_D7AF00 = (178), /* Gamboge              */
    BXI_COLOUR_A256_D7AF5F = (179), /* Equator              */
    BXI_COLOUR_A256_D7AF87 = (180), /* Calico               */
    BXI_COLOUR_A256_D7AFAF = (181), /* Oyster Pink          */
    BXI_COLOUR_A256_D7AFD7 = (182), /* French Lilac         */
    BXI_COLOUR_A256_D7AFFF = (183), /* Mauve                */
    BXI_COLOUR_A256_D7D700 = (184), /* Bird Flower          */
    BXI_COLOUR_A256_D7D75F = (185), /* Manz                 */
    BXI_COLOUR_A256_D7D787 = (186), /* Deco                 */
    BXI_COLOUR_A256_D7D7AF = (187), /* Orinoco              */
    BXI_COLOUR_A256_D7D7D7 = (188), /* Light Grey           */
    BXI_COLOUR_A256_D7D7FF = (189), /* Quartz               */
    BXI_COLOUR_A256_D7FF00 = (190), /* Chartreuse Yellow    */
    BXI_COLOUR_A256_D7FF5F = (191), /* Mindaro              */
    BXI_COLOUR_A256_D7FF87 = (192), /* Sulu                 */
    BXI_COLOUR_A256_D7FFAF = (193), /* Reef                 */
    BXI_COLOUR_A256_D7FFD7 = (194), /* Tara                 */
    BXI_COLOUR_A256_D7FFFF = (195), /* Light Cyan           */
    BXI_COLOUR_A256_FF0000 = (196), /* Red                  */
    BXI_COLOUR_A256_FF005F = (197), /* Razzmatazz           */
    BXI_COLOUR_A256_FF0087 = (198), /* Deep Pink            */
    BXI_COLOUR_A256_FF00AF = (199), /* Hollywood Cerise     */
    BXI_COLOUR_A256_FF00D7 = (200), /* Hot Magenta          */
    BXI_COLOUR_A256_FF00FF = (201), /* Fuchsia              */
    BXI_COLOUR_A256_FF5F00 = (202), /* Safety Orange        */
    BXI_COLOUR_A256_FF5F5F = (203), /* Bittersweet          */
    BXI_COLOUR_A256_FF5F87 = (204), /* Brink Pink           */
    BXI_COLOUR_A256_FF5FAF = (205), /* Hot Pink             */
    BXI_COLOUR_A256_FF5FD7 = (206), /* Neon Pink            */
    BXI_COLOUR_A256_FF5FFF = (207), /* Pink Flamingo        */
    BXI_COLOUR_A256_FF8700 = (208), /* Dark Orange          */
    BXI_COLOUR_A256_FF875F = (209), /* Coral                */
    BXI_COLOUR_A256_FF8787 = (210), /* Light Coral          */
    BXI_COLOUR_A256_FF87AF = (211), /* Tickle Me Pink       */
    BXI_COLOUR_A256_FF87D7 = (212), /* Pale Magenta         */
    BXI_COLOUR_A256_FF87FF = (213), /* Fuchsia Pink         */
    BXI_COLOUR_A256_FFAF00 = (214), /* Orange               */
    BXI_COLOUR_A256_FFAF5F = (215), /* Rajah                */
    BXI_COLOUR_A256_FFAF87 = (216), /* Tacao                */
    BXI_COLOUR_A256_FFAFAF = (217), /* Sundown              */
    BXI_COLOUR_A256_FFAFD7 = (218), /* Lavender Pink        */
    BXI_COLOUR_A256_FFAFFF = (219), /* Lavender Rose        */
    BXI_COLOUR_A256_FFD700 = (220), /* Gold                 */
    BXI_COLOUR_A256_FFD75F = (221), /* Dandelion            */
    BXI_COLOUR_A256_FFD787 = (222), /* Golden Glow          */
    BXI_COLOUR_A256_FFD7AF = (223), /* Sandy Beach          */
    BXI_COLOUR_A256_FFD7D7 = (224), /* Cosmos               */
    BXI_COLOUR_A256_FFD7FF = (225), /* Selago               */
    BXI_COLOUR_A256_FFFF00 = (226), /* Yellow               */
    BXI_COLOUR_A256_FFFF5F = (227), /* Laser Lemon          */
    BXI_COLOUR_A256_FFFF87 = (228), /* Canary               */
    BXI_COLOUR_A256_FFFFAF = (229), /* Shalimar             */
    BXI_COLOUR_A256_FFFFD7 = (230), /* Cream                */
    BXI_COLOUR_A256_FFFFFF = (231), /* White                */
    BXI_COLOUR_A256_080808 = (232), /* Black                */
    BXI_COLOUR_A256_121212 = (233), /* Black                */
    BXI_COLOUR_A256_1C1C1C = (234), /* Nero                 */
    BXI_COLOUR_A256_262626 = (235), /* Nero                 */
    BXI_COLOUR_A256_303030 = (236), /* Night Rider          */
    BXI_COLOUR_A256_3A3A3A = (237), /* Eclipse              */
    BXI_COLOUR_A256_444444 = (238), /* Charcoal             */
    BXI_COLOUR_A256_4E4E4E = (239), /* Matterhorn           */
    BXI_COLOUR_A256_585858 = (240), /* Zambezi              */
    BXI_COLOUR_A256_626262 = (241), /* Dim Gray             */
    BXI_COLOUR_A256_6C6C6C = (242), /* Dim Gray             */
    BXI_COLOUR_A256_767676 = (243), /* Grey                 */
    BXI_COLOUR_A256_808080 = (244), /* Gray                 */
    BXI_COLOUR_A256_8A8A8A = (245), /* Suva Grey            */
    BXI_COLOUR_A256_949494 = (246), /* Nobel                */
    BXI_COLOUR_A256_9E9E9E = (247), /* Nobel                */
    BXI_COLOUR_A256_A8A8A8 = (248), /* Dark Gray            */
    BXI_COLOUR_A256_B2B2B2 = (249), /* Pink Swan            */
    BXI_COLOUR_A256_BCBCBC = (250), /* Silver               */
    BXI_COLOUR_A256_C6C6C6 = (251), /* Silver               */
    BXI_COLOUR_A256_D0D0D0 = (252), /* Light Grey           */
    BXI_COLOUR_A256_DADADA = (253), /* Gainsboro            */
    BXI_COLOUR_A256_E4E4E4 = (254), /* Whisper              */
    BXI_COLOUR_A256_EEEEEE = (255)  /* Whisper              */
};

EXPORT enum bxi_colours_controls {
    BXI_COLOUR_ANSI_FOREGROUND = (30),
    BXI_COLOUR_ANSI_BACKGROUND = (40)
};

EXPORT enum bxi_colours_vga16 {
    BXI_COLOUR_VGA16_WHITE   = (0xffffffu),
    BXI_COLOUR_VGA16_SILVER  = (0xc0c0c0u),
    BXI_COLOUR_VGA16_GRAY    = (0x808080u),
    BXI_COLOUR_VGA16_BLACK   = (0x000000u),
    BXI_COLOUR_VGA16_RED     = (0xff0000u),
    BXI_COLOUR_VGA16_MAROON  = (0x800000u),
    BXI_COLOUR_VGA16_YELLOW  = (0xffff00u),
    BXI_COLOUR_VGA16_OLIVE   = (0x808000u),
    BXI_COLOUR_VGA16_LIME    = (0x00ff00u),
    BXI_COLOUR_VGA16_GREEN   = (0x008000u),
    BXI_COLOUR_VGA16_AQUA    = (0x00ffffu),
    BXI_COLOUR_VGA16_TEAL    = (0x008080u),
    BXI_COLOUR_VGA16_BLUE    = (0x0000ffu),
    BXI_COLOUR_VGA16_NAVY    = (0x000080u),
    BXI_COLOUR_VGA16_FUCHSIA = (0xff00ffu),
    BXI_COLOUR_VGA16_PURPLE  = (0x800080u)
};

EXPORT enum bxi_colours_webx11 {
    BXI_COLOUR_WEBX11_ALICEBLUE            = (0xf0f8ffu),
    BXI_COLOUR_WEBX11_ANTIQUEWHITE         = (0xfaebd7u),
    BXI_COLOUR_WEBX11_AQUA                 = (0x00ffffu),
    BXI_COLOUR_WEBX11_AQUAMARINE           = (0x7fffd4u),
    BXI_COLOUR_WEBX11_AZURE                = (0xf0ffffu),
    BXI_COLOUR_WEBX11_BEIGE                = (0xf5f5dcu),
    BXI_COLOUR_WEBX11_BISQUE               = (0xffe4c4u),
    BXI_COLOUR_WEBX11_BLACK                = (0x000000u),
    BXI_COLOUR_WEBX11_BLANCHEDALMOND       = (0xffebcdu),
    BXI_COLOUR_WEBX11_BLUE                 = (0x0000ffu),
    BXI_COLOUR_WEBX11_BLUEVIOLET           = (0x8a2be2u),
    BXI_COLOUR_WEBX11_BROWN                = (0xa52a2au),
    BXI_COLOUR_WEBX11_BURLYWOOD            = (0xdeb887u),
    BXI_COLOUR_WEBX11_CADETBLUE            = (0x5f9ea0u),
    BXI_COLOUR_WEBX11_CHARTREUSE           = (0x7fff00u),
    BXI_COLOUR_WEBX11_CHOCOLATE            = (0xd2691eu),
    BXI_COLOUR_WEBX11_CORAL                = (0xff7f50u),
    BXI_COLOUR_WEBX11_CORNFLOWERBLUE       = (0x6495edu),
    BXI_COLOUR_WEBX11_CORNSILK             = (0xfff8dcu),
    BXI_COLOUR_WEBX11_CRIMSON              = (0xdc143cu),
    BXI_COLOUR_WEBX11_CYAN                 = (0x00ffffu),
    BXI_COLOUR_WEBX11_DARKBLUE             = (0x00008bu),
    BXI_COLOUR_WEBX11_DARKCYAN             = (0x008b8bu),
    BXI_COLOUR_WEBX11_DARKGOLDENROD        = (0xb8860bu),
    BXI_COLOUR_WEBX11_DARKGRAY             = (0xa9a9a9u),
    BXI_COLOUR_WEBX11_DARKGREEN            = (0x006400u),
    BXI_COLOUR_WEBX11_DARKGREY             = (0xa9a9a9u),
    BXI_COLOUR_WEBX11_DARKKHAKI            = (0xbdb76bu),
    BXI_COLOUR_WEBX11_DARKMAGENTA          = (0x8b008bu),
    BXI_COLOUR_WEBX11_DARKOLIVEGREEN       = (0x556b2fu),
    BXI_COLOUR_WEBX11_DARKORANGE           = (0xff8c00u),
    BXI_COLOUR_WEBX11_DARKORCHID           = (0x9932ccu),
    BXI_COLOUR_WEBX11_DARKRED              = (0x8b0000u),
    BXI_COLOUR_WEBX11_DARKSALMON           = (0xe9967au),
    BXI_COLOUR_WEBX11_DARKSEAGREEN         = (0x8fbc8fu),
    BXI_COLOUR_WEBX11_DARKSLATEBLUE        = (0x483d8bu),
    BXI_COLOUR_WEBX11_DARKSLATEGRAY        = (0x2f4f4fu),
    BXI_COLOUR_WEBX11_DARKSLATEGREY        = (0x2f4f4fu),
    BXI_COLOUR_WEBX11_DARKTURQUOISE        = (0x00ced1u),
    BXI_COLOUR_WEBX11_DARKVIOLET           = (0x9400d3u),
    BXI_COLOUR_WEBX11_DEEPPINK             = (0xff1493u),
    BXI_COLOUR_WEBX11_DEEPSKYBLUE          = (0x00bfffu),
    BXI_COLOUR_WEBX11_DIMGRAY              = (0x696969u),
    BXI_COLOUR_WEBX11_DIMGREY              = (0x696969u),
    BXI_COLOUR_WEBX11_DODGERBLUE           = (0x1e90ffu),
    BXI_COLOUR_WEBX11_FIREBRICK            = (0xb22222u),
    BXI_COLOUR_WEBX11_FLORALWHITE          = (0xfffaf0u),
    BXI_COLOUR_WEBX11_FORESTGREEN          = (0x228b22u),
    BXI_COLOUR_WEBX11_FUCHSIA              = (0xff00ffu),
    BXI_COLOUR_WEBX11_GAINSBORO            = (0xdcdcdcu),
    BXI_COLOUR_WEBX11_GHOSTWHITE           = (0xf8f8ffu),
    BXI_COLOUR_WEBX11_GOLD                 = (0xffd700u),
    BXI_COLOUR_WEBX11_GOLDENROD            = (0xdaa520u),
    BXI_COLOUR_WEBX11_GRAY                 = (0x808080u),
    BXI_COLOUR_WEBX11_GREY                 = (0x808080u),
    BXI_COLOUR_WEBX11_GREEN                = (0x008000u),
    BXI_COLOUR_WEBX11_GREENYELLOW          = (0xadff2fu),
    BXI_COLOUR_WEBX11_HONEYDEW             = (0xf0fff0u),
    BXI_COLOUR_WEBX11_HOTPINK              = (0xff69b4u),
    BXI_COLOUR_WEBX11_INDIANRED            = (0xcd5c5cu),
    BXI_COLOUR_WEBX11_INDIGO               = (0x4b0082u),
    BXI_COLOUR_WEBX11_IVORY                = (0xfffff0u),
    BXI_COLOUR_WEBX11_KHAKI                = (0xf0e68cu),
    BXI_COLOUR_WEBX11_LAVENDER             = (0xe6e6fau),
    BXI_COLOUR_WEBX11_LAVENDERBLUSH        = (0xfff0f5u),
    BXI_COLOUR_WEBX11_LAWNGREEN            = (0x7cfc00u),
    BXI_COLOUR_WEBX11_LEMONCHIFFON         = (0xfffacdu),
    BXI_COLOUR_WEBX11_LIGHTBLUE            = (0xadd8e6u),
    BXI_COLOUR_WEBX11_LIGHTCORAL           = (0xf08080u),
    BXI_COLOUR_WEBX11_LIGHTCYAN            = (0xe0ffffu),
    BXI_COLOUR_WEBX11_LIGHTGOLDENRODYELLOW = (0xfafad2u),
    BXI_COLOUR_WEBX11_LIGHTGRAY            = (0xd3d3d3u),
    BXI_COLOUR_WEBX11_LIGHTGREEN           = (0x90ee90u),
    BXI_COLOUR_WEBX11_LIGHTGREY            = (0xd3d3d3u),
    BXI_COLOUR_WEBX11_LIGHTPINK            = (0xffb6c1u),
    BXI_COLOUR_WEBX11_LIGHTSALMON          = (0xffa07au),
    BXI_COLOUR_WEBX11_LIGHTSEAGREEN        = (0x20b2aau),
    BXI_COLOUR_WEBX11_LIGHTSKYBLUE         = (0x87cefau),
    BXI_COLOUR_WEBX11_LIGHTSLATEGRAY       = (0x778899u),
    BXI_COLOUR_WEBX11_LIGHTSLATEGREY       = (0x778899u),
    BXI_COLOUR_WEBX11_LIGHTSTEELBLUE       = (0xb0c4deu),
    BXI_COLOUR_WEBX11_LIGHTYELLOW          = (0xffffe0u),
    BXI_COLOUR_WEBX11_LIME                 = (0x00ff00u),
    BXI_COLOUR_WEBX11_LIMEGREEN            = (0x32cd32u),
    BXI_COLOUR_WEBX11_LINEN                = (0xfaf0e6u),
    BXI_COLOUR_WEBX11_MAGENTA              = (0xff00ffu),
    BXI_COLOUR_WEBX11_MAROON               = (0x800000u),
    BXI_COLOUR_WEBX11_MEDIUMAQUAMARINE     = (0x66cdaau),
    BXI_COLOUR_WEBX11_MEDIUMBLUE           = (0x0000cdu),
    BXI_COLOUR_WEBX11_MEDIUMORCHID         = (0xba55d3u),
    BXI_COLOUR_WEBX11_MEDIUMPURPLE         = (0x9370dbu),
    BXI_COLOUR_WEBX11_MEDIUMSEAGREEN       = (0x3cb371u),
    BXI_COLOUR_WEBX11_MEDIUMSLATEBLUE      = (0x7b68eeu),
    BXI_COLOUR_WEBX11_MEDIUMSPRINGGREEN    = (0x00fa9au),
    BXI_COLOUR_WEBX11_MEDIUMTURQUOISE      = (0x48d1ccu),
    BXI_COLOUR_WEBX11_MEDIUMVIOLETRED      = (0xc71585u),
    BXI_COLOUR_WEBX11_MIDNIGHTBLUE         = (0x191970u),
    BXI_COLOUR_WEBX11_MINTCREAM            = (0xf5fffau),
    BXI_COLOUR_WEBX11_MISTYROSE            = (0xffe4e1u),
    BXI_COLOUR_WEBX11_MOCCASIN             = (0xffe4b5u),
    BXI_COLOUR_WEBX11_NAVAJOWHITE          = (0xffdeadu),
    BXI_COLOUR_WEBX11_NAVY                 = (0x000080u),
    BXI_COLOUR_WEBX11_OLDLACE              = (0xfdf5e6u),
    BXI_COLOUR_WEBX11_OLIVE                = (0x808000u),
    BXI_COLOUR_WEBX11_OLIVEDRAB            = (0x6b8e23u),
    BXI_COLOUR_WEBX11_ORANGE               = (0xffa500u),
    BXI_COLOUR_WEBX11_ORANGERED            = (0xff4500u),
    BXI_COLOUR_WEBX11_ORCHID               = (0xda70d6u),
    BXI_COLOUR_WEBX11_PALEGOLDENROD        = (0xeee8aau),
    BXI_COLOUR_WEBX11_PALEGREEN            = (0x98fb98u),
    BXI_COLOUR_WEBX11_PALETURQUOISE        = (0xafeeeeu),
    BXI_COLOUR_WEBX11_PALEVIOLETRED        = (0xdb7093u),
    BXI_COLOUR_WEBX11_PAPAYAWHIP           = (0xffefd5u),
    BXI_COLOUR_WEBX11_PEACHPUFF            = (0xffdab9u),
    BXI_COLOUR_WEBX11_PERU                 = (0xcd853fu),
    BXI_COLOUR_WEBX11_PINK                 = (0xffc0cbu),
    BXI_COLOUR_WEBX11_PLUM                 = (0xdda0ddu),
    BXI_COLOUR_WEBX11_POWDERBLUE           = (0xb0e0e6u),
    BXI_COLOUR_WEBX11_PURPLE               = (0x800080u),
    BXI_COLOUR_WEBX11_RED                  = (0xff0000u),
    BXI_COLOUR_WEBX11_ROSYBROWN            = (0xbc8f8fu),
    BXI_COLOUR_WEBX11_ROYALBLUE            = (0x4169e1u),
    BXI_COLOUR_WEBX11_SADDLEBROWN          = (0x8b4513u),
    BXI_COLOUR_WEBX11_SALMON               = (0xfa8072u),
    BXI_COLOUR_WEBX11_SANDYBROWN           = (0xf4a460u),
    BXI_COLOUR_WEBX11_SEAGREEN             = (0x2e8b57u),
    BXI_COLOUR_WEBX11_SEASHELL             = (0x2e8b57u),
    BXI_COLOUR_WEBX11_SIENNA               = (0xa0522du),
    BXI_COLOUR_WEBX11_SILVER               = (0xc0c0c0u),
    BXI_COLOUR_WEBX11_SKYBLUE              = (0x87ceebu),
    BXI_COLOUR_WEBX11_SLATEBLUE            = (0x6a5acdu),
    BXI_COLOUR_WEBX11_SLATEGRAY            = (0x708090u),
    BXI_COLOUR_WEBX11_SLATEGREY            = (0x708090u),
    BXI_COLOUR_WEBX11_SNOW                 = (0xfffafau),
    BXI_COLOUR_WEBX11_SPRINGGREEN          = (0x00ff7fu),
    BXI_COLOUR_WEBX11_STEELBLUE            = (0x4682b4u),
    BXI_COLOUR_WEBX11_TAN                  = (0xd2b48cu),
    BXI_COLOUR_WEBX11_TEAL                 = (0x008080u),
    BXI_COLOUR_WEBX11_THISTLE              = (0xd8bfd8u),
    BXI_COLOUR_WEBX11_TOMATO               = (0xff6347u),
    BXI_COLOUR_WEBX11_TURQUOISE            = (0x40e0d0u),
    BXI_COLOUR_WEBX11_VIOLET               = (0xee82eeu),
    BXI_COLOUR_WEBX11_WHEAT                = (0xf5deb3u),
    BXI_COLOUR_WEBX11_WHITE                = (0xffffffu),
    BXI_COLOUR_WEBX11_WHITESMOKE           = (0xf5f5f5u),
    BXI_COLOUR_WEBX11_YELLOW               = (0xffff00u),
    BXI_COLOUR_WEBX11_YELLOWGREEN          = (0x9acd32u)
};

EXPORT typedef struct {
    u8 r;
    u8 g;
    u8 b;
} bxi_rgb;

EXPORT typedef struct {
    u8 a;
    u8 r;
    u8 g;
    u8 b;
} bxi_argb;

/* @todo test bxi_argb_u */
EXPORT typedef union {
    u8       raw[4];
    u32      quad;
    bxi_argb argb;
} bxi_argb_u;

EXPORT typedef u32 bxi_colour;

EXPORT bxi_argb   bxi_colour2argb(bxi_colour col);
EXPORT bxi_colour bxi_argb2colour(bxi_argb  argb);

EXPORT bxi_argb_u bxi_chan2u(u8 a, u8 r, u8 g, u8 b);
EXPORT bxi_argb_u bxi_argb2u(bxi_argb argb);
EXPORT bxi_argb_u bxi_quad2u(u32 quad);

EXPORT_FROM
#define BXI_COLOUR_A(col) ((u8)(((col) >> (BITS_IN_BYTE * 3)) & 0xff))
#define BXI_COLOUR_R(col) ((u8)(((col) >> (BITS_IN_BYTE * 2)) & 0xff))
#define BXI_COLOUR_G(col) ((u8)(((col) >> (BITS_IN_BYTE * 1)) & 0xff))
#define BXI_COLOUR_B(col) ((u8)(((col)                      ) & 0xff))

#define BXI_COLOUR_ARGB(a, r, g, b) ((bxi_colour) \
    (((u8)(a) << (BITS_IN_BYTE * 3)) | \
     ((u8)(r) << (BITS_IN_BYTE * 2)) | \
     ((u8)(g) << (BITS_IN_BYTE * 1)) | \
     ((u8)(b))))
#define BXI_COLOUR_MIX(c1, c2, a) \
    (bxi_colour)(((BXI_FAST_U16DIV255(BXI_COLOUR_A(c1) * (0xff - (a)) + \
                                      BXI_COLOUR_A(c2) * (a))) << (BITS_IN_BYTE * 3)) | \
                 ((BXI_FAST_U16DIV255(BXI_COLOUR_R(c1) * (0xff - (a)) + \
                                      BXI_COLOUR_R(c2) * (a))) << (BITS_IN_BYTE * 2)) | \
                 ((BXI_FAST_U16DIV255(BXI_COLOUR_G(c1) * (0xff - (a)) + \
                                      BXI_COLOUR_G(c2) * (a))) << (BITS_IN_BYTE * 1)) | \
                 ((BXI_FAST_U16DIV255(BXI_COLOUR_B(c1) * (0xff - (a)) + \
                                      BXI_COLOUR_B(c2) * (a)))      ))
#define BXI_COLOUR_RANDOM ((bxi_colour)bxi_randu32())
EXPORT_TO

#endif /* BXICOLOUR_H */

