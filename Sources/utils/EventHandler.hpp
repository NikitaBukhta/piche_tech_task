#ifndef __TECHTASK_SOURCES_UTILS_EVENTHANDLER_HPP__
#define __TECHTASK_SOURCES_UTILS_EVENTHANDLER_HPP__

#include "ISubscriber.hpp"

#include <vector>
#include <unordered_map>

namespace utils {

class EventHandler {
public:
  void subscribe(ISubscriber* const subscriber, const std::vector<ISubscriber::Event>& events);
  void notify(ISubscriber::Event event);

private:
  std::unordered_map<ISubscriber::Event, std::vector<ISubscriber*>> _event_subs;
};

} // utils

#endif // __TECHTASK_SOURCES_UTILS_EVENTHANDLER_HPP__