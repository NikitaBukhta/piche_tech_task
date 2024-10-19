#include "KeyboardInputHandler.hpp"

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

  KeyboardInputHandler::~KeyboardInputHandler() {
    unhook();
  }

  void KeyboardInputHandler::hook() {
    if (!_hook) {
      _hook = SetWindowsHookEx(WH_KEYBOARD_LL, handle_hook, NULL, 0);
    }
  }

  void KeyboardInputHandler::unhook() {
    UnhookWindowsHookEx(_hook);
    _hook = 0;
  }

  /*
   * PUBLIC section ENDS;
   */

   /*
    * PRIVATE section STARTS;
    */

  KeyboardInputHandler::KeyboardInputHandler() : _hook{ 0 } {
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

  KeyboardInputHandler& KeyboardInputHandler::instance() {
    static std::unique_ptr<KeyboardInputHandler> instance(new KeyboardInputHandler);

    return *instance;
  }

  /*
   * PUBLIC section ENDS;
   */

   /*
    * PRIVATE section STARTS;
    */

  LRESULT CALLBACK KeyboardInputHandler::handle_hook(int event_code, WPARAM w_param, LPARAM l_param) {
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