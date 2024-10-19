#include "Core/InputManager.hpp"
#include "Core/UserActivityManager.hpp"

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

  auto file_sink = spdlog::basic_logger_mt(_INIT_LOGGER_NAME_, base::configuration::config::LOG_FILE_NAME);
  file_sink->set_pattern(log_pattern);

  DECLARE_TAG_SCOPE(_INIT_LOGGER_NAME_);
  LOG_INFO("logger inited");
}

int main(int argc, char** argv) {
  init_logger();

  std::shared_ptr<utils::EventHandler> event_handler(new utils::EventHandler);

  base::core::InputManager input_manager(event_handler);
  base::core::UserActivityManager activity_manager(event_handler);
  // std::thread(&base::core::InputManager::run, &input_manager).join();
  input_manager.run();
  activity_manager.run();


  MSG msg;
  while (GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  input_manager.stop();

  return 0;
}