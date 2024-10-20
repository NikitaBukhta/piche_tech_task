#include "InputManager.hpp"

#include "Handlers/KeyboardInputHandler.hpp"
#include "Handlers/MouseInputHandler.hpp"

#include "Configuration/config.hpp"
#include "logger.hpp"

namespace base::core {

InputManager::InputManager(std::weak_ptr<utils::EventHandler> event_handler) {
  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
  LOG_INFO("called");

  _handlers.reserve(2);

  _handlers.emplace_back(&platform::handlers::KeyboardInputHandler::instance());
  _handlers.emplace_back(&platform::handlers::MouseInputHandler::instance());

  for (auto &it : _handlers) {
    it->set_event_handler(event_handler);
  }
}

InputManager::~InputManager() {
  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
  LOG_INFO("called");

  stop();
}

void InputManager::run() {
  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
  LOG_INFO("called");

  for (auto &it : _handlers) {
    it->hook();
  }
}

void InputManager::stop() {
  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
  LOG_INFO("called");

  for (auto &it : _handlers) {
    it->unhook();
  }
}

} // namespace base::core