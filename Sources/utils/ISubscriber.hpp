#ifndef __TECHTASK_SOURCES_UTILS_ISUBSCRIBER_HPP__
#define __TECHTASK_SOURCES_UTILS_ISUBSCRIBER_HPP__

#include <cinttypes>

namespace utils {

class ISubscriber {
public:
  enum class Event : std::int16_t {
    UserInteractionHandled
  };

public: 
  virtual void update(Event event) = 0;
};

} // utils

#endif // __TECHTASK_SOURCES_UTILS_ISUBSCRIBER_HPP__