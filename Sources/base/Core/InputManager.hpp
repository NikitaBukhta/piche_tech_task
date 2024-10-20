#ifndef __TECHTASK_SOURCES_BASE_CORE_INPUTMANAGER_HPP__
#define __TECHTASK_SOURCES_BASE_CORE_INPUTMANAGER_HPP__

/**
 * @file InputManager.hpp
 * @author Mykyta Bukhta (nikita.bukhta.dev@gmail.com)
 * @brief Declaration of class InputManager. Handling all user inputs from the
 * peripheral devices;
 * @version 0.1
 * @date 2024-10-21
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Handlers/InputHandler.hpp"

#include <memory>
#include <vector>
namespace base::core {

class InputManager {
public:
  InputManager(std::weak_ptr<utils::EventHandler> event_handler);
  ~InputManager();

  /**
   * @brief start handling user input;
   *
   */
  virtual void run();

  /**
   * @brief stop handling user input;
   *
   */
  virtual void stop();

private:
  std::vector<handlers::InputHandler *> _handlers;
};

} // namespace base::core

#endif // __TECHTASK_SOURCES_BASE_CORE_INPUTMANAGER_HPP__