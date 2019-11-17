cmake_minimum_required(VERSION 2.6)

project(ModBoost)
set(CMAKE_CXX_FLAGS -std=c++11)

add_library(Boost SHARED ModBoost.cpp
		../../../Objetos/Carro/Carro.cpp
		../../../Objetos/Carro/Carro.h)
set_target_properties(Boost PROPERTIES PUBLIC_HEADER ModBoost.h)
install(TARGETS Boost
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION lib)