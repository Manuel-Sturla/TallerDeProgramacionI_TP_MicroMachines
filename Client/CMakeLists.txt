cmake_minimum_required(VERSION 3.6)
project(OpenGLTest)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(SOURCE_FILES main.cpp Hilo.h Juego/Pista.cpp Juego/Pista.h Juego/Juego.cpp Juego/Juego.h Vista/HiloVisualizacion.cpp Vista/HiloVisualizacion.h Comandos/AdministradorComandos.cpp Comandos/AdministradorComandos.h Comandos/Comando.h Comandos/ComandoAcelerar.cpp Comandos/ComandoAcelerar.h Comandos/ComandoFrenar.cpp Comandos/ComandoFrenar.h Sockets/ServidorProxy.cpp Sockets/ServidorProxy.h Comandos/ComandoIzquierda.cpp Comandos/ComandoIzquierda.h Comandos/ComandoDerecha.cpp Comandos/ComandoDerecha.h Lector/LectorTeclado.cpp Lector/LectorTeclado.h Excepciones/ExcepcionConPos.h Sdl/Ventana.cpp Sdl/Ventana.h Sdl/Renderizador.cpp Sdl/Renderizador.h Sdl/Textura.cpp Sdl/Textura.h Sdl/Posicion.cpp Sdl/Posicion.h Juego/Partida.cpp Juego/Partida.h Lector/HiloLector.cpp Lector/HiloLector.h Comandos/ComandoCerrar.cpp Comandos/ComandoCerrar.h Juego/Auto.cpp Juego/Auto.h Vista/Camara.cpp Vista/Camara.h Vista/HiloReceptor.cpp Vista/HiloReceptor.h Comandos/ComandoIniciarPartida.cpp Comandos/ComandoIniciarPartida.h HiloMenu.cpp HiloMenu.h Sockets/Protocolo.cpp Sockets/Protocolo.h Sockets/SocketAmigo.cpp Sockets/SocketAmigo.h Sockets/SocketPeerException.cpp Sockets/SocketPeerException.h Sockets/SocketException.cpp Sockets/SocketException.h Sockets/SocketActivo.cpp Sockets/SocketActivo.h Sockets/Utilidades.cpp Sockets/Utilidades.h)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
add_executable(OpenGLTest ${SOURCE_FILES})

#pkg_search_module(SDL2 REQUIRED sdl2)
#pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

#inlude_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
#target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
target_link_libraries(OpenGLTest SDL2main SDL2_image SDL2)

install(FILES assets/cat.gif DESTINATION ${CMAKE_BINARY_DIR})