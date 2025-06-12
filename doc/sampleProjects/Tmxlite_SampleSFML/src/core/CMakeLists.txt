add_library(lib_core
  SFMLOrthogonalLayer.h
  myMain.cpp
  myMain.h
)
target_include_directories(lib_core PUBLIC ./)
target_link_libraries(lib_core PUBLIC pugixml sfml-graphics)
