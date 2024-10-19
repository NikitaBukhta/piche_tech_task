#include "MouseInputHandler.hpp"

#include "logger.hpp"
#include "Configuration/config.hpp"

#include <winuser.h>
#include <memory>
#include <iostream>

namespace platform::handlers {

  /*
   * COMMON methods STARTS;
   */

   /*
    * PUBLIC section STARTS;
    */

  MouseInputHandler::~MouseInputHandler() {
    DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
    LOG_INFO("called");

    unhook();
  }

  void MouseInputHandler::hook() {
    DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
    LOG_INFO("called");
    
    if (!_hook) {
      _hook = SetWindowsHookEx(WH_MOUSE_LL, handle_hook, NULL, 0);

      if (!_hook) {
        LOG_ERROR("Cannot to set the hook");
      }
    } else {
      LOG_WARNING("hook is already existed");
    }
  }

  void MouseInputHandler::unhook() {
    DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
    LOG_INFO("called");

    UnhookWindowsHookEx(_hook);
    _hook = 0;
  }

  /*
   * PUBLIC section ENDS;
   */

   /*
    * PRIVATE section STARTS;
    */

  MouseInputHandler::MouseInputHandler() : _hook{ 0 } {
  }

  /*
   * PRIVATE section ENDS;
   */

   /*
    * COMMON methods ENDS;
    */

    /*
     * STATIC methods STARTS;
     */

     /*
      * PUBLIC section STARTS;
      */

  MouseInputHandler& MouseInputHandler::instance() {
    DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
    LOG_TRACE("called");

    static std::unique_ptr<MouseInputHandler> instance(new MouseInputHandler);

    return *instance;
  }

  /*
   * PUBLIC section ENDS;
   */

   /*
    * PRIVATE section STARTS;
    */

  LRESULT CALLBACK MouseInputHandler::handle_hook(int ncode, WPARAM w_param, LPARAM l_param) {
    DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
    
    if (ncode >= 0) {
      auto mouse_info = (MSLLHOOKSTRUCT*)l_param;
      if (mouse_info) {
        LOG_INFO("Mouse coords = ({}; {}), event {}", mouse_info->pt.x, mouse_info->pt.y, w_param);
      }
      else {
        LOG_ERROR("Mouse info could not be read");
      }
    }
    else {
      LOG_INFO("No info to read");
    }


    return CallNextHookEx(instance()._hook, ncode, w_param, l_param);
  }

  /*
   * PRIVATE section ENDS;
   */

   /*
    * STATIC methods ENDS;
    */

} // platform::handlers