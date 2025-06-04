add_library(lib_core
      myMain.cpp
      myMain.h
      DrawingVersionUniquePtr.cpp
      SymbolDefinition.cpp
      SymbolDefinition.h
      SymbolReference.cpp
      SymbolReference.h
      symbols_and_intelligent_pointers.h
)
target_include_directories(lib_core PUBLIC ./)
target_link_libraries(lib_core PUBLIC pugixml sfml-graphics)

