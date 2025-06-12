add_library(
    visitor_lib
    defaultVisitor.cpp
    defaultVisitor.hpp
)

target_include_directories(visitor_lib PUBLIC ./)



target_link_libraries(visitor_lib PUBLIC lib_core pugixml sfml-graphics)
