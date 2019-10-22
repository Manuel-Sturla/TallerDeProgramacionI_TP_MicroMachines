cmake_minimum_required(VERSION 3.10)

project(PruebasLibrerias)

add_executable(prueba main.cpp)
add_subdirectory(BibliotecaEstatica lib)

target_link_libraries(prueba utilidades ${CMAKE_DL_LIBS})