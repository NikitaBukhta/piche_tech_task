#ifndef __TECHTASK_SOURCES_BASE_CONFIGURATION_CONFIG_HPP__
#define __TECHTASK_SOURCES_BASE_CONFIGURATION_CONFIG_HPP__

/**
 * @file config.hpp
 * @author Mykyta Bukhta (nikita.bukhta.dev@gmail.com)
 * @brief contain all constant values used across all project;
 * @version 0.1
 * @date 2024-10-21
 *
 * @copyright Copyright (c) 2024
 *
 */

#define _INIT_LOGGER_NAME_ "file_logger_output"

#include <cinttypes>
#include <string>
namespace base::configuration::config {

const std::uint8_t ACTIVITY_PERIOD_MINUTES = 5;
const std::uint8_t SEC_IN_MIN = 60;
const std::uint16_t MS_IN_SEC = 1000;
const std::int32_t MODIFIED_NEW_IMG_WIDTH = 800;
const std::int32_t MODIFIED_NEW_IMG_HEIGHT = 600;
constexpr std::uint32_t ACTIVITY_PERIOD_MS =
    MS_IN_SEC * SEC_IN_MIN * ACTIVITY_PERIOD_MINUTES;

const wchar_t WEXTENSION_SEPARATOR = L'.';

const std::string LOG_FILE_NAME = "activity_logs.txt";
const std::wstring SCREENSHOT_COMMON_NAME = L"screenshot.bmp";
const std::wstring CONVERTED_IMAGE_NAME = L"output.bmp";

} // namespace base::configuration::config

#endif // __TECHTASK_SOURCES_BASE_CONFIGURATION_CONFIG_HPP__