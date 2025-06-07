add_library(lib_core
      entityManager.cpp
      entityManager.hpp
      gameManager.cpp
      gameManager.hpp
      gameDatas.hpp
      myMain.cpp
      myMain.h
)

add_subdirectory(entities)

target_include_directories(lib_core PUBLIC ./)
target_link_libraries(lib_core PUBLIC entities pugixml sfml-graphics)

