cmake_minimum_required(VERSION 3.14)
project(Protocolo)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS -pthread)

include_directories(Socket)
add_executable(Protocolo main.cpp
        Socket/SocketPeerException.cpp
        Socket/SocketPeerException.h
        Socket/SocketPassiveException.cpp
        Socket/SocketPassiveException.h
        Socket/SocketActivo.cpp
        Socket/SocketActivo.h
        Socket/SocketAmigo.cpp
        Socket/SocketAmigo.h
        Socket/SocketPasivo.cpp
        Socket/SocketPasivo.h
        Socket/SocketException.cpp
        Socket/SocketException.h
        Protocolo.cpp
        Protocolo.h
        ClienteProxy.cpp
        ClienteProxy.h
        ServidorProxy.cpp
        ServidorProxy.h
        Utilidades.cpp
        Utilidades.h
        Hilos/Hilo.h Hilos/HiloCliente.cpp Hilos/HiloCliente.h Hilos/HiloServidor.cpp Hilos/HiloServidor.h Comandos/Comando.cpp Comandos/Comando.h Comandos/ElegirPartida.cpp Comandos/ElegirPartida.h Comandos/EnviarPosiciones.cpp Comandos/EnviarPosiciones.h Partida.cpp Partida.h Comandos/EnviarMapa.cpp Comandos/EnviarMapa.h Comandos/AgregarMovimiento.cpp Comandos/AgregarMovimiento.h)