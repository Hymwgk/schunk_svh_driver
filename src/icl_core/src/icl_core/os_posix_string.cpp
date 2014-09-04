// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-

// -- BEGIN LICENSE BLOCK ----------------------------------------------
// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!\file
 *
 * \author  Klaus Uhl <uhl@fzi.de>
 * \date    2008-03-29
 *
 */
//----------------------------------------------------------------------
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "icl_core/os_posix_string.h"

namespace icl_core {
namespace os {
namespace hidden_posix {

char * stpcpy(char *dst, const char *src)
{
#if defined(_SYSTEM_QNX_)||defined(__ANDROID__)
  char *result = strcpy(dst, src);
  for (; *result != 0; ++result)
  { }
  return result;
#else
  return ::stpcpy(dst, src);
#endif
}

char * strdup(const char *s)
{
  return ::strdup(s);
}

int vsnprintf(char *buffer, size_t maxlen, const char *format, va_list argptr)
{
  return ::vsnprintf(buffer, maxlen, format, argptr);
}

}
}
}
