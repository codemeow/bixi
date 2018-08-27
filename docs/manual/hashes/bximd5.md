## bximd5.h 

The following functionality provides full support of MD5 hashing functions:
```c
#define MD5_SIZE
#define MD5_STEP_COUNT
```
```c
typedef struct
{
    u32     abcd[MD5_STEP_COUNT];
    u32     leng;
    u32     totl[2];
    u8      data[MD5_SIZE * sizeof(u32)];
    hash_16 hash;
} md5_t;
```
```c
void md5_init     (md5_t * md5);
void md5_append   (md5_t * md5, const u8 * data, u32 len);
void md5_appendstr(md5_t * md5, const char * str);
void md5_appendi8 (md5_t * md5, i8 num);
void md5_appendu8 (md5_t * md5, u8 num);
void md5_appendi16(md5_t * md5, i16 num);
void md5_appendu16(md5_t * md5, u16 num);
void md5_appendi32(md5_t * md5, i32 num);
void md5_appendu32(md5_t * md5, u32 num);
void md5_final    (md5_t * md5);
void md5_copy     (md5_t * md5, u8 * out);
```