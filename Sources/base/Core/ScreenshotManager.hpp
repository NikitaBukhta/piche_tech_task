#ifndef __TECHTASK_SOURCES_BASE_CORE_SCREENSHOTMANAGER_HPP__
#define __TECHTASK_SOURCES_BASE_CORE_SCREENSHOTMANAGER_HPP__

#include "Handlers/ScreenshotHandler.hpp"
#include "Modifiers/ImageModifier.hpp"

#include <memory>

namespace base::core {

  class ScreenshotManager {
  public:
    ScreenshotManager();

    void run();
  
  private:
    std::unique_ptr<handlers::ScreenshotHandler> _screenshot_handler;
    std::unique_ptr<modifiers::ImageModifier> _image_modifier;
  };

} // base::core

#endif // __TECHTASK_SOURCES_BASE_CORE_SCREENSHOTMANAGER_HPP__