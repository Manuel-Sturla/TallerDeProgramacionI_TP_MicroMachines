cmake_minimum_required(VERSION 2.6)

project(MicroMachines)

add_executable(tp main.cpp)

#Para crear librerias
#add_library(nombre fuentes.cpp)
#Para linkear librerias
#target_link_libraries(nombre libreria)
#Para agregar directorios (con sus respectivos cmakelists)
#add_subdirectory(carpeta)

#Para ejecutar siempre hay que /correr cmake <ruta_al_cmakelists> y te crea en 
#la carpeta actual todo lo necesario. Es conveniente no hacerlo en la misma.