#include "ImageModifierSpecific.hpp"

#include "logger.hpp"
#include "Configuration/config.hpp"

#include <cinttypes>
#include <cmath>

namespace platform::modifiers {

  ImageModifierSpecific::ImageModifierSpecific(const std::wstring& image_path) {
    update_img_path(image_path);
  }

  void ImageModifierSpecific::update_img_path(const std::wstring& image_path) {
    _image = std::make_unique<Gdiplus::Image>(image_path.c_str());

    _bitmap = std::make_unique<Gdiplus::Bitmap>(_image->GetWidth(), _image->GetHeight(), _image->GetPixelFormat());

    Gdiplus::Graphics graphics(_bitmap.get());
    graphics.DrawImage(_image.get(), 0, 0);
  }

  void ImageModifierSpecific::resize_image(const std::wstring img_path, std::int32_t width, std::int32_t height, bool keep_ratio) {
    std::uint32_t original_width = _image->GetWidth();
    std::uint32_t original_height = _image->GetHeight();
    std::uint32_t new_width = width;
    std::uint32_t new_height = height;

    if (keep_ratio) {
      float widthScale = static_cast<float>(width) / original_width;
      float heightScale = static_cast<float>(height) / original_height;
      float scale = std::min(widthScale, heightScale);

      new_width = static_cast<UINT>(original_width * scale);
      new_height = static_cast<UINT>(original_height * scale);
    }

    std::unique_ptr<Gdiplus::Bitmap> modified_bitmap(new Gdiplus::Bitmap(new_width, new_height, _bitmap->GetPixelFormat()));

    Gdiplus::Graphics graphics(modified_bitmap.get());
    graphics.SetInterpolationMode(Gdiplus::InterpolationModeHighQualityBicubic);
    graphics.DrawImage(_bitmap.get(), 0, 0, new_width, new_height);

    _bitmap.release();
    _bitmap = std::move(modified_bitmap);
  }

  void ImageModifierSpecific::make_grayout() {
    Gdiplus::ColorMatrix grayscale_matrix = {
        0.299f, 0.299f, 0.299f, 0, 0,
        0.587f, 0.587f, 0.587f, 0, 0,
        0.114f, 0.114f, 0.114f, 0, 0,
        0,      0,      0,      1, 0,
        0,      0,      0,      0, 1
    };

    Gdiplus::ImageAttributes img_attr;
    img_attr.SetColorMatrix(&grayscale_matrix, Gdiplus::ColorMatrixFlagsDefault, Gdiplus::ColorAdjustTypeBitmap);

    Gdiplus::Graphics graphics(_bitmap.get());
    Gdiplus::Rect rect(0, 0, _bitmap->GetWidth(), _bitmap->GetHeight());

    // Создаем временный bitmap для преобразования
    std::unique_ptr<Gdiplus::Bitmap> modified_bitmap(new Gdiplus::Bitmap(_bitmap->GetWidth(), _bitmap->GetHeight(), _bitmap->GetPixelFormat()));
    Gdiplus::Graphics modified_graphics(modified_bitmap.get());
    modified_graphics.DrawImage(_bitmap.get(), rect, 0, 0, _bitmap->GetWidth(), _bitmap->GetHeight(), Gdiplus::UnitPixel, &img_attr);

    _bitmap.release();
    _bitmap = std::move(modified_bitmap);
  }

  void ImageModifierSpecific::save_file() {
    save_file(_opened_file_name, *_bitmap);
  }

  void ImageModifierSpecific::save_file(const std::wstring& new_file_name) {
    save_file(new_file_name, *_bitmap);
  }

  void ImageModifierSpecific::save_file(const std::wstring& file_name, Gdiplus::Bitmap& bitmap) {
    DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)

    CLSID clsid;
    auto format = get_mime_type(file_name);
    if (get_encoder_clsid(format.c_str(), clsid) != -1)
    {
      bitmap.Save(file_name.c_str(), &clsid, nullptr);
    }
    else
    {
      LOG_ERROR("Impossible to find coder for the {} format", utils::to_string(format));
    }
  }

  std::wstring ImageModifierSpecific::get_mime_type(const std::wstring& file) {
    auto extension_index = file.find_last_of(base::configuration::config::WEXTENSION_SEPARATOR);
    return std::wstring{ L"image/" } + file.substr(extension_index + 1);
  }

  int ImageModifierSpecific::get_encoder_clsid(const std::wstring& format, CLSID& clsid)
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

} // platform::modifiers