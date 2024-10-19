#include "ActivityHandlerSpecific.hpp"

#include "logger.hpp"
#include "Configuration/config.hpp"

#include <mmsystem.h>
#include <memory>

namespace platform::handlers {
  ActivityHandlerSpecific::ActivityHandlerSpecific() {
    DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
    LOG_INFO("called");
  }

  ActivityHandlerSpecific& ActivityHandlerSpecific::instance() {
    DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
    LOG_TRACE("called");

    static std::unique_ptr<ActivityHandlerSpecific> instance(new ActivityHandlerSpecific);

    return *instance;
  }

  void CALLBACK ActivityHandlerSpecific::on_user_inactive(UINT uID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2) {
    DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
    LOG_INFO("called");
  }

  void ActivityHandlerSpecific::start_timer() {
    DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
    LOG_INFO("called");

    _timer_id = timeSetEvent(base::configuration::config::ACTIVITY_PERIOD_MS, 0, on_user_inactive, 0, TIME_ONESHOT);
  }

  void ActivityHandlerSpecific::stop_timer() {
    DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
    LOG_INFO("called");

    timeKillEvent(_timer_id);
  }

} // platform::handlers