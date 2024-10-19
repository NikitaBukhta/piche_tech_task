#ifndef __TECHTASK_SOURCES_BASE_HANDLER_ACTIVITYHANDLER_HPP__
#define __TECHTASK_SOURCES_BASE_HANDLER_ACTIVITYHANDLER_HPP__

#include "ISubscriber.hpp"
#include "EventHandler.hpp"

#include <memory>

namespace base::handlers {

  class ActivityHandler : public utils::ISubscriber {
  public:
    void set_event_handler(std::weak_ptr<utils::EventHandler> val);
    void init();
    void run();

    void update(Event event) override;

  protected:
    virtual void start_timer() = 0;
    virtual void stop_timer() = 0;

  private:
    void on_user_interaction_handled();

  private:
    std::shared_ptr<utils::EventHandler> _event_handler;
  };

} // base::handlers

#endif // __TECHTASK_SOURCES_BASE_HANDLER_ACTIVITYHANDLER_HPP__