## bxiassert.h 

### Assert 

```c
#define COMPILE_ASSERT(expr)
```
This macro checks the provided expression for truth. If the expression's result
is false, the asser happens and compilation fails.
This macro automatically disables when `NDEBUG` macro is set.