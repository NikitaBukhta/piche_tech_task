#include "ScreenshotHandlerSpecific.hpp"

#include "logger.hpp"
#include "Configuration/config.hpp"

#include <objidl.h>   // to escape the error: 'PROPID' has not been declared when gdiplus.h is included;
#include <windows.h>
#include <gdiplus.h>
#include <iostream>
#include <vector>

namespace platform::handlers {

  ScreenshotHandlerSpecific::ScreenshotHandlerSpecific() {
    DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
    LOG_INFO("called");

    InitializeGDIPlus();
  }

  bool ScreenshotHandlerSpecific::take_screenshot(std::int32_t monitor, const std::wstring& output_name) {
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

  void ScreenshotHandlerSpecific::InitializeGDIPlus()
  {
    DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
    LOG_INFO("called");

    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr);
  }

  void ScreenshotHandlerSpecific::save_bitmap_to_file(HBITMAP bitmap, const std::wstring& filePath)
  {
    DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
    LOG_INFO("called");

    auto format = get_mime_type(filePath);

    CLSID clsid;
    if (get_encoder_clsid(format.c_str(), clsid) != -1)
    {
      Gdiplus::Bitmap gdi_bitmap(bitmap, nullptr);
      gdi_bitmap.Save(filePath.c_str(), &clsid, nullptr);
    }
    else
    {
      LOG_ERROR("Impossible to find coder for the {} format", utils::to_string(format));
    }
  }

  int ScreenshotHandlerSpecific::get_encoder_clsid(const std::wstring& format, CLSID& clsid)
  {
    UINT codecs_count = 0;
    UINT codecs_array_size = 0;
    Gdiplus::ImageCodecInfo* imager_codec_info = nullptr;

    Gdiplus::GetImageEncodersSize(&codecs_count, &codecs_array_size);

    if (codecs_array_size != 0) {
      std::vector<Gdiplus::ImageCodecInfo> imager_codec_info(codecs_array_size);
      Gdiplus::GetImageEncoders(codecs_count, codecs_array_size, imager_codec_info.data());

      for (auto& it : imager_codec_info) {
        if (wcscmp(it.MimeType, format.c_str()) == 0)
        {
          clsid = it.Clsid;
          return 0;
        }
      }
    }

    return -1;
  }

  std::wstring ScreenshotHandlerSpecific::get_mime_type(const std::wstring& file) {
    auto extension_index = file.find_last_of(base::configuration::config::WEXTENSION_SEPARATOR);
    return std::wstring{L"image/"} + file.substr(extension_index + 1);
  }

} // platform::handlers