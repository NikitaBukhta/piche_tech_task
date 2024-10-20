#ifndef __TECHTASK_SOURCES_WIN_HANDLER_ACTIVITYHANDLERSPECIFIC_HPP__
#define __TECHTASK_SOURCES_WIN_HANDLER_ACTIVITYHANDLERSPECIFIC_HPP__

#include "Handlers/ActivityHandler.hpp"

#include <windef.h>
#include <mmsyscom.h>
#include <minwindef.h>

namespace platform::handlers {

  class ActivityHandlerSpecific : public base::handlers::ActivityHandler {
  public:
    ActivityHandlerSpecific(const ActivityHandlerSpecific& other) = delete;
    ActivityHandlerSpecific(ActivityHandlerSpecific&& other) = delete;

    ActivityHandlerSpecific& operator=(const ActivityHandlerSpecific& other) = delete;
    ActivityHandlerSpecific& operator=(ActivityHandlerSpecific&& other) = delete;

    static ActivityHandlerSpecific& instance();

  protected:
    void start_timer() override;
    void stop_timer() override;

  private:
    ActivityHandlerSpecific();
    static void CALLBACK on_user_inactive(UINT uID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2);

  private:
    MMRESULT _timer_id;
    bool _user_is_active;
  };

} // platform::handlers

#endif // __TECHTASK_SOURCES_WIN_HANDLER_ACTIVITYHANDLERSPECIFIC_HPP__