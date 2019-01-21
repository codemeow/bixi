## bxiserread.h 

For the purposes of deserialisation Bixi library provides the following functions:
```c
i8     bxi_read_i8    (const u8 * src);
u8     bxi_read_u8    (const u8 * src);
i16    bxi_read_i16   (const u8 * src);
u16    bxi_read_u16   (const u8 * src);
i32    bxi_read_i32   (const u8 * src);
u32    bxi_read_u32   (const u8 * src);
i16_be bxi_read_i16_be(const u8 * src);
u16_be bxi_read_u16_be(const u8 * src);
i32_be bxi_read_i32_be(const u8 * src);
u32_be bxi_read_u32_be(const u8 * src);
i16_le bxi_read_i16_le(const u8 * src);
u16_le bxi_read_u16_le(const u8 * src);
i32_le bxi_read_i32_le(const u8 * src);
u32_le bxi_read_u32_le(const u8 * src);
void   bxi_read_uuid  (const u8 * src, bxi_uuid_t uuid);
```