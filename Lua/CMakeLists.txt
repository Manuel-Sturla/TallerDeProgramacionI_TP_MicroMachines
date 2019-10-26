cmake_minimum_required(VERSION 3.15)
project(LuaTest)

set(CMAKE_CXX_STANDARD 11)
include_directories(${LUA_INCLUDE_DIR})
find_package(Lua REQUIRED)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out)
add_executable(LuaTest
        main.cpp InterpreteLua.cpp InterpreteLua.h
        ErrorLua.cpp ErrorLua.h
        ParametrosLua/ParametroLua.cpp ParametrosLua/ParametroLua.h ParametrosLua/EnteroLua.cpp ParametrosLua/EnteroLua.h ParametrosLua/FlotanteLua.cpp ParametrosLua/FlotanteLua.h ParametrosLua/CadenaLua.cpp ParametrosLua/CadenaLua.h)
target_link_libraries(LuaTest lua5.3)
