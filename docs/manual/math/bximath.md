## bximath.h 

For math calculations purposes the following constants and functions are provided:
```c
#define BXI_PI            /* Pi             */
#define BXI_PI_DIV_2      /* Pi / 2         */
#define BXI_PI_DIV_4      /* Pi / 4         */
#define BXI_1_DIV_PI      /* 1 / Pi         */
#define BXI_2_DIV_PI      /* 2 / Pi         */
#define BXI_4_DIV_PI      /* 4 / Pi         */
#define BXI_4_DIV_SQR_PI  /* 4 / Pi^2       */

#define BXI_E             /* Euler's number */
#define BXI_PHI           /* Golden ratio   */
#define BXI_E_POW_PI      /* e^Pi           */

#define BXI_LOG2_E        /* Log2(e)        */
#define BXI_LOG10_E       /* Log10(e)       */
#define BXI_LN_E          /* Ln(2)          */
#define BXI_LN_10         /* Ln(10)         */

#define BXI_SQRT_2        /* Sqrt(2)        */
#define BXI_SQRT_3        /* Sqrt(3)        */
#define BXI_SQRT_5        /* Sqrt(5)        */
#define BXI_1_DIV_SQRT_2  /* 1 / Sqrt(2)    */
```
```c
#define BXI_MAX(a, b)
#define BXI_MIN(a, b)
```
*NOTE*: be aware that `MAX` & `MIN` definitions doublecalculate the arguments.
```c
#define BXI_FAST_DIV_2(x)         
#define BXI_FAST_DIV_4(x)         
#define BXI_FAST_DIV_8(x)         
#define BXI_FAST_DIV_16(x)        
#define BXI_FAST_DIV_32(x)        
#define BXI_FAST_DIV_64(x)        
#define BXI_FAST_DIV_128(x)       
#define BXI_FAST_DIV_256(x)       
#define BXI_FAST_DIV_512(x)       
#define BXI_FAST_DIV_1024(x)      
#define BXI_FAST_DIV_2048(x)      
#define BXI_FAST_DIV_4096(x)      
#define BXI_FAST_DIV_8192(x)      
#define BXI_FAST_DIV_16384(x)     
#define BXI_FAST_DIV_32768(x)     
#define BXI_FAST_DIV_65536(x)     
#define BXI_FAST_DIV_131072(x)    
#define BXI_FAST_DIV_262144(x)    
#define BXI_FAST_DIV_524288(x)    
#define BXI_FAST_DIV_1048576(x)   
#define BXI_FAST_DIV_2097152(x)   
#define BXI_FAST_DIV_4194304(x)   
#define BXI_FAST_DIV_8388608(x)   
#define BXI_FAST_DIV_16777216(x)  
#define BXI_FAST_DIV_33554432(x)  
#define BXI_FAST_DIV_67108864(x)  
#define BXI_FAST_DIV_134217728(x) 
#define BXI_FAST_DIV_268435456(x) 
#define BXI_FAST_DIV_536870912(x) 
#define BXI_FAST_DIV_1073741824(x)
#define BXI_FAST_DIV_2147483648(x)

#define BXI_FAST_MUL_2(x)       
#define BXI_FAST_MUL_4(x)       
#define BXI_FAST_MUL_8(x)       
#define BXI_FAST_MUL_16(x)      
#define BXI_FAST_MUL_32(x)      
#define BXI_FAST_MUL_64(x)      
#define BXI_FAST_MUL_128(x)     
#define BXI_FAST_MUL_256(x)     
#define BXI_FAST_MUL_512(x)     
#define BXI_FAST_MUL_1024(x)    
#define BXI_FAST_MUL_2048(x)    
#define BXI_FAST_MUL_4096(x)     
#define BXI_FAST_MUL_8192(x)     
#define BXI_FAST_MUL_16384(x)    
#define BXI_FAST_MUL_32768(x)    
#define BXI_FAST_MUL_65536(x)    
#define BXI_FAST_MUL_131072(x)   
#define BXI_FAST_MUL_262144(x)   
#define BXI_FAST_MUL_524288(x)   
#define BXI_FAST_MUL_1048576(x)  
#define BXI_FAST_MUL_2097152(x)   
#define BXI_FAST_MUL_4194304(x)   
#define BXI_FAST_MUL_8388608(x)   
#define BXI_FAST_MUL_16777216(x)   
#define BXI_FAST_MUL_33554432(x)   
#define BXI_FAST_MUL_67108864(x)   
#define BXI_FAST_MUL_134217728(x) 
#define BXI_FAST_MUL_268435456(x)  
#define BXI_FAST_MUL_536870912(x) 
#define BXI_FAST_MUL_1073741824(x) 
#define BXI_FAST_MUL_2147483648(x) 

#define BXI_FAST_U16DIV255(x) 

#define BXI_NAN   
#define BXI_INF_POS
#define BXI_INF_NEG
```
```c
u32  bxi_abs(i32 val);
i32  bxi_sign(i32 val);
i32  bxi_gcd(i32 a, i32 b);
i32  bxi_lcm(i32 a, i32 b);
u32  bxi_sqrti(u32 x);
f64  bxi_nan    (void);
f64  bxi_inf_pos(void);
f64  bxi_inf_neg(void);
bool bxi_isnan(f64 x);
bool bxi_isinfpos(f64 x);
bool bxi_isinfneg(f64 x);
f64  bxi_floor(f64 x);
f64  bxi_round(f64 x);
f64  bxi_ceil (f64 x);
f64  bxi_trunc(f64 x);
f64  bxi_modf (f64 x, f64 * i);
f64  bxi_fmod (f64 x, f64   y);
f64  bxi_fabs (f64 x);
f64  bxi_fsin(f64 x); /* -Pi..+Pi */
f64  bxi_fcos(f64 x); /* -Pi..+Pi */
```
*NOTE*: the `bxi_sqrti` function uses about 32 KB of memory for statically calculated
corrections table. If the 32 KB of additionally occupied is crucial the library could
be built without it:
```
-DBXI_NO_SQRTI
```