#include "InputManagerSpecific.hpp"

#include "logger.hpp"
#include "Configuration/config.hpp"

#include <processthreadsapi.h>

namespace platform::core {

  InputManagerSpecific::InputManagerSpecific(std::weak_ptr<utils::EventHandler> event_handler) : InputManager(event_handler) {}

  void InputManagerSpecific::run() {
    DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
    LOG_INFO("called");

    _main_manager_thread_id = GetCurrentThreadId();

    InputManager::run();

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
      if (msg.message == WM_QUIT) {
        LOG_INFO("Stopping the handle loop...");
        break;
      }

      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }
  }

  void InputManagerSpecific::stop() {
    DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
    LOG_INFO("called");

    PostThreadMessage(_main_manager_thread_id, WM_QUIT, 0, 0);

    InputManager::stop();
  }

} // platform::handlers