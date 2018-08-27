## bxirand.h 

### Limits 

The following macro are defined:
```c
#define BXI_RAND32_MAX
#define BXI_RAND16_MAX
#define BXI_RAND8_MAX
```

### Functions 

```c
void bxi_srand(u32 seed);
u32  bxi_randu32(void);
u16  bxi_randu16(void);
u8   bxi_randu8 (void);
i32  bxi_randi32(void);
i16  bxi_randi16(void);
i8   bxi_randi8 (void);
```