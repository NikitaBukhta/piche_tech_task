#ifndef __TECHTASK_SOURCES_BASE_HANDLER_INPUTHANDLER_HPP__
#define __TECHTASK_SOURCES_BASE_HANDLER_INPUTHANDLER_HPP__

/**
 * @file InputHandler.hpp
 * @author Mykyta Bukhta (nikita.bukhta.dev@gmail.com)
 * @brief Declaration of interface InputHandler. Main goal of interface is
 * handling user inputes;
 * @version 0.1
 * @date 2024-10-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "EventHandler.hpp"

#include <windef.h>
#include <winuser.h>

#include <memory>

namespace base::handlers {

class InputHandler {
public:
  void set_event_handler(std::weak_ptr<utils::EventHandler> val);

  /**
   * @brief start handling some input events;
   *
   */
  virtual void hook() = 0;

  /**
   * @brief finished handling some input events;
   *
   */
  virtual void unhook() = 0;

protected:
  std::shared_ptr<utils::EventHandler> _event_handler;
};

} // namespace base::handlers

#endif // __TECHTASK_SOURCES_BASE_HANDLER_INPUTHANDLER_HPP__