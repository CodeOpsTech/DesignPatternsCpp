
// -*- C++ -*-
// SSLIOP_Export.h,v 1.4 2000/10/10 22:16:02 nanbor Exp
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl
// ------------------------------
#ifndef TAO_SSLIOP_EXPORT_H
#define TAO_SSLIOP_EXPORT_H

#include "ace/config-all.h"

#if defined (TAO_AS_STATIC_LIBS)
#  if !defined (TAO_SSLIOP_HAS_DLL)
#    define TAO_SSLIOP_HAS_DLL 0
#  endif /* ! TAO_SSLIOP_HAS_DLL */
#else
#  if !defined (TAO_SSLIOP_HAS_DLL)
#    define TAO_SSLIOP_HAS_DLL 1
#  endif /* ! TAO_SSLIOP_HAS_DLL */
#endif

#if defined (TAO_SSLIOP_HAS_DLL) && (TAO_SSLIOP_HAS_DLL == 1)
#  if defined (TAO_SSLIOP_BUILD_DLL)
#    define TAO_SSLIOP_Export ACE_Proper_Export_Flag
#    define TAO_SSLIOP_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define TAO_SSLIOP_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* TAO_SSLIOP_BUILD_DLL */
#    define TAO_SSLIOP_Export ACE_Proper_Import_Flag
#    define TAO_SSLIOP_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define TAO_SSLIOP_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* TAO_SSLIOP_BUILD_DLL */
#else /* TAO_SSLIOP_HAS_DLL == 1 */
#  define TAO_SSLIOP_Export
#  define TAO_SSLIOP_SINGLETON_DECLARATION(T)
#  define TAO_SSLIOP_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* TAO_SSLIOP_HAS_DLL == 1 */

#endif /* TAO_SSLIOP_EXPORT_H */

// End of auto generated file.
