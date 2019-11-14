cmake_minimum_required(VERSION 3.6)
project(client)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
find_package(Qt5Widgets)
include_directories(${PROJECT_BINARY_DIR})
link_directories(${PROJECT_SOURCE_DIR}/lib)

qt5_wrap_ui(UIS_HEADERS
        Ui/inicio.ui
        Ui/lobby.ui
        )




set(SOURCE_FILES main.cpp Hilo.h Juego/Pista.cpp Juego/Pista.h Vista/Visualizacion.cpp Vista/Visualizacion.h Comandos/AdministradorComandos.cpp Comandos/AdministradorComandos.h Comandos/Comando.h Comandos/ComandoAcelerar.cpp Comandos/ComandoAcelerar.h Comandos/ComandoFrenar.cpp Comandos/ComandoFrenar.h Sockets/ServidorProxy.cpp Sockets/ServidorProxy.h Comandos/ComandoIzquierda.cpp Comandos/ComandoIzquierda.h Comandos/ComandoDerecha.cpp Comandos/ComandoDerecha.h Lector/LectorTeclado.cpp Lector/LectorTeclado.h Excepciones/ExcepcionConPos.h Sdl/Ventana.cpp Sdl/Ventana.h Sdl/Renderizador.cpp Sdl/Renderizador.h Sdl/Textura.cpp Sdl/Textura.h Sdl/Posicion.cpp Sdl/Posicion.h Lector/HiloLector.cpp Lector/HiloLector.h Comandos/ComandoCerrar.cpp Comandos/ComandoCerrar.h Juego/Auto.cpp Juego/Auto.h Vista/Camara.cpp Vista/Camara.h Vista/HiloReceptor.cpp Vista/HiloReceptor.h Comandos/ComandoIniciarPartida.cpp Comandos/ComandoIniciarPartida.h Sockets/Protocolo.cpp Sockets/Protocolo.h Sockets/SocketAmigo.cpp Sockets/SocketAmigo.h Sockets/SocketPeerException.cpp Sockets/SocketPeerException.h Sockets/SocketException.cpp Sockets/SocketException.h Sockets/SocketActivo.cpp Sockets/SocketActivo.h Sockets/Utilidades.cpp Sockets/Utilidades.h Menu/Inicio.cpp Menu/Inicio.h Menu/Lobby.cpp Menu/Lobby.h Juego/Administrador.cpp Juego/Administrador.h Juego/Desplazable.h Juego/Desplazable.cpp Juego/Extra.cpp Juego/Extra.h Sdl/Sonido.cpp Sdl/Sonido.h)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
add_executable(client Ui/inicio.ui Ui/lobby.ui ${SOURCE_FILES})

find_package(TIFF)
if ( TIFF_FOUND )
    include_directories( ${TIFF_INCLUDE_DIRS} )
    target_link_libraries(client ${TIFF_LIBRARIES} )
endif( TIFF_FOUND )

target_link_libraries(client SDL2_ttf SDL2main SDL2_image SDL2 Qt5::Widgets SDL2_mixer)

#install(FILES assets/cat.gif DESTINATION ${CMAKE_BINARY_DIR})