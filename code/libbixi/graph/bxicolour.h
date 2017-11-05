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

/* Not widely supported */
/* @todo colors */
/*  #include <stdio.h>
    int main()
    {
        int r, g, b;
        for (r = 0; r < 6; r++)
        for (g = 0; g < 6; g++)
        {
            for (b = 0; b < 6; b++)
            {
                int c = 16 + r * 36 + g * 6 + b;
                printf("\x1b[48;5;%dm %3d \x1b[0m", c, c);
            }
            printf("\n");
        }
        printf("\n");
        return 0;
    } */

EXPORT enum bxi_colours_ansi8
{
    BXI_COLOUR_A8_BLACK   = (0),
    BXI_COLOUR_A8_RED     = (1),
    BXI_COLOUR_A8_GREEN   = (2),
    BXI_COLOUR_A8_YELLOW  = (3),
    BXI_COLOUR_A8_BLUE    = (4),
    BXI_COLOUR_A8_MAGENTA = (5),
    BXI_COLOUR_A8_CYAN    = (6),
    BXI_COLOUR_A8_WHITE   = (7)
};

EXPORT enum bxi_colours_ansi256
{
    /* Widely supported */
    BXI_COLOUR_A256_BLACK     = ( 0),
    BXI_COLOUR_A256_RED       = ( 1),
    BXI_COLOUR_A256_GREEN     = ( 2),
    BXI_COLOUR_A256_YELLOW    = ( 3),
    BXI_COLOUR_A256_BLUE      = ( 4),
    BXI_COLOUR_A256_MAGENTA   = ( 5),
    BXI_COLOUR_A256_CYAN      = ( 6),
    BXI_COLOUR_A256_WHITE     = ( 7),
    BXI_COLOUR_A256_B_BLACK   = ( 8),
    BXI_COLOUR_A256_B_RED     = ( 9),
    BXI_COLOUR_A256_B_GREEN   = (10),
    BXI_COLOUR_A256_B_YELLOW  = (11),
    BXI_COLOUR_A256_B_BLUE    = (12),
    BXI_COLOUR_A256_B_MAGENTA = (13),
    BXI_COLOUR_A256_B_CYAN    = (14),
    BXI_COLOUR_A256_B_WHITE   = (15)
    /* Not widely supported */
};

EXPORT enum bxi_colours_controls
{
    BXI_COLOUR_ANSI_FOREGROUND = (30),
    BXI_COLOUR_ANSI_BACKGROUND = (40)
};

EXPORT enum bxi_colours_vga16
{
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

EXPORT enum bxi_colours_webx11
{
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

#endif /* BXICOLOUR_H */

