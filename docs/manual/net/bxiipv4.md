## bxiipv4.h 

Bixi library provides a few functions for IPv4 conversion to [u8 x 4] format/string
formats and vice versa:
```c
typedef u8 bxi_ipv4[4];
```
```c
bool bxi_str2ipv4(const char * str, bxi_ipv4 *  ip);
bool bxi_ipv42str(bxi_ipv4   * ip,      char * str);
u32  bxi_ipv42u32(bxi_ipv4     ip);
void bxi_u322ipv4(u32 pack,         bxi_ipv4    ip);
```
