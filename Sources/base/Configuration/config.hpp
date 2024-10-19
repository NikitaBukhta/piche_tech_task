#ifndef __TECHTASK_SOURCES_BASE_CONFIGURATION_CONFIG_HPP__
#define __TECHTASK_SOURCES_BASE_CONFIGURATION_CONFIG_HPP__

#define _INIT_LOGGER_NAME_ "file_logger_output"

#include <cinttypes>
namespace base::configuration::config {

const std::uint8_t ACTIVITY_PERIOD_MINUTES = 5;
const std::uint8_t SEC_IN_MIN = 60;
const std::uint16_t MS_IN_SEC = 1000;
constexpr std::uint32_t ACTIVITY_PERIOD_MS = MS_IN_SEC * SEC_IN_MIN * ACTIVITY_PERIOD_MINUTES;

} // base::configuration::config

#endif // __TECHTASK_SOURCES_BASE_CONFIGURATION_CONFIG_HPP__