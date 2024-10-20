#ifndef __TECHTASK_SOURCES_WIN_HANDLER_MOUSEINPUTHANDLER_HPP__
#define __TECHTASK_SOURCES_WIN_HANDLER_MOUSEINPUTHANDLER_HPP__

/**
 * @file MouseInputHandler.hpp
 * @author Mykyta Bukhta (nikita.bukhta.dev@gmail.com)
 * @brief This class is created to handle any user mouse input and do some
 * action based on input. According to the specification, current behavior is
 * described as ouput the user input to the logs. Current class is implemeneted
 * with Singleton pattern due to WinAPI callback function need to be static or
 * independed from the class. To keep the OOP princeples and structures, this
 * pattern is used. For more detail of class specialization refer to
 * base/Handlers/InputHandler.hpp.
 * @version 0.1
 * @date 2024-10-19
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Handlers/InputHandler.hpp"

#include <cinttypes>
#include <windef.h>

namespace platform::handlers {

class MouseInputHandler : public base::handlers::InputHandler {
public:
  ~MouseInputHandler();
  MouseInputHandler(const MouseInputHandler &other) = delete;
  MouseInputHandler(MouseInputHandler &&other) = delete;

  MouseInputHandler &operator=(const MouseInputHandler &other) = delete;
  MouseInputHandler &operator=(MouseInputHandler &&other) = delete;

  void hook() override;
  void unhook() override;

  static MouseInputHandler &instance();

private:
  MouseInputHandler();

  /**
   * @brief handling any mouse input;
   *
   * @param ncode - should be handled or not;
   * @param w_param - event type;
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
  static LRESULT CALLBACK handle_hook(int ncode, WPARAM w_param,
                                      LPARAM l_param);

private:
  HHOOK _hook;
};

} // namespace platform::handlers

#endif // __TECHTASK_SOURCES_WIN_HANDLER_MOUSEINPUTHANDLER_HPP__