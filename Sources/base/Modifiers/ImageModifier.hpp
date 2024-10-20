#ifndef __TECHTASK_SOURCES_BASE_MODIFIERS_IMAGEMODIFIER_HPP__
#define __TECHTASK_SOURCES_BASE_MODIFIERS_IMAGEMODIFIER_HPP__

/**
 * @file ImageModifier.hpp
 * @author Mykyta Bukhta (nikita.bukhta.dev@gmail.com)
 * @brief Declaration of ImageModifier interface. Needed for manipulation with
 * images: their modification, resizing, color changing, saving, etc...
 * @version 0.1
 * @date 2024-10-21
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <cinttypes>
#include <string>

namespace base::modifiers {

class ImageModifier {
public:
  /**
   * @brief upload new img that should be modified;
   *
   * @param image_path - path to the new image;
   */
  virtual void update_img_path(const std::wstring &image_path) = 0;

  /**
   * @brief resize the image with specific size
   *
   * @param img_path - path to img
   * @param width - new width
   * @param height - new height
   * @param keep_ratio - should we keep ratio? If true, should be keept the
   * width or height where is min scale value;
   */
  virtual void resize_image(const std::wstring img_path, std::int32_t width,
                            std::int32_t height, bool keep_ratio = false) = 0;

  /**
   * @brief grayout modified img;s
   *
   */
  virtual void make_grayout() = 0;

  /**
   * @brief save modifications and replace the file;
   *
   */
  virtual void save_file() = 0;
  /**
   * @brief save modification with new file name;
   *
   * @param new_file_name - name of file where the changes should be written;
   */
  virtual void save_file(const std::wstring &new_file_name) = 0;
};

} // namespace base::modifiers

#endif // __TECHTASK_SOURCES_BASE_MODIFIERS_IMAGEMODIFIER_HPP__