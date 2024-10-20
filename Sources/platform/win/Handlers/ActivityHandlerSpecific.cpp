#include "ActivityHandlerSpecific.hpp"

#include "Configuration/config.hpp"
#include "logger.hpp"

#include <memory>
#include <mmsystem.h>

namespace platform::handlers {
ActivityHandlerSpecific::ActivityHandlerSpecific() : _user_is_active{false} {
  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
  LOG_INFO("called");
}

ActivityHandlerSpecific &ActivityHandlerSpecific::instance() {
  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
  LOG_TRACE("called");

  static std::unique_ptr<ActivityHandlerSpecific> instance(
      new ActivityHandlerSpecific);

  return *instance;
}

void CALLBACK ActivityHandlerSpecific::on_user_inactive(UINT uID, UINT uMsg,
                                                        DWORD_PTR dwUser,
                                                        DWORD_PTR dw1,
                                                        DWORD_PTR dw2) {
  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
  LOG_INFO("called");

  instance()._user_is_active = false;
}

void ActivityHandlerSpecific::start_timer() {
  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
  LOG_TRACE("called");

  _timer_id = timeSetEvent(base::configuration::config::ACTIVITY_PERIOD_MS, 0,
                           on_user_inactive, 0, TIME_ONESHOT);

  if (!_user_is_active) {
    LOG_INFO("user is active again!");
    _user_is_active = true;
  }
}

void ActivityHandlerSpecific::stop_timer() {
  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
  LOG_TRACE("called");

  timeKillEvent(_timer_id);
}

} // namespace platform::handlers