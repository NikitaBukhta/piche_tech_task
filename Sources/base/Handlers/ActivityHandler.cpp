#include "ActivityHandler.hpp"

#include "logger.hpp"
#include "Configuration/config.hpp"

namespace base::handlers {

  void ActivityHandler::set_event_handler(std::weak_ptr<utils::EventHandler> val) {
    _event_handler = val.lock();
  }

  void ActivityHandler::init() {
    _event_handler->subscribe(this, {
      utils::ISubscriber::Event::UserInteractionHandled
      });
  }

  void ActivityHandler::run() {
    start_timer();
  }

  void ActivityHandler::update(Event event) {
    DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
    LOG_INFO("event = {}", static_cast<std::int16_t>(event));

    switch (event) {
      case Event::UserInteractionHandled:
        on_user_interaction_handled();
        break;

      default:
        break;
    }
  }

  void ActivityHandler::on_user_interaction_handled() {
    DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
    LOG_DEBUG("called");

    stop_timer();
    start_timer();
  }
} // base::handlers