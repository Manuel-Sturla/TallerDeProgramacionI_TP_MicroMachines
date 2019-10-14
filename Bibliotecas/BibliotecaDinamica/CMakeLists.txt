cmake_minimum_required(VERSION 2.6)

project(Mod)

add_library(PruebaMod SHARED PruebaMod.cpp)
set_target_properties(PruebaMod PROPERTIES PUBLIC_HEADER PruebaMod.h)
install(TARGETS PruebaMod
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION lib)