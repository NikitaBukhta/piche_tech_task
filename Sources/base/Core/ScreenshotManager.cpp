#include "ScreenshotManager.hpp"

#include "Handlers/ScreenshotHandlerSpecific.hpp"

#include "logger.hpp"
#include "Configuration/config.hpp"
namespace base::core {

ScreenshotManager::ScreenshotManager() {
  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
  LOG_INFO("called");

  _screenshot_handler = std::make_unique<platform::handlers::ScreenshotHandlerSpecific>();
}

void ScreenshotManager::run() {
  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
  LOG_INFO("called");

  _screenshot_handler->take_screenshot(1, configuration::config::SCREENSHOT_COMMON_NAME);
}

} // base::core