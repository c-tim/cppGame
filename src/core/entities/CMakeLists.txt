add_library(
    entities
    Entity.cpp
    Entity.hpp
    Human.hpp
    Human.cpp
    Player.cpp
    Player.hpp
    crops.cpp
    crops.hpp
    entityState.hpp
    entityState.cpp
    animatedSprite.hpp
    animatedSprite.cpp
    ressourcesLoader.hpp
    ressourcesLoader.cpp

)

target_include_directories(entities PUBLIC ./)



target_link_libraries(entities PUBLIC lib_core visitor_lib pugixml sfml-graphics)
