// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-

// -- BEGIN LICENSE BLOCK ----------------------------------------------
// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!\file
 *
 * \author  Klaus Uhl <uhl@fzi.de>
 * \date    2008-10-26
 *
 * \brief   Collects all exported header files for use with precompiled headers.
 *
 */
//----------------------------------------------------------------------
#ifndef ICL_CORE_LOGGING_ICL_CORE_LOGGING_H_INCLUDED
#define ICL_CORE_LOGGING_ICL_CORE_LOGGING_H_INCLUDED

#ifndef _IC_BUILDER_ICL_CORE_LOGGING_
#  define _IC_BUILDER_ICL_CORE_LOGGING_
#endif

#include <icl_core/icl_core.h>
#include <icl_core_config/icl_core_config.h>

#include "icl_core_logging/Logging.h"
#include "icl_core_logging/LoggingManager.h"
#include "icl_core_logging/LogLevel.h"
#include "icl_core_logging/LogOutputStream.h"

// -- START Deprecated compatibility headers --
#include "icl_core_logging/tLogLevel.h"
// -- END Deprecated compatibility headers --

#endif
