#ifndef __TECHTASK_SOURCES_WIN_CORE_INPUTMANAGERSPECIFIC_HPP__
#define __TECHTASK_SOURCES_WIN_CORE_INPUTMANAGERSPECIFIC_HPP__

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

} // platform::handlers

#endif // __TECHTASK_SOURCES_WIN_CORE_INPUTMANAGERSPECIFIC_HPP__