#include "KeyboardInputHandler.hpp"

#include "Configuration/config.hpp"
#include "logger.hpp"

#include <iostream>
#include <memory>
#include <winuser.h>

namespace platform::handlers {

/*
 * COMMON methods STARTS;
 */

/*
 * PUBLIC section STARTS;
 */

KeyboardInputHandler::~KeyboardInputHandler() {
  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
  LOG_INFO("called");

  unhook();
}

void KeyboardInputHandler::hook() {
  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
  LOG_INFO("called");

  if (!_hook) {
    _hook = SetWindowsHookEx(WH_KEYBOARD_LL, handle_hook, NULL, 0);
    if (!_hook) {
      LOG_ERROR("Cannot to set the hook");
    }
  } else {
    LOG_WARNING("hook is already existed");
  }
}

void KeyboardInputHandler::unhook() {
  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
  LOG_INFO("called");

  UnhookWindowsHookEx(_hook);
  _hook = 0;
}

/*
 * PUBLIC section ENDS;
 */

/*
 * PRIVATE section STARTS;
 */

KeyboardInputHandler::KeyboardInputHandler() : _hook{0} {
  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
  LOG_INFO("called");
}

/*
 * PRIVATE section ENDS;
 */

/*
 * COMMON methods ENDS;
 */

/*
 * STATIC methods STARTS;
 */

/*
 * PUBLIC section STARTS;
 */

KeyboardInputHandler &KeyboardInputHandler::instance() {
  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
  LOG_TRACE("called");

  static std::unique_ptr<KeyboardInputHandler> instance(
      new KeyboardInputHandler);

  return *instance;
}

/*
 * PUBLIC section ENDS;
 */

/*
 * PRIVATE section STARTS;
 */

LRESULT CALLBACK KeyboardInputHandler::handle_hook(int ncode, WPARAM w_param,
                                                   LPARAM l_param) {
  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)

  if (ncode >= 0) {
    auto key_info = (KBDLLHOOKSTRUCT *)l_param;
    if (key_info) {
      LOG_TRACE("Key code = {}; scan code = {}; key status = {}",
                key_info->vkCode, key_info->scanCode, w_param);
      instance()._event_handler->notify(
          utils::ISubscriber::Event::UserInteractionHandled);
    } else {
      LOG_ERROR("Key info could not be read");
    }
  } else {
    LOG_INFO("No info to read");
  }

  return CallNextHookEx(instance()._hook, ncode, w_param, l_param);
}

/*
 * PRIVATE section ENDS;
 */

/*
 * STATIC methods ENDS;
 */

} // namespace platform::handlers