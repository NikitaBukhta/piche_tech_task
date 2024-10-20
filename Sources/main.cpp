/**
 * @file main.cpp
 * @author Mykyta Bukhta (nikita.bukhta.dev@domain.com)
 * @brief Init logger and start the launcher;
 * @version 0.1
 * @date 2024-10-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Core/LauncherSpecific.hpp"

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"

#include "Configuration/config.hpp"
#include "logger.hpp"

#include <memory>

void init_logger() {
  std::string log_pattern = "[%Y-%m-%d %H:%M:%S][%l][thread %t][%s][%!] %v";

  auto file_sink = spdlog::basic_logger_mt(
      _INIT_LOGGER_NAME_, base::configuration::config::LOG_FILE_NAME, true);
  file_sink->set_pattern(log_pattern);
  file_sink->set_level(spdlog::level::debug);
  file_sink->flush_on(spdlog::level::debug);

  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_);
  LOG_INFO("logger inited");
}

int main(int argc, char **argv) {
  init_logger();

  std::unique_ptr<base::core::Launcher> launcher(
      new platform::core::LauncherSpecific);
  return launcher->run();
}