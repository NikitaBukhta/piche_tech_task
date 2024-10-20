#ifndef __TECHTASK_SOURCES_BASE_HANDLER_SCREENSHOTHANDLER_HPP__
#define __TECHTASK_SOURCES_BASE_HANDLER_SCREENSHOTHANDLER_HPP__

/**
 * @file ScreenshotHandler.hpp
 * @author Mykyta Bukhta (nikita.bukhta.dev@gmail.com)
 * @brief Declaration of interface ScreenshotHandler. Main goal of interface is handling screen captures;
 * @version 0.1
 * @date 2024-10-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <cinttypes>
#include <string>

namespace base::handlers {

class ScreenshotHandler {
public:
  /**
   * @brief make screenshot of specific monitor.
   *
   * @param monitor - which monitor should be captured;
   * @param output_name - name of screenshot;
   * @return true - screenshot was made successfully;
   * @return false - screenshot wasn't made;
   */
  virtual bool take_screenshot(std::int32_t monitor,
                               const std::wstring &output_name) = 0;
};

} // namespace base::handlers

#endif // __TECHTASK_SOURCES_BASE_HANDLER_SCREENSHOTHANDLER_HPP__