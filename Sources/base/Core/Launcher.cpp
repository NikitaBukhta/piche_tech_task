#include "Launcher.hpp"

#include "Core/InputManagerSpecific.hpp"
#include "Core/ScreenshotManager.hpp"
#include "Core/UserActivityManager.hpp"

#include "EventHandler.hpp"

#include "Configuration/config.hpp"
#include "logger.hpp"

#include <memory>
#include <thread>

namespace base::core {

std::int32_t Launcher::run() {
  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_);

  std::shared_ptr<utils::EventHandler> event_handler(new utils::EventHandler);

  platform::core::InputManagerSpecific input_manager(event_handler);
  base::core::UserActivityManager activity_manager(event_handler);
  base::core::ScreenshotManager screenshot_manager;

  std::thread input_thread(&base::core::InputManager::run, &input_manager);
  std::thread activity_thread(&base::core::UserActivityManager::run,
                              &activity_manager);
  std::thread screenshot_thread(&base::core::ScreenshotManager::run,
                                &screenshot_manager);

  LOG_INFO("Closing the program");

  while (true) {
  }; // TODO: tmp locker;

  input_manager.stop();
  activity_manager.stop();

  if (input_thread.joinable())
    input_thread.join();
  if (activity_thread.joinable())
    activity_thread.join();
  if (screenshot_thread.joinable())
    screenshot_thread.join();

  LOG_INFO("Closed finished");

  return 0;
}

} // namespace base::core