#include "LauncherSpecific.hpp"

#include "Core/InputManager.hpp"
#include "Core/UserActivityManager.hpp"
#include "Core/ScreenshotManager.hpp"

#include "EventHandler.hpp"
#include "ThreadPool.hpp"

#include "logger.hpp"
#include "Configuration/config.hpp"

#include <memory>
#include <thread>

namespace platform::core {

  std::int32_t LauncherSpecific::run() {
    DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_);

    std::shared_ptr<utils::EventHandler> event_handler(new utils::EventHandler);

    base::core::InputManager input_manager(event_handler);
    base::core::UserActivityManager activity_manager(event_handler);
    base::core::ScreenshotManager screenshot_manager;

    std::thread(base::core::InputManager::run, &input_manager).detach();
    std::thread(base::core::UserActivityManager::run, &activity_manager).detach();
    std::thread(base::core::ScreenshotManager::run, &screenshot_manager).detach();

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }

    LOG_INFO("Closing the program");

    input_manager.stop();
    activity_manager.stop();

    LOG_INFO("Closed finished");

    return 0;
  }

} // platform::handlers