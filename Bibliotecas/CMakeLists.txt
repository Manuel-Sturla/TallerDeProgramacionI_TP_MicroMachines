cmake_minimum_required(VERSION 3.10)
project(BibliotecasLocas)

set(CMAKE_CXX_STANDARD 11)

#include_directories(BibliotecaDinamica)
#include_directories(BibliotecaEstatica)  #Lo agrega para buscar fuentes


add_executable(Bibliotecas
        main.cpp LibreriaDinamica.cpp LibreriaDinamica.h ErrorLibreria.cpp ErrorLibreria.h)

add_subdirectory(BibliotecaEstatica) #dependencia del proyecto
add_subdirectory(BibliotecaDinamica)

target_link_libraries(Bibliotecas utilidades ${CMAKE_DL_LIBS})