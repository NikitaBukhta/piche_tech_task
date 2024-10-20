#ifndef __TECHTASK_SOURCES_BASE_CORE_USERACTIVITYMANAGER_HPP__
#define __TECHTASK_SOURCES_BASE_CORE_USERACTIVITYMANAGER_HPP__

/**
 * @file UserActivityManager.hpp
 * @author Mykyta Bukhta (nikita.bukhta.dev@gmail.com)
 * @brief Declaration of UserActivityManager class. Used for initial and
 * starting all components are used for handling user activity;
 * @version 0.1
 * @date 2024-10-21
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Handlers/ActivityHandler.hpp"

#include <memory>
namespace base::core {

class UserActivityManager {
public:
  UserActivityManager(std::weak_ptr<utils::EventHandler> event_handler);

  /**
   * @brief start handling user activity;
   *
   */
  void run();

  /**
   * @brief stop handling user activity;
   *
   */
  void stop();

private:
  handlers::ActivityHandler *_activity_handler;
};

} // namespace base::core

#endif // __TECHTASK_SOURCES_BASE_CORE_USERACTIVITYMANAGER_HPP__