cmake_minimum_required(VERSION 3.6)
project(Servidor)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

set(SOURCE_FILES main.cpp)
add_executable(tp main.cpp)

add_subdirectory(3rd_party/Box2D-cmake)
target_link_libraries(${PROJECT_NAME} tobanteGaming::Box2D)
