add_library(lib_core
      entityManager.cpp
      entityManager.hpp
      gameManager.cpp
      gameManager.hpp
      gameDatas.hpp
      gameEvents.cpp
      gameEvents.hpp
      inputManager.cpp
      inputManager.hpp
      SFMLOrthogonalLayer.h
      myMain.cpp
      myMain.h
)

add_subdirectory(entities)
add_subdirectory(behaviourVisitor)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/behaviourVisitor)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/entities)

target_include_directories(lib_core PUBLIC ./)
target_link_libraries(lib_core PUBLIC entities pugixml sfml-graphics sfml-window)
target_link_libraries(lib_core PRIVATE ImGui-SFML::ImGui-SFML)

target_compile_options(lib_core PRIVATE ${IMGUI_SFML_WARNINGS})
