#ifndef __TECHTASK_SOURCES_WIN_HANDLER_SCREENSHOTHANDLERSPECIFIC_HPP__
#define __TECHTASK_SOURCES_WIN_HANDLER_SCREENSHOTHANDLERSPECIFIC_HPP__

#include "Handlers/ScreenshotHandler.hpp"

#include <windef.h>

#include <cinttypes>
#include <string>

namespace platform::handlers {

class ScreenshotHandlerSpecific : public base::handlers::ScreenshotHandler {
public:
  ScreenshotHandlerSpecific();

  bool take_screenshot(std::int32_t monitor,
                       const std::wstring &output_name) override;

private:
  void save_bitmap_to_file(HBITMAP bitmap, const std::wstring &file_name);
};

} // namespace platform::handlers

#endif // __TECHTASK_SOURCES_WIN_HANDLER_SCREENSHOTHANDLERSPECIFIC_HPP__