cmake_minimum_required(VERSION 2.6)

project(ModBoost)

add_library(Boost SHARED ModBoost.cpp ../Carro.h ../Carro.cpp)
set_target_properties(Boost PROPERTIES PUBLIC_HEADER ModBoost.h)
install(TARGETS Boost
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION lib)