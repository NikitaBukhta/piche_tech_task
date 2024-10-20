#ifndef __TECHTASK_SOURCES_UTILS_LOGGER_HPP__
#define __TECHTASK_SOURCES_UTILS_LOGGER_HPP__

#include "spdlog/spdlog.h"

#include <string>

// Макрос для объявления логгера в текущем скоупе
#ifndef DECLARE_TAG_SCOPE
#define DECLARE_TAG_SCOPE(domain) auto logger = spdlog::get(domain);
#endif // DECLARE_TAG_SCOPE

// Макросы для логирования с использованием VA_ARGS
#ifndef LOG_TRACE
#define LOG_TRACE(...) SPDLOG_LOGGER_TRACE(logger, __VA_ARGS__)
#endif // LOG_DEBUG

#ifndef LOG_DEBUG
#define LOG_DEBUG(...) SPDLOG_LOGGER_DEBUG(logger, __VA_ARGS__)
#endif // LOG_DEBUG

#ifndef LOG_INFO
#define LOG_INFO(...) SPDLOG_LOGGER_INFO(logger, __VA_ARGS__)
#endif // LOG_INFO

#ifndef LOG_WARNING
#define LOG_WARNING(...) SPDLOG_LOGGER_WARN(logger, __VA_ARGS__)
#endif // LOG_WARNING

#ifndef LOG_ERROR
#define LOG_ERROR(...) SPDLOG_LOGGER_ERROR(logger, __VA_ARGS__)
#endif // LOG_ERROR

#ifndef LOG_CRITICAL
#define LOG_CRITICAL(...) SPDLOG_LOGGER_CRITICAL(logger, __VA_ARGS__)
#endif // LOG_CRITICAL

namespace utils {

std::string to_string(const std::wstring &wstr);

}

#endif // __TECHTASK_SOURCES_UTILS_LOGGER_HPP__
