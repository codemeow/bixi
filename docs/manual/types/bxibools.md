## bxibools.h 

The following types are defined to provide boolean functionality in plain C:
```c
typedef u8   b8;
typedef u16  b16;
typedef u32  b32;
```
```c
#define BITS_IN_B8
#define BITS_IN_B16
#define BITS_IN_B32
```
```c
typedef enum
{
    false,
    true
} bool;
```