#include "ScreenshotHandlerSpecific.hpp"

#include "logger.hpp"
#include "Configuration/config.hpp"

#include <objidl.h>   // to escape the error: 'PROPID' has not been declared when gdiplus.h is included;
#include <windows.h>
#include <gdiplus.h>
#include <iostream>

namespace platform::handlers {

  void InitializeGDIPlus()
  {
    DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
    LOG_INFO("called");

    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr);
  }

  // Сохранение скриншота в файл
  void SaveBitmapToFile(HBITMAP hBitmap, const WCHAR* filePath)
  {
    DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
    LOG_INFO("called");

    Gdiplus::Bitmap bitmap(hBitmap, nullptr);
    CLSID pngClsid;
    CLSIDFromString(L"{557CF406-1A04-11D3-9A73-0000F81EF32E}", &pngClsid);
    bitmap.Save(filePath, &pngClsid, nullptr);
  }

  // Функция для захвата скриншота и сохранения его в файл
  void CaptureScreenAndSaveToFile(const WCHAR* filePath)
  {
    DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
    LOG_INFO("called");

    // Получаем размеры экрана
    int screenX = GetSystemMetrics(SM_CXSCREEN);
    int screenY = GetSystemMetrics(SM_CYSCREEN);

    // Получаем дескриптор окна рабочего стола
    HDC hScreenDC = GetDC(nullptr);
    HDC hMemoryDC = CreateCompatibleDC(hScreenDC);

    // Создаем совместимое с экраном изображение
    HBITMAP hBitmap = CreateCompatibleBitmap(hScreenDC, screenX, screenY);
    SelectObject(hMemoryDC, hBitmap);

    // Копируем данные с экрана в память
    BitBlt(hMemoryDC, 0, 0, screenX, screenY, hScreenDC, 0, 0, SRCCOPY);

    // Сохраняем изображение в файл
    SaveBitmapToFile(hBitmap, filePath);

    // Освобождаем ресурсы
    DeleteObject(hBitmap);
    DeleteDC(hMemoryDC);
    ReleaseDC(nullptr, hScreenDC);
  }

  ScreenshotHandlerSpecific::ScreenshotHandlerSpecific() {
    DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
    LOG_INFO("called");

    InitializeGDIPlus();
  }

  bool ScreenshotHandlerSpecific::take_screenshot(std::int32_t monitor, const std::wstring& output_name) {
    DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_)
    LOG_INFO("called");

    // Захват экрана и сохранение скриншота
    CaptureScreenAndSaveToFile(output_name.c_str());

    return true;
  }

} // platform::handlers