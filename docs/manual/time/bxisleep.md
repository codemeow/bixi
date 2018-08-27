## bxisleep.h 

As Bixi library does not has any external dependencies `sleep` function should be
provided by library user by the following type and function:
```c
typedef void (*bxi_sleep_int_func)(u32 sec, u32 nsec);
void bxi_nsleep_set(bxi_sleep_int_func func);
```

After the sleep function is set the following definitions and functions could 
be safely used:
```c
#define BXI_MSEC_IN_SEC  
#define BXI_USEC_IN_SEC 
#define BXI_NSEC_IN_SEC  
#define BXI_NSEC_IN_USEC 
#define BXI_NSEC_IN_MSEC 
#define BXI_USEC_IN_MSEC
```
```c
#define SEC_PER_MIN 
#define MIN_PER_HRS 
#define HRS_PER_DAY 

#define DAYS_PER_WEEK 

#define SEC_PER_HRS 
#define SEC_PER_DAY 
#define MIN_PER_DAY
```
```c
BXI_USES_SLP void bxi_sleep (u32  sec);
BXI_USES_SLP void bxi_msleep(u32 msec);
BXI_USES_SLP void bxi_usleep(u32 usec);
BXI_USES_SLP void bxi_nsleep(u32 nsec);
BXI_USES_SLP void bxi_fsleep(f64  sec);
```
```c
typedef enum
/* days are numbered by the order
 * they've appeared in unixtime
 * to simplify unixtime date math */
{
    BXI_MONDAY    = (4),
    BXI_TUESDAY   = (5),
    BXI_WEDNESDAY = (6),
    BXI_THURSDAY  = (0),
    BXI_FRIDAY    = (1),
    BXI_SATURDAY  = (2),
    BXI_SUNDAY    = (3)
} bxi_weekdays;
```