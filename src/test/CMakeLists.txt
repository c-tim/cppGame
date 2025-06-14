#
# Lines inspired by https://google.github.io/googletest/quickstart-cmake.html
#

# Note: include(GoogleTest)and enable_testing() already done in top CMakeLists.txt

add_executable(unitTests
  unitTests.cpp
)
target_link_libraries(unitTests GTest::gtest_main lib_core lib_core pugixml sfml-window sfml-graphics sfml-audio)


# The next two lines enable CMake’s test runner to discover the tests included in the binary,
# using the GoogleTest CMake module.
include(GoogleTest)
gtest_discover_tests(unitTests)



add_custom_target(copy-ressources2 ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/ressources)
add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/ressources
                   DEPENDS ${CMAKE_SOURCE_DIR}/ressources
                   COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
                           ${CMAKE_SOURCE_DIR}/ressources
                           ${CMAKE_CURRENT_BINARY_DIR}/ressources)

add_dependencies(unitTests copy-ressources2)

