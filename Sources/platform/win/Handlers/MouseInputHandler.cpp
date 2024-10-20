#include "MouseInputHandler.hpp"

#include "Configuration/config.hpp"
#include "logger.hpp"

#include <iostream>
#include <memory>
#include <winuser.h>

namespace platform::handlers {

MouseInputHandler::~MouseInputHandler() {
  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
  LOG_INFO("called");

  unhook();
}

void MouseInputHandler::hook() {
  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
  LOG_INFO("called");

  if (!_hook) {
    _hook = SetWindowsHookEx(WH_MOUSE_LL, handle_hook, NULL, 0);

    if (!_hook) {
      LOG_ERROR("Cannot to set the hook");
    }
  } else {
    LOG_WARNING("hook is already existed");
  }
}

void MouseInputHandler::unhook() {
  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
  LOG_INFO("called");

  UnhookWindowsHookEx(_hook);
  _hook = 0;
}

MouseInputHandler::MouseInputHandler() : _hook{0} {}

MouseInputHandler &MouseInputHandler::instance() {
  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
  LOG_TRACE("called");

  static std::unique_ptr<MouseInputHandler> instance(new MouseInputHandler);

  return *instance;
}

LRESULT CALLBACK MouseInputHandler::handle_hook(int ncode, WPARAM w_param,
                                                LPARAM l_param) {
  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)

  if (ncode >= 0) {
    auto mouse_info = (MSLLHOOKSTRUCT *)l_param;
    if (mouse_info) {
      LOG_TRACE("Mouse coords = ({}; {}), event {}", mouse_info->pt.x,
                mouse_info->pt.y, w_param);
      instance()._event_handler->notify(
          utils::ISubscriber::Event::UserInteractionHandled);
    } else {
      LOG_ERROR("Mouse info could not be read");
    }
  } else {
    LOG_INFO("No info to read");
  }

  return CallNextHookEx(instance()._hook, ncode, w_param, l_param);
}

} // namespace platform::handlers