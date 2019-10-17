cmake_minimum_required(VERSION 3.15)
project(LuaTest)

set(CMAKE_CXX_STANDARD 11)
include_directories(${LUA_INCLUDE_DIR})
find_package(Lua REQUIRED)

add_executable(LuaTest
        main.cpp InterpreteLua.cpp InterpreteLua.h)
target_link_libraries(LuaTest lua5.3)