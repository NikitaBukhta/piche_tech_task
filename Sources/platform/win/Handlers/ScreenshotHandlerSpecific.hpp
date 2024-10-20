#ifndef __TECHTASK_SOURCES_WIN_HANDLER_SCREENSHOTHANDLERSPECIFIC_HPP__
#define __TECHTASK_SOURCES_WIN_HANDLER_SCREENSHOTHANDLERSPECIFIC_HPP__

#include "Handlers/ScreenshotHandler.hpp"

#include <windef.h>

#include <string>
#include <cinttypes>

namespace platform::handlers {

  class ScreenshotHandlerSpecific : public base::handlers::ScreenshotHandler {
  public:
    ScreenshotHandlerSpecific();

    bool take_screenshot(std::int32_t monitor, const std::wstring& output_name) override;

  private:
    void save_bitmap_to_file(HBITMAP bitmap, const std::wstring& file_name);
  };

} // platform::handlers

#endif // __TECHTASK_SOURCES_WIN_HANDLER_SCREENSHOTHANDLERSPECIFIC_HPP__