#include "Core/InputManager.hpp"

#include "Configuration/config.hpp"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include "logger.hpp"

#include <thread>

void init_logger() {
  auto console_logger = spdlog::stdout_color_mt(_INIT_LOGGER_NAME_);
  console_logger->set_pattern("[%Y-%m-%d %H:%M:%S][%l][thread %t][%s][%!] %v");
  spdlog::set_default_logger(console_logger);
  console_logger->set_level(spdlog::level::debug);
  
  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_);
  LOG_INFO("logger inited");
}

int main(int argc, char** argv) {
  init_logger();

  base::core::InputManager input_manager;
  // std::thread(&base::core::InputManager::run, &input_manager).join();
  input_manager.run();

  MSG msg;
  while (GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  input_manager.stop();

  return 0;
}