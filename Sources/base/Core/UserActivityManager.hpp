#ifndef __TECHTASK_SOURCES_BASE_CORE_USERACTIVITYMANAGER_HPP__
#define __TECHTASK_SOURCES_BASE_CORE_USERACTIVITYMANAGER_HPP__

#include "Handlers/ActivityHandler.hpp"

#include <memory>
namespace base::core {

  class UserActivityManager {
  public:
    UserActivityManager(std::weak_ptr<utils::EventHandler> event_handler);

    void run();

  private:
    handlers::ActivityHandler* _activity_handler;
  };

} // base::core

#endif // __TECHTASK_SOURCES_BASE_CORE_USERACTIVITYMANAGER_HPP__