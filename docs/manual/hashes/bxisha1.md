## bxisha1.h 

The following functionality provides full support of SHA-1 hashing functions:
```c
#define SHA1_SIZE /* Size in bytes */
#define SHA1_STEP_COUNT /* Number of steps, used in inner functions */
```
```c
typedef struct
{
    u32     leng;
    u32     totl[2];

    u32     h[SHA1_STEP_COUNT];
    u32     w[16];
    hash_20 hash;
} sha1_t;
```
```c
void sha1_init     (sha1_t * sha1);
void sha1_append   (sha1_t * sha1, const u8 * data, u32 len);
void sha1_appendstr(sha1_t * sha1, const char * str);
void sha1_appendi8 (sha1_t * sha1, i8 num);
void sha1_appendu8 (sha1_t * sha1, u8 num);
void sha1_appendi16(sha1_t * sha1, i16 num);
void sha1_appendu16(sha1_t * sha1, u16 num);
void sha1_appendi32(sha1_t * sha1, i32 num);
void sha1_appendu32(sha1_t * sha1, u32 num);
void sha1_final    (sha1_t * sha1);
void sha12str      (sha1_t * sha1, char * out);
```