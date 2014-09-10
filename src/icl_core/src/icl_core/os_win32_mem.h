// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-

// -- BEGIN LICENSE BLOCK ----------------------------------------------
// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!\file
 *
 * \author  Klaus Uhl <uhl@fzi.de>
 * \date    2008-01-28
 *
 * \brief   Win32 implementation of the global memory functions.
 */
//----------------------------------------------------------------------
#ifndef ICL_CORE_OS_WIN32_MEM_H_INCLUDED
#define ICL_CORE_OS_WIN32_MEM_H_INCLUDED

#include "icl_core/ImportExport.h"

namespace icl_core {
namespace os {
namespace hidden_win32 {

ICL_CORE_IMPORT_EXPORT void *memcpy(void *dest, void *src, size_t count);
ICL_CORE_IMPORT_EXPORT void *memset(void *dest, int c, size_t count);

}
}
}

#endif