## bxiuuid.h

The following functions and definitions provide uuids generating and formatting:
```c
#define UUID_SIZE
#define UUID_STR_SIZE
```
```c
typedef hash_16 bxi_uuid_t;
typedef enum
{
    UUID_PLAIN,  /* "00000000000000000000000000000000"              */
    UUID_HYPHEN, /* "00000000-0000-0000-0000-000000000000"          */
    UUID_URN,    /* "urn:uuid:00000000-0000-0000-0000-000000000000" */
    UUID_CURLY   /* "{00000000-0000-0000-0000-000000000000}"        */
} uuid_format;
```
```c
#define UUID_STRLEN_PLAIN  
#define UUID_STRLEN_HYPHEN 
#define UUID_STRLEN_URN    
#define UUID_STRLEN_CURLY  

#define UUID_URN_PREFIX
#define UUID_EMPTY
```
```c
void uuidv3(uuid_t out, bxi_uuid_t ns, const char * data);
void uuidv4(uuid_t out);
void uuid2str(uuid_t uuid, char * out, uuid_format format);
i32  uuidscmp(uuid_t u1, bxi_uuid_t u2);
bool str2uuid(const char * str, bxi_uuid_t res);
```
