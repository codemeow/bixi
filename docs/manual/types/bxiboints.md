## bxiboints.h 

For the support of Big-endian and Little-endian integers and their conversion functions
Bixi library provides plenty of types, definitions and functions:
```c
typedef enum
{
    BXI_END_BE,
    BXI_END_LE
} bxi_ends;
```
```c
i16_le;
i16_be;
u16_le;
u16_be;
i32_le;
i32_be;
u32_le;
u32_be;
```
```c
#define BITS_IN_U16_LE
#define BITS_IN_U32_LE  
#define BITS_IN_I16_LE  
#define BITS_IN_I32_LE  
#define BITS_IN_U16_BE 
#define BITS_IN_U32_BE 
#define BITS_IN_I16_BE 
#define BITS_IN_I32_BE 

#define  U8_LE_MIN 
#define  U8_BE_MIN 
#define U16_LE_MIN 
#define U16_BE_MIN 
#define U32_LE_MIN 
#define U32_BE_MIN 

#define  I8_LE_MIN 
#define  I8_BE_MIN 
#define I16_LE_MIN 
#define I16_BE_MIN 
#define I32_LE_MIN 
#define I32_BE_MIN 

#define  U8_LE_MAX 
#define  U8_BE_MAX 
#define U16_LE_MAX 
#define U16_BE_MAX
#define U32_LE_MAX 
#define U32_BE_MAX 

#define  I8_LE_MAX 
#define  I8_BE_MAX 
#define I16_LE_MAX 
#define I16_BE_MAX 
#define I32_LE_MAX 
#define I32_BE_MAX 

#define IS_BE
#define IS_LE
```
```c
u16 bxi_chgend16(u16 val);
u32 bxi_chgend32(u32 val);
i16    bxi_i16_le2i16   (i16_le value);
i16    bxi_i16_be2i16   (i16_be value);
i16_be bxi_i16_le2i16_be(i16_le value);
i16_le bxi_i16_be2i16_le(i16_be value);
i16_be    bxi_i162i16_be(i16    value);
i16_le    bxi_i162i16_le(i16    value);
i32    bxi_i32_le2i32   (i32_le value);
i32    bxi_i32_be2i32   (i32_be value);
i32_be bxi_i32_le2i32_be(i32_le value);
i32_le bxi_i32_be2i32_le(i32_be value);
i32_be    bxi_i322i32_be(i32    value);
i32_le    bxi_i322i32_le(i32    value);
u16    bxi_u16_le2u16   (u16_le value);
u16    bxi_u16_be2u16   (u16_be value);
u16_be bxi_u16_le2u16_be(u16_le value);
u16_le bxi_u16_be2u16_le(u16_be value);
u16_be    bxi_u162u16_be(u16    value);
u16_le    bxi_u162u16_le(u16    value);
u32    bxi_u32_le2u32   (u32_le value);
u32    bxi_u32_be2u32   (u32_be value);
u32_be bxi_u32_le2u32_be(u32_le value);
u32_le bxi_u32_be2u32_le(u32_be value);
u32_be    bxi_u322u32_be(u32    value);
u32_le    bxi_u322u32_le(u32    value);
```