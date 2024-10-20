#include "Core/InputManager.hpp"
#include "Core/UserActivityManager.hpp"
#include "Core/ScreenshotManager.hpp"

#include "Configuration/config.hpp"

#include "utils/EventHandler.hpp"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include "logger.hpp"

#include <thread>
#include <memory>
#include <string>

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

  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_);

  std::shared_ptr<utils::EventHandler> event_handler(new utils::EventHandler);

  // base::core::InputManager input_manager(event_handler);
  // base::core::UserActivityManager activity_manager(event_handler);
  base::core::ScreenshotManager screenshot_manager;
  // std::thread(&base::core::InputManager::run, &input_manager).join();
  // input_manager.run();
  // activity_manager.run();
  screenshot_manager.run();

  LOG_INFO("Close the program");
  
  MSG msg;
  while (GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  // input_manager.stop();

  return 0;
}