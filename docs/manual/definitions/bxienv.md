## bxienv.h 

To simplify work on different compilers are operation systems Bixi library
provides plenty of macro definitions:

### Operation system detection 

```c
#define BXI_OS "PowerPC-64"
```
This macro definition contains text description of current operation system
```c
#define BXI_OS_XXX
```
These macro definitions define current operation system as separate macro. Possible
values are:
```c
 BXI_OS_AIX - for AIX
 BXI_OS_AND - for Android
 BXI_OS_AMG - for Amiga
 BXI_OS_BOS - for BeOS
 BXI_OS_FBS - for FreeBSD
 BXI_OS_NBS - for NetBSD
 BXI_OS_OBS - for OpenBSD
 BXI_OS_BSD - for BSD/OS
 BXI_OS_DFL - for DragonFly
 BXI_OS_CYG - for Cygwin
 BXI_OS_MSD - for MS-DOS
 BXI_OS_PAL - for PalmOS
 BXI_OS_UNX - for UNIX
 BXI_OS_MNX - for Minix ----- Tested on real OS
 BXI_OS_GHR - for GNU/Herd
 BXI_OS_GLX - for GNU/Linux - Tested on real OS
 BXI_OS_MAC - for MacOS
 BXI_OS_OS2 - for OS/2
 BXI_OS_WIN - for Windows
 BXI_OS_WCE - for WindowsCE
 BXI_OS_ZOS - for z/OS
 BXI_OS_SLR - for Solaris
 BXI_OS_SOS - for SunOS
```

### 16/32/64 bit OS 

```c
#define BXI_BITS (64)
```
This macro definition contains integer value fo current OS's bitness.
```c
#define BXI_BITS_XX
```
These macto definitions define current OS's bitness as separate macro. Possible
values are:
```c
 BXI_BITS_16 - for 16-bit OS
 BXI_BITS_32 - for 32-bit OS - Tested on real OS
 BXI_BITS_64 - for 64-bit OS - Tested on real OS
```
The following macro defines current endianness:
```c
#define BXI_ENDIAN_BE
or
#define BXI_ENDIAN_LE
```
