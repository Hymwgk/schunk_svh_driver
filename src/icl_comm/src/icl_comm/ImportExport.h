// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-

// -- BEGIN LICENSE BLOCK ----------------------------------------------
// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!\file
 *
 * \author  Jan Oberlaender
 * \date    2012-01-24
 *
 */
//----------------------------------------------------------------------
#ifndef ICL_COMM_IMPORT_EXPORT_H_INCLUDED
#define ICL_COMM_IMPORT_EXPORT_H_INCLUDED

#if defined(_SYSTEM_WIN32_) && !defined(_IC_STATIC_)
#  pragma warning ( disable : 4251 )

# if defined ICL_COMM_EXPORT_SYMBOLS
#  define ICL_COMM_IMPORT_EXPORT __declspec(dllexport)
# else
#  define ICL_COMM_IMPORT_EXPORT __declspec(dllimport)
# endif

#elif defined(__GNUC__) && (__GNUC__ > 3) && !defined(_IC_STATIC_)

# define ICL_COMM_IMPORT_EXPORT __attribute__ ((visibility("default")))

#else

# define ICL_COMM_IMPORT_EXPORT

#endif

#endif
