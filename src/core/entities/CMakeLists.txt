add_library(
    entities
    Entity.cpp
    Entity.hpp
)

target_link_libraries(entities PUBLIC lib_core pugixml sfml-graphics)
