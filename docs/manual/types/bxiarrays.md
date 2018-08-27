## bxiarrays.h 

Bixi library provides support of byte-arrays and provides a bunch of functions
for array management:
```c
bxi_bts;
```
```c
BXI_USES_MEM bxi_bts * bxi_bts_create(               u32 size);
BXI_USES_MEM void      bxi_bts_free  (bxi_bts * bts          );
bxi_bts * bxi_bts_walk  (bxi_bts * bts, bxi_bts_trav_t func);
i32       bxi_bts_search(bxi_bts * bts, u8 value);
bxi_bts * bxi_bts_resize(bxi_bts * bts, u32 size);
bxi_bts * bxi_bts_insert(bxi_bts * dst, bxi_bts * src, u32 pos);
bxi_bts * bxi_bts_append(bxi_bts * dst, bxi_bts * src);
bxi_bts * bxi_bts_delete(bxi_bts * dst, u32 pos, u32 cnt);
bxi_bts * bxi_bts_lshift(bxi_bts * dst, u32 c);
bxi_bts * bxi_bts_append_u8          (bxi_bts * bts, u8     value);
bxi_bts * bxi_bts_append_i8          (bxi_bts * bts, i8     value);
bxi_bts * bxi_bts_append_u16         (bxi_bts * bts, u16    value);
bxi_bts * bxi_bts_append_i16         (bxi_bts * bts, i16    value);
bxi_bts * bxi_bts_append_u32         (bxi_bts * bts, u32    value);
bxi_bts * bxi_bts_append_i32         (bxi_bts * bts, i32    value);
bxi_bts * bxi_bts_append_u16_le      (bxi_bts * bts, u16_le value);
bxi_bts * bxi_bts_append_i16_le      (bxi_bts * bts, i16_le value);
bxi_bts * bxi_bts_append_u16_be      (bxi_bts * bts, u16_be value);
bxi_bts * bxi_bts_append_i16_be      (bxi_bts * bts, i16_be value);
bxi_bts * bxi_bts_append_u32_le      (bxi_bts * bts, u32_le value);
bxi_bts * bxi_bts_append_i32_le      (bxi_bts * bts, i32_le value);
bxi_bts * bxi_bts_append_u32_be      (bxi_bts * bts, u32_be value);
bxi_bts * bxi_bts_append_i32_be      (bxi_bts * bts, i32_be value);
bxi_bts * bxi_bts_append_string      (bxi_bts * bts, const char * value);
bxi_bts * bxi_bts_append_string_fixed(bxi_bts * bts, const char * value, u32 size, char filler);
bxi_bts * bxi_bts_append_uuid        (bxi_bts * bts, uuid_t value);
```