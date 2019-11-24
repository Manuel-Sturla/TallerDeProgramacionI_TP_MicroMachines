cmake_minimum_required(VERSION 3.6)
project(client)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -pthread")
find_package(Lua REQUIRED)
add_subdirectory(yaml-cpp)
include_directories(${PROJECT_BINARY_DIR})
include_directories(${LUA_INCLUDE_DIR})
link_directories(${PROJECT_SOURCE_DIR}/lib)
qt5_wrap_ui(UIS_HEADERS
        Ui/inicio.ui
        Ui/lobby.ui
        )
set(SOURCE_FILES main.cpp Hilo.h Juego/Pista.cpp Juego/Pista.h Vista/Visualizacion.cpp Vista/Visualizacion.h ComandosTeclado/AdministradorComandosTeclado.cpp ComandosTeclado/AdministradorComandosTeclado.h ComandosTeclado/ComandoTeclado.h ComandosTeclado/ComandoAcelerar.cpp ComandosTeclado/ComandoAcelerar.h ComandosTeclado/ComandoFrenar.cpp ComandosTeclado/ComandoFrenar.h Sockets/ServidorProxy.cpp Sockets/ServidorProxy.h ComandosTeclado/ComandoIzquierda.cpp ComandosTeclado/ComandoIzquierda.h ComandosTeclado/ComandoDerecha.cpp ComandosTeclado/ComandoDerecha.h Lector/LectorTeclado.cpp Lector/LectorTeclado.h Excepciones/ExcepcionConPos.h Sdl/Ventana.cpp Sdl/Ventana.h Sdl/Renderizador.cpp Sdl/Renderizador.h Sdl/Textura.cpp Sdl/Textura.h Sdl/Posicion.cpp Sdl/Posicion.h Lector/HiloLector.cpp Lector/HiloLector.h Juego/Auto.cpp Juego/Auto.h Vista/Camara.cpp Vista/Camara.h Vista/HiloReceptor.cpp Vista/HiloReceptor.h Sockets/Protocolo.cpp Sockets/Protocolo.h Sockets/SocketAmigo.cpp Sockets/SocketAmigo.h Sockets/SocketPeerException.cpp Sockets/SocketPeerException.h Sockets/SocketException.cpp Sockets/SocketException.h Sockets/SocketActivo.cpp Sockets/SocketActivo.h Sockets/Utilidades.cpp Sockets/Utilidades.h Menu/Inicio.cpp Menu/Inicio.h Menu/Lobby.cpp Menu/Lobby.h Juego/Administrador.cpp Juego/Administrador.h Juego/Desplazable.h Juego/Desplazable.cpp Juego/Extra.cpp Juego/Extra.h Sdl/Sonido.cpp Sdl/Sonido.h ComandosVisualizacion/ComandoVisualizacion.h ComandosVisualizacion/ComandoMorir.cpp ComandosVisualizacion/ComandoMorir.h ComandosVisualizacion/ComandoPosicionarExtra.cpp ComandosVisualizacion/ComandoPosicionarExtra.h ComandosVisualizacion/ComandoPosicionarAuto.cpp ComandosVisualizacion/ComandoPosicionarAuto.h ComandosVisualizacion/ComandoEscribir.cpp ComandosVisualizacion/ComandoEscribir.h ComandosVisualizacion/ComandoEliminar.cpp ComandosVisualizacion/ComandoEliminar.h
        Jugador/Lua/InterpreteLua.cpp Jugador/Lua/InterpreteLua.h
        GrabadorVideo/BufferBloqueante.cpp
        GrabadorVideo/BufferBloqueante.h
        GrabadorVideo/Codec.cpp
        GrabadorVideo/Codec.h
        GrabadorVideo/ErrorFfmpeg.cpp
        GrabadorVideo/ErrorFfmpeg.h
        GrabadorVideo/Escalador.cpp
        GrabadorVideo/Escalador.h
        GrabadorVideo/Frame.cpp
        GrabadorVideo/Frame.h
        GrabadorVideo/GrabadorVideo.cpp
        GrabadorVideo/GrabadorVideo.h
        GrabadorVideo/HiloEscritor.cpp
        GrabadorVideo/HiloEscritor.h
        GrabadorVideo/VideoSalida.cpp
        GrabadorVideo/VideoSalida.h
        Jugador/Lua/ParametrosLua/CadenaLua.cpp Jugador/Lua/ParametrosLua/CadenaLua.h Jugador/Lua/ParametrosLua/EnteroLua.cpp Jugador/Lua/ParametrosLua/EnteroLua.h
        Jugador/Lua/ParametrosLua/FlotanteLua.cpp Jugador/Lua/ParametrosLua/FlotanteLua.h Jugador/Lua/ParametrosLua/ParametroLua.cpp Jugador/Lua/ParametrosLua/ParametroLua.h Jugador/Lua/ErrorLua.cpp Jugador/Lua/ErrorLua.h Jugador/JugadorReal.cpp Jugador/JugadorReal.h Jugador/JugadorCPU.cpp Jugador/JugadorCPU.h Jugador/Jugador.cpp Jugador/Jugador.h ComandosVisualizacion/ComandoGanador.cpp ComandosVisualizacion/ComandoGanador.h ComandosVisualizacion/ComandoActualizarVida.cpp ComandosVisualizacion/ComandoActualizarVida.h ComandosVisualizacion/ComandoPodio.cpp ComandosVisualizacion/ComandoPodio.h)
add_executable(client Ui/inicio.ui Ui/lobby.ui ${SOURCE_FILES})

target_link_libraries(client yaml-cpp SDL2_ttf SDL2main SDL2_image SDL2 Qt5::Widgets SDL2_mixer
        avformat avcodec avutil swscale
        lua5.3)

#install(FILES assets/cat.gif DESTINATION ${CMAKE_BINARY_DIR})
