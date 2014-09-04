// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-

// -- BEGIN LICENSE BLOCK ----------------------------------------------
// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!\file
 *
 * \author  Klaus Uhl <uhl@fzi.de>
 * \date    2008-01-28
 *
 * \brief   Posix implementation of the global thread functions.
 */
//----------------------------------------------------------------------
#ifndef ICL_CORE_OS_POSIX_THREAD_H_INCLUDED
#define ICL_CORE_OS_POSIX_THREAD_H_INCLUDED

#include <pthread.h>
#include <unistd.h>

#include "icl_core/ImportExport.h"
#include "BaseTypes.h"

namespace icl_core {
namespace os {
namespace hidden_posix {

struct ThreadId
{
  pthread_t m_thread_id;

  ThreadId() : m_thread_id() {}
  ThreadId(pthread_t thread_id) : m_thread_id(thread_id) {}

  operator size_t () const { return size_t(m_thread_id); }
};
ICL_CORE_IMPORT_EXPORT bool operator == (const ThreadId& left, const ThreadId& right);

ICL_CORE_IMPORT_EXPORT ThreadId threadSelf();
pid_t getpid();

}
}
}

#endif
