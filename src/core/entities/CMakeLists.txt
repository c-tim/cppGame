add_library(
    entities
    Entity.cpp
    Entity.hpp
    Human.hpp
    Human.cpp
)

target_include_directories(entities PUBLIC ./)

target_link_libraries(entities PUBLIC lib_core pugixml sfml-graphics)
