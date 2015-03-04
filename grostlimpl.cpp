/***************************************************************************
**                                                                        **
**  Grøstl (http://www.groestl.info/) implementation file                 **
**                                                                        **
**  This file implements the Grøstl hash algorithm as provided by the     **
**  inventors, and submitted to the third round of the NIST SHA-3         **
**  competition.                                                          **
**  For the QGrostlHash wrapper, the originally multiple files were       **
**  combined in this one. Slight modifications have been made to          **
**  allow use in C++ as an independently included .cpp file.              **
**  It is not meant to be compiled into an object, hence, there is no     **
**  header.                                                               **
**                                                                        **
**  The code here is not part of the actual QGrostlHash implementation    **
**  and thus not licensed under the GPLv3 but under its respecitve        **
**  license given by the inventors. Typically, this means it is in the    **
**  public domain, if not noted otherwise.                                **
**                                                                        **
***************************************************************************/

namespace GrostlImpl {

// ================================================================================
// =================== brg_endian.h
// ================================================================================

/*
 ---------------------------------------------------------------------------
 Copyright (c) 1998-2008, Brian Gladman, Worcester, UK. All rights reserved.

 LICENSE TERMS

 The redistribution and use of this software (with or without changes)
 is allowed without the payment of fees or royalties provided that:

  1. source code distributions include the above copyright notice, this
     list of conditions and the following disclaimer;

  2. binary distributions include the above copyright notice, this list
     of conditions and the following disclaimer in their documentation;

  3. the name of the copyright holder is not used to endorse products
     built using this software without specific written permission.

 DISCLAIMER

 This software is provided 'as is' with no explicit or implied warranties
 in respect of its properties, including, but not limited to, correctness
 and/or fitness for purpose.
 ---------------------------------------------------------------------------
 Issue Date: 20/12/2007
*/

#ifndef _BRG_ENDIAN_H
#define _BRG_ENDIAN_H

#define IS_BIG_ENDIAN      4321 /* byte 0 is most significant (mc68k) */
#define IS_LITTLE_ENDIAN   1234 /* byte 0 is least significant (i386) */

/* Include files where endian defines and byteswap functions may reside */
#if defined( __sun )
#  include <sys/isa_defs.h>
#elif defined( __FreeBSD__ ) || defined( __OpenBSD__ ) || defined( __NetBSD__ )
#  include <sys/endian.h>
#elif defined( BSD ) && ( BSD >= 199103 ) || defined( __APPLE__ ) || \
      defined( __CYGWIN32__ ) || defined( __DJGPP__ ) || defined( __osf__ )
#  include <machine/endian.h>
#elif defined( __linux__ ) || defined( __GNUC__ ) || defined( __GNU_LIBRARY__ )
#  if !defined( __MINGW32__ ) && !defined( _AIX )
#    include <endian.h>
#    if !defined( __BEOS__ )
#      include <byteswap.h>
#    endif
#  endif
#endif

/* Now attempt to set the define for platform byte order using any  */
/* of the four forms SYMBOL, _SYMBOL, __SYMBOL & __SYMBOL__, which  */
/* seem to encompass most endian symbol definitions                 */

#if defined( BIG_ENDIAN ) && defined( LITTLE_ENDIAN )
#  if defined( BYTE_ORDER ) && BYTE_ORDER == BIG_ENDIAN
#    define PLATFORM_BYTE_ORDER IS_BIG_ENDIAN
#  elif defined( BYTE_ORDER ) && BYTE_ORDER == LITTLE_ENDIAN
#    define PLATFORM_BYTE_ORDER IS_LITTLE_ENDIAN
#  endif
#elif defined( BIG_ENDIAN )
#  define PLATFORM_BYTE_ORDER IS_BIG_ENDIAN
#elif defined( LITTLE_ENDIAN )
#  define PLATFORM_BYTE_ORDER IS_LITTLE_ENDIAN
#endif

#if defined( _BIG_ENDIAN ) && defined( _LITTLE_ENDIAN )
#  if defined( _BYTE_ORDER ) && _BYTE_ORDER == _BIG_ENDIAN
#    define PLATFORM_BYTE_ORDER IS_BIG_ENDIAN
#  elif defined( _BYTE_ORDER ) && _BYTE_ORDER == _LITTLE_ENDIAN
#    define PLATFORM_BYTE_ORDER IS_LITTLE_ENDIAN
#  endif
#elif defined( _BIG_ENDIAN )
#  define PLATFORM_BYTE_ORDER IS_BIG_ENDIAN
#elif defined( _LITTLE_ENDIAN )
#  define PLATFORM_BYTE_ORDER IS_LITTLE_ENDIAN
#endif

#if defined( __BIG_ENDIAN ) && defined( __LITTLE_ENDIAN )
#  if defined( __BYTE_ORDER ) && __BYTE_ORDER == __BIG_ENDIAN
#    define PLATFORM_BYTE_ORDER IS_BIG_ENDIAN
#  elif defined( __BYTE_ORDER ) && __BYTE_ORDER == __LITTLE_ENDIAN
#    define PLATFORM_BYTE_ORDER IS_LITTLE_ENDIAN
#  endif
#elif defined( __BIG_ENDIAN )
#  define PLATFORM_BYTE_ORDER IS_BIG_ENDIAN
#elif defined( __LITTLE_ENDIAN )
#  define PLATFORM_BYTE_ORDER IS_LITTLE_ENDIAN
#endif

#if defined( __BIG_ENDIAN__ ) && defined( __LITTLE_ENDIAN__ )
#  if defined( __BYTE_ORDER__ ) && __BYTE_ORDER__ == __BIG_ENDIAN__
#    define PLATFORM_BYTE_ORDER IS_BIG_ENDIAN
#  elif defined( __BYTE_ORDER__ ) && __BYTE_ORDER__ == __LITTLE_ENDIAN__
#    define PLATFORM_BYTE_ORDER IS_LITTLE_ENDIAN
#  endif
#elif defined( __BIG_ENDIAN__ )
#  define PLATFORM_BYTE_ORDER IS_BIG_ENDIAN
#elif defined( __LITTLE_ENDIAN__ )
#  define PLATFORM_BYTE_ORDER IS_LITTLE_ENDIAN
#endif

/*  if the platform byte order could not be determined, then try to */
/*  set this define using common machine defines                    */
#if !defined(PLATFORM_BYTE_ORDER)

#if   defined( __alpha__ ) || defined( __alpha ) || defined( i386 )       || \
      defined( __i386__ )  || defined( _M_I86 )  || defined( _M_IX86 )    || \
      defined( __OS2__ )   || defined( sun386 )  || defined( __TURBOC__ ) || \
      defined( vax )       || defined( vms )     || defined( VMS )        || \
      defined( __VMS )     || defined( _M_X64 )
#  define PLATFORM_BYTE_ORDER IS_LITTLE_ENDIAN

#elif defined( AMIGA )   || defined( applec )    || defined( __AS400__ )  || \
      defined( _CRAY )   || defined( __hppa )    || defined( __hp9000 )   || \
      defined( ibm370 )  || defined( mc68000 )   || defined( m68k )       || \
      defined( __MRC__ ) || defined( __MVS__ )   || defined( __MWERKS__ ) || \
      defined( sparc )   || defined( __sparc)    || defined( SYMANTEC_C ) || \
      defined( __VOS__ ) || defined( __TIGCC__ ) || defined( __TANDEM )   || \
      defined( THINK_C ) || defined( __VMCMS__ ) || defined( _AIX )
#  define PLATFORM_BYTE_ORDER IS_BIG_ENDIAN

#elif 0     /* **** EDIT HERE IF NECESSARY **** */
#  define PLATFORM_BYTE_ORDER IS_LITTLE_ENDIAN
#elif 0     /* **** EDIT HERE IF NECESSARY **** */
#  define PLATFORM_BYTE_ORDER IS_BIG_ENDIAN
#else
#  error Please edit lines 126 or 128 in brg_endian.h to set the platform byte order
#endif

#endif

#endif


// ================================================================================
// =================== brg_types.h
// ================================================================================

/*
 ---------------------------------------------------------------------------
 Copyright (c) 1998-2008, Brian Gladman, Worcester, UK. All rights reserved.

 (a few lines added by Soeren S. Thomsen, October 2008)

 LICENSE TERMS

 The redistribution and use of this software (with or without changes)
 is allowed without the payment of fees or royalties provided that:

  1. source code distributions include the above copyright notice, this
     list of conditions and the following disclaimer;

  2. binary distributions include the above copyright notice, this list
     of conditions and the following disclaimer in their documentation;

  3. the name of the copyright holder is not used to endorse products
     built using this software without specific written permission.

 DISCLAIMER

 This software is provided 'as is' with no explicit or implied warranties
 in respect of its properties, including, but not limited to, correctness
 and/or fitness for purpose.
 ---------------------------------------------------------------------------
 Issue Date: 20/12/2007

 The unsigned integer types defined here are of the form uint_<nn>t where
 <nn> is the length of the type; for example, the unsigned 32-bit type is
 'uint_32t'.  These are NOT the same as the 'C99 integer types' that are
 defined in the inttypes.h and stdint.h headers since attempts to use these
 types have shown that support for them is still highly variable.  However,
 since the latter are of the form uint<nn>_t, a regular expression search
 and replace (in VC++ search on 'uint_{:z}t' and replace with 'uint\1_t')
 can be used to convert the types used here to the C99 standard types.
*/

#ifndef _BRG_TYPES_H
#define _BRG_TYPES_H

#include <limits.h>

#if defined( _MSC_VER ) && ( _MSC_VER >= 1300 )
#  include <stddef.h>
#  define ptrint_t intptr_t
#elif defined( __GNUC__ ) && ( __GNUC__ >= 3 )
#  include <stdint.h>
#  define ptrint_t intptr_t
#else
#  define ptrint_t int
#endif

#ifndef BRG_UI8
#  define BRG_UI8
#  if UCHAR_MAX == 255u
     typedef unsigned char uint_8t;
#  else
#    error Please define uint_8t as an 8-bit unsigned integer type in brg_types.h
#  endif
#endif

#ifndef BRG_UI16
#  define BRG_UI16
#  if USHRT_MAX == 65535u
     typedef unsigned short uint_16t;
#  else
#    error Please define uint_16t as a 16-bit unsigned short type in brg_types.h
#  endif
#endif

#ifndef BRG_UI32
#  define BRG_UI32
#  if UINT_MAX == 4294967295u
#    define li_32(h) 0x##h##u
     typedef unsigned int uint_32t;
#  elif ULONG_MAX == 4294967295u
#    define li_32(h) 0x##h##ul
     typedef unsigned long uint_32t;
#  elif defined( _CRAY )
#    error This code needs 32-bit data types, which Cray machines do not provide
#  else
#    error Please define uint_32t as a 32-bit unsigned integer type in brg_types.h
#  endif
#endif

#ifndef BRG_UI64
#  if defined( __BORLANDC__ ) && !defined( __MSDOS__ )
#    define BRG_UI64
#    define li_64(h) 0x##h##ui64
     typedef unsigned __int64 uint_64t;
#  elif defined( _MSC_VER ) && ( _MSC_VER < 1300 )    /* 1300 == VC++ 7.0 */
#    define BRG_UI64
#    define li_64(h) 0x##h##ui64
     typedef unsigned __int64 uint_64t;
#  elif defined( __sun ) && defined( ULONG_MAX ) && ULONG_MAX == 0xfffffffful
#    define BRG_UI64
#    define li_64(h) 0x##h##ull
     typedef unsigned long long uint_64t;
#  elif defined( __MVS__ )
#    define BRG_UI64
#    define li_64(h) 0x##h##ull
     typedef unsigned int long long uint_64t;
#  elif defined( UINT_MAX ) && UINT_MAX > 4294967295u
#    if UINT_MAX == 18446744073709551615u
#      define BRG_UI64
#      define li_64(h) 0x##h##u
       typedef unsigned int uint_64t;
#    endif
#  elif defined( ULONG_MAX ) && ULONG_MAX > 4294967295u
#    if ULONG_MAX == 18446744073709551615ul
#      define BRG_UI64
#      define li_64(h) 0x##h##ul
       typedef unsigned long uint_64t;
#    endif
#  elif defined( ULLONG_MAX ) && ULLONG_MAX > 4294967295u
#    if ULLONG_MAX == 18446744073709551615ull
#      define BRG_UI64
#      define li_64(h) 0x##h##ull
       typedef unsigned long long uint_64t;
#    endif
#  elif defined( ULONG_LONG_MAX ) && ULONG_LONG_MAX > 4294967295u
#    if ULONG_LONG_MAX == 18446744073709551615ull
#      define BRG_UI64
#      define li_64(h) 0x##h##ull
       typedef unsigned long long uint_64t;
#    endif
#  endif
#endif

#if !defined( BRG_UI64 )
#  if defined( NEED_UINT_64T )
#    error Please define uint_64t as an unsigned 64 bit type in brg_types.h
#  endif
#endif

#ifndef RETURN_VALUES
#  define RETURN_VALUES
#  if defined( DLL_EXPORT )
#    if defined( _MSC_VER ) || defined ( __INTEL_COMPILER )
#      define VOID_RETURN    __declspec( dllexport ) void __stdcall
#      define INT_RETURN     __declspec( dllexport ) int  __stdcall
#    elif defined( __GNUC__ )
#      define VOID_RETURN    __declspec( __dllexport__ ) void
#      define INT_RETURN     __declspec( __dllexport__ ) int
#    else
#      error Use of the DLL is only available on the Microsoft, Intel and GCC compilers
#    endif
#  elif defined( DLL_IMPORT )
#    if defined( _MSC_VER ) || defined ( __INTEL_COMPILER )
#      define VOID_RETURN    __declspec( dllimport ) void __stdcall
#      define INT_RETURN     __declspec( dllimport ) int  __stdcall
#    elif defined( __GNUC__ )
#      define VOID_RETURN    __declspec( __dllimport__ ) void
#      define INT_RETURN     __declspec( __dllimport__ ) int
#    else
#      error Use of the DLL is only available on the Microsoft, Intel and GCC compilers
#    endif
#  elif defined( __WATCOMC__ )
#    define VOID_RETURN  void __cdecl
#    define INT_RETURN   int  __cdecl
#  else
#    define VOID_RETURN  void
#    define INT_RETURN   int
#  endif
#endif

/*	These defines are used to detect and set the memory alignment of pointers.
    Note that offsets are in bytes.

	ALIGN_OFFSET(x,n)			return the positive or zero offset of 
								the memory addressed by the pointer 'x' 
								from an address that is aligned on an 
								'n' byte boundary ('n' is a power of 2)

	ALIGN_FLOOR(x,n)			return a pointer that points to memory
								that is aligned on an 'n' byte boundary 
								and is not higher than the memory address
								pointed to by 'x' ('n' is a power of 2)

	ALIGN_CEIL(x,n)				return a pointer that points to memory
								that is aligned on an 'n' byte boundary 
								and is not lower than the memory address
								pointed to by 'x' ('n' is a power of 2)
*/

#define ALIGN_OFFSET(x,n)	(((ptrint_t)(x)) & ((n) - 1))
#define ALIGN_FLOOR(x,n)	((uint_8t*)(x) - ( ((ptrint_t)(x)) & ((n) - 1)))
#define ALIGN_CEIL(x,n)		((uint_8t*)(x) + (-((ptrint_t)(x)) & ((n) - 1)))

/*  These defines are used to declare buffers in a way that allows
    faster operations on longer variables to be used.  In all these
    defines 'size' must be a power of 2 and >= 8. NOTE that the 
    buffer size is in bytes but the type length is in bits

    UNIT_TYPEDEF(x,size)        declares a variable 'x' of length 
                                'size' bits

    BUFR_TYPEDEF(x,size,bsize)  declares a buffer 'x' of length 'bsize' 
                                bytes defined as an array of variables
                                each of 'size' bits (bsize must be a 
                                multiple of size / 8)

    UNIT_CAST(x,size)           casts a variable to a type of 
                                length 'size' bits

    UPTR_CAST(x,size)           casts a pointer to a pointer to a 
                                varaiable of length 'size' bits
*/

#define UI_TYPE(size)               uint_##size##t
#define UNIT_TYPEDEF(x,size)        typedef UI_TYPE(size) x
#define BUFR_TYPEDEF(x,size,bsize)  typedef UI_TYPE(size) x[bsize / (size >> 3)]
#define UNIT_CAST(x,size)           ((UI_TYPE(size) )(x))  
#define UPTR_CAST(x,size)           ((UI_TYPE(size)*)(x))

  /* Added by Soeren S. Thomsen (begin) */
#define u8 uint_8t
#define u32 uint_32t
#define u64 uint_64t
  /* (end) */

#endif

// ================================================================================
// =================== tables.h
// ================================================================================

#ifndef __tables_h
#define __tables_h

//#include "brg_endian.h"
//#include "brg_types.h"

#if (PLATFORM_BYTE_ORDER == IS_BIG_ENDIAN)
const u32 T[8*256]  __attribute__((aligned(64))) = {
  0xc632f4a5UL,0xf86f9784UL,0xee5eb099UL,0xf67a8c8dUL,0xffe8170dUL,0xd60adcbdUL,0xde16c8b1UL,0x916dfc54UL,0x6090f050UL,0x02070503UL,0xce2ee0a9UL,0x56d1877dUL,0xe7cc2b19UL,0xb513a662UL,0x4d7c31e6UL,0xec59b59aUL,0x8f40cf45UL,0x1fa3bc9dUL,0x8949c040UL,0xfa689287UL,0xefd03f15UL,0xb29426ebUL,0x8ece40c9UL,0xfbe61d0bUL,0x416e2fecUL,0xb31aa967UL,0x5f431cfdUL,0x456025eaUL,0x23f9dabfUL,0x535102f7UL,0xe445a196UL,0x9b76ed5bUL,0x75285dc2UL,0xe1c5241cUL,0x3dd4e9aeUL,0x4cf2be6aUL,0x6c82ee5aUL,0x7ebdc341UL,0xf5f30602UL,0x8352d14fUL,0x688ce45cUL,0x515607f4UL,0xd18d5c34UL,0xf9e11808UL,0xe24cae93UL,0xab3e9573UL,0x6297f553UL,0x2a6b413fUL,0x081c140cUL,0x9563f652UL,0x46e9af65UL,0x9d7fe25eUL,0x30487828UL,0x37cff8a1UL,0x0a1b110fUL,0x2febc4b5UL,0x0e151b09UL,0x247e5a36UL,0x1badb69bUL,0xdf98473dUL,0xcda76a26UL,0x4ef5bb69UL,0x7f334ccdUL,0xea50ba9fUL,0x123f2d1bUL,0x1da4b99eUL,0x58c49c74UL,0x3446722eUL,0x3641772dUL,0xdc11cdb2UL,0xb49d29eeUL,0x5b4d16fbUL,0xa4a501f6UL,0x76a1d74dUL,0xb714a361UL,0x7d3449ceUL,0x52df8d7bUL,0xdd9f423eUL,0x5ecd9371UL,0x13b1a297UL,0xa6a204f5UL,0xb901b868UL,0x00000000UL,0xc1b5742cUL,0x40e0a060UL,0xe3c2211fUL,0x793a43c8UL,0xb69a2cedUL,0xd40dd9beUL,0x8d47ca46UL,0x671770d9UL,0x72afdd4bUL,0x94ed79deUL,0x98ff67d4UL,0xb09323e8UL,0x855bde4aUL,0xbb06bd6bUL,0xc5bb7e2aUL,0x4f7b34e5UL,0xedd73a16UL,0x86d254c5UL,0x9af862d7UL,0x6699ff55UL,0x11b6a794UL,0x8ac04acfUL,0xe9d93010UL,0x040e0a06UL,0xfe669881UL,0xa0ab0bf0UL,0x78b4cc44UL,0x25f0d5baUL,0x4b753ee3UL,0xa2ac0ef3UL,0x5d4419feUL,0x80db5bc0UL,0x0580858aUL,0x3fd3ecadUL,0x21fedfbcUL,0x70a8d848UL,0xf1fd0c04UL,0x63197adfUL,0x772f58c1UL,0xaf309f75UL,0x42e7a563UL,0x20705030UL,0xe5cb2e1aUL,0xfdef120eUL,0xbf08b76dUL,0x8155d44cUL,0x18243c14UL,0x26795f35UL,0xc3b2712fUL,0xbe8638e1UL,0x35c8fda2UL,0x88c74fccUL,0x2e654b39UL,0x936af957UL,0x55580df2UL,0xfc619d82UL,0x7ab3c947UL,0xc827efacUL,0xba8832e7UL,0x324f7d2bUL,0xe642a495UL,0xc03bfba0UL,0x19aab398UL,0x9ef668d1UL,0xa322817fUL,0x44eeaa66UL,0x54d6827eUL,0x3bdde6abUL,0x0b959e83UL,0x8cc945caUL,0xc7bc7b29UL,0x6b056ed3UL,0x286c443cUL,0xa72c8b79UL,0xbc813de2UL,0x1631271dUL,0xad379a76UL,0xdb964d3bUL,0x649efa56UL,0x74a6d24eUL,0x1436221eUL,0x92e476dbUL,0x0c121e0aUL,0x48fcb46cUL,0xb88f37e4UL,0x9f78e75dUL,0xbd0fb26eUL,0x43692aefUL,0xc435f1a6UL,0x39dae3a8UL,0x31c6f7a4UL,0xd38a5937UL,0xf274868bUL,0xd5835632UL,0x8b4ec543UL,0x6e85eb59UL,0xda18c2b7UL,0x018e8f8cUL,0xb11dac64UL,0x9cf16dd2UL,0x49723be0UL,0xd81fc7b4UL,0xacb915faUL,0xf3fa0907UL,0xcfa06f25UL,0xca20eaafUL,0xf47d898eUL,0x476720e9UL,0x10382818UL,0x6f0b64d5UL,0xf0738388UL,0x4afbb16fUL,0x5cca9672UL,0x38546c24UL,0x575f08f1UL,0x732152c7UL,0x9764f351UL,0xcbae6523UL,0xa125847cUL,0xe857bf9cUL,0x3e5d6321UL,0x96ea7cddUL,0x611e7fdcUL,0x0d9c9186UL,0x0f9b9485UL,0xe04bab90UL,0x7cbac642UL,0x712657c4UL,0xcc29e5aaUL,0x90e373d8UL,0x06090f05UL,0xf7f40301UL,0x1c2a3612UL,0xc23cfea3UL,0x6a8be15fUL,0xaebe10f9UL,0x69026bd0UL,0x17bfa891UL,0x9971e858UL,0x3a536927UL,0x27f7d0b9UL,0xd9914838UL,0xebde3513UL,0x2be5ceb3UL,0x22775533UL,0xd204d6bbUL,0xa9399070UL,0x07878089UL,0x33c1f2a7UL,0x2decc1b6UL,0x3c5a6622UL,0x15b8ad92UL,0xc9a96020UL,0x875cdb49UL,0xaab01affUL,0x50d88878UL,0xa52b8e7aUL,0x03898a8fUL,0x594a13f8UL,0x09929b80UL,0x1a233917UL,0x651075daUL,0xd7845331UL,0x84d551c6UL,0xd003d3b8UL,0x82dc5ec3UL,0x29e2cbb0UL,0x5ac39977UL,0x1e2d3311UL,0x7b3d46cbUL,0xa8b71ffcUL,0x6d0c61d6UL,0x2c624e3aUL,
  0xc6c632f4UL,0xf8f86f97UL,0xeeee5eb0UL,0xf6f67a8cUL,0xffffe817UL,0xd6d60adcUL,0xdede16c8UL,0x91916dfcUL,0x606090f0UL,0x02020705UL,0xcece2ee0UL,0x5656d187UL,0xe7e7cc2bUL,0xb5b513a6UL,0x4d4d7c31UL,0xecec59b5UL,0x8f8f40cfUL,0x1f1fa3bcUL,0x898949c0UL,0xfafa6892UL,0xefefd03fUL,0xb2b29426UL,0x8e8ece40UL,0xfbfbe61dUL,0x41416e2fUL,0xb3b31aa9UL,0x5f5f431cUL,0x45456025UL,0x2323f9daUL,0x53535102UL,0xe4e445a1UL,0x9b9b76edUL,0x7575285dUL,0xe1e1c524UL,0x3d3dd4e9UL,0x4c4cf2beUL,0x6c6c82eeUL,0x7e7ebdc3UL,0xf5f5f306UL,0x838352d1UL,0x68688ce4UL,0x51515607UL,0xd1d18d5cUL,0xf9f9e118UL,0xe2e24caeUL,0xabab3e95UL,0x626297f5UL,0x2a2a6b41UL,0x08081c14UL,0x959563f6UL,0x4646e9afUL,0x9d9d7fe2UL,0x30304878UL,0x3737cff8UL,0x0a0a1b11UL,0x2f2febc4UL,0x0e0e151bUL,0x24247e5aUL,0x1b1badb6UL,0xdfdf9847UL,0xcdcda76aUL,0x4e4ef5bbUL,0x7f7f334cUL,0xeaea50baUL,0x12123f2dUL,0x1d1da4b9UL,0x5858c49cUL,0x34344672UL,0x36364177UL,0xdcdc11cdUL,0xb4b49d29UL,0x5b5b4d16UL,0xa4a4a501UL,0x7676a1d7UL,0xb7b714a3UL,0x7d7d3449UL,0x5252df8dUL,0xdddd9f42UL,0x5e5ecd93UL,0x1313b1a2UL,0xa6a6a204UL,0xb9b901b8UL,0x00000000UL,0xc1c1b574UL,0x4040e0a0UL,0xe3e3c221UL,0x79793a43UL,0xb6b69a2cUL,0xd4d40dd9UL,0x8d8d47caUL,0x67671770UL,0x7272afddUL,0x9494ed79UL,0x9898ff67UL,0xb0b09323UL,0x85855bdeUL,0xbbbb06bdUL,0xc5c5bb7eUL,0x4f4f7b34UL,0xededd73aUL,0x8686d254UL,0x9a9af862UL,0x666699ffUL,0x1111b6a7UL,0x8a8ac04aUL,0xe9e9d930UL,0x04040e0aUL,0xfefe6698UL,0xa0a0ab0bUL,0x7878b4ccUL,0x2525f0d5UL,0x4b4b753eUL,0xa2a2ac0eUL,0x5d5d4419UL,0x8080db5bUL,0x05058085UL,0x3f3fd3ecUL,0x2121fedfUL,0x7070a8d8UL,0xf1f1fd0cUL,0x6363197aUL,0x77772f58UL,0xafaf309fUL,0x4242e7a5UL,0x20207050UL,0xe5e5cb2eUL,0xfdfdef12UL,0xbfbf08b7UL,0x818155d4UL,0x1818243cUL,0x2626795fUL,0xc3c3b271UL,0xbebe8638UL,0x3535c8fdUL,0x8888c74fUL,0x2e2e654bUL,0x93936af9UL,0x5555580dUL,0xfcfc619dUL,0x7a7ab3c9UL,0xc8c827efUL,0xbaba8832UL,0x32324f7dUL,0xe6e642a4UL,0xc0c03bfbUL,0x1919aab3UL,0x9e9ef668UL,0xa3a32281UL,0x4444eeaaUL,0x5454d682UL,0x3b3bdde6UL,0x0b0b959eUL,0x8c8cc945UL,0xc7c7bc7bUL,0x6b6b056eUL,0x28286c44UL,0xa7a72c8bUL,0xbcbc813dUL,0x16163127UL,0xadad379aUL,0xdbdb964dUL,0x64649efaUL,0x7474a6d2UL,0x14143622UL,0x9292e476UL,0x0c0c121eUL,0x4848fcb4UL,0xb8b88f37UL,0x9f9f78e7UL,0xbdbd0fb2UL,0x4343692aUL,0xc4c435f1UL,0x3939dae3UL,0x3131c6f7UL,0xd3d38a59UL,0xf2f27486UL,0xd5d58356UL,0x8b8b4ec5UL,0x6e6e85ebUL,0xdada18c2UL,0x01018e8fUL,0xb1b11dacUL,0x9c9cf16dUL,0x4949723bUL,0xd8d81fc7UL,0xacacb915UL,0xf3f3fa09UL,0xcfcfa06fUL,0xcaca20eaUL,0xf4f47d89UL,0x47476720UL,0x10103828UL,0x6f6f0b64UL,0xf0f07383UL,0x4a4afbb1UL,0x5c5cca96UL,0x3838546cUL,0x57575f08UL,0x73732152UL,0x979764f3UL,0xcbcbae65UL,0xa1a12584UL,0xe8e857bfUL,0x3e3e5d63UL,0x9696ea7cUL,0x61611e7fUL,0x0d0d9c91UL,0x0f0f9b94UL,0xe0e04babUL,0x7c7cbac6UL,0x71712657UL,0xcccc29e5UL,0x9090e373UL,0x0606090fUL,0xf7f7f403UL,0x1c1c2a36UL,0xc2c23cfeUL,0x6a6a8be1UL,0xaeaebe10UL,0x6969026bUL,0x1717bfa8UL,0x999971e8UL,0x3a3a5369UL,0x2727f7d0UL,0xd9d99148UL,0xebebde35UL,0x2b2be5ceUL,0x22227755UL,0xd2d204d6UL,0xa9a93990UL,0x07078780UL,0x3333c1f2UL,0x2d2decc1UL,0x3c3c5a66UL,0x1515b8adUL,0xc9c9a960UL,0x87875cdbUL,0xaaaab01aUL,0x5050d888UL,0xa5a52b8eUL,0x0303898aUL,0x59594a13UL,0x0909929bUL,0x1a1a2339UL,0x65651075UL,0xd7d78453UL,0x8484d551UL,0xd0d003d3UL,0x8282dc5eUL,0x2929e2cbUL,0x5a5ac399UL,0x1e1e2d33UL,0x7b7b3d46UL,0xa8a8b71fUL,0x6d6d0c61UL,0x2c2c624eUL,
  0xa5c6c632UL,0x84f8f86fUL,0x99eeee5eUL,0x8df6f67aUL,0x0dffffe8UL,0xbdd6d60aUL,0xb1dede16UL,0x5491916dUL,0x50606090UL,0x03020207UL,0xa9cece2eUL,0x7d5656d1UL,0x19e7e7ccUL,0x62b5b513UL,0xe64d4d7cUL,0x9aecec59UL,0x458f8f40UL,0x9d1f1fa3UL,0x40898949UL,0x87fafa68UL,0x15efefd0UL,0xebb2b294UL,0xc98e8eceUL,0x0bfbfbe6UL,0xec41416eUL,0x67b3b31aUL,0xfd5f5f43UL,0xea454560UL,0xbf2323f9UL,0xf7535351UL,0x96e4e445UL,0x5b9b9b76UL,0xc2757528UL,0x1ce1e1c5UL,0xae3d3dd4UL,0x6a4c4cf2UL,0x5a6c6c82UL,0x417e7ebdUL,0x02f5f5f3UL,0x4f838352UL,0x5c68688cUL,0xf4515156UL,0x34d1d18dUL,0x08f9f9e1UL,0x93e2e24cUL,0x73abab3eUL,0x53626297UL,0x3f2a2a6bUL,0x0c08081cUL,0x52959563UL,0x654646e9UL,0x5e9d9d7fUL,0x28303048UL,0xa13737cfUL,0x0f0a0a1bUL,0xb52f2febUL,0x090e0e15UL,0x3624247eUL,0x9b1b1badUL,0x3ddfdf98UL,0x26cdcda7UL,0x694e4ef5UL,0xcd7f7f33UL,0x9feaea50UL,0x1b12123fUL,0x9e1d1da4UL,0x745858c4UL,0x2e343446UL,0x2d363641UL,0xb2dcdc11UL,0xeeb4b49dUL,0xfb5b5b4dUL,0xf6a4a4a5UL,0x4d7676a1UL,0x61b7b714UL,0xce7d7d34UL,0x7b5252dfUL,0x3edddd9fUL,0x715e5ecdUL,0x971313b1UL,0xf5a6a6a2UL,0x68b9b901UL,0x00000000UL,0x2cc1c1b5UL,0x604040e0UL,0x1fe3e3c2UL,0xc879793aUL,0xedb6b69aUL,0xbed4d40dUL,0x468d8d47UL,0xd9676717UL,0x4b7272afUL,0xde9494edUL,0xd49898ffUL,0xe8b0b093UL,0x4a85855bUL,0x6bbbbb06UL,0x2ac5c5bbUL,0xe54f4f7bUL,0x16ededd7UL,0xc58686d2UL,0xd79a9af8UL,0x55666699UL,0x941111b6UL,0xcf8a8ac0UL,0x10e9e9d9UL,0x0604040eUL,0x81fefe66UL,0xf0a0a0abUL,0x447878b4UL,0xba2525f0UL,0xe34b4b75UL,0xf3a2a2acUL,0xfe5d5d44UL,0xc08080dbUL,0x8a050580UL,0xad3f3fd3UL,0xbc2121feUL,0x487070a8UL,0x04f1f1fdUL,0xdf636319UL,0xc177772fUL,0x75afaf30UL,0x634242e7UL,0x30202070UL,0x1ae5e5cbUL,0x0efdfdefUL,0x6dbfbf08UL,0x4c818155UL,0x14181824UL,0x35262679UL,0x2fc3c3b2UL,0xe1bebe86UL,0xa23535c8UL,0xcc8888c7UL,0x392e2e65UL,0x5793936aUL,0xf2555558UL,0x82fcfc61UL,0x477a7ab3UL,0xacc8c827UL,0xe7baba88UL,0x2b32324fUL,0x95e6e642UL,0xa0c0c03bUL,0x981919aaUL,0xd19e9ef6UL,0x7fa3a322UL,0x664444eeUL,0x7e5454d6UL,0xab3b3bddUL,0x830b0b95UL,0xca8c8cc9UL,0x29c7c7bcUL,0xd36b6b05UL,0x3c28286cUL,0x79a7a72cUL,0xe2bcbc81UL,0x1d161631UL,0x76adad37UL,0x3bdbdb96UL,0x5664649eUL,0x4e7474a6UL,0x1e141436UL,0xdb9292e4UL,0x0a0c0c12UL,0x6c4848fcUL,0xe4b8b88fUL,0x5d9f9f78UL,0x6ebdbd0fUL,0xef434369UL,0xa6c4c435UL,0xa83939daUL,0xa43131c6UL,0x37d3d38aUL,0x8bf2f274UL,0x32d5d583UL,0x438b8b4eUL,0x596e6e85UL,0xb7dada18UL,0x8c01018eUL,0x64b1b11dUL,0xd29c9cf1UL,0xe0494972UL,0xb4d8d81fUL,0xfaacacb9UL,0x07f3f3faUL,0x25cfcfa0UL,0xafcaca20UL,0x8ef4f47dUL,0xe9474767UL,0x18101038UL,0xd56f6f0bUL,0x88f0f073UL,0x6f4a4afbUL,0x725c5ccaUL,0x24383854UL,0xf157575fUL,0xc7737321UL,0x51979764UL,0x23cbcbaeUL,0x7ca1a125UL,0x9ce8e857UL,0x213e3e5dUL,0xdd9696eaUL,0xdc61611eUL,0x860d0d9cUL,0x850f0f9bUL,0x90e0e04bUL,0x427c7cbaUL,0xc4717126UL,0xaacccc29UL,0xd89090e3UL,0x05060609UL,0x01f7f7f4UL,0x121c1c2aUL,0xa3c2c23cUL,0x5f6a6a8bUL,0xf9aeaebeUL,0xd0696902UL,0x911717bfUL,0x58999971UL,0x273a3a53UL,0xb92727f7UL,0x38d9d991UL,0x13ebebdeUL,0xb32b2be5UL,0x33222277UL,0xbbd2d204UL,0x70a9a939UL,0x89070787UL,0xa73333c1UL,0xb62d2decUL,0x223c3c5aUL,0x921515b8UL,0x20c9c9a9UL,0x4987875cUL,0xffaaaab0UL,0x785050d8UL,0x7aa5a52bUL,0x8f030389UL,0xf859594aUL,0x80090992UL,0x171a1a23UL,0xda656510UL,0x31d7d784UL,0xc68484d5UL,0xb8d0d003UL,0xc38282dcUL,0xb02929e2UL,0x775a5ac3UL,0x111e1e2dUL,0xcb7b7b3dUL,0xfca8a8b7UL,0xd66d6d0cUL,0x3a2c2c62UL,
  0x97a5c6c6UL,0xeb84f8f8UL,0xc799eeeeUL,0xf78df6f6UL,0xe50dffffUL,0xb7bdd6d6UL,0xa7b1dedeUL,0x39549191UL,0xc0506060UL,0x04030202UL,0x87a9ceceUL,0xac7d5656UL,0xd519e7e7UL,0x7162b5b5UL,0x9ae64d4dUL,0xc39aececUL,0x05458f8fUL,0x3e9d1f1fUL,0x09408989UL,0xef87fafaUL,0xc515efefUL,0x7febb2b2UL,0x07c98e8eUL,0xed0bfbfbUL,0x82ec4141UL,0x7d67b3b3UL,0xbefd5f5fUL,0x8aea4545UL,0x46bf2323UL,0xa6f75353UL,0xd396e4e4UL,0x2d5b9b9bUL,0xeac27575UL,0xd91ce1e1UL,0x7aae3d3dUL,0x986a4c4cUL,0xd85a6c6cUL,0xfc417e7eUL,0xf102f5f5UL,0x1d4f8383UL,0xd05c6868UL,0xa2f45151UL,0xb934d1d1UL,0xe908f9f9UL,0xdf93e2e2UL,0x4d73ababUL,0xc4536262UL,0x543f2a2aUL,0x100c0808UL,0x31529595UL,0x8c654646UL,0x215e9d9dUL,0x60283030UL,0x6ea13737UL,0x140f0a0aUL,0x5eb52f2fUL,0x1c090e0eUL,0x48362424UL,0x369b1b1bUL,0xa53ddfdfUL,0x8126cdcdUL,0x9c694e4eUL,0xfecd7f7fUL,0xcf9feaeaUL,0x241b1212UL,0x3a9e1d1dUL,0xb0745858UL,0x682e3434UL,0x6c2d3636UL,0xa3b2dcdcUL,0x73eeb4b4UL,0xb6fb5b5bUL,0x53f6a4a4UL,0xec4d7676UL,0x7561b7b7UL,0xface7d7dUL,0xa47b5252UL,0xa13eddddUL,0xbc715e5eUL,0x26971313UL,0x57f5a6a6UL,0x6968b9b9UL,0x00000000UL,0x992cc1c1UL,0x80604040UL,0xdd1fe3e3UL,0xf2c87979UL,0x77edb6b6UL,0xb3bed4d4UL,0x01468d8dUL,0xced96767UL,0xe44b7272UL,0x33de9494UL,0x2bd49898UL,0x7be8b0b0UL,0x114a8585UL,0x6d6bbbbbUL,0x912ac5c5UL,0x9ee54f4fUL,0xc116ededUL,0x17c58686UL,0x2fd79a9aUL,0xcc556666UL,0x22941111UL,0x0fcf8a8aUL,0xc910e9e9UL,0x08060404UL,0xe781fefeUL,0x5bf0a0a0UL,0xf0447878UL,0x4aba2525UL,0x96e34b4bUL,0x5ff3a2a2UL,0xbafe5d5dUL,0x1bc08080UL,0x0a8a0505UL,0x7ead3f3fUL,0x42bc2121UL,0xe0487070UL,0xf904f1f1UL,0xc6df6363UL,0xeec17777UL,0x4575afafUL,0x84634242UL,0x40302020UL,0xd11ae5e5UL,0xe10efdfdUL,0x656dbfbfUL,0x194c8181UL,0x30141818UL,0x4c352626UL,0x9d2fc3c3UL,0x67e1bebeUL,0x6aa23535UL,0x0bcc8888UL,0x5c392e2eUL,0x3d579393UL,0xaaf25555UL,0xe382fcfcUL,0xf4477a7aUL,0x8bacc8c8UL,0x6fe7babaUL,0x642b3232UL,0xd795e6e6UL,0x9ba0c0c0UL,0x32981919UL,0x27d19e9eUL,0x5d7fa3a3UL,0x88664444UL,0xa87e5454UL,0x76ab3b3bUL,0x16830b0bUL,0x03ca8c8cUL,0x9529c7c7UL,0xd6d36b6bUL,0x503c2828UL,0x5579a7a7UL,0x63e2bcbcUL,0x2c1d1616UL,0x4176adadUL,0xad3bdbdbUL,0xc8566464UL,0xe84e7474UL,0x281e1414UL,0x3fdb9292UL,0x180a0c0cUL,0x906c4848UL,0x6be4b8b8UL,0x255d9f9fUL,0x616ebdbdUL,0x86ef4343UL,0x93a6c4c4UL,0x72a83939UL,0x62a43131UL,0xbd37d3d3UL,0xff8bf2f2UL,0xb132d5d5UL,0x0d438b8bUL,0xdc596e6eUL,0xafb7dadaUL,0x028c0101UL,0x7964b1b1UL,0x23d29c9cUL,0x92e04949UL,0xabb4d8d8UL,0x43faacacUL,0xfd07f3f3UL,0x8525cfcfUL,0x8fafcacaUL,0xf38ef4f4UL,0x8ee94747UL,0x20181010UL,0xded56f6fUL,0xfb88f0f0UL,0x946f4a4aUL,0xb8725c5cUL,0x70243838UL,0xaef15757UL,0xe6c77373UL,0x35519797UL,0x8d23cbcbUL,0x597ca1a1UL,0xcb9ce8e8UL,0x7c213e3eUL,0x37dd9696UL,0xc2dc6161UL,0x1a860d0dUL,0x1e850f0fUL,0xdb90e0e0UL,0xf8427c7cUL,0xe2c47171UL,0x83aaccccUL,0x3bd89090UL,0x0c050606UL,0xf501f7f7UL,0x38121c1cUL,0x9fa3c2c2UL,0xd45f6a6aUL,0x47f9aeaeUL,0xd2d06969UL,0x2e911717UL,0x29589999UL,0x74273a3aUL,0x4eb92727UL,0xa938d9d9UL,0xcd13ebebUL,0x56b32b2bUL,0x44332222UL,0xbfbbd2d2UL,0x4970a9a9UL,0x0e890707UL,0x66a73333UL,0x5ab62d2dUL,0x78223c3cUL,0x2a921515UL,0x8920c9c9UL,0x15498787UL,0x4fffaaaaUL,0xa0785050UL,0x517aa5a5UL,0x068f0303UL,0xb2f85959UL,0x12800909UL,0x34171a1aUL,0xcada6565UL,0xb531d7d7UL,0x13c68484UL,0xbbb8d0d0UL,0x1fc38282UL,0x52b02929UL,0xb4775a5aUL,0x3c111e1eUL,0xf6cb7b7bUL,0x4bfca8a8UL,0xdad66d6dUL,0x583a2c2cUL,
  0xf497a5c6UL,0x97eb84f8UL,0xb0c799eeUL,0x8cf78df6UL,0x17e50dffUL,0xdcb7bdd6UL,0xc8a7b1deUL,0xfc395491UL,0xf0c05060UL,0x05040302UL,0xe087a9ceUL,0x87ac7d56UL,0x2bd519e7UL,0xa67162b5UL,0x319ae64dUL,0xb5c39aecUL,0xcf05458fUL,0xbc3e9d1fUL,0xc0094089UL,0x92ef87faUL,0x3fc515efUL,0x267febb2UL,0x4007c98eUL,0x1ded0bfbUL,0x2f82ec41UL,0xa97d67b3UL,0x1cbefd5fUL,0x258aea45UL,0xda46bf23UL,0x02a6f753UL,0xa1d396e4UL,0xed2d5b9bUL,0x5deac275UL,0x24d91ce1UL,0xe97aae3dUL,0xbe986a4cUL,0xeed85a6cUL,0xc3fc417eUL,0x06f102f5UL,0xd11d4f83UL,0xe4d05c68UL,0x07a2f451UL,0x5cb934d1UL,0x18e908f9UL,0xaedf93e2UL,0x954d73abUL,0xf5c45362UL,0x41543f2aUL,0x14100c08UL,0xf6315295UL,0xaf8c6546UL,0xe2215e9dUL,0x78602830UL,0xf86ea137UL,0x11140f0aUL,0xc45eb52fUL,0x1b1c090eUL,0x5a483624UL,0xb6369b1bUL,0x47a53ddfUL,0x6a8126cdUL,0xbb9c694eUL,0x4cfecd7fUL,0xbacf9feaUL,0x2d241b12UL,0xb93a9e1dUL,0x9cb07458UL,0x72682e34UL,0x776c2d36UL,0xcda3b2dcUL,0x2973eeb4UL,0x16b6fb5bUL,0x0153f6a4UL,0xd7ec4d76UL,0xa37561b7UL,0x49face7dUL,0x8da47b52UL,0x42a13eddUL,0x93bc715eUL,0xa2269713UL,0x0457f5a6UL,0xb86968b9UL,0x00000000UL,0x74992cc1UL,0xa0806040UL,0x21dd1fe3UL,0x43f2c879UL,0x2c77edb6UL,0xd9b3bed4UL,0xca01468dUL,0x70ced967UL,0xdde44b72UL,0x7933de94UL,0x672bd498UL,0x237be8b0UL,0xde114a85UL,0xbd6d6bbbUL,0x7e912ac5UL,0x349ee54fUL,0x3ac116edUL,0x5417c586UL,0x622fd79aUL,0xffcc5566UL,0xa7229411UL,0x4a0fcf8aUL,0x30c910e9UL,0x0a080604UL,0x98e781feUL,0x0b5bf0a0UL,0xccf04478UL,0xd54aba25UL,0x3e96e34bUL,0x0e5ff3a2UL,0x19bafe5dUL,0x5b1bc080UL,0x850a8a05UL,0xec7ead3fUL,0xdf42bc21UL,0xd8e04870UL,0x0cf904f1UL,0x7ac6df63UL,0x58eec177UL,0x9f4575afUL,0xa5846342UL,0x50403020UL,0x2ed11ae5UL,0x12e10efdUL,0xb7656dbfUL,0xd4194c81UL,0x3c301418UL,0x5f4c3526UL,0x719d2fc3UL,0x3867e1beUL,0xfd6aa235UL,0x4f0bcc88UL,0x4b5c392eUL,0xf93d5793UL,0x0daaf255UL,0x9de382fcUL,0xc9f4477aUL,0xef8bacc8UL,0x326fe7baUL,0x7d642b32UL,0xa4d795e6UL,0xfb9ba0c0UL,0xb3329819UL,0x6827d19eUL,0x815d7fa3UL,0xaa886644UL,0x82a87e54UL,0xe676ab3bUL,0x9e16830bUL,0x4503ca8cUL,0x7b9529c7UL,0x6ed6d36bUL,0x44503c28UL,0x8b5579a7UL,0x3d63e2bcUL,0x272c1d16UL,0x9a4176adUL,0x4dad3bdbUL,0xfac85664UL,0xd2e84e74UL,0x22281e14UL,0x763fdb92UL,0x1e180a0cUL,0xb4906c48UL,0x376be4b8UL,0xe7255d9fUL,0xb2616ebdUL,0x2a86ef43UL,0xf193a6c4UL,0xe372a839UL,0xf762a431UL,0x59bd37d3UL,0x86ff8bf2UL,0x56b132d5UL,0xc50d438bUL,0xebdc596eUL,0xc2afb7daUL,0x8f028c01UL,0xac7964b1UL,0x6d23d29cUL,0x3b92e049UL,0xc7abb4d8UL,0x1543faacUL,0x09fd07f3UL,0x6f8525cfUL,0xea8fafcaUL,0x89f38ef4UL,0x208ee947UL,0x28201810UL,0x64ded56fUL,0x83fb88f0UL,0xb1946f4aUL,0x96b8725cUL,0x6c702438UL,0x08aef157UL,0x52e6c773UL,0xf3355197UL,0x658d23cbUL,0x84597ca1UL,0xbfcb9ce8UL,0x637c213eUL,0x7c37dd96UL,0x7fc2dc61UL,0x911a860dUL,0x941e850fUL,0xabdb90e0UL,0xc6f8427cUL,0x57e2c471UL,0xe583aaccUL,0x733bd890UL,0x0f0c0506UL,0x03f501f7UL,0x3638121cUL,0xfe9fa3c2UL,0xe1d45f6aUL,0x1047f9aeUL,0x6bd2d069UL,0xa82e9117UL,0xe8295899UL,0x6974273aUL,0xd04eb927UL,0x48a938d9UL,0x35cd13ebUL,0xce56b32bUL,0x55443322UL,0xd6bfbbd2UL,0x904970a9UL,0x800e8907UL,0xf266a733UL,0xc15ab62dUL,0x6678223cUL,0xad2a9215UL,0x608920c9UL,0xdb154987UL,0x1a4fffaaUL,0x88a07850UL,0x8e517aa5UL,0x8a068f03UL,0x13b2f859UL,0x9b128009UL,0x3934171aUL,0x75cada65UL,0x53b531d7UL,0x5113c684UL,0xd3bbb8d0UL,0x5e1fc382UL,0xcb52b029UL,0x99b4775aUL,0x333c111eUL,0x46f6cb7bUL,0x1f4bfca8UL,0x61dad66dUL,0x4e583a2cUL,
  0xa5f497a5UL,0x8497eb84UL,0x99b0c799UL,0x8d8cf78dUL,0x0d17e50dUL,0xbddcb7bdUL,0xb1c8a7b1UL,0x54fc3954UL,0x50f0c050UL,0x03050403UL,0xa9e087a9UL,0x7d87ac7dUL,0x192bd519UL,0x62a67162UL,0xe6319ae6UL,0x9ab5c39aUL,0x45cf0545UL,0x9dbc3e9dUL,0x40c00940UL,0x8792ef87UL,0x153fc515UL,0xeb267febUL,0xc94007c9UL,0x0b1ded0bUL,0xec2f82ecUL,0x67a97d67UL,0xfd1cbefdUL,0xea258aeaUL,0xbfda46bfUL,0xf702a6f7UL,0x96a1d396UL,0x5bed2d5bUL,0xc25deac2UL,0x1c24d91cUL,0xaee97aaeUL,0x6abe986aUL,0x5aeed85aUL,0x41c3fc41UL,0x0206f102UL,0x4fd11d4fUL,0x5ce4d05cUL,0xf407a2f4UL,0x345cb934UL,0x0818e908UL,0x93aedf93UL,0x73954d73UL,0x53f5c453UL,0x3f41543fUL,0x0c14100cUL,0x52f63152UL,0x65af8c65UL,0x5ee2215eUL,0x28786028UL,0xa1f86ea1UL,0x0f11140fUL,0xb5c45eb5UL,0x091b1c09UL,0x365a4836UL,0x9bb6369bUL,0x3d47a53dUL,0x266a8126UL,0x69bb9c69UL,0xcd4cfecdUL,0x9fbacf9fUL,0x1b2d241bUL,0x9eb93a9eUL,0x749cb074UL,0x2e72682eUL,0x2d776c2dUL,0xb2cda3b2UL,0xee2973eeUL,0xfb16b6fbUL,0xf60153f6UL,0x4dd7ec4dUL,0x61a37561UL,0xce49faceUL,0x7b8da47bUL,0x3e42a13eUL,0x7193bc71UL,0x97a22697UL,0xf50457f5UL,0x68b86968UL,0x00000000UL,0x2c74992cUL,0x60a08060UL,0x1f21dd1fUL,0xc843f2c8UL,0xed2c77edUL,0xbed9b3beUL,0x46ca0146UL,0xd970ced9UL,0x4bdde44bUL,0xde7933deUL,0xd4672bd4UL,0xe8237be8UL,0x4ade114aUL,0x6bbd6d6bUL,0x2a7e912aUL,0xe5349ee5UL,0x163ac116UL,0xc55417c5UL,0xd7622fd7UL,0x55ffcc55UL,0x94a72294UL,0xcf4a0fcfUL,0x1030c910UL,0x060a0806UL,0x8198e781UL,0xf00b5bf0UL,0x44ccf044UL,0xbad54abaUL,0xe33e96e3UL,0xf30e5ff3UL,0xfe19bafeUL,0xc05b1bc0UL,0x8a850a8aUL,0xadec7eadUL,0xbcdf42bcUL,0x48d8e048UL,0x040cf904UL,0xdf7ac6dfUL,0xc158eec1UL,0x759f4575UL,0x63a58463UL,0x30504030UL,0x1a2ed11aUL,0x0e12e10eUL,0x6db7656dUL,0x4cd4194cUL,0x143c3014UL,0x355f4c35UL,0x2f719d2fUL,0xe13867e1UL,0xa2fd6aa2UL,0xcc4f0bccUL,0x394b5c39UL,0x57f93d57UL,0xf20daaf2UL,0x829de382UL,0x47c9f447UL,0xacef8bacUL,0xe7326fe7UL,0x2b7d642bUL,0x95a4d795UL,0xa0fb9ba0UL,0x98b33298UL,0xd16827d1UL,0x7f815d7fUL,0x66aa8866UL,0x7e82a87eUL,0xabe676abUL,0x839e1683UL,0xca4503caUL,0x297b9529UL,0xd36ed6d3UL,0x3c44503cUL,0x798b5579UL,0xe23d63e2UL,0x1d272c1dUL,0x769a4176UL,0x3b4dad3bUL,0x56fac856UL,0x4ed2e84eUL,0x1e22281eUL,0xdb763fdbUL,0x0a1e180aUL,0x6cb4906cUL,0xe4376be4UL,0x5de7255dUL,0x6eb2616eUL,0xef2a86efUL,0xa6f193a6UL,0xa8e372a8UL,0xa4f762a4UL,0x3759bd37UL,0x8b86ff8bUL,0x3256b132UL,0x43c50d43UL,0x59ebdc59UL,0xb7c2afb7UL,0x8c8f028cUL,0x64ac7964UL,0xd26d23d2UL,0xe03b92e0UL,0xb4c7abb4UL,0xfa1543faUL,0x0709fd07UL,0x256f8525UL,0xafea8fafUL,0x8e89f38eUL,0xe9208ee9UL,0x18282018UL,0xd564ded5UL,0x8883fb88UL,0x6fb1946fUL,0x7296b872UL,0x246c7024UL,0xf108aef1UL,0xc752e6c7UL,0x51f33551UL,0x23658d23UL,0x7c84597cUL,0x9cbfcb9cUL,0x21637c21UL,0xdd7c37ddUL,0xdc7fc2dcUL,0x86911a86UL,0x85941e85UL,0x90abdb90UL,0x42c6f842UL,0xc457e2c4UL,0xaae583aaUL,0xd8733bd8UL,0x050f0c05UL,0x0103f501UL,0x12363812UL,0xa3fe9fa3UL,0x5fe1d45fUL,0xf91047f9UL,0xd06bd2d0UL,0x91a82e91UL,0x58e82958UL,0x27697427UL,0xb9d04eb9UL,0x3848a938UL,0x1335cd13UL,0xb3ce56b3UL,0x33554433UL,0xbbd6bfbbUL,0x70904970UL,0x89800e89UL,0xa7f266a7UL,0xb6c15ab6UL,0x22667822UL,0x92ad2a92UL,0x20608920UL,0x49db1549UL,0xff1a4fffUL,0x7888a078UL,0x7a8e517aUL,0x8f8a068fUL,0xf813b2f8UL,0x809b1280UL,0x17393417UL,0xda75cadaUL,0x3153b531UL,0xc65113c6UL,0xb8d3bbb8UL,0xc35e1fc3UL,0xb0cb52b0UL,0x7799b477UL,0x11333c11UL,0xcb46f6cbUL,0xfc1f4bfcUL,0xd661dad6UL,0x3a4e583aUL,
  0xf4a5f497UL,0x978497ebUL,0xb099b0c7UL,0x8c8d8cf7UL,0x170d17e5UL,0xdcbddcb7UL,0xc8b1c8a7UL,0xfc54fc39UL,0xf050f0c0UL,0x05030504UL,0xe0a9e087UL,0x877d87acUL,0x2b192bd5UL,0xa662a671UL,0x31e6319aUL,0xb59ab5c3UL,0xcf45cf05UL,0xbc9dbc3eUL,0xc040c009UL,0x928792efUL,0x3f153fc5UL,0x26eb267fUL,0x40c94007UL,0x1d0b1dedUL,0x2fec2f82UL,0xa967a97dUL,0x1cfd1cbeUL,0x25ea258aUL,0xdabfda46UL,0x02f702a6UL,0xa196a1d3UL,0xed5bed2dUL,0x5dc25deaUL,0x241c24d9UL,0xe9aee97aUL,0xbe6abe98UL,0xee5aeed8UL,0xc341c3fcUL,0x060206f1UL,0xd14fd11dUL,0xe45ce4d0UL,0x07f407a2UL,0x5c345cb9UL,0x180818e9UL,0xae93aedfUL,0x9573954dUL,0xf553f5c4UL,0x413f4154UL,0x140c1410UL,0xf652f631UL,0xaf65af8cUL,0xe25ee221UL,0x78287860UL,0xf8a1f86eUL,0x110f1114UL,0xc4b5c45eUL,0x1b091b1cUL,0x5a365a48UL,0xb69bb636UL,0x473d47a5UL,0x6a266a81UL,0xbb69bb9cUL,0x4ccd4cfeUL,0xba9fbacfUL,0x2d1b2d24UL,0xb99eb93aUL,0x9c749cb0UL,0x722e7268UL,0x772d776cUL,0xcdb2cda3UL,0x29ee2973UL,0x16fb16b6UL,0x01f60153UL,0xd74dd7ecUL,0xa361a375UL,0x49ce49faUL,0x8d7b8da4UL,0x423e42a1UL,0x937193bcUL,0xa297a226UL,0x04f50457UL,0xb868b869UL,0x00000000UL,0x742c7499UL,0xa060a080UL,0x211f21ddUL,0x43c843f2UL,0x2ced2c77UL,0xd9bed9b3UL,0xca46ca01UL,0x70d970ceUL,0xdd4bdde4UL,0x79de7933UL,0x67d4672bUL,0x23e8237bUL,0xde4ade11UL,0xbd6bbd6dUL,0x7e2a7e91UL,0x34e5349eUL,0x3a163ac1UL,0x54c55417UL,0x62d7622fUL,0xff55ffccUL,0xa794a722UL,0x4acf4a0fUL,0x301030c9UL,0x0a060a08UL,0x988198e7UL,0x0bf00b5bUL,0xcc44ccf0UL,0xd5bad54aUL,0x3ee33e96UL,0x0ef30e5fUL,0x19fe19baUL,0x5bc05b1bUL,0x858a850aUL,0xecadec7eUL,0xdfbcdf42UL,0xd848d8e0UL,0x0c040cf9UL,0x7adf7ac6UL,0x58c158eeUL,0x9f759f45UL,0xa563a584UL,0x50305040UL,0x2e1a2ed1UL,0x120e12e1UL,0xb76db765UL,0xd44cd419UL,0x3c143c30UL,0x5f355f4cUL,0x712f719dUL,0x38e13867UL,0xfda2fd6aUL,0x4fcc4f0bUL,0x4b394b5cUL,0xf957f93dUL,0x0df20daaUL,0x9d829de3UL,0xc947c9f4UL,0xefacef8bUL,0x32e7326fUL,0x7d2b7d64UL,0xa495a4d7UL,0xfba0fb9bUL,0xb398b332UL,0x68d16827UL,0x817f815dUL,0xaa66aa88UL,0x827e82a8UL,0xe6abe676UL,0x9e839e16UL,0x45ca4503UL,0x7b297b95UL,0x6ed36ed6UL,0x443c4450UL,0x8b798b55UL,0x3de23d63UL,0x271d272cUL,0x9a769a41UL,0x4d3b4dadUL,0xfa56fac8UL,0xd24ed2e8UL,0x221e2228UL,0x76db763fUL,0x1e0a1e18UL,0xb46cb490UL,0x37e4376bUL,0xe75de725UL,0xb26eb261UL,0x2aef2a86UL,0xf1a6f193UL,0xe3a8e372UL,0xf7a4f762UL,0x593759bdUL,0x868b86ffUL,0x563256b1UL,0xc543c50dUL,0xeb59ebdcUL,0xc2b7c2afUL,0x8f8c8f02UL,0xac64ac79UL,0x6dd26d23UL,0x3be03b92UL,0xc7b4c7abUL,0x15fa1543UL,0x090709fdUL,0x6f256f85UL,0xeaafea8fUL,0x898e89f3UL,0x20e9208eUL,0x28182820UL,0x64d564deUL,0x838883fbUL,0xb16fb194UL,0x967296b8UL,0x6c246c70UL,0x08f108aeUL,0x52c752e6UL,0xf351f335UL,0x6523658dUL,0x847c8459UL,0xbf9cbfcbUL,0x6321637cUL,0x7cdd7c37UL,0x7fdc7fc2UL,0x9186911aUL,0x9485941eUL,0xab90abdbUL,0xc642c6f8UL,0x57c457e2UL,0xe5aae583UL,0x73d8733bUL,0x0f050f0cUL,0x030103f5UL,0x36123638UL,0xfea3fe9fUL,0xe15fe1d4UL,0x10f91047UL,0x6bd06bd2UL,0xa891a82eUL,0xe858e829UL,0x69276974UL,0xd0b9d04eUL,0x483848a9UL,0x351335cdUL,0xceb3ce56UL,0x55335544UL,0xd6bbd6bfUL,0x90709049UL,0x8089800eUL,0xf2a7f266UL,0xc1b6c15aUL,0x66226678UL,0xad92ad2aUL,0x60206089UL,0xdb49db15UL,0x1aff1a4fUL,0x887888a0UL,0x8e7a8e51UL,0x8a8f8a06UL,0x13f813b2UL,0x9b809b12UL,0x39173934UL,0x75da75caUL,0x533153b5UL,0x51c65113UL,0xd3b8d3bbUL,0x5ec35e1fUL,0xcbb0cb52UL,0x997799b4UL,0x3311333cUL,0x46cb46f6UL,0x1ffc1f4bUL,0x61d661daUL,0x4e3a4e58UL,
  0x32f4a5f4UL,0x6f978497UL,0x5eb099b0UL,0x7a8c8d8cUL,0xe8170d17UL,0x0adcbddcUL,0x16c8b1c8UL,0x6dfc54fcUL,0x90f050f0UL,0x07050305UL,0x2ee0a9e0UL,0xd1877d87UL,0xcc2b192bUL,0x13a662a6UL,0x7c31e631UL,0x59b59ab5UL,0x40cf45cfUL,0xa3bc9dbcUL,0x49c040c0UL,0x68928792UL,0xd03f153fUL,0x9426eb26UL,0xce40c940UL,0xe61d0b1dUL,0x6e2fec2fUL,0x1aa967a9UL,0x431cfd1cUL,0x6025ea25UL,0xf9dabfdaUL,0x5102f702UL,0x45a196a1UL,0x76ed5bedUL,0x285dc25dUL,0xc5241c24UL,0xd4e9aee9UL,0xf2be6abeUL,0x82ee5aeeUL,0xbdc341c3UL,0xf3060206UL,0x52d14fd1UL,0x8ce45ce4UL,0x5607f407UL,0x8d5c345cUL,0xe1180818UL,0x4cae93aeUL,0x3e957395UL,0x97f553f5UL,0x6b413f41UL,0x1c140c14UL,0x63f652f6UL,0xe9af65afUL,0x7fe25ee2UL,0x48782878UL,0xcff8a1f8UL,0x1b110f11UL,0xebc4b5c4UL,0x151b091bUL,0x7e5a365aUL,0xadb69bb6UL,0x98473d47UL,0xa76a266aUL,0xf5bb69bbUL,0x334ccd4cUL,0x50ba9fbaUL,0x3f2d1b2dUL,0xa4b99eb9UL,0xc49c749cUL,0x46722e72UL,0x41772d77UL,0x11cdb2cdUL,0x9d29ee29UL,0x4d16fb16UL,0xa501f601UL,0xa1d74dd7UL,0x14a361a3UL,0x3449ce49UL,0xdf8d7b8dUL,0x9f423e42UL,0xcd937193UL,0xb1a297a2UL,0xa204f504UL,0x01b868b8UL,0x00000000UL,0xb5742c74UL,0xe0a060a0UL,0xc2211f21UL,0x3a43c843UL,0x9a2ced2cUL,0x0dd9bed9UL,0x47ca46caUL,0x1770d970UL,0xafdd4bddUL,0xed79de79UL,0xff67d467UL,0x9323e823UL,0x5bde4adeUL,0x06bd6bbdUL,0xbb7e2a7eUL,0x7b34e534UL,0xd73a163aUL,0xd254c554UL,0xf862d762UL,0x99ff55ffUL,0xb6a794a7UL,0xc04acf4aUL,0xd9301030UL,0x0e0a060aUL,0x66988198UL,0xab0bf00bUL,0xb4cc44ccUL,0xf0d5bad5UL,0x753ee33eUL,0xac0ef30eUL,0x4419fe19UL,0xdb5bc05bUL,0x80858a85UL,0xd3ecadecUL,0xfedfbcdfUL,0xa8d848d8UL,0xfd0c040cUL,0x197adf7aUL,0x2f58c158UL,0x309f759fUL,0xe7a563a5UL,0x70503050UL,0xcb2e1a2eUL,0xef120e12UL,0x08b76db7UL,0x55d44cd4UL,0x243c143cUL,0x795f355fUL,0xb2712f71UL,0x8638e138UL,0xc8fda2fdUL,0xc74fcc4fUL,0x654b394bUL,0x6af957f9UL,0x580df20dUL,0x619d829dUL,0xb3c947c9UL,0x27efacefUL,0x8832e732UL,0x4f7d2b7dUL,0x42a495a4UL,0x3bfba0fbUL,0xaab398b3UL,0xf668d168UL,0x22817f81UL,0xeeaa66aaUL,0xd6827e82UL,0xdde6abe6UL,0x959e839eUL,0xc945ca45UL,0xbc7b297bUL,0x056ed36eUL,0x6c443c44UL,0x2c8b798bUL,0x813de23dUL,0x31271d27UL,0x379a769aUL,0x964d3b4dUL,0x9efa56faUL,0xa6d24ed2UL,0x36221e22UL,0xe476db76UL,0x121e0a1eUL,0xfcb46cb4UL,0x8f37e437UL,0x78e75de7UL,0x0fb26eb2UL,0x692aef2aUL,0x35f1a6f1UL,0xdae3a8e3UL,0xc6f7a4f7UL,0x8a593759UL,0x74868b86UL,0x83563256UL,0x4ec543c5UL,0x85eb59ebUL,0x18c2b7c2UL,0x8e8f8c8fUL,0x1dac64acUL,0xf16dd26dUL,0x723be03bUL,0x1fc7b4c7UL,0xb915fa15UL,0xfa090709UL,0xa06f256fUL,0x20eaafeaUL,0x7d898e89UL,0x6720e920UL,0x38281828UL,0x0b64d564UL,0x73838883UL,0xfbb16fb1UL,0xca967296UL,0x546c246cUL,0x5f08f108UL,0x2152c752UL,0x64f351f3UL,0xae652365UL,0x25847c84UL,0x57bf9cbfUL,0x5d632163UL,0xea7cdd7cUL,0x1e7fdc7fUL,0x9c918691UL,0x9b948594UL,0x4bab90abUL,0xbac642c6UL,0x2657c457UL,0x29e5aae5UL,0xe373d873UL,0x090f050fUL,0xf4030103UL,0x2a361236UL,0x3cfea3feUL,0x8be15fe1UL,0xbe10f910UL,0x026bd06bUL,0xbfa891a8UL,0x71e858e8UL,0x53692769UL,0xf7d0b9d0UL,0x91483848UL,0xde351335UL,0xe5ceb3ceUL,0x77553355UL,0x04d6bbd6UL,0x39907090UL,0x87808980UL,0xc1f2a7f2UL,0xecc1b6c1UL,0x5a662266UL,0xb8ad92adUL,0xa9602060UL,0x5cdb49dbUL,0xb01aff1aUL,0xd8887888UL,0x2b8e7a8eUL,0x898a8f8aUL,0x4a13f813UL,0x929b809bUL,0x23391739UL,0x1075da75UL,0x84533153UL,0xd551c651UL,0x03d3b8d3UL,0xdc5ec35eUL,0xe2cbb0cbUL,0xc3997799UL,0x2d331133UL,0x3d46cb46UL,0xb71ffc1fUL,0x0c61d661UL,0x624e3a4eUL};
#endif /* IS_BIG_ENDIAN */

#if (PLATFORM_BYTE_ORDER == IS_LITTLE_ENDIAN)
const u32 T[8*256]  __attribute__((aligned(64))) = {
  0xa5f432c6UL,0x84976ff8UL,0x99b05eeeUL,0x8d8c7af6UL,0x0d17e8ffUL,0xbddc0ad6UL,0xb1c816deUL,0x54fc6d91UL,0x50f09060UL,0x03050702UL,0xa9e02eceUL,0x7d87d156UL,0x192bcce7UL,0x62a613b5UL,0xe6317c4dUL,0x9ab559ecUL,0x45cf408fUL,0x9dbca31fUL,0x40c04989UL,0x879268faUL,0x153fd0efUL,0xeb2694b2UL,0xc940ce8eUL,0x0b1de6fbUL,0xec2f6e41UL,0x67a91ab3UL,0xfd1c435fUL,0xea256045UL,0xbfdaf923UL,0xf7025153UL,0x96a145e4UL,0x5bed769bUL,0xc25d2875UL,0x1c24c5e1UL,0xaee9d43dUL,0x6abef24cUL,0x5aee826cUL,0x41c3bd7eUL,0x0206f3f5UL,0x4fd15283UL,0x5ce48c68UL,0xf4075651UL,0x345c8dd1UL,0x0818e1f9UL,0x93ae4ce2UL,0x73953eabUL,0x53f59762UL,0x3f416b2aUL,0x0c141c08UL,0x52f66395UL,0x65afe946UL,0x5ee27f9dUL,0x28784830UL,0xa1f8cf37UL,0x0f111b0aUL,0xb5c4eb2fUL,0x091b150eUL,0x365a7e24UL,0x9bb6ad1bUL,0x3d4798dfUL,0x266aa7cdUL,0x69bbf54eUL,0xcd4c337fUL,0x9fba50eaUL,0x1b2d3f12UL,0x9eb9a41dUL,0x749cc458UL,0x2e724634UL,0x2d774136UL,0xb2cd11dcUL,0xee299db4UL,0xfb164d5bUL,0xf601a5a4UL,0x4dd7a176UL,0x61a314b7UL,0xce49347dUL,0x7b8ddf52UL,0x3e429fddUL,0x7193cd5eUL,0x97a2b113UL,0xf504a2a6UL,0x68b801b9UL,0x00000000UL,0x2c74b5c1UL,0x60a0e040UL,0x1f21c2e3UL,0xc8433a79UL,0xed2c9ab6UL,0xbed90dd4UL,0x46ca478dUL,0xd9701767UL,0x4bddaf72UL,0xde79ed94UL,0xd467ff98UL,0xe82393b0UL,0x4ade5b85UL,0x6bbd06bbUL,0x2a7ebbc5UL,0xe5347b4fUL,0x163ad7edUL,0xc554d286UL,0xd762f89aUL,0x55ff9966UL,0x94a7b611UL,0xcf4ac08aUL,0x1030d9e9UL,0x060a0e04UL,0x819866feUL,0xf00baba0UL,0x44ccb478UL,0xbad5f025UL,0xe33e754bUL,0xf30eaca2UL,0xfe19445dUL,0xc05bdb80UL,0x8a858005UL,0xadecd33fUL,0xbcdffe21UL,0x48d8a870UL,0x040cfdf1UL,0xdf7a1963UL,0xc1582f77UL,0x759f30afUL,0x63a5e742UL,0x30507020UL,0x1a2ecbe5UL,0x0e12effdUL,0x6db708bfUL,0x4cd45581UL,0x143c2418UL,0x355f7926UL,0x2f71b2c3UL,0xe13886beUL,0xa2fdc835UL,0xcc4fc788UL,0x394b652eUL,0x57f96a93UL,0xf20d5855UL,0x829d61fcUL,0x47c9b37aUL,0xacef27c8UL,0xe73288baUL,0x2b7d4f32UL,0x95a442e6UL,0xa0fb3bc0UL,0x98b3aa19UL,0xd168f69eUL,0x7f8122a3UL,0x66aaee44UL,0x7e82d654UL,0xabe6dd3bUL,0x839e950bUL,0xca45c98cUL,0x297bbcc7UL,0xd36e056bUL,0x3c446c28UL,0x798b2ca7UL,0xe23d81bcUL,0x1d273116UL,0x769a37adUL,0x3b4d96dbUL,0x56fa9e64UL,0x4ed2a674UL,0x1e223614UL,0xdb76e492UL,0x0a1e120cUL,0x6cb4fc48UL,0xe4378fb8UL,0x5de7789fUL,0x6eb20fbdUL,0xef2a6943UL,0xa6f135c4UL,0xa8e3da39UL,0xa4f7c631UL,0x37598ad3UL,0x8b8674f2UL,0x325683d5UL,0x43c54e8bUL,0x59eb856eUL,0xb7c218daUL,0x8c8f8e01UL,0x64ac1db1UL,0xd26df19cUL,0xe03b7249UL,0xb4c71fd8UL,0xfa15b9acUL,0x0709faf3UL,0x256fa0cfUL,0xafea20caUL,0x8e897df4UL,0xe9206747UL,0x18283810UL,0xd5640b6fUL,0x888373f0UL,0x6fb1fb4aUL,0x7296ca5cUL,0x246c5438UL,0xf1085f57UL,0xc7522173UL,0x51f36497UL,0x2365aecbUL,0x7c8425a1UL,0x9cbf57e8UL,0x21635d3eUL,0xdd7cea96UL,0xdc7f1e61UL,0x86919c0dUL,0x85949b0fUL,0x90ab4be0UL,0x42c6ba7cUL,0xc4572671UL,0xaae529ccUL,0xd873e390UL,0x050f0906UL,0x0103f4f7UL,0x12362a1cUL,0xa3fe3cc2UL,0x5fe18b6aUL,0xf910beaeUL,0xd06b0269UL,0x91a8bf17UL,0x58e87199UL,0x2769533aUL,0xb9d0f727UL,0x384891d9UL,0x1335deebUL,0xb3cee52bUL,0x33557722UL,0xbbd604d2UL,0x709039a9UL,0x89808707UL,0xa7f2c133UL,0xb6c1ec2dUL,0x22665a3cUL,0x92adb815UL,0x2060a9c9UL,0x49db5c87UL,0xff1ab0aaUL,0x7888d850UL,0x7a8e2ba5UL,0x8f8a8903UL,0xf8134a59UL,0x809b9209UL,0x1739231aUL,0xda751065UL,0x315384d7UL,0xc651d584UL,0xb8d303d0UL,0xc35edc82UL,0xb0cbe229UL,0x7799c35aUL,0x11332d1eUL,0xcb463d7bUL,0xfc1fb7a8UL,0xd6610c6dUL,0x3a4e622cUL,
  0xf432c6c6UL,0x976ff8f8UL,0xb05eeeeeUL,0x8c7af6f6UL,0x17e8ffffUL,0xdc0ad6d6UL,0xc816dedeUL,0xfc6d9191UL,0xf0906060UL,0x05070202UL,0xe02ececeUL,0x87d15656UL,0x2bcce7e7UL,0xa613b5b5UL,0x317c4d4dUL,0xb559ececUL,0xcf408f8fUL,0xbca31f1fUL,0xc0498989UL,0x9268fafaUL,0x3fd0efefUL,0x2694b2b2UL,0x40ce8e8eUL,0x1de6fbfbUL,0x2f6e4141UL,0xa91ab3b3UL,0x1c435f5fUL,0x25604545UL,0xdaf92323UL,0x02515353UL,0xa145e4e4UL,0xed769b9bUL,0x5d287575UL,0x24c5e1e1UL,0xe9d43d3dUL,0xbef24c4cUL,0xee826c6cUL,0xc3bd7e7eUL,0x06f3f5f5UL,0xd1528383UL,0xe48c6868UL,0x07565151UL,0x5c8dd1d1UL,0x18e1f9f9UL,0xae4ce2e2UL,0x953eababUL,0xf5976262UL,0x416b2a2aUL,0x141c0808UL,0xf6639595UL,0xafe94646UL,0xe27f9d9dUL,0x78483030UL,0xf8cf3737UL,0x111b0a0aUL,0xc4eb2f2fUL,0x1b150e0eUL,0x5a7e2424UL,0xb6ad1b1bUL,0x4798dfdfUL,0x6aa7cdcdUL,0xbbf54e4eUL,0x4c337f7fUL,0xba50eaeaUL,0x2d3f1212UL,0xb9a41d1dUL,0x9cc45858UL,0x72463434UL,0x77413636UL,0xcd11dcdcUL,0x299db4b4UL,0x164d5b5bUL,0x01a5a4a4UL,0xd7a17676UL,0xa314b7b7UL,0x49347d7dUL,0x8ddf5252UL,0x429fddddUL,0x93cd5e5eUL,0xa2b11313UL,0x04a2a6a6UL,0xb801b9b9UL,0x00000000UL,0x74b5c1c1UL,0xa0e04040UL,0x21c2e3e3UL,0x433a7979UL,0x2c9ab6b6UL,0xd90dd4d4UL,0xca478d8dUL,0x70176767UL,0xddaf7272UL,0x79ed9494UL,0x67ff9898UL,0x2393b0b0UL,0xde5b8585UL,0xbd06bbbbUL,0x7ebbc5c5UL,0x347b4f4fUL,0x3ad7ededUL,0x54d28686UL,0x62f89a9aUL,0xff996666UL,0xa7b61111UL,0x4ac08a8aUL,0x30d9e9e9UL,0x0a0e0404UL,0x9866fefeUL,0x0baba0a0UL,0xccb47878UL,0xd5f02525UL,0x3e754b4bUL,0x0eaca2a2UL,0x19445d5dUL,0x5bdb8080UL,0x85800505UL,0xecd33f3fUL,0xdffe2121UL,0xd8a87070UL,0x0cfdf1f1UL,0x7a196363UL,0x582f7777UL,0x9f30afafUL,0xa5e74242UL,0x50702020UL,0x2ecbe5e5UL,0x12effdfdUL,0xb708bfbfUL,0xd4558181UL,0x3c241818UL,0x5f792626UL,0x71b2c3c3UL,0x3886bebeUL,0xfdc83535UL,0x4fc78888UL,0x4b652e2eUL,0xf96a9393UL,0x0d585555UL,0x9d61fcfcUL,0xc9b37a7aUL,0xef27c8c8UL,0x3288babaUL,0x7d4f3232UL,0xa442e6e6UL,0xfb3bc0c0UL,0xb3aa1919UL,0x68f69e9eUL,0x8122a3a3UL,0xaaee4444UL,0x82d65454UL,0xe6dd3b3bUL,0x9e950b0bUL,0x45c98c8cUL,0x7bbcc7c7UL,0x6e056b6bUL,0x446c2828UL,0x8b2ca7a7UL,0x3d81bcbcUL,0x27311616UL,0x9a37adadUL,0x4d96dbdbUL,0xfa9e6464UL,0xd2a67474UL,0x22361414UL,0x76e49292UL,0x1e120c0cUL,0xb4fc4848UL,0x378fb8b8UL,0xe7789f9fUL,0xb20fbdbdUL,0x2a694343UL,0xf135c4c4UL,0xe3da3939UL,0xf7c63131UL,0x598ad3d3UL,0x8674f2f2UL,0x5683d5d5UL,0xc54e8b8bUL,0xeb856e6eUL,0xc218dadaUL,0x8f8e0101UL,0xac1db1b1UL,0x6df19c9cUL,0x3b724949UL,0xc71fd8d8UL,0x15b9acacUL,0x09faf3f3UL,0x6fa0cfcfUL,0xea20cacaUL,0x897df4f4UL,0x20674747UL,0x28381010UL,0x640b6f6fUL,0x8373f0f0UL,0xb1fb4a4aUL,0x96ca5c5cUL,0x6c543838UL,0x085f5757UL,0x52217373UL,0xf3649797UL,0x65aecbcbUL,0x8425a1a1UL,0xbf57e8e8UL,0x635d3e3eUL,0x7cea9696UL,0x7f1e6161UL,0x919c0d0dUL,0x949b0f0fUL,0xab4be0e0UL,0xc6ba7c7cUL,0x57267171UL,0xe529ccccUL,0x73e39090UL,0x0f090606UL,0x03f4f7f7UL,0x362a1c1cUL,0xfe3cc2c2UL,0xe18b6a6aUL,0x10beaeaeUL,0x6b026969UL,0xa8bf1717UL,0xe8719999UL,0x69533a3aUL,0xd0f72727UL,0x4891d9d9UL,0x35deebebUL,0xcee52b2bUL,0x55772222UL,0xd604d2d2UL,0x9039a9a9UL,0x80870707UL,0xf2c13333UL,0xc1ec2d2dUL,0x665a3c3cUL,0xadb81515UL,0x60a9c9c9UL,0xdb5c8787UL,0x1ab0aaaaUL,0x88d85050UL,0x8e2ba5a5UL,0x8a890303UL,0x134a5959UL,0x9b920909UL,0x39231a1aUL,0x75106565UL,0x5384d7d7UL,0x51d58484UL,0xd303d0d0UL,0x5edc8282UL,0xcbe22929UL,0x99c35a5aUL,0x332d1e1eUL,0x463d7b7bUL,0x1fb7a8a8UL,0x610c6d6dUL,0x4e622c2cUL,
  0x32c6c6a5UL,0x6ff8f884UL,0x5eeeee99UL,0x7af6f68dUL,0xe8ffff0dUL,0x0ad6d6bdUL,0x16dedeb1UL,0x6d919154UL,0x90606050UL,0x07020203UL,0x2ececea9UL,0xd156567dUL,0xcce7e719UL,0x13b5b562UL,0x7c4d4de6UL,0x59ecec9aUL,0x408f8f45UL,0xa31f1f9dUL,0x49898940UL,0x68fafa87UL,0xd0efef15UL,0x94b2b2ebUL,0xce8e8ec9UL,0xe6fbfb0bUL,0x6e4141ecUL,0x1ab3b367UL,0x435f5ffdUL,0x604545eaUL,0xf92323bfUL,0x515353f7UL,0x45e4e496UL,0x769b9b5bUL,0x287575c2UL,0xc5e1e11cUL,0xd43d3daeUL,0xf24c4c6aUL,0x826c6c5aUL,0xbd7e7e41UL,0xf3f5f502UL,0x5283834fUL,0x8c68685cUL,0x565151f4UL,0x8dd1d134UL,0xe1f9f908UL,0x4ce2e293UL,0x3eabab73UL,0x97626253UL,0x6b2a2a3fUL,0x1c08080cUL,0x63959552UL,0xe9464665UL,0x7f9d9d5eUL,0x48303028UL,0xcf3737a1UL,0x1b0a0a0fUL,0xeb2f2fb5UL,0x150e0e09UL,0x7e242436UL,0xad1b1b9bUL,0x98dfdf3dUL,0xa7cdcd26UL,0xf54e4e69UL,0x337f7fcdUL,0x50eaea9fUL,0x3f12121bUL,0xa41d1d9eUL,0xc4585874UL,0x4634342eUL,0x4136362dUL,0x11dcdcb2UL,0x9db4b4eeUL,0x4d5b5bfbUL,0xa5a4a4f6UL,0xa176764dUL,0x14b7b761UL,0x347d7dceUL,0xdf52527bUL,0x9fdddd3eUL,0xcd5e5e71UL,0xb1131397UL,0xa2a6a6f5UL,0x01b9b968UL,0x00000000UL,0xb5c1c12cUL,0xe0404060UL,0xc2e3e31fUL,0x3a7979c8UL,0x9ab6b6edUL,0x0dd4d4beUL,0x478d8d46UL,0x176767d9UL,0xaf72724bUL,0xed9494deUL,0xff9898d4UL,0x93b0b0e8UL,0x5b85854aUL,0x06bbbb6bUL,0xbbc5c52aUL,0x7b4f4fe5UL,0xd7eded16UL,0xd28686c5UL,0xf89a9ad7UL,0x99666655UL,0xb6111194UL,0xc08a8acfUL,0xd9e9e910UL,0x0e040406UL,0x66fefe81UL,0xaba0a0f0UL,0xb4787844UL,0xf02525baUL,0x754b4be3UL,0xaca2a2f3UL,0x445d5dfeUL,0xdb8080c0UL,0x8005058aUL,0xd33f3fadUL,0xfe2121bcUL,0xa8707048UL,0xfdf1f104UL,0x196363dfUL,0x2f7777c1UL,0x30afaf75UL,0xe7424263UL,0x70202030UL,0xcbe5e51aUL,0xeffdfd0eUL,0x08bfbf6dUL,0x5581814cUL,0x24181814UL,0x79262635UL,0xb2c3c32fUL,0x86bebee1UL,0xc83535a2UL,0xc78888ccUL,0x652e2e39UL,0x6a939357UL,0x585555f2UL,0x61fcfc82UL,0xb37a7a47UL,0x27c8c8acUL,0x88babae7UL,0x4f32322bUL,0x42e6e695UL,0x3bc0c0a0UL,0xaa191998UL,0xf69e9ed1UL,0x22a3a37fUL,0xee444466UL,0xd654547eUL,0xdd3b3babUL,0x950b0b83UL,0xc98c8ccaUL,0xbcc7c729UL,0x056b6bd3UL,0x6c28283cUL,0x2ca7a779UL,0x81bcbce2UL,0x3116161dUL,0x37adad76UL,0x96dbdb3bUL,0x9e646456UL,0xa674744eUL,0x3614141eUL,0xe49292dbUL,0x120c0c0aUL,0xfc48486cUL,0x8fb8b8e4UL,0x789f9f5dUL,0x0fbdbd6eUL,0x694343efUL,0x35c4c4a6UL,0xda3939a8UL,0xc63131a4UL,0x8ad3d337UL,0x74f2f28bUL,0x83d5d532UL,0x4e8b8b43UL,0x856e6e59UL,0x18dadab7UL,0x8e01018cUL,0x1db1b164UL,0xf19c9cd2UL,0x724949e0UL,0x1fd8d8b4UL,0xb9acacfaUL,0xfaf3f307UL,0xa0cfcf25UL,0x20cacaafUL,0x7df4f48eUL,0x674747e9UL,0x38101018UL,0x0b6f6fd5UL,0x73f0f088UL,0xfb4a4a6fUL,0xca5c5c72UL,0x54383824UL,0x5f5757f1UL,0x217373c7UL,0x64979751UL,0xaecbcb23UL,0x25a1a17cUL,0x57e8e89cUL,0x5d3e3e21UL,0xea9696ddUL,0x1e6161dcUL,0x9c0d0d86UL,0x9b0f0f85UL,0x4be0e090UL,0xba7c7c42UL,0x267171c4UL,0x29ccccaaUL,0xe39090d8UL,0x09060605UL,0xf4f7f701UL,0x2a1c1c12UL,0x3cc2c2a3UL,0x8b6a6a5fUL,0xbeaeaef9UL,0x026969d0UL,0xbf171791UL,0x71999958UL,0x533a3a27UL,0xf72727b9UL,0x91d9d938UL,0xdeebeb13UL,0xe52b2bb3UL,0x77222233UL,0x04d2d2bbUL,0x39a9a970UL,0x87070789UL,0xc13333a7UL,0xec2d2db6UL,0x5a3c3c22UL,0xb8151592UL,0xa9c9c920UL,0x5c878749UL,0xb0aaaaffUL,0xd8505078UL,0x2ba5a57aUL,0x8903038fUL,0x4a5959f8UL,0x92090980UL,0x231a1a17UL,0x106565daUL,0x84d7d731UL,0xd58484c6UL,0x03d0d0b8UL,0xdc8282c3UL,0xe22929b0UL,0xc35a5a77UL,0x2d1e1e11UL,0x3d7b7bcbUL,0xb7a8a8fcUL,0x0c6d6dd6UL,0x622c2c3aUL,
  0xc6c6a597UL,0xf8f884ebUL,0xeeee99c7UL,0xf6f68df7UL,0xffff0de5UL,0xd6d6bdb7UL,0xdedeb1a7UL,0x91915439UL,0x606050c0UL,0x02020304UL,0xcecea987UL,0x56567dacUL,0xe7e719d5UL,0xb5b56271UL,0x4d4de69aUL,0xecec9ac3UL,0x8f8f4505UL,0x1f1f9d3eUL,0x89894009UL,0xfafa87efUL,0xefef15c5UL,0xb2b2eb7fUL,0x8e8ec907UL,0xfbfb0bedUL,0x4141ec82UL,0xb3b3677dUL,0x5f5ffdbeUL,0x4545ea8aUL,0x2323bf46UL,0x5353f7a6UL,0xe4e496d3UL,0x9b9b5b2dUL,0x7575c2eaUL,0xe1e11cd9UL,0x3d3dae7aUL,0x4c4c6a98UL,0x6c6c5ad8UL,0x7e7e41fcUL,0xf5f502f1UL,0x83834f1dUL,0x68685cd0UL,0x5151f4a2UL,0xd1d134b9UL,0xf9f908e9UL,0xe2e293dfUL,0xabab734dUL,0x626253c4UL,0x2a2a3f54UL,0x08080c10UL,0x95955231UL,0x4646658cUL,0x9d9d5e21UL,0x30302860UL,0x3737a16eUL,0x0a0a0f14UL,0x2f2fb55eUL,0x0e0e091cUL,0x24243648UL,0x1b1b9b36UL,0xdfdf3da5UL,0xcdcd2681UL,0x4e4e699cUL,0x7f7fcdfeUL,0xeaea9fcfUL,0x12121b24UL,0x1d1d9e3aUL,0x585874b0UL,0x34342e68UL,0x36362d6cUL,0xdcdcb2a3UL,0xb4b4ee73UL,0x5b5bfbb6UL,0xa4a4f653UL,0x76764decUL,0xb7b76175UL,0x7d7dcefaUL,0x52527ba4UL,0xdddd3ea1UL,0x5e5e71bcUL,0x13139726UL,0xa6a6f557UL,0xb9b96869UL,0x00000000UL,0xc1c12c99UL,0x40406080UL,0xe3e31fddUL,0x7979c8f2UL,0xb6b6ed77UL,0xd4d4beb3UL,0x8d8d4601UL,0x6767d9ceUL,0x72724be4UL,0x9494de33UL,0x9898d42bUL,0xb0b0e87bUL,0x85854a11UL,0xbbbb6b6dUL,0xc5c52a91UL,0x4f4fe59eUL,0xeded16c1UL,0x8686c517UL,0x9a9ad72fUL,0x666655ccUL,0x11119422UL,0x8a8acf0fUL,0xe9e910c9UL,0x04040608UL,0xfefe81e7UL,0xa0a0f05bUL,0x787844f0UL,0x2525ba4aUL,0x4b4be396UL,0xa2a2f35fUL,0x5d5dfebaUL,0x8080c01bUL,0x05058a0aUL,0x3f3fad7eUL,0x2121bc42UL,0x707048e0UL,0xf1f104f9UL,0x6363dfc6UL,0x7777c1eeUL,0xafaf7545UL,0x42426384UL,0x20203040UL,0xe5e51ad1UL,0xfdfd0ee1UL,0xbfbf6d65UL,0x81814c19UL,0x18181430UL,0x2626354cUL,0xc3c32f9dUL,0xbebee167UL,0x3535a26aUL,0x8888cc0bUL,0x2e2e395cUL,0x9393573dUL,0x5555f2aaUL,0xfcfc82e3UL,0x7a7a47f4UL,0xc8c8ac8bUL,0xbabae76fUL,0x32322b64UL,0xe6e695d7UL,0xc0c0a09bUL,0x19199832UL,0x9e9ed127UL,0xa3a37f5dUL,0x44446688UL,0x54547ea8UL,0x3b3bab76UL,0x0b0b8316UL,0x8c8cca03UL,0xc7c72995UL,0x6b6bd3d6UL,0x28283c50UL,0xa7a77955UL,0xbcbce263UL,0x16161d2cUL,0xadad7641UL,0xdbdb3badUL,0x646456c8UL,0x74744ee8UL,0x14141e28UL,0x9292db3fUL,0x0c0c0a18UL,0x48486c90UL,0xb8b8e46bUL,0x9f9f5d25UL,0xbdbd6e61UL,0x4343ef86UL,0xc4c4a693UL,0x3939a872UL,0x3131a462UL,0xd3d337bdUL,0xf2f28bffUL,0xd5d532b1UL,0x8b8b430dUL,0x6e6e59dcUL,0xdadab7afUL,0x01018c02UL,0xb1b16479UL,0x9c9cd223UL,0x4949e092UL,0xd8d8b4abUL,0xacacfa43UL,0xf3f307fdUL,0xcfcf2585UL,0xcacaaf8fUL,0xf4f48ef3UL,0x4747e98eUL,0x10101820UL,0x6f6fd5deUL,0xf0f088fbUL,0x4a4a6f94UL,0x5c5c72b8UL,0x38382470UL,0x5757f1aeUL,0x7373c7e6UL,0x97975135UL,0xcbcb238dUL,0xa1a17c59UL,0xe8e89ccbUL,0x3e3e217cUL,0x9696dd37UL,0x6161dcc2UL,0x0d0d861aUL,0x0f0f851eUL,0xe0e090dbUL,0x7c7c42f8UL,0x7171c4e2UL,0xccccaa83UL,0x9090d83bUL,0x0606050cUL,0xf7f701f5UL,0x1c1c1238UL,0xc2c2a39fUL,0x6a6a5fd4UL,0xaeaef947UL,0x6969d0d2UL,0x1717912eUL,0x99995829UL,0x3a3a2774UL,0x2727b94eUL,0xd9d938a9UL,0xebeb13cdUL,0x2b2bb356UL,0x22223344UL,0xd2d2bbbfUL,0xa9a97049UL,0x0707890eUL,0x3333a766UL,0x2d2db65aUL,0x3c3c2278UL,0x1515922aUL,0xc9c92089UL,0x87874915UL,0xaaaaff4fUL,0x505078a0UL,0xa5a57a51UL,0x03038f06UL,0x5959f8b2UL,0x09098012UL,0x1a1a1734UL,0x6565dacaUL,0xd7d731b5UL,0x8484c613UL,0xd0d0b8bbUL,0x8282c31fUL,0x2929b052UL,0x5a5a77b4UL,0x1e1e113cUL,0x7b7bcbf6UL,0xa8a8fc4bUL,0x6d6dd6daUL,0x2c2c3a58UL,
  0xc6a597f4UL,0xf884eb97UL,0xee99c7b0UL,0xf68df78cUL,0xff0de517UL,0xd6bdb7dcUL,0xdeb1a7c8UL,0x915439fcUL,0x6050c0f0UL,0x02030405UL,0xcea987e0UL,0x567dac87UL,0xe719d52bUL,0xb56271a6UL,0x4de69a31UL,0xec9ac3b5UL,0x8f4505cfUL,0x1f9d3ebcUL,0x894009c0UL,0xfa87ef92UL,0xef15c53fUL,0xb2eb7f26UL,0x8ec90740UL,0xfb0bed1dUL,0x41ec822fUL,0xb3677da9UL,0x5ffdbe1cUL,0x45ea8a25UL,0x23bf46daUL,0x53f7a602UL,0xe496d3a1UL,0x9b5b2dedUL,0x75c2ea5dUL,0xe11cd924UL,0x3dae7ae9UL,0x4c6a98beUL,0x6c5ad8eeUL,0x7e41fcc3UL,0xf502f106UL,0x834f1dd1UL,0x685cd0e4UL,0x51f4a207UL,0xd134b95cUL,0xf908e918UL,0xe293dfaeUL,0xab734d95UL,0x6253c4f5UL,0x2a3f5441UL,0x080c1014UL,0x955231f6UL,0x46658cafUL,0x9d5e21e2UL,0x30286078UL,0x37a16ef8UL,0x0a0f1411UL,0x2fb55ec4UL,0x0e091c1bUL,0x2436485aUL,0x1b9b36b6UL,0xdf3da547UL,0xcd26816aUL,0x4e699cbbUL,0x7fcdfe4cUL,0xea9fcfbaUL,0x121b242dUL,0x1d9e3ab9UL,0x5874b09cUL,0x342e6872UL,0x362d6c77UL,0xdcb2a3cdUL,0xb4ee7329UL,0x5bfbb616UL,0xa4f65301UL,0x764decd7UL,0xb76175a3UL,0x7dcefa49UL,0x527ba48dUL,0xdd3ea142UL,0x5e71bc93UL,0x139726a2UL,0xa6f55704UL,0xb96869b8UL,0x00000000UL,0xc12c9974UL,0x406080a0UL,0xe31fdd21UL,0x79c8f243UL,0xb6ed772cUL,0xd4beb3d9UL,0x8d4601caUL,0x67d9ce70UL,0x724be4ddUL,0x94de3379UL,0x98d42b67UL,0xb0e87b23UL,0x854a11deUL,0xbb6b6dbdUL,0xc52a917eUL,0x4fe59e34UL,0xed16c13aUL,0x86c51754UL,0x9ad72f62UL,0x6655ccffUL,0x119422a7UL,0x8acf0f4aUL,0xe910c930UL,0x0406080aUL,0xfe81e798UL,0xa0f05b0bUL,0x7844f0ccUL,0x25ba4ad5UL,0x4be3963eUL,0xa2f35f0eUL,0x5dfeba19UL,0x80c01b5bUL,0x058a0a85UL,0x3fad7eecUL,0x21bc42dfUL,0x7048e0d8UL,0xf104f90cUL,0x63dfc67aUL,0x77c1ee58UL,0xaf75459fUL,0x426384a5UL,0x20304050UL,0xe51ad12eUL,0xfd0ee112UL,0xbf6d65b7UL,0x814c19d4UL,0x1814303cUL,0x26354c5fUL,0xc32f9d71UL,0xbee16738UL,0x35a26afdUL,0x88cc0b4fUL,0x2e395c4bUL,0x93573df9UL,0x55f2aa0dUL,0xfc82e39dUL,0x7a47f4c9UL,0xc8ac8befUL,0xbae76f32UL,0x322b647dUL,0xe695d7a4UL,0xc0a09bfbUL,0x199832b3UL,0x9ed12768UL,0xa37f5d81UL,0x446688aaUL,0x547ea882UL,0x3bab76e6UL,0x0b83169eUL,0x8cca0345UL,0xc729957bUL,0x6bd3d66eUL,0x283c5044UL,0xa779558bUL,0xbce2633dUL,0x161d2c27UL,0xad76419aUL,0xdb3bad4dUL,0x6456c8faUL,0x744ee8d2UL,0x141e2822UL,0x92db3f76UL,0x0c0a181eUL,0x486c90b4UL,0xb8e46b37UL,0x9f5d25e7UL,0xbd6e61b2UL,0x43ef862aUL,0xc4a693f1UL,0x39a872e3UL,0x31a462f7UL,0xd337bd59UL,0xf28bff86UL,0xd532b156UL,0x8b430dc5UL,0x6e59dcebUL,0xdab7afc2UL,0x018c028fUL,0xb16479acUL,0x9cd2236dUL,0x49e0923bUL,0xd8b4abc7UL,0xacfa4315UL,0xf307fd09UL,0xcf25856fUL,0xcaaf8feaUL,0xf48ef389UL,0x47e98e20UL,0x10182028UL,0x6fd5de64UL,0xf088fb83UL,0x4a6f94b1UL,0x5c72b896UL,0x3824706cUL,0x57f1ae08UL,0x73c7e652UL,0x975135f3UL,0xcb238d65UL,0xa17c5984UL,0xe89ccbbfUL,0x3e217c63UL,0x96dd377cUL,0x61dcc27fUL,0x0d861a91UL,0x0f851e94UL,0xe090dbabUL,0x7c42f8c6UL,0x71c4e257UL,0xccaa83e5UL,0x90d83b73UL,0x06050c0fUL,0xf701f503UL,0x1c123836UL,0xc2a39ffeUL,0x6a5fd4e1UL,0xaef94710UL,0x69d0d26bUL,0x17912ea8UL,0x995829e8UL,0x3a277469UL,0x27b94ed0UL,0xd938a948UL,0xeb13cd35UL,0x2bb356ceUL,0x22334455UL,0xd2bbbfd6UL,0xa9704990UL,0x07890e80UL,0x33a766f2UL,0x2db65ac1UL,0x3c227866UL,0x15922aadUL,0xc9208960UL,0x874915dbUL,0xaaff4f1aUL,0x5078a088UL,0xa57a518eUL,0x038f068aUL,0x59f8b213UL,0x0980129bUL,0x1a173439UL,0x65daca75UL,0xd731b553UL,0x84c61351UL,0xd0b8bbd3UL,0x82c31f5eUL,0x29b052cbUL,0x5a77b499UL,0x1e113c33UL,0x7bcbf646UL,0xa8fc4b1fUL,0x6dd6da61UL,0x2c3a584eUL,
  0xa597f4a5UL,0x84eb9784UL,0x99c7b099UL,0x8df78c8dUL,0x0de5170dUL,0xbdb7dcbdUL,0xb1a7c8b1UL,0x5439fc54UL,0x50c0f050UL,0x03040503UL,0xa987e0a9UL,0x7dac877dUL,0x19d52b19UL,0x6271a662UL,0xe69a31e6UL,0x9ac3b59aUL,0x4505cf45UL,0x9d3ebc9dUL,0x4009c040UL,0x87ef9287UL,0x15c53f15UL,0xeb7f26ebUL,0xc90740c9UL,0x0bed1d0bUL,0xec822fecUL,0x677da967UL,0xfdbe1cfdUL,0xea8a25eaUL,0xbf46dabfUL,0xf7a602f7UL,0x96d3a196UL,0x5b2ded5bUL,0xc2ea5dc2UL,0x1cd9241cUL,0xae7ae9aeUL,0x6a98be6aUL,0x5ad8ee5aUL,0x41fcc341UL,0x02f10602UL,0x4f1dd14fUL,0x5cd0e45cUL,0xf4a207f4UL,0x34b95c34UL,0x08e91808UL,0x93dfae93UL,0x734d9573UL,0x53c4f553UL,0x3f54413fUL,0x0c10140cUL,0x5231f652UL,0x658caf65UL,0x5e21e25eUL,0x28607828UL,0xa16ef8a1UL,0x0f14110fUL,0xb55ec4b5UL,0x091c1b09UL,0x36485a36UL,0x9b36b69bUL,0x3da5473dUL,0x26816a26UL,0x699cbb69UL,0xcdfe4ccdUL,0x9fcfba9fUL,0x1b242d1bUL,0x9e3ab99eUL,0x74b09c74UL,0x2e68722eUL,0x2d6c772dUL,0xb2a3cdb2UL,0xee7329eeUL,0xfbb616fbUL,0xf65301f6UL,0x4decd74dUL,0x6175a361UL,0xcefa49ceUL,0x7ba48d7bUL,0x3ea1423eUL,0x71bc9371UL,0x9726a297UL,0xf55704f5UL,0x6869b868UL,0x00000000UL,0x2c99742cUL,0x6080a060UL,0x1fdd211fUL,0xc8f243c8UL,0xed772cedUL,0xbeb3d9beUL,0x4601ca46UL,0xd9ce70d9UL,0x4be4dd4bUL,0xde3379deUL,0xd42b67d4UL,0xe87b23e8UL,0x4a11de4aUL,0x6b6dbd6bUL,0x2a917e2aUL,0xe59e34e5UL,0x16c13a16UL,0xc51754c5UL,0xd72f62d7UL,0x55ccff55UL,0x9422a794UL,0xcf0f4acfUL,0x10c93010UL,0x06080a06UL,0x81e79881UL,0xf05b0bf0UL,0x44f0cc44UL,0xba4ad5baUL,0xe3963ee3UL,0xf35f0ef3UL,0xfeba19feUL,0xc01b5bc0UL,0x8a0a858aUL,0xad7eecadUL,0xbc42dfbcUL,0x48e0d848UL,0x04f90c04UL,0xdfc67adfUL,0xc1ee58c1UL,0x75459f75UL,0x6384a563UL,0x30405030UL,0x1ad12e1aUL,0x0ee1120eUL,0x6d65b76dUL,0x4c19d44cUL,0x14303c14UL,0x354c5f35UL,0x2f9d712fUL,0xe16738e1UL,0xa26afda2UL,0xcc0b4fccUL,0x395c4b39UL,0x573df957UL,0xf2aa0df2UL,0x82e39d82UL,0x47f4c947UL,0xac8befacUL,0xe76f32e7UL,0x2b647d2bUL,0x95d7a495UL,0xa09bfba0UL,0x9832b398UL,0xd12768d1UL,0x7f5d817fUL,0x6688aa66UL,0x7ea8827eUL,0xab76e6abUL,0x83169e83UL,0xca0345caUL,0x29957b29UL,0xd3d66ed3UL,0x3c50443cUL,0x79558b79UL,0xe2633de2UL,0x1d2c271dUL,0x76419a76UL,0x3bad4d3bUL,0x56c8fa56UL,0x4ee8d24eUL,0x1e28221eUL,0xdb3f76dbUL,0x0a181e0aUL,0x6c90b46cUL,0xe46b37e4UL,0x5d25e75dUL,0x6e61b26eUL,0xef862aefUL,0xa693f1a6UL,0xa872e3a8UL,0xa462f7a4UL,0x37bd5937UL,0x8bff868bUL,0x32b15632UL,0x430dc543UL,0x59dceb59UL,0xb7afc2b7UL,0x8c028f8cUL,0x6479ac64UL,0xd2236dd2UL,0xe0923be0UL,0xb4abc7b4UL,0xfa4315faUL,0x07fd0907UL,0x25856f25UL,0xaf8feaafUL,0x8ef3898eUL,0xe98e20e9UL,0x18202818UL,0xd5de64d5UL,0x88fb8388UL,0x6f94b16fUL,0x72b89672UL,0x24706c24UL,0xf1ae08f1UL,0xc7e652c7UL,0x5135f351UL,0x238d6523UL,0x7c59847cUL,0x9ccbbf9cUL,0x217c6321UL,0xdd377cddUL,0xdcc27fdcUL,0x861a9186UL,0x851e9485UL,0x90dbab90UL,0x42f8c642UL,0xc4e257c4UL,0xaa83e5aaUL,0xd83b73d8UL,0x050c0f05UL,0x01f50301UL,0x12383612UL,0xa39ffea3UL,0x5fd4e15fUL,0xf94710f9UL,0xd0d26bd0UL,0x912ea891UL,0x5829e858UL,0x27746927UL,0xb94ed0b9UL,0x38a94838UL,0x13cd3513UL,0xb356ceb3UL,0x33445533UL,0xbbbfd6bbUL,0x70499070UL,0x890e8089UL,0xa766f2a7UL,0xb65ac1b6UL,0x22786622UL,0x922aad92UL,0x20896020UL,0x4915db49UL,0xff4f1affUL,0x78a08878UL,0x7a518e7aUL,0x8f068a8fUL,0xf8b213f8UL,0x80129b80UL,0x17343917UL,0xdaca75daUL,0x31b55331UL,0xc61351c6UL,0xb8bbd3b8UL,0xc31f5ec3UL,0xb052cbb0UL,0x77b49977UL,0x113c3311UL,0xcbf646cbUL,0xfc4b1ffcUL,0xd6da61d6UL,0x3a584e3aUL,
  0x97f4a5f4UL,0xeb978497UL,0xc7b099b0UL,0xf78c8d8cUL,0xe5170d17UL,0xb7dcbddcUL,0xa7c8b1c8UL,0x39fc54fcUL,0xc0f050f0UL,0x04050305UL,0x87e0a9e0UL,0xac877d87UL,0xd52b192bUL,0x71a662a6UL,0x9a31e631UL,0xc3b59ab5UL,0x05cf45cfUL,0x3ebc9dbcUL,0x09c040c0UL,0xef928792UL,0xc53f153fUL,0x7f26eb26UL,0x0740c940UL,0xed1d0b1dUL,0x822fec2fUL,0x7da967a9UL,0xbe1cfd1cUL,0x8a25ea25UL,0x46dabfdaUL,0xa602f702UL,0xd3a196a1UL,0x2ded5bedUL,0xea5dc25dUL,0xd9241c24UL,0x7ae9aee9UL,0x98be6abeUL,0xd8ee5aeeUL,0xfcc341c3UL,0xf1060206UL,0x1dd14fd1UL,0xd0e45ce4UL,0xa207f407UL,0xb95c345cUL,0xe9180818UL,0xdfae93aeUL,0x4d957395UL,0xc4f553f5UL,0x54413f41UL,0x10140c14UL,0x31f652f6UL,0x8caf65afUL,0x21e25ee2UL,0x60782878UL,0x6ef8a1f8UL,0x14110f11UL,0x5ec4b5c4UL,0x1c1b091bUL,0x485a365aUL,0x36b69bb6UL,0xa5473d47UL,0x816a266aUL,0x9cbb69bbUL,0xfe4ccd4cUL,0xcfba9fbaUL,0x242d1b2dUL,0x3ab99eb9UL,0xb09c749cUL,0x68722e72UL,0x6c772d77UL,0xa3cdb2cdUL,0x7329ee29UL,0xb616fb16UL,0x5301f601UL,0xecd74dd7UL,0x75a361a3UL,0xfa49ce49UL,0xa48d7b8dUL,0xa1423e42UL,0xbc937193UL,0x26a297a2UL,0x5704f504UL,0x69b868b8UL,0x00000000UL,0x99742c74UL,0x80a060a0UL,0xdd211f21UL,0xf243c843UL,0x772ced2cUL,0xb3d9bed9UL,0x01ca46caUL,0xce70d970UL,0xe4dd4bddUL,0x3379de79UL,0x2b67d467UL,0x7b23e823UL,0x11de4adeUL,0x6dbd6bbdUL,0x917e2a7eUL,0x9e34e534UL,0xc13a163aUL,0x1754c554UL,0x2f62d762UL,0xccff55ffUL,0x22a794a7UL,0x0f4acf4aUL,0xc9301030UL,0x080a060aUL,0xe7988198UL,0x5b0bf00bUL,0xf0cc44ccUL,0x4ad5bad5UL,0x963ee33eUL,0x5f0ef30eUL,0xba19fe19UL,0x1b5bc05bUL,0x0a858a85UL,0x7eecadecUL,0x42dfbcdfUL,0xe0d848d8UL,0xf90c040cUL,0xc67adf7aUL,0xee58c158UL,0x459f759fUL,0x84a563a5UL,0x40503050UL,0xd12e1a2eUL,0xe1120e12UL,0x65b76db7UL,0x19d44cd4UL,0x303c143cUL,0x4c5f355fUL,0x9d712f71UL,0x6738e138UL,0x6afda2fdUL,0x0b4fcc4fUL,0x5c4b394bUL,0x3df957f9UL,0xaa0df20dUL,0xe39d829dUL,0xf4c947c9UL,0x8befacefUL,0x6f32e732UL,0x647d2b7dUL,0xd7a495a4UL,0x9bfba0fbUL,0x32b398b3UL,0x2768d168UL,0x5d817f81UL,0x88aa66aaUL,0xa8827e82UL,0x76e6abe6UL,0x169e839eUL,0x0345ca45UL,0x957b297bUL,0xd66ed36eUL,0x50443c44UL,0x558b798bUL,0x633de23dUL,0x2c271d27UL,0x419a769aUL,0xad4d3b4dUL,0xc8fa56faUL,0xe8d24ed2UL,0x28221e22UL,0x3f76db76UL,0x181e0a1eUL,0x90b46cb4UL,0x6b37e437UL,0x25e75de7UL,0x61b26eb2UL,0x862aef2aUL,0x93f1a6f1UL,0x72e3a8e3UL,0x62f7a4f7UL,0xbd593759UL,0xff868b86UL,0xb1563256UL,0x0dc543c5UL,0xdceb59ebUL,0xafc2b7c2UL,0x028f8c8fUL,0x79ac64acUL,0x236dd26dUL,0x923be03bUL,0xabc7b4c7UL,0x4315fa15UL,0xfd090709UL,0x856f256fUL,0x8feaafeaUL,0xf3898e89UL,0x8e20e920UL,0x20281828UL,0xde64d564UL,0xfb838883UL,0x94b16fb1UL,0xb8967296UL,0x706c246cUL,0xae08f108UL,0xe652c752UL,0x35f351f3UL,0x8d652365UL,0x59847c84UL,0xcbbf9cbfUL,0x7c632163UL,0x377cdd7cUL,0xc27fdc7fUL,0x1a918691UL,0x1e948594UL,0xdbab90abUL,0xf8c642c6UL,0xe257c457UL,0x83e5aae5UL,0x3b73d873UL,0x0c0f050fUL,0xf5030103UL,0x38361236UL,0x9ffea3feUL,0xd4e15fe1UL,0x4710f910UL,0xd26bd06bUL,0x2ea891a8UL,0x29e858e8UL,0x74692769UL,0x4ed0b9d0UL,0xa9483848UL,0xcd351335UL,0x56ceb3ceUL,0x44553355UL,0xbfd6bbd6UL,0x49907090UL,0x0e808980UL,0x66f2a7f2UL,0x5ac1b6c1UL,0x78662266UL,0x2aad92adUL,0x89602060UL,0x15db49dbUL,0x4f1aff1aUL,0xa0887888UL,0x518e7a8eUL,0x068a8f8aUL,0xb213f813UL,0x129b809bUL,0x34391739UL,0xca75da75UL,0xb5533153UL,0x1351c651UL,0xbbd3b8d3UL,0x1f5ec35eUL,0x52cbb0cbUL,0xb4997799UL,0x3c331133UL,0xf646cb46UL,0x4b1ffc1fUL,0xda61d661UL,0x584e3a4eUL,
  0xf4a5f432UL,0x9784976fUL,0xb099b05eUL,0x8c8d8c7aUL,0x170d17e8UL,0xdcbddc0aUL,0xc8b1c816UL,0xfc54fc6dUL,0xf050f090UL,0x05030507UL,0xe0a9e02eUL,0x877d87d1UL,0x2b192bccUL,0xa662a613UL,0x31e6317cUL,0xb59ab559UL,0xcf45cf40UL,0xbc9dbca3UL,0xc040c049UL,0x92879268UL,0x3f153fd0UL,0x26eb2694UL,0x40c940ceUL,0x1d0b1de6UL,0x2fec2f6eUL,0xa967a91aUL,0x1cfd1c43UL,0x25ea2560UL,0xdabfdaf9UL,0x02f70251UL,0xa196a145UL,0xed5bed76UL,0x5dc25d28UL,0x241c24c5UL,0xe9aee9d4UL,0xbe6abef2UL,0xee5aee82UL,0xc341c3bdUL,0x060206f3UL,0xd14fd152UL,0xe45ce48cUL,0x07f40756UL,0x5c345c8dUL,0x180818e1UL,0xae93ae4cUL,0x9573953eUL,0xf553f597UL,0x413f416bUL,0x140c141cUL,0xf652f663UL,0xaf65afe9UL,0xe25ee27fUL,0x78287848UL,0xf8a1f8cfUL,0x110f111bUL,0xc4b5c4ebUL,0x1b091b15UL,0x5a365a7eUL,0xb69bb6adUL,0x473d4798UL,0x6a266aa7UL,0xbb69bbf5UL,0x4ccd4c33UL,0xba9fba50UL,0x2d1b2d3fUL,0xb99eb9a4UL,0x9c749cc4UL,0x722e7246UL,0x772d7741UL,0xcdb2cd11UL,0x29ee299dUL,0x16fb164dUL,0x01f601a5UL,0xd74dd7a1UL,0xa361a314UL,0x49ce4934UL,0x8d7b8ddfUL,0x423e429fUL,0x937193cdUL,0xa297a2b1UL,0x04f504a2UL,0xb868b801UL,0x00000000UL,0x742c74b5UL,0xa060a0e0UL,0x211f21c2UL,0x43c8433aUL,0x2ced2c9aUL,0xd9bed90dUL,0xca46ca47UL,0x70d97017UL,0xdd4bddafUL,0x79de79edUL,0x67d467ffUL,0x23e82393UL,0xde4ade5bUL,0xbd6bbd06UL,0x7e2a7ebbUL,0x34e5347bUL,0x3a163ad7UL,0x54c554d2UL,0x62d762f8UL,0xff55ff99UL,0xa794a7b6UL,0x4acf4ac0UL,0x301030d9UL,0x0a060a0eUL,0x98819866UL,0x0bf00babUL,0xcc44ccb4UL,0xd5bad5f0UL,0x3ee33e75UL,0x0ef30eacUL,0x19fe1944UL,0x5bc05bdbUL,0x858a8580UL,0xecadecd3UL,0xdfbcdffeUL,0xd848d8a8UL,0x0c040cfdUL,0x7adf7a19UL,0x58c1582fUL,0x9f759f30UL,0xa563a5e7UL,0x50305070UL,0x2e1a2ecbUL,0x120e12efUL,0xb76db708UL,0xd44cd455UL,0x3c143c24UL,0x5f355f79UL,0x712f71b2UL,0x38e13886UL,0xfda2fdc8UL,0x4fcc4fc7UL,0x4b394b65UL,0xf957f96aUL,0x0df20d58UL,0x9d829d61UL,0xc947c9b3UL,0xefacef27UL,0x32e73288UL,0x7d2b7d4fUL,0xa495a442UL,0xfba0fb3bUL,0xb398b3aaUL,0x68d168f6UL,0x817f8122UL,0xaa66aaeeUL,0x827e82d6UL,0xe6abe6ddUL,0x9e839e95UL,0x45ca45c9UL,0x7b297bbcUL,0x6ed36e05UL,0x443c446cUL,0x8b798b2cUL,0x3de23d81UL,0x271d2731UL,0x9a769a37UL,0x4d3b4d96UL,0xfa56fa9eUL,0xd24ed2a6UL,0x221e2236UL,0x76db76e4UL,0x1e0a1e12UL,0xb46cb4fcUL,0x37e4378fUL,0xe75de778UL,0xb26eb20fUL,0x2aef2a69UL,0xf1a6f135UL,0xe3a8e3daUL,0xf7a4f7c6UL,0x5937598aUL,0x868b8674UL,0x56325683UL,0xc543c54eUL,0xeb59eb85UL,0xc2b7c218UL,0x8f8c8f8eUL,0xac64ac1dUL,0x6dd26df1UL,0x3be03b72UL,0xc7b4c71fUL,0x15fa15b9UL,0x090709faUL,0x6f256fa0UL,0xeaafea20UL,0x898e897dUL,0x20e92067UL,0x28182838UL,0x64d5640bUL,0x83888373UL,0xb16fb1fbUL,0x967296caUL,0x6c246c54UL,0x08f1085fUL,0x52c75221UL,0xf351f364UL,0x652365aeUL,0x847c8425UL,0xbf9cbf57UL,0x6321635dUL,0x7cdd7ceaUL,0x7fdc7f1eUL,0x9186919cUL,0x9485949bUL,0xab90ab4bUL,0xc642c6baUL,0x57c45726UL,0xe5aae529UL,0x73d873e3UL,0x0f050f09UL,0x030103f4UL,0x3612362aUL,0xfea3fe3cUL,0xe15fe18bUL,0x10f910beUL,0x6bd06b02UL,0xa891a8bfUL,0xe858e871UL,0x69276953UL,0xd0b9d0f7UL,0x48384891UL,0x351335deUL,0xceb3cee5UL,0x55335577UL,0xd6bbd604UL,0x90709039UL,0x80898087UL,0xf2a7f2c1UL,0xc1b6c1ecUL,0x6622665aUL,0xad92adb8UL,0x602060a9UL,0xdb49db5cUL,0x1aff1ab0UL,0x887888d8UL,0x8e7a8e2bUL,0x8a8f8a89UL,0x13f8134aUL,0x9b809b92UL,0x39173923UL,0x75da7510UL,0x53315384UL,0x51c651d5UL,0xd3b8d303UL,0x5ec35edcUL,0xcbb0cbe2UL,0x997799c3UL,0x3311332dUL,0x46cb463dUL,0x1ffc1fb7UL,0x61d6610cUL,0x4e3a4e62UL};
#endif /* IS_LITTLE_ENDIAN */

#endif /* __tables_h */


// ================================================================================
// =================== hash.h
// ================================================================================

#ifndef __hash_h
#define __hash_h

#include <stdio.h>
#include <stdlib.h>
//#include "brg_endian.h"
//#include "brg_types.h"

/* some sizes (number of bytes) */
#define ROWS 8
#define LENGTHFIELDLEN ROWS
#define COLS512 8
#define COLS1024 16

#define SIZE512 (ROWS*COLS512)
#define SIZE1024 (ROWS*COLS1024)

#define ROUNDS512 10
#define ROUNDS1024 14

#define ROTL32(v, n) ((((v)<<(n))|((v)>>(32-(n))))&li_32(ffffffff))

#if (PLATFORM_BYTE_ORDER == IS_BIG_ENDIAN)
#define EXT_BYTE(var,n) ((u8)((u32)(var) >> (8*(3-(n)))))
#define U32BIG(a) (a)
#endif /* IS_BIG_ENDIAN */

#if (PLATFORM_BYTE_ORDER == IS_LITTLE_ENDIAN)
#define EXT_BYTE(var,n) ((u8)((u32)(var) >> (8*n)))
#define U32BIG(a)				\
  ((ROTL32(a,8) & li_32(00FF00FF)) |		\
   (ROTL32(a,24) & li_32(FF00FF00)))
#endif /* IS_LITTLE_ENDIAN */

typedef enum { LONG, SHORT } Var;


/* NIST API begin */
typedef unsigned char BitSequence;
typedef unsigned long long DataLength;
typedef enum { SUCCESS = 0, FAIL = 1, BAD_HASHLEN = 2 } HashReturn;
class hashState {
public:
  u32 *chaining;            /* actual state */
  u32 block_counter1,
    block_counter2;         /* message block counter(s) */
  int hashbitlen;           /* output length in bits */
  BitSequence *buffer;      /* data buffer */
  int buf_ptr;              /* data buffer pointer */
  int bits_in_last_byte;    /* no. of message bits in last byte of
			       data buffer */
  int columns;              /* no. of columns in state */
  int statesize;            /* total no. of bytes in state */
  Var v;                    /* LONG or SHORT */
};

HashReturn Init(hashState*, int);
HashReturn Update(hashState*, const BitSequence*, DataLength);
HashReturn Final(hashState*, BitSequence*);
HashReturn Hash(int, const BitSequence*, DataLength, BitSequence*);
/* NIST API end   */


#endif /* __hash_h */


// ================================================================================
// =================== hash.c
// ================================================================================


/* hash.c     January 2011
 * Groestl ANSI C code optimised for 32-bit machines
 * Authors: Soeren S. Thomsen
 *          Krystian Matusiewicz
 *
 * This code is placed in the public domain
 */

//#include "hash.h"
//#include "tables.h"

/* compute one new state column */
#define COLUMN(x,y,i,c0,c1,c2,c3,c4,c5,c6,c7)				\
  y[i] =								\
    T[0*256+EXT_BYTE(x[c0], 0)]^					\
    T[1*256+EXT_BYTE(x[c1], 1)]^					\
    T[2*256+EXT_BYTE(x[c2], 2)]^					\
    T[3*256+EXT_BYTE(x[c3], 3)]^					\
    T[4*256+EXT_BYTE(x[c4], 0)]^					\
    T[5*256+EXT_BYTE(x[c5], 1)]^					\
    T[6*256+EXT_BYTE(x[c6], 2)]^					\
    T[7*256+EXT_BYTE(x[c7], 3)]

/* compute one round of P (short variants) */
void RND512P(u32 *x, u32 *y, u32 r) {
  x[ 0] ^= U32BIG((u32)0x00000000u)^r;
  x[ 2] ^= U32BIG((u32)0x10000000u)^r;
  x[ 4] ^= U32BIG((u32)0x20000000u)^r;
  x[ 6] ^= U32BIG((u32)0x30000000u)^r;
  x[ 8] ^= U32BIG((u32)0x40000000u)^r;
  x[10] ^= U32BIG((u32)0x50000000u)^r;
  x[12] ^= U32BIG((u32)0x60000000u)^r;
  x[14] ^= U32BIG((u32)0x70000000u)^r;
  COLUMN(x,y, 0,  0,  2,  4,  6,  9, 11, 13, 15);
  COLUMN(x,y, 1,  9, 11, 13, 15,  0,  2,  4,  6);
  COLUMN(x,y, 2,  2,  4,  6,  8, 11, 13, 15,  1);
  COLUMN(x,y, 3, 11, 13, 15,  1,  2,  4,  6,  8);
  COLUMN(x,y, 4,  4,  6,  8, 10, 13, 15,  1,  3);
  COLUMN(x,y, 5, 13, 15,  1,  3,  4,  6,  8, 10);
  COLUMN(x,y, 6,  6,  8, 10, 12, 15,  1,  3,  5);
  COLUMN(x,y, 7, 15,  1,  3,  5,  6,  8, 10, 12);
  COLUMN(x,y, 8,  8, 10, 12, 14,  1,  3,  5,  7);
  COLUMN(x,y, 9,  1,  3,  5,  7,  8, 10, 12, 14);
  COLUMN(x,y,10, 10, 12, 14,  0,  3,  5,  7,  9);
  COLUMN(x,y,11,  3,  5,  7,  9, 10, 12, 14,  0);
  COLUMN(x,y,12, 12, 14,  0,  2,  5,  7,  9, 11);
  COLUMN(x,y,13,  5,  7,  9, 11, 12, 14,  0,  2);
  COLUMN(x,y,14, 14,  0,  2,  4,  7,  9, 11, 13);
  COLUMN(x,y,15,  7,  9, 11, 13, 14,  0,  2,  4);
}

/* compute one round of Q (short variants) */
void RND512Q(u32 *x, u32 *y, u32 r) {
  x[ 0] = ~x[ 0];
  x[ 1] ^= U32BIG((u32)0xffffffffu)^r;
  x[ 2] = ~x[ 2];
  x[ 3] ^= U32BIG((u32)0xffffffefu)^r;
  x[ 4] = ~x[ 4];
  x[ 5] ^= U32BIG((u32)0xffffffdfu)^r;
  x[ 6] = ~x[ 6];
  x[ 7] ^= U32BIG((u32)0xffffffcfu)^r;
  x[ 8] = ~x[ 8];
  x[ 9] ^= U32BIG((u32)0xffffffbfu)^r;
  x[10] = ~x[10];
  x[11] ^= U32BIG((u32)0xffffffafu)^r;
  x[12] = ~x[12];
  x[13] ^= U32BIG((u32)0xffffff9fu)^r;
  x[14] = ~x[14];
  x[15] ^= U32BIG((u32)0xffffff8fu)^r;
  COLUMN(x,y, 0,  2,  6, 10, 14,  1,  5,  9, 13);
  COLUMN(x,y, 1,  1,  5,  9, 13,  2,  6, 10, 14);
  COLUMN(x,y, 2,  4,  8, 12,  0,  3,  7, 11, 15);
  COLUMN(x,y, 3,  3,  7, 11, 15,  4,  8, 12,  0);
  COLUMN(x,y, 4,  6, 10, 14,  2,  5,  9, 13,  1);
  COLUMN(x,y, 5,  5,  9, 13,  1,  6, 10, 14,  2);
  COLUMN(x,y, 6,  8, 12,  0,  4,  7, 11, 15,  3);
  COLUMN(x,y, 7,  7, 11, 15,  3,  8, 12,  0,  4);
  COLUMN(x,y, 8, 10, 14,  2,  6,  9, 13,  1,  5);
  COLUMN(x,y, 9,  9, 13,  1,  5, 10, 14,  2,  6);
  COLUMN(x,y,10, 12,  0,  4,  8, 11, 15,  3,  7);
  COLUMN(x,y,11, 11, 15,  3,  7, 12,  0,  4,  8);
  COLUMN(x,y,12, 14,  2,  6, 10, 13,  1,  5,  9);
  COLUMN(x,y,13, 13,  1,  5,  9, 14,  2,  6, 10);
  COLUMN(x,y,14,  0,  4,  8, 12, 15,  3,  7, 11);
  COLUMN(x,y,15, 15,  3,  7, 11,  0,  4,  8, 12);
}

/* compute one round of P (short variants) */
void RND1024P(u32 *x, u32 *y, u32 r) {
  x[ 0] ^= U32BIG((u32)0x00000000u)^r;
  x[ 2] ^= U32BIG((u32)0x10000000u)^r;
  x[ 4] ^= U32BIG((u32)0x20000000u)^r;
  x[ 6] ^= U32BIG((u32)0x30000000u)^r;
  x[ 8] ^= U32BIG((u32)0x40000000u)^r;
  x[10] ^= U32BIG((u32)0x50000000u)^r;
  x[12] ^= U32BIG((u32)0x60000000u)^r;
  x[14] ^= U32BIG((u32)0x70000000u)^r;
  x[16] ^= U32BIG((u32)0x80000000u)^r;
  x[18] ^= U32BIG((u32)0x90000000u)^r;
  x[20] ^= U32BIG((u32)0xa0000000u)^r;
  x[22] ^= U32BIG((u32)0xb0000000u)^r;
  x[24] ^= U32BIG((u32)0xc0000000u)^r;
  x[26] ^= U32BIG((u32)0xd0000000u)^r;
  x[28] ^= U32BIG((u32)0xe0000000u)^r;
  x[30] ^= U32BIG((u32)0xf0000000u)^r;

  COLUMN(x,y, 0, 0, 2, 4, 6, 9,11,13,23);
  COLUMN(x,y, 2, 2, 4, 6, 8,11,13,15,25);
  COLUMN(x,y, 4, 4, 6, 8,10,13,15,17,27);
  COLUMN(x,y, 6, 6, 8,10,12,15,17,19,29);
  COLUMN(x,y, 8, 8,10,12,14,17,19,21,31);
  COLUMN(x,y,10,10,12,14,16,19,21,23, 1);
  COLUMN(x,y,12,12,14,16,18,21,23,25, 3);
  COLUMN(x,y,14,14,16,18,20,23,25,27, 5);
  COLUMN(x,y,16,16,18,20,22,25,27,29, 7);
  COLUMN(x,y,18,18,20,22,24,27,29,31, 9);
  COLUMN(x,y,20,20,22,24,26,29,31, 1,11);
  COLUMN(x,y,22,22,24,26,28,31, 1, 3,13);
  COLUMN(x,y,24,24,26,28,30, 1, 3, 5,15);
  COLUMN(x,y,26,26,28,30, 0, 3, 5, 7,17);
  COLUMN(x,y,28,28,30, 0, 2, 5, 7, 9,19);
  COLUMN(x,y,30,30, 0, 2, 4, 7, 9,11,21);

  COLUMN(x,y, 1, 9,11,13,23, 0, 2, 4, 6);
  COLUMN(x,y, 3,11,13,15,25, 2, 4, 6, 8);
  COLUMN(x,y, 5,13,15,17,27, 4, 6, 8,10);
  COLUMN(x,y, 7,15,17,19,29, 6, 8,10,12);
  COLUMN(x,y, 9,17,19,21,31, 8,10,12,14);
  COLUMN(x,y,11,19,21,23, 1,10,12,14,16);
  COLUMN(x,y,13,21,23,25, 3,12,14,16,18);
  COLUMN(x,y,15,23,25,27, 5,14,16,18,20);
  COLUMN(x,y,17,25,27,29, 7,16,18,20,22);
  COLUMN(x,y,19,27,29,31, 9,18,20,22,24);
  COLUMN(x,y,21,29,31, 1,11,20,22,24,26);
  COLUMN(x,y,23,31, 1, 3,13,22,24,26,28);
  COLUMN(x,y,25, 1, 3, 5,15,24,26,28,30);
  COLUMN(x,y,27, 3, 5, 7,17,26,28,30, 0);
  COLUMN(x,y,29, 5, 7, 9,19,28,30, 0, 2);
  COLUMN(x,y,31, 7, 9,11,21,30, 0, 2, 4);
}

/* compute one round of Q (short variants) */
void RND1024Q(u32 *x, u32 *y, u32 r) {
  x[ 0] = ~x[ 0];
  x[ 1] ^= U32BIG((u32)0xffffffffu)^r;
  x[ 2] = ~x[ 2];
  x[ 3] ^= U32BIG((u32)0xffffffefu)^r;
  x[ 4] = ~x[ 4];
  x[ 5] ^= U32BIG((u32)0xffffffdfu)^r;
  x[ 6] = ~x[ 6];
  x[ 7] ^= U32BIG((u32)0xffffffcfu)^r;
  x[ 8] = ~x[ 8];
  x[ 9] ^= U32BIG((u32)0xffffffbfu)^r;
  x[10] = ~x[10];
  x[11] ^= U32BIG((u32)0xffffffafu)^r;
  x[12] = ~x[12];
  x[13] ^= U32BIG((u32)0xffffff9fu)^r;
  x[14] = ~x[14];
  x[15] ^= U32BIG((u32)0xffffff8fu)^r;
  x[16] = ~x[16];
  x[17] ^= U32BIG((u32)0xffffff7fu)^r;
  x[18] = ~x[18];
  x[19] ^= U32BIG((u32)0xffffff6fu)^r;
  x[20] = ~x[20];
  x[21] ^= U32BIG((u32)0xffffff5fu)^r;
  x[22] = ~x[22];
  x[23] ^= U32BIG((u32)0xffffff4fu)^r;
  x[24] = ~x[24];
  x[25] ^= U32BIG((u32)0xffffff3fu)^r;
  x[26] = ~x[26];
  x[27] ^= U32BIG((u32)0xffffff2fu)^r;
  x[28] = ~x[28];
  x[29] ^= U32BIG((u32)0xffffff1fu)^r;
  x[30] = ~x[30];
  x[31] ^= U32BIG((u32)0xffffff0fu)^r;

  COLUMN(x,y, 0,  2,  6, 10, 22,  1,  5,  9, 13);
  COLUMN(x,y, 1,  1,  5,  9, 13,  2,  6, 10, 22);
  COLUMN(x,y, 2,  4,  8, 12, 24,  3,  7, 11, 15);
  COLUMN(x,y, 3,  3,  7, 11, 15,  4,  8, 12, 24);
  COLUMN(x,y, 4,  6, 10, 14, 26,  5,  9, 13, 17);
  COLUMN(x,y, 5,  5,  9, 13, 17,  6, 10, 14, 26);
  COLUMN(x,y, 6,  8, 12, 16, 28,  7, 11, 15, 19);
  COLUMN(x,y, 7,  7, 11, 15, 19,  8, 12, 16, 28);
  COLUMN(x,y, 8, 10, 14, 18, 30,  9, 13, 17, 21);
  COLUMN(x,y, 9,  9, 13, 17, 21, 10, 14, 18, 30);
  COLUMN(x,y,10, 12, 16, 20,  0, 11, 15, 19, 23);
  COLUMN(x,y,11, 11, 15, 19, 23, 12, 16, 20,  0);
  COLUMN(x,y,12, 14, 18, 22,  2, 13, 17, 21, 25);
  COLUMN(x,y,13, 13, 17, 21, 25, 14, 18, 22,  2);
  COLUMN(x,y,14, 16, 20, 24,  4, 15, 19, 23, 27);
  COLUMN(x,y,15, 15, 19, 23, 27, 16, 20, 24,  4);

  COLUMN(x,y,16, 18, 22, 26,  6, 17, 21, 25, 29);
  COLUMN(x,y,17, 17, 21, 25, 29, 18, 22, 26,  6);
  COLUMN(x,y,18, 20, 24, 28,  8, 19, 23, 27, 31);
  COLUMN(x,y,19, 19, 23, 27, 31, 20, 24, 28,  8);
  COLUMN(x,y,20, 22, 26, 30, 10, 21, 25, 29,  1);
  COLUMN(x,y,21, 21, 25, 29,  1, 22, 26, 30, 10);
  COLUMN(x,y,22, 24, 28,  0, 12, 23, 27, 31,  3);
  COLUMN(x,y,23, 23, 27, 31,  3, 24, 28,  0, 12);
  COLUMN(x,y,24, 26, 30,  2, 14, 25, 29,  1,  5);
  COLUMN(x,y,25, 25, 29,  1,  5, 26, 30,  2, 14);
  COLUMN(x,y,26, 28,  0,  4, 16, 27, 31,  3,  7);
  COLUMN(x,y,27, 27, 31,  3,  7, 28,  0,  4, 16);
  COLUMN(x,y,28, 30,  2,  6, 18, 29,  1,  5,  9);
  COLUMN(x,y,29, 29,  1,  5,  9, 30,  2,  6, 18);
  COLUMN(x,y,30,  0,  4,  8, 20, 31,  3,  7, 11);
  COLUMN(x,y,31, 31,  3,  7, 11,  0,  4,  8, 20);
}


/* compute compression function (short variants) */
void F512(u32 *h, const u32 *m) {
  int i;
  u32 Ptmp[2*COLS512];
  u32 Qtmp[2*COLS512];
  u32 y[2*COLS512];
  u32 z[2*COLS512];

  for (i = 0; i < 2*COLS512; i++) {
    z[i] = m[i];
    Ptmp[i] = h[i]^m[i];
  }

  /* compute Q(m) */
  RND512Q(z, y, U32BIG((u32)0x00000000u));
  RND512Q(y, z, U32BIG((u32)0x00000001u));
  RND512Q(z, y, U32BIG((u32)0x00000002u));
  RND512Q(y, z, U32BIG((u32)0x00000003u));
  RND512Q(z, y, U32BIG((u32)0x00000004u));
  RND512Q(y, z, U32BIG((u32)0x00000005u));
  RND512Q(z, y, U32BIG((u32)0x00000006u));
  RND512Q(y, z, U32BIG((u32)0x00000007u));
  RND512Q(z, y, U32BIG((u32)0x00000008u));
  RND512Q(y, Qtmp, U32BIG((u32)0x00000009u));

  /* compute P(h+m) */
  RND512P(Ptmp, y, U32BIG((u32)0x00000000u));
  RND512P(y, z, U32BIG((u32)0x01000000u));
  RND512P(z, y, U32BIG((u32)0x02000000u));
  RND512P(y, z, U32BIG((u32)0x03000000u));
  RND512P(z, y, U32BIG((u32)0x04000000u));
  RND512P(y, z, U32BIG((u32)0x05000000u));
  RND512P(z, y, U32BIG((u32)0x06000000u));
  RND512P(y, z, U32BIG((u32)0x07000000u));
  RND512P(z, y, U32BIG((u32)0x08000000u));
  RND512P(y, Ptmp, U32BIG((u32)0x09000000u));

  /* compute P(h+m) + Q(m) + h */
  for (i = 0; i < 2*COLS512; i++) {
    h[i] ^= Ptmp[i]^Qtmp[i];
  }
}

/* compute compression function (long variants) */
void F1024(u32 *h, const u32 *m) {
  int i;
  u32 Ptmp[2*COLS1024];
  u32 Qtmp[2*COLS1024];
  u32 y[2*COLS1024];
  u32 z[2*COLS1024];

  for (i = 0; i < 2*COLS1024; i++) {
    z[i] = m[i];
    Ptmp[i] = h[i]^m[i];
  }

  /* compute Q(m) */
  RND1024Q(z, y, U32BIG((u32)0x00000000u));
  for (i = 1; i < ROUNDS1024-1; i += 2) {
    RND1024Q(y, z, U32BIG((u32)i));
    RND1024Q(z, y, U32BIG((u32)i+1));
  }
  RND1024Q(y, Qtmp, U32BIG((u32)0x0000000du));

  /* compute P(h+m) */
  RND1024P(Ptmp, y, U32BIG((u32)0x00000000u));
  for (i = 1; i < ROUNDS1024-1; i += 2) {
    RND1024P(y, z, U32BIG((u32)i<<24));
    RND1024P(z, y, U32BIG(((u32)i+1)<<24));
  }
  RND1024P(y, Ptmp, U32BIG(((u32)ROUNDS1024-1)<<24));

  /* compute P(h+m) + Q(m) + h */
  for (i = 0; i < 2*COLS1024; i++) {
    h[i] ^= Ptmp[i]^Qtmp[i];
  }
}


/* digest up to msglen bytes of input (full blocks only) */
void Transform(hashState *ctx, 
	       const u8 *input, 
	       int msglen) {
  /* determine variant, SHORT or LONG, and select underlying
     compression function based on the variant */
  void (*F)(u32*,const u32*);
  switch ( ctx->v ) {
  case SHORT : F = &F512; break;
  case LONG  : 
  default    : F = &F1024; break;
  }

  /* digest message, one block at a time */
  for (; msglen >= ctx->statesize; 
       msglen -= ctx->statesize, input += ctx->statesize) {
    F(ctx->chaining,(u32*)input);

    /* increment block counter */
    ctx->block_counter1++;
    if (ctx->block_counter1 == 0) ctx->block_counter2++;
  }
}

/* given state h, do h <- P(h)+h */
void OutputTransformation(hashState *ctx) {
  int j;
  u32 *temp, *y, *z;
  temp = (uint_32t*)malloc(2*ctx->columns*sizeof(u32));
  y    = (uint_32t*)malloc(2*ctx->columns*sizeof(u32));
  z    = (uint_32t*)malloc(2*ctx->columns*sizeof(u32));

  /* determine variant */
  switch (ctx->v) {
  case SHORT :
    for (j = 0; j < 2*COLS512; j++) {
      temp[j] = ctx->chaining[j];
    }
    RND512P(temp, y, U32BIG((u32)0x00000000u));
    RND512P(y, z, U32BIG((u32)0x01000000u));
    RND512P(z, y, U32BIG((u32)0x02000000u));
    RND512P(y, z, U32BIG((u32)0x03000000u));
    RND512P(z, y, U32BIG((u32)0x04000000u));
    RND512P(y, z, U32BIG((u32)0x05000000u));
    RND512P(z, y, U32BIG((u32)0x06000000u));
    RND512P(y, z, U32BIG((u32)0x07000000u));
    RND512P(z, y, U32BIG((u32)0x08000000u));
    RND512P(y, temp, U32BIG((u32)0x09000000u));
    for (j = 0; j < 2*COLS512; j++) {
      ctx->chaining[j] ^= temp[j];
    }
    break;
  case LONG  :
    for (j = 0; j < 2*COLS1024; j++) {
      temp[j] = ctx->chaining[j];
    }
    RND1024P(temp,y,U32BIG((u32)0x00000000u));
    for (j = 1; j < ROUNDS1024-1; j += 2) {
      RND1024P(y,z,U32BIG((u32)j<<24));
      RND1024P(z,y,U32BIG(((u32)j+1)<<24));
    }
    RND1024P(y,temp,U32BIG(((u32)ROUNDS1024-1)<<24));
    for (j = 0; j < 2*COLS1024; j++) {
      ctx->chaining[j] ^= temp[j];
    }
    break;
  }

  free(temp);
  free(y);
  free(z);
}

/* initialise context */
HashReturn Init(hashState* ctx,
		int hashbitlen) {
  /* output size (in bits) must be a positive integer less than or
     equal to 512, and divisible by 8 */
  if (hashbitlen <= 0 || (hashbitlen%8) || hashbitlen > 512)
    return BAD_HASHLEN;

  /* set number of state columns and state size depending on
     variant */
  if (hashbitlen <= 256) {
    ctx->columns = COLS512;
    ctx->statesize = SIZE512;
    ctx->v = SHORT;
  }
  else {
    ctx->columns = COLS1024;
    ctx->statesize = SIZE1024;
    ctx->v = LONG;
  }

  /* allocate memory for state and data buffer */
  ctx->chaining = (uint_32t*)calloc(ctx->statesize,1);
  ctx->buffer = (BitSequence*)malloc(ctx->statesize);
  if (ctx->chaining == NULL || ctx->buffer == NULL)
    return FAIL;

  /* set initial value */
  ctx->chaining[2*ctx->columns-1] = U32BIG((u32)hashbitlen);

  /* set other variables */
  ctx->hashbitlen = hashbitlen;
  ctx->buf_ptr = 0;
  ctx->block_counter1 = 0;
  ctx->block_counter2 = 0;
  ctx->bits_in_last_byte = 0;

  return SUCCESS;
}

/* update state with databitlen bits of input */
HashReturn Update(hashState* ctx,
		  const BitSequence* input,
		  DataLength databitlen) {
  int index = 0;
  int msglen = (int)(databitlen/8);
  int rem = (int)(databitlen%8);

  /* non-integral number of message bytes can only be supplied in the
     last call to this function */
  if (ctx->bits_in_last_byte) return FAIL;

  /* if the buffer contains data that has not yet been digested, first
     add data to buffer until full */
  if (ctx->buf_ptr) {
    while (ctx->buf_ptr < ctx->statesize && index < msglen) {
      ctx->buffer[(int)ctx->buf_ptr++] = input[index++];
    }
    if (ctx->buf_ptr < ctx->statesize) {
      /* buffer still not full, return */
      if (rem) {
	ctx->bits_in_last_byte = rem;
	ctx->buffer[(int)ctx->buf_ptr++] = input[index];
      }
      return SUCCESS;
    }

    /* digest buffer */
    ctx->buf_ptr = 0;
    Transform(ctx, ctx->buffer, ctx->statesize);
  }

  /* digest bulk of message */
  Transform(ctx, input+index, msglen-index);
  index += ((msglen-index)/ctx->statesize)*ctx->statesize;

  /* store remaining data in buffer */
  while (index < msglen) {
    ctx->buffer[(int)ctx->buf_ptr++] = input[index++];
  }

  /* if non-integral number of bytes have been supplied, store
     remaining bits in last byte, together with information about
     number of bits */
  if (rem) {
    ctx->bits_in_last_byte = rem;
    ctx->buffer[(int)ctx->buf_ptr++] = input[index];
  }
  return SUCCESS;
}

#define BILB ctx->bits_in_last_byte

/* finalise: process remaining data (including padding), perform
   output transformation, and write hash result to 'output' */
HashReturn Final(hashState* ctx,
		 BitSequence* output) {
  int i, j = 0, hashbytelen = ctx->hashbitlen/8;
  u8 *s = (BitSequence*)ctx->chaining;

  /* pad with '1'-bit and first few '0'-bits */
  if (BILB) {
    ctx->buffer[(int)ctx->buf_ptr-1] &= ((1<<BILB)-1)<<(8-BILB);
    ctx->buffer[(int)ctx->buf_ptr-1] ^= 0x1<<(7-BILB);
    BILB = 0;
  }
  else ctx->buffer[(int)ctx->buf_ptr++] = 0x80;

  /* pad with '0'-bits */
  if (ctx->buf_ptr > ctx->statesize-LENGTHFIELDLEN) {
    /* padding requires two blocks */
    while (ctx->buf_ptr < ctx->statesize) {
      ctx->buffer[(int)ctx->buf_ptr++] = 0;
    }
    /* digest first padding block */
    Transform(ctx, ctx->buffer, ctx->statesize);
    ctx->buf_ptr = 0;
  }
  while (ctx->buf_ptr < ctx->statesize-LENGTHFIELDLEN) {
    ctx->buffer[(int)ctx->buf_ptr++] = 0;
  }

  /* length padding */
  ctx->block_counter1++;
  if (ctx->block_counter1 == 0) ctx->block_counter2++;
  ctx->buf_ptr = ctx->statesize;

  while (ctx->buf_ptr > ctx->statesize-(int)sizeof(u32)) {
    ctx->buffer[(int)--ctx->buf_ptr] = (u8)ctx->block_counter1;
    ctx->block_counter1 >>= 8;
  }
  while (ctx->buf_ptr > ctx->statesize-LENGTHFIELDLEN) {
    ctx->buffer[(int)--ctx->buf_ptr] = (u8)ctx->block_counter2;
    ctx->block_counter2 >>= 8;
  }

  /* digest final padding block */
  Transform(ctx, ctx->buffer, ctx->statesize);
  /* perform output transformation */
  OutputTransformation(ctx);

  /* store hash result in output */
  for (i = ctx->statesize-hashbytelen; i < ctx->statesize; i++,j++) {
    output[j] = s[i];
  }

  /* zeroise relevant variables and deallocate memory */
  for (i = 0; i < ctx->columns; i++) {
    ctx->chaining[i] = 0;
  }
  for (i = 0; i < ctx->statesize; i++) {
    ctx->buffer[i] = 0;
  }
  free(ctx->chaining);
  free(ctx->buffer);

  return SUCCESS;
}

/* hash bit sequence */
HashReturn Hash(int hashbitlen,
		const BitSequence* data, 
		DataLength databitlen,
		BitSequence* hashval) {
  HashReturn ret;
  hashState context;

  /* initialise */
  if ((ret = Init(&context, hashbitlen)) != SUCCESS)
    return ret;

  /* process message */
  if ((ret = Update(&context, data, databitlen)) != SUCCESS)
    return ret;

  /* finalise */
  ret = Final(&context, hashval);

  return ret;
}


} // end of namespace GrostlImpl
