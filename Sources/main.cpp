#include "Core/LauncherSpecific.hpp"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include "Configuration/config.hpp"
#include "logger.hpp"

void init_logger() {
  std::string log_pattern = "[%Y-%m-%d %H:%M:%S][%l][thread %t][%s][%!] %v";

  auto file_sink = spdlog::basic_logger_mt(_INIT_LOGGER_NAME_, base::configuration::config::LOG_FILE_NAME, true);
  file_sink->set_pattern(log_pattern);
  file_sink->set_level(spdlog::level::debug);
  file_sink->flush_on(spdlog::level::info);

  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_);
  LOG_INFO("logger inited");
}

int main(int argc, char** argv) {
  init_logger();

  platform::core::LauncherSpecific launcher;
  return launcher.run();
}