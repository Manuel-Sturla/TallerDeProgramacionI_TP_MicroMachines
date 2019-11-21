cmake_minimum_required(VERSION 2.6)

project(ModBoost)
set(CMAKE_CXX_FLAGS -std=c++11)

add_library(Boost SHARED ModBoost.cpp
		../CarroDTO.h)
set_target_properties(Boost PROPERTIES PUBLIC_HEADER ModBoost.h)
install(TARGETS Boost
    LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/Lib
    PUBLIC_HEADER DESTINATION ${PROJECT_SOURCE_DIR}/Lib)