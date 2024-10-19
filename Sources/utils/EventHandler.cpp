#include "EventHandler.hpp"

namespace utils {

  void EventHandler::subscribe(ISubscriber* const subscriber, const std::vector<ISubscriber::Event>& events) {
    for (auto event : events) {
      _event_subs[event].push_back(subscriber);
    }
  }

  void EventHandler::notify(ISubscriber::Event event) {
    auto& subs = _event_subs[event];

    for (auto& sub : subs) {
      sub->update(event);
    }
  }

} // utils