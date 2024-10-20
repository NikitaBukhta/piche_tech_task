#ifndef __TECHTASK_SOURCES_BASE_MODIFIERS_IMAGEMODIFIER_HPP__
#define __TECHTASK_SOURCES_BASE_MODIFIERS_IMAGEMODIFIER_HPP__

#include <cinttypes>
#include <string>

namespace base::modifiers {

class ImageModifier {
public:
  /**
   * @brief resize the image with specific size
   *
   * @param img_path - path to img
   * @param width - new width
   * @param height - new height
   * @param keep_ratio - should we keep ratio? If true, should be keept the
   * width or height where is min scale value;
   */
  virtual void update_img_path(const std::wstring &image_path) = 0;
  virtual void resize_image(const std::wstring img_path, std::int32_t width,
                            std::int32_t height, bool keep_ratio = false) = 0;
  virtual void make_grayout() = 0;
  virtual void save_file() = 0;
  virtual void save_file(const std::wstring &new_file_name) = 0;
};

} // namespace base::modifiers

#endif // __TECHTASK_SOURCES_BASE_MODIFIERS_IMAGEMODIFIER_HPP__