#ifndef __TECHTASK_SOURCES_WIN_HANDLER_IMAGEMODIFIERSPECIFIC_HPP__
#define __TECHTASK_SOURCES_WIN_HANDLER_IMAGEMODIFIERSPECIFIC_HPP__

/**
 * @file ImageModifierSpecific.hpp
 * @author Mykyta Bukhta (nikita.bukhta.dev@gmail.com)
 * @brief Declaration of ImageModifierSpecific class. This class has specific
 * implemetation for WinOS. For more detail of class specialization refer to
 * base/Modifiers/ImageModifier.hpp.
 * @version 0.1
 * @date 2024-10-21
 *
 * @copyright Copyright (c) 2024
 *
 */

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

  /**
   * @brief convert bitmap to the img with specific file name and extension
   *
   * @param file_name - name and extension of file we need to create;
   * @param bitmap - information about img we need to create;
   */
  static void save_file(const std::wstring &file_name, Gdiplus::Bitmap &bitmap);

private:
  /**
   * @brief Get the mime type as wstring to further get clsid.
   * Used with get_encoder_clsid method;
   *
   * @param file - file name where we get the extension;
   * @return std::wstring - mine format as image/png and etc;
   */
  static std::wstring get_mime_type(const std::wstring &file);

  /**
   * @brief Get the encoder clsid object;
   *
   * @param format - mime type. Refer to get_mime_type method;
   * @param clsid - writable arg where we write the identified of file
   * extension;
   * @return int - if return -1, some errors was happened;
   */
  static int get_encoder_clsid(const std::wstring &format, CLSID &clsid);

private:
  std::unique_ptr<Gdiplus::Image> _image;
  std::unique_ptr<Gdiplus::Bitmap> _bitmap;
  ULONG_PTR gdiplusToken;
  std::wstring _opened_file_name;
};

} // namespace platform::modifiers

#endif // __TECHTASK_SOURCES_WIN_HANDLER_IMAGEMODIFIERSPECIFIC_HPP__