cmake_minimum_required(VERSION 3.6)
project(client)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
find_package(Qt5Widgets)
include_directories(${PROJECT_BINARY_DIR})
include_directories(${LUA_INCLUDE_DIR})
find_package(Lua REQUIRED)
link_directories(${PROJECT_SOURCE_DIR}/lib)
qt5_wrap_ui(UIS_HEADERS
        Ui/inicio.ui
        Ui/lobby.ui
        )




set(SOURCE_FILES main.cpp Hilo.h Juego/Pista.cpp Juego/Pista.h Vista/Visualizacion.cpp Vista/Visualizacion.h ComandosTeclado/AdministradorComandosTeclado.cpp ComandosTeclado/AdministradorComandosTeclado.h ComandosTeclado/ComandoTeclado.h ComandosTeclado/ComandoAcelerar.cpp ComandosTeclado/ComandoAcelerar.h ComandosTeclado/ComandoFrenar.cpp ComandosTeclado/ComandoFrenar.h Sockets/ServidorProxy.cpp Sockets/ServidorProxy.h ComandosTeclado/ComandoIzquierda.cpp ComandosTeclado/ComandoIzquierda.h ComandosTeclado/ComandoDerecha.cpp ComandosTeclado/ComandoDerecha.h Lector/LectorTeclado.cpp Lector/LectorTeclado.h Excepciones/ExcepcionConPos.h Sdl/Ventana.cpp Sdl/Ventana.h Sdl/Renderizador.cpp Sdl/Renderizador.h Sdl/Textura.cpp Sdl/Textura.h Sdl/Posicion.cpp Sdl/Posicion.h Lector/HiloLector.cpp Lector/HiloLector.h ComandosTeclado/ComandoCerrar.cpp ComandosTeclado/ComandoCerrar.h Juego/Auto.cpp Juego/Auto.h Vista/Camara.cpp Vista/Camara.h Vista/HiloReceptor.cpp Vista/HiloReceptor.h Sockets/Protocolo.cpp Sockets/Protocolo.h Sockets/SocketAmigo.cpp Sockets/SocketAmigo.h Sockets/SocketPeerException.cpp Sockets/SocketPeerException.h Sockets/SocketException.cpp Sockets/SocketException.h Sockets/SocketActivo.cpp Sockets/SocketActivo.h Sockets/Utilidades.cpp Sockets/Utilidades.h Menu/Inicio.cpp Menu/Inicio.h Menu/Lobby.cpp Menu/Lobby.h Juego/Administrador.cpp Juego/Administrador.h Juego/Desplazable.h Juego/Desplazable.cpp Juego/Extra.cpp Juego/Extra.h Sdl/Sonido.cpp Sdl/Sonido.h ComandosVisualizacion/ComandoVisualizacion.h ComandosVisualizacion/ComandoMorir.cpp ComandosVisualizacion/ComandoMorir.h ComandosVisualizacion/ComandoPosicionarExtra.cpp ComandosVisualizacion/ComandoPosicionarExtra.h ComandosVisualizacion/ComandoPosicionarAuto.cpp ComandosVisualizacion/ComandoPosicionarAuto.h ComandosVisualizacion/ComandoEscribir.cpp ComandosVisualizacion/ComandoEscribir.h ComandosVisualizacion/ComandoEliminar.cpp ComandosVisualizacion/ComandoEliminar.h
        Jugador/Lua/InterpreteLua.cpp Jugador/Lua/InterpreteLua.h
        Jugador/Lua/ParametrosLua/CadenaLua.cpp Jugador/Lua/ParametrosLua/CadenaLua.h Jugador/Lua/ParametrosLua/EnteroLua.cpp Jugador/Lua/ParametrosLua/EnteroLua.h
        Jugador/Lua/ParametrosLua/FlotanteLua.cpp Jugador/Lua/ParametrosLua/FlotanteLua.h Jugador/Lua/ParametrosLua/ParametroLua.cpp Jugador/Lua/ParametrosLua/ParametroLua.h Jugador/Lua/ErrorLua.cpp Jugador/Lua/ErrorLua.h Jugador/JugadorReal.cpp Jugador/JugadorReal.h Jugador/JugadorCPU.cpp Jugador/JugadorCPU.h Jugador/Jugador.cpp Jugador/Jugador.h ComandosVisualizacion/ComandoPodio.cpp ComandosVisualizacion/ComandoPodio.h)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
add_executable(client Ui/inicio.ui Ui/lobby.ui ${SOURCE_FILES})

find_package(TIFF)
if ( TIFF_FOUND )
    include_directories( ${TIFF_INCLUDE_DIRS} )
    target_link_libraries(client ${TIFF_LIBRARIES} )
endif( TIFF_FOUND )

target_link_libraries(client SDL2_ttf SDL2main SDL2_image SDL2 Qt5::Widgets SDL2_mixer lua5.3)

#install(FILES assets/cat.gif DESTINATION ${CMAKE_BINARY_DIR})