#ifndef __TECHTASK_SOURCES_WIN_HANDLER_MOUSEINPUTHANDLER_HPP__
#define __TECHTASK_SOURCES_WIN_HANDLER_MOUSEINPUTHANDLER_HPP__

#include "Handlers/InputHandler.hpp"

#include <windef.h>
#include <cinttypes>

namespace platform::handlers {

  class MouseInputHandler : public base::handlers::InputHandler {
  public:
    ~MouseInputHandler();
    MouseInputHandler(const MouseInputHandler& other) = delete;
    MouseInputHandler(MouseInputHandler&& other) = delete;

    MouseInputHandler& operator=(const MouseInputHandler& other) = delete;
    MouseInputHandler& operator=(MouseInputHandler&& other) = delete;

    void hook() override;
    void unhook() override;

    static MouseInputHandler& instance();

  private:
    MouseInputHandler();
    
    static LRESULT CALLBACK handle_hook(int event_code, WPARAM w_param, LPARAM l_param);

  private:
    HHOOK _hook; 
  };

} // platform::handlers

#endif // __TECHTASK_SOURCES_WIN_HANDLER_MOUSEINPUTHANDLER_HPP__