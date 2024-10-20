#include "ScreenshotHandlerSpecific.hpp"

#include "Modifiers/ImageModifierSpecific.hpp"

#include "Configuration/config.hpp"
#include "logger.hpp"

#include <gdiplus.h>
#include <iostream>
#include <objidl.h> // to escape the error: 'PROPID' has not been declared when gdiplus.h is included;
#include <vector>
#include <windows.h>

namespace platform::handlers {

ScreenshotHandlerSpecific::ScreenshotHandlerSpecific() {
  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
  LOG_INFO("called");
}

bool ScreenshotHandlerSpecific::take_screenshot(
    std::int32_t monitor, const std::wstring &output_name) {
  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
  LOG_INFO("called");

  int screen_x = GetSystemMetrics(SM_CXSCREEN);
  int screen_y = GetSystemMetrics(SM_CYSCREEN);

  HDC screen_dc = GetDC(nullptr);
  HDC memory_dc = CreateCompatibleDC(screen_dc);

  HBITMAP bitmap = CreateCompatibleBitmap(screen_dc, screen_x, screen_y);
  SelectObject(memory_dc, bitmap);

  // copy data from the screen into the virtual memory;
  BitBlt(memory_dc, 0, 0, screen_x, screen_y, screen_dc, 0, 0, SRCCOPY);

  save_bitmap_to_file(bitmap, output_name);

  // free descriptors and resources;
  DeleteObject(bitmap);
  DeleteDC(memory_dc);
  ReleaseDC(nullptr, screen_dc);

  return true;
}

void ScreenshotHandlerSpecific::save_bitmap_to_file(
    HBITMAP bitmap, const std::wstring &file_name) {
  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
  LOG_INFO("called");

  Gdiplus::Bitmap gdi_bitmap(bitmap, nullptr);
  modifiers::ImageModifierSpecific::save_file(file_name, gdi_bitmap);
}

} // namespace platform::handlers