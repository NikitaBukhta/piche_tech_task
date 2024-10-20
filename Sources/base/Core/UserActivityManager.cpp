#include "UserActivityManager.hpp"
#include "Handlers/ActivityHandlerSpecific.hpp"

#include "logger.hpp"
#include "Configuration/config.hpp"

namespace base::core {

  UserActivityManager::UserActivityManager(std::weak_ptr<utils::EventHandler> event_handler) {
    DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
    LOG_INFO("called");

    _activity_handler = &platform::handlers::ActivityHandlerSpecific::instance();
    _activity_handler->set_event_handler(event_handler);
    _activity_handler->init();
  }

  void UserActivityManager::run() {
    DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
    LOG_INFO("called");

    _activity_handler->run();
  }

  void UserActivityManager::stop() {
    _activity_handler->stop();
  }

} // base::core