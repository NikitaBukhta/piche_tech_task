#ifndef __TECHTASK_SOURCES_BASE_CORE_SCREENSHOTMANAGER_HPP__
#define __TECHTASK_SOURCES_BASE_CORE_SCREENSHOTMANAGER_HPP__

/**
 * @file ScreenshotManager.hpp
 * @author Mykyta Bukhta (nikita.bukhta.dev@gmail.com)
 * @brief Declaration of ScreenshotManager class. Used for initial and
 * starting all components are used for working with screenshots and images;
 * @version 0.1
 * @date 2024-10-21
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Handlers/ScreenshotHandler.hpp"
#include "Modifiers/ImageModifier.hpp"

#include <memory>

namespace base::core {

class ScreenshotManager {
public:
  ScreenshotManager();

  /**
   * @brief start making screenshots and modify them;
   *
   */
  void run();

private:
  std::unique_ptr<handlers::ScreenshotHandler> _screenshot_handler;
  std::unique_ptr<modifiers::ImageModifier> _image_modifier;
};

} // namespace base::core

#endif // __TECHTASK_SOURCES_BASE_CORE_SCREENSHOTMANAGER_HPP__