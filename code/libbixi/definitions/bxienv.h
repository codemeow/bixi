/*
 * "Bixi" - Basic types management C89 library
 *
 *  Copyright (C) Alexey Shishkin 2017
 *
 *  This file is part of Project "Bixi".
 *
 *  Project "Bixi" is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Project "Bixi" is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with Project "Bixi". If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef BXIENV_H
#define BXIENV_H

#include "../definitions/bxiexport.h"

EXPORT_FROM
/* Macro list:
Operation systems:
 BXI_OS as "XXXX" for OS-name
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
 BXI_OS_MNX (T) - for Minix
 BXI_OS_GHR - for GNU/Herd
 BXI_OS_GLX (T) - for GNU/Linux
 BXI_OS_MAC - for MacOS
 BXI_OS_OS2 - for OS/2
 BXI_OS_WIN - for Windows
 BXI_OS_WCE - for WindowsCE
 BXI_OS_ZOS - for z/OS
 BXI_OS_SLR - for Solaris
 BXI_OS_SOS - for SunOS
*T - completely tested

Bits:
 BXI_BITS as XX for bits
 BXI_BITS_16 - for 16-bit OS
 BXI_BITS_32 - for 32-bit OS
 BXI_BITS_64 - for 64-bit OS

Architecture:
 BXI_ARCH as "XXXX" for arch-name
 BXI_ARCH_P32 - for PowerPC-32
 BXI_ARCH_P64 - for PowerPC-64
 BXI_ARCH_S32 - for Sparc-32
 BXI_ARCH_S64 - for Sparc-64
 BXI_ARCH_ALP - for Alpha
 BXI_ARCH_A32 - for ARM-32
 BXI_ARCH_A64 - for ARM-64
 BXI_ARCH_M32 - for MIPS-32
 BXI_ARCH_M64 - for MIPS-64
 BXI_ARCH_Z32 - for System-370/390
 BXI_ARCH_Z64 - for z/Architecture
 BXI_ARCH_X32 - for x86
 BXI_ARCH_X64 - for x86_64
 BXI_ARCH_I64 - for Intel Itanium */
EXPORT_TO

/* Bits and arch */

EXPORT_FROM
#if defined(__powerpc__) || defined(__ppc__) || defined(__PPC__)
#if defined(__powerpc64__) || defined(__ppc64__) || defined(__PPC64__) || \
    defined(__64BIT__) || defined(_LP64) || defined(__LP64__)
#   define BXI_BITS_64
#   define BXI_BITS (64)
#   define BXI_ARCH_P64
#   define BXI_ARCH "PowerPC-64"
#else
#   define BXI_BITS_32
#   define BXI_BITS (32)
#   define BXI_ARCH_P32
#   define BXI_ARCH "PowerPC-32"
#endif
#endif
EXPORT_TO

EXPORT_FROM
#if defined(__sparc)
#   define BXI_BITS_32
#   define BXI_BITS (32)
#   define BXI_ARCH_S32
#   define BXI_ARCH "Sparc-32"

/*#   define BXI_BITS_64*/
/*#   define BXI_ARCH_S64*/
/*#   define BXI_ARCH "Sparc-64"*/
#endif
EXPORT_TO

EXPORT_FROM
#if defined(__alpha) || defined(__alpha__) || defined(_M_ALPHA)
#   define BXI_ARCH_ALP
#   define BXI_BITS_64
#   define BXI_BITS (64)
#   define BXI_ARCH "Alpha"
#endif
EXPORT_TO

EXPORT_FROM
#if defined(__arm) || defined(__arm__) || defined (_M_ARM)
# if defined (__aarch64__)
#   define BXI_ARCH_A64
#   define BXI_BITS_64
#   define BXI_BITS (64)
#   define BXI_ARCH "ARM-64"
# else
#   define BXI_ARCH_A32
#   define BXI_BITS_32
#   define BXI_BITS (32)
#   define BXI_ARCH "ARM-32"
#endif
#endif
EXPORT_TO

EXPORT_FROM
#if defined(__mips) || defined(__mips__) || defined(__MIPS__)
# if defined(_R3000) || defined(_MIPS_ISA_MIPS1) || defined(_MIPS_ISA_MIPS2)
#   define BXI_ARCH_M32
#   define BXI_BITS_32
#   define BXI_BITS (32)
#   define BXI_ARCH "MIPS-32"
# else
#   define BXI_ARCH_M64
#   define BXI_BITS_64
#   define BXI_BITS (64)
#   define BXI_ARCH "MIPS-64"
# endif
#endif
EXPORT_TO

EXPORT_FROM
#if defined(__370__) || defined(__THW_370__) || defined(__s390__)
#   define BXI_ARCH_Z32
#   define BXI_BITS_32
#   define BXI_BITS (32)
#   define BXI_ARCH "System-370/390"
#endif
EXPORT_TO

EXPORT_FROM
#if defined(__s390x__) || defined(__zarch__) || defined(__SYSC_ZARCH__)
#   define BXI_ARCH_Z64
#   define BXI_BITS_64
#   define BXI_BITS (64)
#   define BXI_ARCH "z/Architecture"
#endif
EXPORT_TO

EXPORT_FROM
#if defined(__x86_64__) || defined(_M_X64) || defined(__amd64__) || defined(__amd64)
#   define BXI_ARCH_X64
#   define BXI_BITS_64
#   define BXI_BITS (64)
#   define BXI_ARCH "x86_64"
#elif defined(__i386) || defined(_M_IX86)
#   define BXI_ARCH_X32
#   define BXI_BITS_32
#   define BXI_BITS (32)
#   define BXI_ARCH "x86"
#endif
EXPORT_TO

EXPORT_FROM
#if defined(__ia64) || defined(__itanium__) || defined(_M_IA64)
#   define BXI_ARCH_I64
#   define BXI_BITS_64
#   define BXI_BITS (64)
#   define BXI_ARCH "Intel Itanium"
#endif
EXPORT_TO

/* OS */

EXPORT_FROM
#if defined(__AIX)
#   define BXI_OS "AIX"
#   define BXI_OS_AIX
#endif
EXPORT_TO

EXPORT_FROM
#if defined(__ANDROID__)
#   define BXI_OS "Android"
#   define BXI_OS_AND
#endif
EXPORT_TO

EXPORT_FROM
#if defined(AMIGA)
#   define BXI_OS "Amiga"
#   define BXI_OS_AMG
#endif
EXPORT_TO

EXPORT_FROM
#if defined(__BEOS__)
#   define BXI_OS "BeOS"
#   define BXI_OS_BOS
#endif
EXPORT_TO

EXPORT_FROM
#if defined(__FreeBSD__)
#   define BXI_OS "FreeBSD"
#   define BXI_OS_FBS
#endif
EXPORT_TO

EXPORT_FROM
#if defined(__NetBSD__)
#   define BXI_OS "NetBSD"
#   define BXI_OS_NBS
#endif
EXPORT_TO

EXPORT_FROM
#if defined(__OpenBSD__)
#   define BXI_OS "OpenBSD"
#   define BXI_OS_OBS
#endif
EXPORT_TO

EXPORT_FROM
#if defined(__bsdi__)
#   define BXI_OS "BSD/OS"
#   define BXI_OS_BSD
#endif
EXPORT_TO

EXPORT_FROM
#if defined(__DragonFly__)
#   define BXI_OS "DragonFly"
#   define BXI_OS_DFL
#endif
EXPORT_TO

EXPORT_FROM
#if defined(__CYGWIN__)
#   define BXI_OS "Cygwin"
#   define BXI_OS_CYG
#endif
EXPORT_TO

EXPORT_FROM
#if defined(MSDOS) || defined(__MSDOS__) || defined(_MSDOS) || defined(__DOS__)
#   define BXI_OS_MSD
#   define BXI_OS "MS-DOS"
#endif
EXPORT_TO

EXPORT_FROM
#if defined(__palmos__)
#   define BXI_OS "PalmOS"
#   define BXI_OS_PAL
#endif
EXPORT_TO

EXPORT_FROM
#if (defined(__unix__) || defined(__unix)) && (!defined(__linux__)) && (!defined(__minix))
#   define BXI_OS "UNIX"
#   define BXI_OS_UNX
#endif
EXPORT_TO

EXPORT_FROM
#if defined(__minix)
#   define BXI_OS "Minix"
#   define BXI_OS_MNX
#endif
EXPORT_TO

EXPORT_FROM
#if defined(__GNU__) || defined(__gnu_herd__)
#   define BXI_OS "GNU/Herd"
#   define BXI_OS_GHR
#endif
EXPORT_TO

EXPORT_FROM
#if defined(__gnu_linux__)
#   define BXI_OS "GNU/Linux"
#   define BXI_OS_GLX
#endif
EXPORT_TO

EXPORT_FROM
#if (defined(__APPLE__) && defined(__MACH__)) || defined(macintosh)
#   define BXI_OS "MacOS"
#   define BXI_OS_MAC
#endif
EXPORT_TO

EXPORT_FROM
#if defined(OS2) || defined(_OS2) || defined(__OS2__) || defined(__TOS_OS2__)
#   define BXI_OS "OS/2"
#   define BXI_OS_OS2
#endif
EXPORT_TO

EXPORT_FROM
#if defined(_WIN16) || defined(_WIN32) || defined(_WIN64) || \
    defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
#   define BXI_OS "Windows"
#   define BXI_OS_WIN
#endif
EXPORT_TO

EXPORT_FROM
#if defined(_WIN32_WCE)
#   define BXI_OS "WindowsCE"
#   define BXI_OS_WCE
#endif
EXPORT_TO

EXPORT_FROM
#if defined(__MVS__) || defined(__HOS_MVS__) || defined(__TOS_MVS__)
#   define BXI_OS "z/OS"
#   define BXI_OS_ZOS
#endif
EXPORT_TO

EXPORT_FROM
#if defined(sun) || defined(__sun)
# if defined(__SVR4) || defined(__svr4__)
#   define BXI_OS "Solaris"
#   define BXI_OS_SLR
# else
#   define BXI_OS "SunOS"
#   define BXI_OS_SOS
# endif
#endif
EXPORT_TO

EXPORT_FROM
#define BXI_WORD_SIZE ((BXI_BITS) >> 3)
EXPORT_TO

#endif /* BXIENV_H */
