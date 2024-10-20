#ifndef __TECHTASK_SOURCES_BASE_CORE_INPUTMANAGER_HPP__
#define __TECHTASK_SOURCES_BASE_CORE_INPUTMANAGER_HPP__

#include "Handlers/InputHandler.hpp"

#include <memory>
#include <vector>
namespace base::core {

class InputManager {
public:
  InputManager(std::weak_ptr<utils::EventHandler> event_handler);
  ~InputManager();

  virtual void run();
  virtual void stop();

private:
  std::vector<handlers::InputHandler *> _handlers;
};

} // namespace base::core

#endif // __TECHTASK_SOURCES_BASE_CORE_INPUTMANAGER_HPP__