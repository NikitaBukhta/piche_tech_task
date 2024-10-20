#ifndef __TECHTASK_SOURCES_BASE_CORE_LAUNCHER_HPP__
#define __TECHTASK_SOURCES_BASE_CORE_LAUNCHER_HPP__

#include <cinttypes>

namespace base::core {

  class Laucnher {
  public:
    virtual std::int32_t run() = 0;
  };

} // base::core

#endif // __TECHTASK_SOURCES_BASE_CORE_LAUNCHER_HPP__