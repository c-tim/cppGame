cmake_minimum_required(VERSION 3.26)

include(FetchContent)
project(JIN4_SampleSFML VERSION 1.0.0 LANGUAGES CXX)

if(WIN32)
  # SonarLint support for CMake requires the following flag to be set on.
  #(see https://community.sonarsource.com/t/sonarlint-for-visual-studio-v4-38-support-cmake-projects/50127)
  set (CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()

set (BUILD_SHARED_LIBS FALSE)

FetchContent_Declare( sfml
  URL https://github.com/SFML/SFML/archive/refs/tags/3.0.1.tar.gz
)
option(SFML_BUILD_AUDIO "Build audio" OFF)
option(SFML_BUILD_NETWORK "Build network" OFF)
FetchContent_MakeAvailable(sfml)

FetchContent_Declare( imgui
  URL https://github.com/ocornut/imgui/archive/refs/tags/v1.91.9.tar.gz
)
FetchContent_MakeAvailable(imgui)

FetchContent_Declare( imgui-sfml
  URL https://github.com/SFML/imgui-sfml/archive/refs/tags/v3.0.tar.gz
)
set(IMGUI_DIR ${imgui_SOURCE_DIR})
option(IMGUI_SFML_FIND_SFML "Use find_package to find SFML" OFF)
option(IMGUI_SFML_IMGUI_DEMO "Build imgui_demo.cpp" OFF)
FetchContent_MakeAvailable(imgui-sfml)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(src/main)

