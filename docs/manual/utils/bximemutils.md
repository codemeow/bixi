## bximemutils.h 

### Memory allocation 

As the Bixi library does not have any external dependencies it requires the 
memory allocation functions to be set manually. The following functions and
types allow to do that:
```c
typedef u32 bxi_memopt_t;
typedef void * (* bxi_malloc_t )(            u32 size, const char * file, u32 line);
typedef void   (* bxi_free_t   )(void * ptr,           const char * file, u32 line);
typedef void * (* bxi_realloc_t)(void * ptr, u32 size, const char * file, u32 line);
typedef void   (* bxi_memerr_t )(            u32 size, const char * file, u32 line);
```
If user requires the whole memory to be zero-initialised right after the allocation
the `bxi_memopt_set`  function with `BXI_MEM_ZERO` parameter should be used.
```c
#define BXI_MEM_NONE
#define BXI_MEM_ZERO
void   bxi_memopt_set (bxi_memopt_t memopt);
```
```c
void   bxi_malloc_set (bxi_malloc_t  func);
void   bxi_free_set   (bxi_free_t    func);
void   bxi_realloc_set(bxi_realloc_t func);
void   bxi_memerr_set (bxi_memerr_t  func);

void * bxi_malloc_call (            u32 size, const char * file, u32 line);
void   bxi_free_call   (void * ptr          , const char * file, u32 line);
void * bxi_realloc_call(void * ptr, u32 size, const char * file, u32 line);
```

For the memory allocation/re/deallocation user should use the following definitions:
```c
#define bxi_malloc(size)
#define bxi_realloc(ptr, size)
#define bxi_free(ptr)
```

### Memory management 

As Bixi library does not use standart library functions the following functions
might be used for memory management:
```c
void * bxi_memset  (      void * ptr,        i32   val,        u32 cnt);
void * bxi_memset16(      void * ptr,        u32   val,        u32 cnt);
void * bxi_memset32(      void * ptr,        u32   val,        u32 cnt);
void * bxi_memcpy  (      void * dst, const void * src,        u32 cnt);
void * bxi_memmove (      void * dst, const void * src,        u32 cnt);
i32    bxi_memcmp  (const void * p1,  const void * p2,         u32 cnt);
void * bxi_memfrob (      void * ptr,         u8   val,        u32 cnt);
void * bxi_memchr  (const void * ptr,         u8   val,        u32 cnt);
void * bxi_memrchr (const void * ptr,         u8   val,        u32 cnt);
void * bxi_mempcpy (      void * dst, const void * src,        u32 cnt);
void * bxi_memccpy (      void * dst, const void * src, i32 c, u32 cnt);
```
*NOTE*: the `bxi_memfrob` function in difference with usual version additionally
has `val` parameter.