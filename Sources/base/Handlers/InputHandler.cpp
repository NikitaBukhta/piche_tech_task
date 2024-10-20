#include "InputHandler.hpp"

namespace base::handlers {

void InputHandler::set_event_handler(std::weak_ptr<utils::EventHandler> val) {
  _event_handler = val.lock();
}

} // namespace base::handlers