#include "EventHandler.hpp"

namespace utils {

void EventHandler::subscribe(ISubscriber *const subscriber,
                             const std::vector<ISubscriber::Event> &events) {
  std::lock_guard guard(_event_subs_mutex);
  for (auto event : events) {
    _event_subs[event].push_back(subscriber);
  }
}

void EventHandler::notify(ISubscriber::Event event) {
  std::lock_guard guard(_event_subs_mutex);

  auto &subs = _event_subs[event];
  for (auto &sub : subs) {
    sub->update(event);
  }
}

} // namespace utils