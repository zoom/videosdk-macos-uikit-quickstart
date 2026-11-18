/////////////////////////////////////////////////////////////////////////////
//  OS / target-platform definition macros.
//
//  Provides:
//    * Numeric platform identifiers:
//        CMM_PLATFORM_LINUX / BSD / SUN / CYGWIN /
//        WIN32 / WIN64 / WIN_ARM64 /
//        MAC / MAC64 / ANDROID
//    * A CMM_PLATFORM value set to one of the above, based on compiler
//      predefines of the current translation unit.
//    * Target-OS indicator macros (defined when applicable):
//        CMM_ANDROID / CMM_LINUX / CMM_BSD / CMM_SUN / CMM_CYGWIN /
//        CMM_WIN (+ CMM_WIN32 / CMM_WIN64 / CMM_WIN_ARM64 / CMM_WINX86) /
//        CMM_MAC (+ CMM_MAC32 / CMM_MAC64)
//    * CMM_POSIX on POSIX-family targets, CMM_GNU on GNU-toolchain targets.
//
//  Typical usage:
//      #include "CmmOsDef.h"
//      #if defined(CMM_WIN)
//          ...
//      #elif defined(CMM_MAC)
//          ...
//      #endif
/////////////////////////////////////////////////////////////////////////////

#ifndef __COMMON_OS_DEF_H_INCLUDED_
#define __COMMON_OS_DEF_H_INCLUDED_

#define CMM_PLATFORM_LINUX                   0
#define CMM_PLATFORM_BSD                     1
#define CMM_PLATFORM_SUN                     2
#define CMM_PLATFORM_CYGWIN                  3
#define CMM_PLATFORM_WIN32                   4
#define CMM_PLATFORM_WIN64                   5
#define CMM_PLATFORM_MAC                     6
#define CMM_PLATFORM_MAC64                   7
#define CMM_PLATFORM_ANDROID                 8
#define CMM_PLATFORM_WIN_ARM64               9

#if defined (ANDROID)
#   define CMM_ANDROID
#   define CMM_GNU
#   define CMM_PLATFORM                      CMM_PLATFORM_ANDROID
#	define CMM_POSIX
#	define NO_TIMEGM                         1
#elif defined ( linux ) || defined ( __linux ) || defined ( __linux__ )
#   define CMM_GNU
#   define CMM_LINUX
#   define CMM_PLATFORM                      CMM_PLATFORM_LINUX
#	define CMM_POSIX
#elif defined ( __FreeBSD__ ) || defined ( __NetBSD__ ) || defined ( __OpenBSD__ )
#   define CMM_GNU
#   define CMM_BSD
#   define CMM_PLATFORM                      CMM_PLATFORM_BSD
#	define CMM_POSIX
#elif defined ( sun ) || defined ( __sun )
#   define CMM_GNU
#   define CMM_SUN
#   define CMM_PLATFORM                      CMM_PLATFORM_SUN
#	define CMM_POSIX
#elif defined ( __CYGWIN__ )
#   define CMM_GNU
#   define CMM_CYGWIN
#   define CMM_PLATFORM                      CMM_PLATFORM_CYGWIN
#	define CMM_POSIX
#elif defined ( _WIN32 ) || defined ( __WIN32__ ) || defined ( WIN32 )
#   define CMM_WIN
#   define CMM_WIN32   // This is equivalent to CMM_WIN because of historical compatibility
#   if defined(_M_ARM64)
#       define CMM_WIN_ARM64
#       define CMM_PLATFORM                      CMM_PLATFORM_WIN_ARM64
#   elif defined ( _WIN64 ) || defined ( __WIN64__ ) || defined ( WIN64 )
#       define CMM_WIN64
#       define CMM_PLATFORM                      CMM_PLATFORM_WIN64
#   else
#       define CMM_WINX86
#       define CMM_PLATFORM                      CMM_PLATFORM_WIN32
#   endif
#elif defined ( macintosh ) || defined ( __APPLE__ ) || defined ( __APPLE_CC__ )
#   define CMM_MAC
#	define CMM_POSIX
#   if defined (__LP64__) || defined (__64BIT__) || defined (_LP64) || (__WORDSIZE == 64)
#       define CMM_MAC64
#       define CMM_PLATFORM                  CMM_PLATFORM_MAC64
#   else
#       define CMM_MAC32
#       define CMM_PLATFORM                  CMM_PLATFORM_MAC
#   endif
#endif

#endif // __COMMON_OS_DEF_H_INCLUDED_
