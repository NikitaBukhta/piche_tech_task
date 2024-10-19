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
    
    /**
     * @brief
     *
     * @param ncode - should be handled or not
     * @param w_param - event type
     * @param l_param - memory address with information about
     * typedef struct tagMSLLHOOKSTRUCT {
     *  POINT pt;
     *  DWORD mouseData;
     *  DWORD flags;
     *  DWORD time; 
     *  ULONG_PTR dwExtraInfo;
     * };
     * @return LRESULT
     */
    static LRESULT CALLBACK handle_hook(int ncode, WPARAM w_param, LPARAM l_param);

  private:
    HHOOK _hook; 
  };

} // platform::handlers

#endif // __TECHTASK_SOURCES_WIN_HANDLER_MOUSEINPUTHANDLER_HPP__