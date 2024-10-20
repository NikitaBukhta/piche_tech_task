#ifndef __TECHTASK_SOURCES_BASE_HANDLER_SCREENSHOTHANDLER_HPP__
#define __TECHTASK_SOURCES_BASE_HANDLER_SCREENSHOTHANDLER_HPP__

#include <cinttypes>
#include <string>

namespace base::handlers {

  class ScreenshotHandler {
  public:
    virtual bool take_screenshot(std::int32_t monitor, const std::wstring& output_name) = 0;
  };

} // base::handlers

#endif // __TECHTASK_SOURCES_BASE_HANDLER_SCREENSHOTHANDLER_HPP__