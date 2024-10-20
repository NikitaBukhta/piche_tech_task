#ifndef __TECHTASK_SOURCES_WIN_HANDLER_ACTIVITYHANDLERSPECIFIC_HPP__
#define __TECHTASK_SOURCES_WIN_HANDLER_ACTIVITYHANDLERSPECIFIC_HPP__

/**
 * @file ActivityHandlerSpecific.hpp
 * @author Mykyta Bukhta (nikita.bukhta.dev@gmail.com)
 * @brief Declaration of ScreenshotHandlerSpecific class. This class has
 * specific implemetation for WinOS. Current class is implemeneted
 * with Singleton pattern due to WinAPI callback function need to be static or
 * independed from the class. For more detail of class specialization
 * refer to base/Handlers/ActivityHandler.hpp.
 * @version 0.1
 * @date 2024-10-19
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Handlers/ActivityHandler.hpp"

#include <minwindef.h>
#include <mmsyscom.h>
#include <windef.h>

namespace platform::handlers {

class ActivityHandlerSpecific : public base::handlers::ActivityHandler {
public:
  ActivityHandlerSpecific(const ActivityHandlerSpecific &other) = delete;
  ActivityHandlerSpecific(ActivityHandlerSpecific &&other) = delete;

  ActivityHandlerSpecific &
  operator=(const ActivityHandlerSpecific &other) = delete;
  ActivityHandlerSpecific &operator=(ActivityHandlerSpecific &&other) = delete;

  static ActivityHandlerSpecific &instance();

protected:
  void start_timer() override;
  void stop_timer() override;

private:
  ActivityHandlerSpecific();

  /**
   * @brief set user inactivity state;
   *
   * @param uID
   * @param uMsg
   * @param dwUser
   * @param dw1
   * @param dw2
   */
  static void CALLBACK on_user_inactive(UINT uID, UINT uMsg, DWORD_PTR dwUser,
                                        DWORD_PTR dw1, DWORD_PTR dw2);

private:
  MMRESULT _timer_id;
  bool _user_is_active;
};

} // namespace platform::handlers

#endif // __TECHTASK_SOURCES_WIN_HANDLER_ACTIVITYHANDLERSPECIFIC_HPP__