cmake_minimum_required(VERSION 3.6)
project(Servidor)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
link_directories(${PROJECT_SOURCE_DIR}/Servidor/lib)

set(SOURCE_FILES main.cpp)

target_link_libraries(lib/Box2D)
