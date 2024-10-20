#ifndef __TECHTASK_SOURCES_BASE_HANDLER_INPUTHANDLER_HPP__
#define __TECHTASK_SOURCES_BASE_HANDLER_INPUTHANDLER_HPP__

#include "EventHandler.hpp"

#include <windef.h>
#include <winuser.h>

#include <memory>

namespace base::handlers {

class InputHandler {
public:
  void set_event_handler(std::weak_ptr<utils::EventHandler> val);

  virtual void hook() = 0;
  virtual void unhook() = 0;

protected:
  std::shared_ptr<utils::EventHandler> _event_handler;
};

} // namespace base::handlers

#endif // __TECHTASK_SOURCES_BASE_HANDLER_INPUTHANDLER_HPP__