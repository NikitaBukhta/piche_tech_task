#ifndef __TECHTASK_SOURCES_WIN_CORE_LAUNCHERSPECIFIC_HPP__
#define __TECHTASK_SOURCES_WIN_CORE_LAUNCHERSPECIFIC_HPP__

/**
 * @file LauncherSpecific.hpp
 * @author Mykyta Bukhta (nikita.bukhta.dev@gmail.com)
 * @brief Declaration of LauncherSpecific class. This class has
 * specific implemetation for WinOS. For more detail of class specialization
 * refer to base/Core/Launcher.hpp.
 * @version 0.1
 * @date 2024-10-21
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Core/Launcher.hpp"

namespace platform::core {

class LauncherSpecific : public base::core::Launcher {
public:
  std::int32_t run() override;

private:
  /**
   * @brief init gdi in startup for correct work with graphics and imgs;
   *
   */
  void init_gdi_plus();
};

} // namespace platform::core

#endif // __TECHTASK_SOURCES_WIN_CORE_LAUNCHERSPECIFIC_HPP__