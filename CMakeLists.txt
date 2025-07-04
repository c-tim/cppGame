cmake_minimum_required(VERSION 3.26)

include(FetchContent)
project(OutilVisualisation_CorrigeEtape6 VERSION 1.0.0 LANGUAGES CXX)

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

set(CMAKE_CXX_STANDARD 23)



#
# Tmxlite : A simple FetchContent does not work We generate its library
# in the same manner as GoogleTest
#

# Download and unpack tmxlite at configure time
set (TMXLITE_STATIC_LIB TRUE)
configure_file(CMakeLists_tmxlite.txt.in tmxlite-download/tmxlite/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/tmxlite-download/tmxlite )
if(result)
  message(FATAL_ERROR "CMake step for tmxlite failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/tmxlite-download/tmxlite )
if(result)
  message(FATAL_ERROR "Build step for tmxlite failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add tmxlite directly to our build. This defines tmxlite target
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/tmxlite-src/tmxlite
                 ${CMAKE_CURRENT_BINARY_DIR}/tmxlite-build/tmxlite
                 EXCLUDE_FROM_ALL)
include_directories("${CMAKE_CURRENT_BINARY_DIR}/tmxlite-src/tmxlite/include")

#----


FetchContent_Declare( pugixml
  URL https://github.com/zeux/pugixml/archive/refs/tags/v1.15.tar.gz
)
FetchContent_MakeAvailable(pugixml)

add_subdirectory(src/core)
add_subdirectory(src/main)


#
# Include GoogleTest
#
FetchContent_Declare( googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.16.0.tar.gz
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# enable_testing() must be in the source directory root (see cmake documentation at https://cmake.org/cmake/help/latest/command/enable_testing.html)
# Otherwise, Visual Studio test explorer does not see unit tests (See ticket https://developercommunity.visualstudio.com/t/No-tests-discovered-for-googletest-and-C/1148799#T-ND1150621)
include(GoogleTest)
enable_testing()
add_subdirectory(src/test)

FILE(COPY ressources DESTINATION "${CMAKE_BINARY_DIR}")

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
