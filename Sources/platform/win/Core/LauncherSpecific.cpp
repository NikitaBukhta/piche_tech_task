#include "LauncherSpecific.hpp"

#include "Core/InputManagerSpecific.hpp"
#include "Core/UserActivityManager.hpp"
#include "Core/ScreenshotManager.hpp"

#include "EventHandler.hpp"

#include "logger.hpp"
#include "Configuration/config.hpp"

#include <memory>
#include <thread>

#include <objidl.h>   // to escape the error: 'PROPID' has not been declared when gdiplus.h is included;
#include <gdiplus.h>

namespace platform::core {

  std::int32_t LauncherSpecific::run() {
    DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_);

    init_gdi_plus();
    return Launcher::run();
  }

  void LauncherSpecific::init_gdi_plus() {
    DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
    LOG_INFO("called");

    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr);
  }

} // platform::handlers