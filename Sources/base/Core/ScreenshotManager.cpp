#include "ScreenshotManager.hpp"

#include "Handlers/ScreenshotHandlerSpecific.hpp"
#include "Modifiers/ImageModifierSpecific.hpp"

#include "Configuration/config.hpp"
#include "logger.hpp"
namespace base::core {

ScreenshotManager::ScreenshotManager() {
  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
  LOG_INFO("called");

  _screenshot_handler =
      std::make_unique<platform::handlers::ScreenshotHandlerSpecific>();
  _image_modifier =
      std::make_unique<platform::modifiers::ImageModifierSpecific>();
}

void ScreenshotManager::run() {
  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
  LOG_INFO("called");

  _screenshot_handler->take_screenshot(
      1, configuration::config::SCREENSHOT_COMMON_NAME);
  _image_modifier->update_img_path(
      configuration::config::SCREENSHOT_COMMON_NAME);
  _image_modifier->resize_image(configuration::config::SCREENSHOT_COMMON_NAME,
                                configuration::config::MODIFIED_NEW_IMG_WIDTH,
                                configuration::config::MODIFIED_NEW_IMG_HEIGHT,
                                true);
  _image_modifier->make_grayout();
  _image_modifier->save_file(configuration::config::CONVERTED_IMAGE_NAME);
}

} // namespace base::core