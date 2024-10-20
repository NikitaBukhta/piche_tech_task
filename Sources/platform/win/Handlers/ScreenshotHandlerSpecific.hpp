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
    void InitializeGDIPlus();
    void save_bitmap_to_file(HBITMAP hBitmap, const std::wstring& filePath);
    int get_encoder_clsid(const std::wstring& format, CLSID& clsid);
    std::wstring get_mime_type(const std::wstring& file);


    // /**
    //  * @brief make screen capture and save it into RAM;
    //  *
    //  * @param monitor - which screen we should to capture;
    //  * @return HBITMAP - screen capture;
    //  */
    // HBITMAP make_screenshot_vm(std::int32_t monitor);

    // /**
    //  * @brief 
    //  * 
    //  * @param virtual_bitmap 
    //  * @param output_name 
    //  */
    // bool convert_bitmap_into_file(HBITMAP virtual_bitmap, const std::wstring& output_name);

    // /**
    //  * @brief Get the encoder clsid (Class Identifier) object
    //  * 
    //  * @param format - img clsid format we are looking for;
    //  * @param ret_clsid - should store the clsid val. Writable arg;
    //  * 
    //  * @return int 
    //  *  0 - if codec was found
    //  *  -1 - some errors happened;
    //  */
    // int get_encoder_clsid(const std::wstring& format, CLSID& ret_clsid);

    // std::wstring get_mime_type(const std::wstring& file);
  };

} // platform::handlers

#endif // __TECHTASK_SOURCES_WIN_HANDLER_SCREENSHOTHANDLERSPECIFIC_HPP__