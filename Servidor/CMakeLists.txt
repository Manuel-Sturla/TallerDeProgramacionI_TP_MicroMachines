cmake_minimum_required(VERSION 3.6)
project(Servidor)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_subdirectory(3rd_party/Box2D-cmake)

set(SOURCE_FILES main.cpp Comunicacion/Sockets/SocketPasivo.cpp Comunicacion/Sockets/SocketAmigo.cpp Servidor.cpp Planos/PlanoDePista.cpp Partida/Pista.cpp Acciones/Accion.cpp Acciones/Frenar.cpp Acciones/GiroAIzquierda.cpp
        Acciones/GiroADerecha.cpp Acciones/Acelerar.cpp Objetos/Carro/Vida.cpp Objetos/Modificadores/Modificador.cpp Objetos/Modificadores/CajaDeSalud.cpp Objetos/Carro/VelocidadBase.cpp
        Objetos/Carro/VelocidadBoost.cpp Objetos/Carro/EstadoVelocidad.cpp Objetos/Suelos/Curva.cpp
        Objetos/Modificadores/Boost.cpp Objetos/Modificadores/Barro.cpp Objetos/Modificadores/Aceite.cpp Objetos/Carro/Visibilidad.cpp Objetos/Carro/Agarre.cpp Partida/Partida.cpp
        Objetos/Modificadores/Piedra.cpp Objetos/Carro/Carro.cpp)

add_executable(tp main.cpp Comunicacion/ClienteProxy.cpp Comunicacion/Comandos/Comando.cpp Comunicacion/Comandos/ElegirPartida.cpp Comunicacion/Comandos/EnviarMapa.cpp Comunicacion/Comandos/EnviarPosiciones.cpp
        Comunicacion/Utilidades.cpp
        Comunicacion/Sockets/SocketPasivo.cpp Comunicacion/Protocolo.cpp Comunicacion/Sockets/SocketAmigo.cpp Comunicacion/Sockets/SocketPassiveException.cpp Comunicacion/Sockets/SocketPeerException.cpp Comunicacion/Sockets/SocketPassiveException.cpp Comunicacion/Sockets/SocketException.cpp Servidor.cpp Planos/PlanoDePista.cpp Partida/Pista.cpp Acciones/Accion.cpp Acciones/Acelerar.cpp Acciones/Frenar.cpp
        Acciones/GiroAIzquierda.cpp Acciones/GiroADerecha.cpp Objetos/Carro/Vida.cpp Objetos/Modificadores/Modificador.cpp Objetos/Modificadores/CajaDeSalud.cpp Objetos/Modificadores/Piedra.cpp
        Objetos/Carro/VelocidadBase.cpp Objetos/Carro/VelocidadBoost.cpp Objetos/Carro/EstadoVelocidad.cpp
        Objetos/Modificadores/Boost.cpp Objetos/Modificadores/Barro.cpp Objetos/Modificadores/Aceite.cpp Objetos/Carro/Visibilidad.cpp Objetos/Carro/Agarre.cpp Objetos/Suelos/Curva.cpp
        Objetos/Carro/Carro.cpp Objetos/Suelos/Recta.cpp Partida/ManejadorDeContactos.cpp Objetos/Suelos/Asfalto.cpp Partida/Partida.cpp
        Objetos/Suelos/LimiteDePista.cpp Objetos/Suelos/Pasto.cpp Objetos/Carro/Velocidad.cpp Planos/PlanoDeSuelo.h Planos/PlanoDeRecta.cpp Planos/PlanoDeRecta.h Planos/PlanoDeCurva.cpp Planos/PlanoDeCurva.h Partida/Mapa.cpp Partida/Mapa.h Objetos/Objeto.cpp Objetos/Suelos/Material.cpp)
target_link_libraries(tp tobanteGaming::Box2D)
