# Bixi
![Logo](images/logosmall.png)\
C89 basic types and functions library for Linux, BSD and Minix operation systems.

# Origins of the name
![bixi statue image](https://upload.wikimedia.org/wikipedia/commons/thumb/7/72/Minzu-zhengqi-haoran-changcun-Bixi-3565.jpg/220px-Minzu-zhengqi-haoran-changcun-Bixi-3565.jpg "bixi statue")\
Bixi or Bi Xi (Wade–Giles: Pi-hsi), is a figure from Chinese mythology. One of the 9 sons of the Dragon King, he is depicted as a dragon with the shell of a turtle. Stone sculptures of Bixi have been used in Chinese culture for centuries as a decorative plinth for commemorative steles and tablets, particularly in the funerary complexes of its later emperors and to commemorate important events, such as an imperial visit or the anniversary of a World War II victory. They are also used at the bases of bridges and archways. Sculptures of Bixi are traditionally rubbed for good luck, which can cause conservation issues. They can be found throughout East Asia in Japan, Korea, Vietnam, Mongolia, and even the Russian Far East.\
_(from wikipedia.org)_\
The name Bixi was selected to symbolise the basis of any solid and reliable library.

# User manual

## Definitions
* [bxiarch.h](/docs/manual/definitions/bxiarch.md)
* [bxiassert.h](/docs/manual/definitions/bxiassert.md)
* [bxienv.h](/docs/manual/definitions/bxienv.md)
* [bxiexport.h](/docs/manual/definitions/bxiexport.md)
* [bximacros.h](/docs/manual/definitions/bximacros.md)

## Graph
* [bxicolour.h](/docs/manual/graph/bxicolour.md)

## Hashes
* [bxibase64.h](/docs/manual/hashes/bxibase64.md)
* [bxicrypt.h](/docs/manual/hashes/bxicrypt.md)
* [bxihash.h](/docs/manual/hashes/bxihash.md)
* [bximd5.h](/docs/manual/hashes/bximd5.md)
* [bxisha1.h](/docs/manual/hashes/bxisha1.md)
* [bxiuuid.h](/docs/manual/hashes/bxiuuid.md)

## Math
* [bximath.h](/docs/manual/math/bximath.md)
* [bxiplan.h](/docs/manual/math/bxiplan.md)

## Net
* [bxiipv4.h](/docs/manual/net/bxiipv4.md)

## Random
* [bxirand.h](/docs/manual/random/bxirand.md)

## Serials
* [bxiserread.h](/docs/manual/serials/bxiserread.md)
* [bxiserwrite.h](/docs/manual/serials/bxiserwrite.md)

## Strings
* [bxistrconv.h](/docs/manual/strings/bxistrconv.md)
* [bxistring.h](/docs/manual/strings/bxistring.md)

## Thread
* [bxithread.h](/docs/manual/thread/bxithread.md)

## Time
* [bxisleep.h](/docs/manual/time/bxisleep.md)

## Types
* [bxiarrays.h](/docs/manual/types/bxiarrays.md)
* [bxiboints.h](/docs/manual/types/bxiboints.md)
* [bxibools.h](/docs/manual/types/bxibools.md)
* [bxifloats.h](/docs/manual/types/bxifloats.md)
* [bxiints.h](/docs/manual/types/bxiints.md)

## Utils
* [bxibitutils.h](/docs/manual/utils/bxibitutils.md)
* [bximemutils.h](/docs/manual/utils/bximemutils.md)

# External dependencies

Bixi library has no external dependencies. Headers of the standart library are
not included anywhere in the project.

# Compiling

Debug mode:
```sh
./scripts/build.sh debug
```
Release mode:
```sh
./scripts/build.sh release
```
All the binaries will be put into `./bin` directory.\
All the includes wiil be put into `./includes` directory.

Additional compiler options could be transferred as additional arguments:
```sh
./scripts/build.sh release -DBXI_NO_SQRTI
```

# Examples and demos

The library packed with examples of use and demos the following programs are available:

## Braxel

Braxel library provides a few functions to be able to draw by Braille characters in `stdout` or `FILE *`. The following functions are present:

```c
typedef struct
{
    bxi_size size;
    bxi_bts  data;
} brx_pic_t;

typedef enum
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
```
```c
brx_pic_t * brx_pic_create   (bxi_size   size);
void        brx_pic_free     (brx_pic_t * pic);
void        brx_pic_draw     (brx_pic_t * pic, FILE * file);
void        brx_pic_pixel_set(brx_pic_t * pic, bxi_point pt, u8 value);
u8          brx_pic_pixel_get(brx_pic_t * pic, bxi_point pt);
void        brx_pic_map(brx_pic_t * back, brx_pic_t * front, bxi_point pt, brx_mode mode);
```

The examples of use are present in the next example:

## Braxel-demo

This example shows use of Bixi library and Braxel library to simulate "Tetris" demo. The code demonstrates use of integer names and size/position related structions (like `bxi_size`) and functions (like `bxi_point_c`).

*NOTE*: To run this demo you also need to add `./bin/braxel` path to your LD_LIBRARY_PATH.
