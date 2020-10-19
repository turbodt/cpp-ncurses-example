#ifndef INCLUDE_LOGGING_H
#define INCLUDE_LOGGING_H

#include "spdlog/sinks/basic_file_sink.h"

namespace logging {
  extern std::shared_ptr<spdlog::logger> logger;
}

#endif
