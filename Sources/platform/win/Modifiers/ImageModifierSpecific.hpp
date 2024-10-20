#ifndef __TECHTASK_SOURCES_WIN_HANDLER_IMAGEMODIFIERSPECIFIC_HPP__
#define __TECHTASK_SOURCES_WIN_HANDLER_IMAGEMODIFIERSPECIFIC_HPP__

#include "Modifiers/ImageModifier.hpp"

#include <gdiplus.h>
#include <objidl.h> // to escape the error: 'PROPID' has not been declared when gdiplus.h is included;
#include <windef.h>

#include <memory>
#include <string>

namespace platform::modifiers {

class ImageModifierSpecific : public base::modifiers::ImageModifier {
public:
  ImageModifierSpecific() = default;
  ImageModifierSpecific(const std::wstring &image_path);

  void update_img_path(const std::wstring &image_path) override;
  void resize_image(const std::wstring img_path, std::int32_t width,
                    std::int32_t height, bool keep_ratio = false) override;
  void make_grayout() override;
  void save_file() override;
  void save_file(const std::wstring &new_file_name) override;

  static void save_file(const std::wstring &file_name, Gdiplus::Bitmap &bitmap);

private:
  static std::wstring get_mime_type(const std::wstring &file);
  static int get_encoder_clsid(const std::wstring &format, CLSID &clsid);

private:
  std::unique_ptr<Gdiplus::Image> _image;
  std::unique_ptr<Gdiplus::Bitmap> _bitmap;
  ULONG_PTR gdiplusToken;
  std::wstring _opened_file_name;
};

} // namespace platform::modifiers

#endif // __TECHTASK_SOURCES_WIN_HANDLER_IMAGEMODIFIERSPECIFIC_HPP__