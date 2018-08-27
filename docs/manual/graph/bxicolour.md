## bxicolour.h 

### Colours 

For the purpose of graphical calculations the following enumerations are provided:
```c
enum bxi_colours_ansi8
{
    BXI_COLOUR_A8_XXX
}
```
```c
enum bxi_colours_ansi256
{
    BXI_COLOUR_A256_XXX
}
```
```c
enum bxi_colours_controls
{
    BXI_COLOUR_ANSI_FOREGROUND,
    BXI_COLOUR_ANSI_BACKGROUND
}
```
These definitions are required for terminal coloration
```c
enum bxi_colours_vga16
{
    BXI_COLOUR_VGA16_XXX
}
```
```c
enum bxi_colours_webx11
{
    BXI_COLOUR_WEBX11_XXX
}
```
### Types 
```c
typedef struct
{
    u8 r;
    u8 g;
    u8 b;
} bxi_rgb;

typedef struct
{
    u8 a;
    u8 r;
    u8 g;
    u8 b;
} bxi_argb;

typedef union
{
    u8       raw[4];
    u32      quad;
    bxi_argb argb;
} bxi_argb_u;

typedef u32 bxi_colour;
```

### Functions 

The following functions are simple converters:
```c
bxi_argb   bxi_colour2argb(bxi_colour col);
bxi_colour bxi_argb2colour(bxi_argb  argb);
bxi_argb_u bxi_chan2u(u8 a, u8 r, u8 g, u8 b);
bxi_argb_u bxi_argb2u(bxi_argb argb);
bxi_argb_u bxi_quad2u(u32 quad);
```

### Macro definitions 
The following definitions extract desired channel from the colour in `bxi_colour` type
and returns `u8`:
```c
#define BXI_COLOUR_A(col)
#define BXI_COLOUR_R(col) 
#define BXI_COLOUR_G(col) 
#define BXI_COLOUR_B(col)
```

The following definition merges 4 separate colour channels in `u8` format to `bxi_colour`:
```c
#define BXI_COLOUR_ARGB(a, r, g, b)
```
The following definition mixes two `bxi_colour` colours with provided level of 
alpha blending:
```c
#define BXI_COLOUR_MIX(c1, c2, a)
```

The following macro returns random `bxi_colour`-typed colour:
```c
#define BXI_COLOUR_RANDOM
```