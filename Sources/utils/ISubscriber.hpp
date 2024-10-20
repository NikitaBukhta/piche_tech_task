#ifndef __TECHTASK_SOURCES_UTILS_ISUBSCRIBER_HPP__
#define __TECHTASK_SOURCES_UTILS_ISUBSCRIBER_HPP__

/**
 * @file ISubscriber.hpp
 * @author Mykyta Bukhta (nikita.bukhta.dev@gmail.com)
 * @brief Declaration of ISuscriber interface. Need to make subscription to some
 * events;
 * @version 0.1
 * @date 2024-10-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <cinttypes>

namespace utils {

class ISubscriber {
public:
  enum class Event : std::int16_t { UserInteractionHandled };

public:
  /**
   * @brief there you can handle notification from subscriptions
   *
   * @param event - subscribed event what is handled;
   */
  virtual void update(Event event) = 0;
};

} // namespace utils

#endif // __TECHTASK_SOURCES_UTILS_ISUBSCRIBER_HPP__