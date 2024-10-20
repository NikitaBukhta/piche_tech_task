#ifndef __TECHTASK_SOURCES_BASE_HANDLER_ACTIVITYHANDLER_HPP__
#define __TECHTASK_SOURCES_BASE_HANDLER_ACTIVITYHANDLER_HPP__

/**
 * @file ActivityHandler.hpp
 * @author Mykyta Bukhta (nikita.bukhta.dev@gmail.com)
 * @brief Declaration of ActivityHandler interface. Implemented for detecting
 * any user activity state and set its status. Could be usefull for traffic
 * safity in future.
 * @version 0.1
 * @date 2024-10-21
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "EventHandler.hpp"
#include "ISubscriber.hpp"

#include <memory>

namespace base::handlers {

class ActivityHandler : public utils::ISubscriber {
public:
  /**
   * @brief Set the event handler object
   *
   * @param val
   */
  void set_event_handler(std::weak_ptr<utils::EventHandler> val);

  /**
   * @brief finishing initializaiton of object's fields;
   *
   */
  void init();

  /**
   * @brief first run timer to detect user inactive state;
   *
   */
  void run();

  /**
   * @brief stop handling user activity and stop timers;
   *
   */
  void stop();

  void update(Event event) override;

protected:
  /**
   * @brief start timer to detect user inactivity state;
   *
   */
  virtual void start_timer() = 0;
  /**
   * @brief stop handling user activity state;
   *
   */
  virtual void stop_timer() = 0;

private:
  void on_user_interaction_handled();

private:
  std::shared_ptr<utils::EventHandler> _event_handler;
};

} // namespace base::handlers

#endif // __TECHTASK_SOURCES_BASE_HANDLER_ACTIVITYHANDLER_HPP__