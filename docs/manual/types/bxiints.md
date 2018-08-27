## bxiints.h 

### Short integers names 

Bixi library provides short names for fixed-size integers. This comes in handy
when the building target is std-c89 which doesn't contain stdint.

Defined types are
```c
i8  - for signed 8-bit integer
u8  - for unsigned 8-bit integer
i16 - for signed 16-bit integer
u16 - for unsigned 16-bit integer
i32 - for signed 32-bit integer
u32 - for unsigned 32-bit integer

imax - for signed integer of maximum size on current platform (2^32 on 32 bit OS)
umax - for unsigned integer of maximum size on current platform (2^64 on 64 bit OS)
```
```c
pu_t - for pointers (this type's size equals to pointer size)
```
### Size definitions 

Defined constants are
```c
#define BITS_IN_BYTE
#define BITS_IN_U8  
#define BITS_IN_U16 
#define BITS_IN_U32 
#define BITS_IN_I8  
#define BITS_IN_I16  
#define BITS_IN_I32  
```
These macro definitions made for readable calculations which use type wideness

### Limits 

The following definitions provided:
```c
#define  U8_MIN
#define U16_MIN
#define U32_MIN 

#define  U8_MAX 
#define U16_MAX 
#define U32_MAX 

#define  I8_MIN 
#define I16_MIN 
#define I32_MIN 

#define  I8_MAX
#define I16_MAX
#define I32_MAX 
```