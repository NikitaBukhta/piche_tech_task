#--------------------------- MAIN CONFIGURATION ---------------------------#

cmake_minimum_required(VERSION 3.10.0)
set(PROJECT_NAME app_tech_task_solution)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

set(BASE_FOLDER_NAME "base")
set(UTILITIES_FOLDER_NAME "utils")

if (WIN32)
  set(OS_FOLDER_NAME "platform/win")
endif (WIN32)

set(CPP_SOURCE_PATH "Sources")
set(CPP_SOURCES
  ${CPP_SOURCE_PATH}/main.cpp
  # ---- UTILITIES
  ${CPP_SOURCE_PATH}/${UTILITIES_FOLDER_NAME}/EventHandler.cpp
  ${CPP_SOURCE_PATH}/${UTILITIES_FOLDER_NAME}/logger.cpp
  # ---- BASE FILES
  ${CPP_SOURCE_PATH}/${BASE_FOLDER_NAME}/Core/InputManager.cpp
  ${CPP_SOURCE_PATH}/${BASE_FOLDER_NAME}/Core/ScreenshotManager.cpp
  ${CPP_SOURCE_PATH}/${BASE_FOLDER_NAME}/Core/UserActivityManager.cpp
  ${CPP_SOURCE_PATH}/${BASE_FOLDER_NAME}/Handlers/ActivityHandler.cpp
  ${CPP_SOURCE_PATH}/${BASE_FOLDER_NAME}/Handlers/InputHandler.cpp
  ${CPP_SOURCE_PATH}/${BASE_FOLDER_NAME}/Handlers/ScreenshotHandler.cpp
  ${CPP_SOURCE_PATH}/${BASE_FOLDER_NAME}/Modifiers/ImageModifier.cpp
  # ---- OS SPECIFIC
  ${CPP_SOURCE_PATH}/${OS_FOLDER_NAME}/Handlers/ActivityHandlerSpecific.cpp
  ${CPP_SOURCE_PATH}/${OS_FOLDER_NAME}/Handlers/KeyboardInputHandler.cpp
  ${CPP_SOURCE_PATH}/${OS_FOLDER_NAME}/Handlers/MouseInputHandler.cpp
  ${CPP_SOURCE_PATH}/${OS_FOLDER_NAME}/Handlers/ScreenshotHandlerSpecific.cpp
)

add_executable(
  ${PROJECT_NAME}
  ${CPP_SOURCES}
)

target_include_directories(
  ${PROJECT_NAME}
  PRIVATE
  ${CPP_SOURCE_PATH}/${BASE_FOLDER_NAME}/
  ${CPP_SOURCE_PATH}/${OS_FOLDER_NAME}/
  ${CPP_SOURCE_PATH}/${UTILITIES_FOLDER_NAME}/
)

#------------------------------ LINK SYSTEM DLL ------------------------------#

if (WIN32)
  target_link_libraries(${PROJECT_NAME} PRIVATE winmm gdiplus)
endif (WIN32)

#----------------------------- LINK THIRD PARTIES -----------------------------#

add_subdirectory(ThirdParty)

set(
  PRIVATE_LIBS
  spdlog::spdlog
)

target_link_libraries(
  ${PROJECT_NAME}
  PRIVATE
  ${PRIVATE_LIBS}
)