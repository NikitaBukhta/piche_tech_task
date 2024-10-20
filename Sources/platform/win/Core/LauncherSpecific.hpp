#ifndef __TECHTASK_SOURCES_WIN_CORE_LAUNCHERSPECIFIC_HPP__
#define __TECHTASK_SOURCES_WIN_CORE_LAUNCHERSPECIFIC_HPP__

#include "Core/Launcher.hpp"

namespace platform::core {

  class LauncherSpecific : public base::core::Launcher {
  public:
    std::int32_t run() override;

  private:
    void init_gdi_plus();
  };

} // platform::handlers

#endif // __TECHTASK_SOURCES_WIN_CORE_LAUNCHERSPECIFIC_HPP__