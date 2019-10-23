cmake_minimum_required(VERSION 3.6)
project(OpenGLTest)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(SOURCE_FILES main.cpp Juego/Juego.cpp Juego/Juego.h Juego/Partida.cpp Juego/Partida.h Comandos/AdministradorComandos.cpp Comandos/AdministradorComandos.h Comandos/Comando.h Comandos/ComandoAcelerar.cpp Comandos/ComandoAcelerar.h Comandos/ComandoFrenar.cpp Comandos/ComandoFrenar.h Servidor.cpp Servidor.h Comandos/ComandoIzquierda.cpp Comandos/ComandoIzquierda.h Comandos/ComandoDerecha.cpp Comandos/ComandoDerecha.h LectorTeclado.cpp LectorTeclado.h Excepciones/ExcepcionConPos.h Sdl/Ventana.cpp Sdl/Ventana.h Sdl/Renderizador.cpp Sdl/Renderizador.h Sdl/VectorDeTexturas.cpp Sdl/VectorDeTexturas.h Sdl/Textura.cpp Sdl/Textura.h)
add_executable(OpenGLTest ${SOURCE_FILES})

#pkg_search_module(SDL2 REQUIRED sdl2)
#pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

#inlude_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
#target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
target_link_libraries(OpenGLTest SDL2main SDL2_image SDL2)

install(FILES assets/cat.gif DESTINATION ${CMAKE_BINARY_DIR})