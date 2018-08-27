## bxiexport.h 

### Export purposes 

For export purposes Bixi library uses the following macro definitions:

```c
#define   EXPORT
#define   EXPORT_FROM
#define   EXPORT_TO
```

These definitions are needed for C-otter building system.

### Markers 

The following macro definitions are designed to mark functions that are needed
extra preactions to work:

```c
#define BXI_USES_MEM 
```

This macro definition warns that the function needs memory allocation functions
to be set.

```c
#define BXI_USES_SLP
```

This macro definition warns that the function needs sleep functions to be set