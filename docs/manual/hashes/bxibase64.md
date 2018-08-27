## bxibase64.h 

The following functionality provides full support of BASE64 hashing functions:
```c
typedef enum
{
    BXI_BASE64_RFC1421,
    BXI_BASE64_RFC2045,
    BXI_BASE64_RFC3548,
    BXI_BASE64_Y64,
    BXI_BASE64_XMLTOKEN,
    BXI_BASE64_XMLNAME,
    BXI_BASE64_PIDENT1,
    BXI_BASE64_PIDENT2,
    BXI_BASE64_FREENET,
    BXI_BASE64_RFC4880,
    BXI_BASE64_RFC1642,
    BXI_BASE64_RFC3501,

    BXI_BASE64_RFC4648,
    BXI_BASE64_RFC7515,
    BXI_BASE64_RFC2152,

    BXI_BASE64_STANDARD,
    BXI_BASE64_MIME,
    BXI_BASE64_PEM,
    BXI_BASE64_RADIX64,
    BXI_BASE64_UTF7,
    BXI_BASE64_IMAP,
    BXI_BASE64_URL,
    BXI_BASE64_OPENPGP
} bxi_base64_rfc;
```
```c
#define BXI_BASE64_ENC_SIZE
#define BXI_BASE64_DEC_SIZE

#define BXI_STR2BASE64_OUT_SIZE(IN)
#define BXI_BASE642STR_OUT_SIZE(IN)
```
```c
void bxi_bin2base64(u8 * in, u32 len, char * out, bxi_base64_rfc rfc);
```