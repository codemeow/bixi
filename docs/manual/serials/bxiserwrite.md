## bxiserwrite.h 

For the purposes of serialization Bixi library provides the following functions:
```c
void bxi_write_i8    (i8     val, u8 * dst);
void bxi_write_u8    (u8     val, u8 * dst);
void bxi_write_i16   (i16    val, u8 * dst);
void bxi_write_u16   (u16    val, u8 * dst);
void bxi_write_i32   (i32    val, u8 * dst);
void bxi_write_u32   (u32    val, u8 * dst);
void bxi_write_i16_be(i16_be val, u8 * dst);
void bxi_write_u16_be(u16_be val, u8 * dst);
void bxi_write_i32_be(i32_be val, u8 * dst);
void bxi_write_u32_be(u32_be val, u8 * dst);
void bxi_write_i16_le(i16_le val, u8 * dst);
void bxi_write_u16_le(u16_le val, u8 * dst);
void bxi_write_i32_le(i32_le val, u8 * dst);
void bxi_write_u32_le(u32_le val, u8 * dst);
```