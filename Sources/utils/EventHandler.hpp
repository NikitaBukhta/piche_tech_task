#ifndef __TECHTASK_SOURCES_UTILS_EVENTHANDLER_HPP__
#define __TECHTASK_SOURCES_UTILS_EVENTHANDLER_HPP__

/**
 * @file EventHandler.hpp
 * @author Mykyta Bukhta (nikita.bukhta.dev@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-10-21
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "ISubscriber.hpp"

#include <mutex>
#include <unordered_map>
#include <vector>

namespace utils {

class EventHandler {
public:
  /**
   * @brief subscribe object to the following events;
   *
   * @param subscriber - pointer to subscription object;
   * @param events - events we want to handle;
   */
  void subscribe(ISubscriber *const subscriber,
                 const std::vector<ISubscriber::Event> &events);

  /**
   * @brief notify all subs of some event trigger;
   *
   * @param event - event what was triggered;
   */
  void notify(ISubscriber::Event event);

private:
  std::unordered_map<ISubscriber::Event, std::vector<ISubscriber *>>
      _event_subs;
  std::mutex _event_subs_mutex;
};

} // namespace utils

#endif // __TECHTASK_SOURCES_UTILS_EVENTHANDLER_HPP__