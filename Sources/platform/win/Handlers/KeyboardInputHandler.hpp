#ifndef __TECHTASK_SOURCES_WIN_HANDLER_KEYBOARDINPUTHANDLER_HPP__
#define __TECHTASK_SOURCES_WIN_HANDLER_KEYBOARDINPUTHANDLER_HPP__

/**
 * @file KeyboardInputHandler.hpp
 * @author Mykyta Bukhta (nikita.bukhta.dev@gmail.com)
 * @brief This class is created to handle any user keyboard input and do some action based on input.
 *  According to the specification, current behavior is described as ouput the user input to the logs.
 *  Current class is implemeneted with Singleton pattern due to WinAPI callback function need to be static
 * or independed from the class. To keep the OOP princeples and structures, this pattern is used.
 * @version 0.1
 * @date 2024-10-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Handlers/InputHandler.hpp"

#include <windef.h>
#include <cinttypes>

namespace platform::handlers {

  class KeyboardInputHandler : public base::handlers::InputHandler {
  public:
    ~KeyboardInputHandler();
    KeyboardInputHandler(const KeyboardInputHandler& other) = delete;
    KeyboardInputHandler(KeyboardInputHandler&& other) = delete;

    KeyboardInputHandler& operator=(const KeyboardInputHandler& other) = delete;
    KeyboardInputHandler& operator=(KeyboardInputHandler&& other) = delete;

    void hook() override;
    void unhook() override;

    static KeyboardInputHandler& instance();

  private:
    KeyboardInputHandler();

    static LRESULT CALLBACK handle_hook(int event_code, WPARAM w_param, LPARAM l_param);

  private:
    HHOOK _hook; 
  };

} // platform::handlers

#endif // __TECHTASK_SOURCES_WIN_HANDLER_KEYBOARDINPUTHANDLER_HPP__