#include "MouseInputHandler.hpp"

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
    unhook();
  }

  void MouseInputHandler::hook() {
    if (!_hook) {
      _hook = SetWindowsHookEx(WH_MOUSE_LL, handle_hook, NULL, 0);
    }
  }

  void MouseInputHandler::unhook() {
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
    static std::unique_ptr<MouseInputHandler> instance(new MouseInputHandler);

    return *instance;
  }

  /*
   * PUBLIC section ENDS;
   */

   /*
    * PRIVATE section STARTS;
    */

  LRESULT CALLBACK MouseInputHandler::handle_hook(int event_code, WPARAM w_param, LPARAM l_param) {
    std::cout << __PRETTY_FUNCTION__ << " called" << std::endl;

    return CallNextHookEx(instance()._hook, event_code, w_param, l_param);
  }

  /*
   * PRIVATE section ENDS;
   */

   /*
    * STATIC methods ENDS;
    */

} // platform::handlers