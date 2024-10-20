#ifndef __TECHTASK_SOURCES_BASE_CORE_LAUNCHER_HPP__
#define __TECHTASK_SOURCES_BASE_CORE_LAUNCHER_HPP__

/**
 * @file Launcher.hpp
 * @author Mykyta Bukhta (nikita.bukhta.dev@gmail.com)
 * @brief Declaration of Launcher class. The heart of the app. Init all managers
 * and launch base logic of applications independed from the OS.
 * @version 0.1
 * @date 2024-10-21
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <cinttypes>

namespace base::core {

class Launcher {
public:
  /**
   * @brief start the app;
   *
   * @return std::int32_t - exit code;
   */
  virtual std::int32_t run();
};

} // namespace base::core

#endif // __TECHTASK_SOURCES_BASE_CORE_LAUNCHER_HPP__