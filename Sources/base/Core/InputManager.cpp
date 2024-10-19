#include "InputManager.hpp"

#include "Handlers/KeyboardInputHandler.hpp"
#include "Handlers/MouseInputHandler.hpp"

namespace base::core {

  InputManager::InputManager() {
    _handlers.reserve(2);

    _handlers.emplace_back(&platform::handlers::KeyboardInputHandler::instance());
    _handlers.emplace_back(&platform::handlers::MouseInputHandler::instance());
  }

  InputManager::~InputManager() {
    stop();
  }

  void InputManager::run() {
    for (auto& it : _handlers) {
      it->hook();
    }
  }

  void InputManager::stop() {
    for (auto& it : _handlers) {
      it->unhook();
    }
  }

} // base::core