#ifndef __TECHTASK_SOURCES_WIN_CORE_INPUTMANAGERSPECIFIC_HPP__
#define __TECHTASK_SOURCES_WIN_CORE_INPUTMANAGERSPECIFIC_HPP__

/**
 * @file InputManagerSpecific.hpp
 * @author Mykyta Bukhta (nikita.bukhta.dev@gmail.com)
 * @brief Declaration of InputManagerSpecific class. This class has
 * specific implemetation for WinOS. For more detail of class specialization
 * refer to base/Core/Launcher.hpp.
 * @version 0.1
 * @date 2024-10-21
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Core/InputManager.hpp"

#include <windef.h>

namespace platform::core {

class InputManagerSpecific : public base::core::InputManager {
public:
  InputManagerSpecific(std::weak_ptr<utils::EventHandler> event_handler);

  void run() override;
  void stop() override;

private:
  DWORD _main_manager_thread_id;
};

} // namespace platform::core

#endif // __TECHTASK_SOURCES_WIN_CORE_INPUTMANAGERSPECIFIC_HPP__