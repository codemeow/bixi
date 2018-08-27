## bxibitutils.h 

For the purposes of bit-twiddling Bixi library provides the following objects:
```c
#define BXI_SWAP(a, b)
```
```c
u8   bxi_rotl8 (u8   val, u32 n);
u8   bxi_rotr8 (u8   val, u32 n);
u16  bxi_rotl16(u16  val, u32 n);
u16  bxi_rotr16(u16  val, u32 n);
u32  bxi_rotl32(u32  val, u32 n);
u32  bxi_rotr32(u32  val, u32 n);
u8  bxi_getbit(u32 val, u8 n);
u32 bxi_setbit(u32 val, u8 n);
u32 bxi_tglbit(u32 val, u8 n);
u32 bxi_clrbit(u32 val, u8 n);
u32 bxi_chgbit(u32 val, u8 n, u8 bit);
u8  bxi_cntbit(u32 val);
```