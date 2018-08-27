## bxithread.h 

Bixi library also provides mutex realisation for platforms without stable version of it
and/or with version with unfair locks:

```c
#define BXI_MUTEX_PERIOD  (1) /* us */
#define BXI_MUTEX_INITIALIZER
```
```c
typedef u32 bxi_mutex;
typedef enum
{
    BXI_MUTEX_UNLOCKED,
    BXI_MUTEX_LOCKED,
    BXI_MUTEX_UNDEFINED
} bxi_mutex_st;
```
```c
             void         bxi_mutex_init  (volatile bxi_mutex * mutex);
BXI_USES_SLP void         bxi_mutex_lock  (volatile bxi_mutex * mutex);
             void         bxi_mutex_unlock(volatile bxi_mutex * mutex);
             bxi_mutex_st bxi_mutex_test  (volatile bxi_mutex * mutex);
```