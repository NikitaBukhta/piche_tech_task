#include "Core/InputManager.hpp"

#include <thread>

int main(int argc, char** argv) {
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