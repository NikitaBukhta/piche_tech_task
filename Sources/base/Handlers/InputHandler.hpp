#ifndef __TECHTASK_SOURCES_BASE_HANDLER_INPUTHANDLER_HPP__
#define __TECHTASK_SOURCES_BASE_HANDLER_INPUTHANDLER_HPP__

#include <windef.h>
#include <winuser.h>

namespace base::handlers {

  class InputHandler {
  public:
    virtual void hook() = 0;
    virtual void unhook() = 0;
  };

} // base::handlers

#endif // __TECHTASK_SOURCES_BASE_HANDLER_INPUTHANDLER_HPP__