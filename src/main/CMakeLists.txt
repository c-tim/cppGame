add_executable(main
  main.cpp
)

target_link_libraries(main PUBLIC lib_core entities pugixml sfml-window sfml-graphics sfml-audio)

add_custom_target(copy-ressources ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/ressources)
add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/ressources
                   DEPENDS ${CMAKE_SOURCE_DIR}/ressources
                   COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
                           ${CMAKE_SOURCE_DIR}/ressources
                           ${CMAKE_CURRENT_BINARY_DIR}/ressources)
add_dependencies(main copy-ressources)
