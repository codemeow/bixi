## bxistring.h 

Bixi librarary provides replaces for standart string functions with additional 
protection and extends the list with new functions like `trim`:
```c
#define BXI_IS_ASCII_MAX
#define BXI_ASCII_MAX
#define BXI_ASCII_COUNT
```
```c
enum bxi_ascii_characters
```
```c
enum bxi_strerror
```
```c
typedef bxi_hash;
```
```c
bxi_hash bxi_strhash  (const char * str);
  char * bxi_strshiftl(      char * str, u32 count);
  char * bxi_strtriml (      char * str);
  char * bxi_strtrimr (      char * str);
  char * bxi_strtrim  (      char * str);
u32    bxi_strlen   (const char * str);
i32    bxi_strcmp   (const char * str1, const char * str2);
i32    bxi_strncmp  (const char * str1, const char * str2, u32 n);
u32    bxi_strprs   (char * str, char ** output);
u32    bxi_strprsnq (char * str, char ** output);
char * bxi_strchr   (const char * str, i32 c);
char * bxi_strrchr  (const char * str, i32 c);
char * bxi_strchrnul(const char * str, i32 c);
char * bxi_strcpy   (      char * dst, const char * src);
char * bxi_strncpy  (      char * dst, const char * src, u32 n);
char * bxi_strstr   (const char * str, const char * sub);
char * bxi_strcat   (      char * dst, const char * src);
char * bxi_strncat  (      char * dst, const char * src, u32 n);
char * bxi_strpbrk  (const char * str, const char * lst);
u32    bxi_strspn   (const char * str, const char * lst);
u32    bxi_strcspn  (const char * str, const char * lst);
char * bxi_strrep   (      char * str, const char * what, const char * by);
BXI_USES_MEM char * bxi_strdup(const char * str);
BXI_USES_MEM char * bxi_strapp(char ** dst, const char * src);
bool bxi_iscntrl (u32 c);
bool bxi_isprint (u32 c);
bool bxi_isspace (u32 c);
bool bxi_isblank (u32 c);
bool bxi_isgraph (u32 c);
bool bxi_ispunct (u32 c);
bool bxi_isalnum (u32 c);
bool bxi_isalpha (u32 c);
bool bxi_isupper (u32 c);
bool bxi_islower (u32 c);
bool bxi_isdigit (u32 c);
bool bxi_isxdigit(u32 c);
u32 bxi_2upper(u32 c);
u32 bxi_2lower(u32 c);
void bxi_str2upper(char * str);
void bxi_str2lower(char * str);
```