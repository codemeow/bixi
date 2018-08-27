## bxistrconv.h 

Bixi library provides huge possibilities to format output hex string with the
following functions and definitions:
```c
#define BXI_HEX_CASE_LOW    
#define BXI_HEX_CASE_UP     
#define BXI_HEX_PREFIX_AMP 
#define BXI_HEX_PREFIX_HASH
#define BXI_HEX_PREFIX_DOL  
#define BXI_HEX_PREFIX_0    
#define BXI_HEX_PREFIX_x    
#define BXI_HEX_SUFFIX_h   
#define BXI_HEX_SUFFIX_u    
#define BXI_HEX_SUFFIX_l    
#define BXI_HEX_DELIM_COMMA 
#define BXI_HEX_DELIM_SEMIC
#define BXI_HEX_DELIM_COLON 
#define BXI_HEX_DELIM_SPACE 
#define BXI_HEX_GROUP_2     
#define BXI_HEX_GROUP_3     
#define BXI_HEX_GROUP_4     
#define BXI_HEX_GROUP_8    
#define BXI_HEX_END_CLOSED

#define BXI_HEX_COMBO_C
#define BXI_HEX_COMBO_XML
#define BXI_HEX_COMBO_PASCAL
#define BXI_HEX_COMBO_INTEL
#define BXI_HEX_COMBO_IPv6
#define BXI_HEX_COMBO_CSS

typedef u32 bxi_hex_format;

u32 bxi_raw2hex(      char * out, u8 * raw, u32 count, bxi_hex_format format);
u32 bxi_hex2raw(const char * hex, u8 * raw);
```
Also there is a functionality to convert string and integers into each other:
```c
u32 bxi_hex2u32end(const char * str, i32 * len, bxi_ends end);
i8     bxi_str2i8    (const char * str, i32 * len);
u8     bxi_str2u8    (const char * str, i32 * len);
i16    bxi_str2i16   (const char * str, i32 * len);
u16    bxi_str2u16   (const char * str, i32 * len);
i32    bxi_str2i32   (const char * str, i32 * len);
u32    bxi_str2u32   (const char * str, i32 * len);
i8     bxi_hex2i8    (const char * str, i32 * len);
u8     bxi_hex2u8    (const char * str, i32 * len);
i16    bxi_hex2i16   (const char * str, i32 * len);
u16    bxi_hex2u16   (const char * str, i32 * len);
i32    bxi_hex2i32   (const char * str, i32 * len);
u32    bxi_hex2u32   (const char * str, i32 * len);
i16_le bxi_hex2i16_le(const char * str, i32 * len);
u16_le bxi_hex2u16_le(const char * str, i32 * len);
i32_le bxi_hex2i32_le(const char * str, i32 * len);
u32_le bxi_hex2u32_le(const char * str, i32 * len);
i16_be bxi_hex2i16_be(const char * str, i32 * len);
u16_be bxi_hex2u16_be(const char * str, i32 * len);
i32_be bxi_hex2i32_be(const char * str, i32 * len);
u32_be bxi_hex2u32_be(const char * str, i32 * len);
```
```c
u32 bxi_i82raw    (i8     val, u8 * raw);
u32 bxi_u82raw    (u8     val, u8 * raw);
u32 bxi_i162raw   (i16    val, u8 * raw);
u32 bxi_i16_le2raw(i16_le val, u8 * raw);
u32 bxi_i16_be2raw(i16_be val, u8 * raw);
u32 bxi_u162raw   (u16    val, u8 * raw);
u32 bxi_u16_le2raw(u16_le val, u8 * raw);
u32 bxi_u16_be2raw(u16_be val, u8 * raw);
u32 bxi_i322raw   (i32    val, u8 * raw);
u32 bxi_i32_le2raw(i32_le val, u8 * raw);
u32 bxi_i32_be2raw(i32_be val, u8 * raw);
u32 bxi_u322raw   (u32    val, u8 * raw);
u32 bxi_u32_le2raw(u32_le val, u8 * raw);
u32 bxi_u32_be2raw(u32_be val, u8 * raw);
```
```c
u32 bxi_i82hex    (char * out, i8     val);
u32 bxi_i82str    (char * out, i8     val);
u32 bxi_i162hex   (char * out, i16    val);
u32 bxi_i162str   (char * out, i16    val);
u32 bxi_i16_be2hex(char * out, i16_be val);
u32 bxi_i16_be2str(char * out, i16_be val);
u32 bxi_i16_le2hex(char * out, i16_le val);
u32 bxi_i16_le2str(char * out, i16_le val);
u32 bxi_i322hex   (char * out, i32    val);
u32 bxi_i322str   (char * out, i32    val);
u32 bxi_i32_be2hex(char * out, i32_be val);
u32 bxi_i32_be2str(char * out, i32_be val);
u32 bxi_i32_le2hex(char * out, i32_le val);
u32 bxi_i32_le2str(char * out, i32_le val);
u32 bxi_u82hex    (char * out, u8     val);
u32 bxi_u82str    (char * out, u8     val);
u32 bxi_u162hex   (char * out, u16    val);
u32 bxi_u162str   (char * out, u16    val);
u32 bxi_u16_be2hex(char * out, u16_be val);
u32 bxi_u16_be2str(char * out, u16_be val);
u32 bxi_u16_le2hex(char * out, u16_le val);
u32 bxi_u16_le2str(char * out, u16_le val);
u32 bxi_u322hex   (char * out, u32    val);
u32 bxi_u322str   (char * out, u32    val);
u32 bxi_u32_be2hex(char * out, u32_be val);
u32 bxi_u32_be2str(char * out, u32_be val);
u32 bxi_u32_le2hex(char * out, u32_le val);
u32 bxi_u32_le2str(char * out, u32_le val);
```