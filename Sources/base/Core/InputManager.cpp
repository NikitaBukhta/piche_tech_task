#include "InputManager.hpp"

#include "Handlers/KeyboardInputHandler.hpp"
#include "Handlers/MouseInputHandler.hpp"

#include "logger.hpp"
#include "Configuration/config.hpp"

namespace base::core {

  InputManager::InputManager() {
    DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
    LOG_INFO("called");

    _handlers.reserve(2);

    _handlers.emplace_back(&platform::handlers::KeyboardInputHandler::instance());
    _handlers.emplace_back(&platform::handlers::MouseInputHandler::instance());
  }

  InputManager::~InputManager() {
    DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
    LOG_INFO("called");

    stop();
  }

  void InputManager::run() {
    DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
    LOG_INFO("called");

    for (auto& it : _handlers) {
      it->hook();
    }
  }

  void InputManager::stop() {
    DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
    LOG_INFO("called");

    for (auto& it : _handlers) {
      it->unhook();
    }
  }

} // base::core