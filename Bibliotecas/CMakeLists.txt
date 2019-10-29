cmake_minimum_required(VERSION 3.10)
project(BibliotecasLocas)

set(CMAKE_CXX_STANDARD 11)

#include_directories(BibliotecaDinamica)
#include_directories(BibliotecaEstatica)  #Lo agrega para buscar fuentes

add_subdirectory(BibliotecaEstatica) #dependencia del proyecto
add_subdirectory(BibliotecaDinamica1)
add_subdirectory(BibliotecaDinamica2)

add_executable(Bibliotecas
        main.cpp
        BibliotecaDinamica.cpp BibliotecaDinamica.h
        ErrorBiblioteca.cpp ErrorBiblioteca.h
        Plugin.cpp Plugin.h Carro.cpp Carro.h ModAuto.cpp ModAuto.h)


target_link_libraries(Bibliotecas utilidades ${CMAKE_DL_LIBS})