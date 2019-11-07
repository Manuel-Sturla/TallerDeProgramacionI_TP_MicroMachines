cmake_minimum_required(VERSION 3.6)
project(Servidor)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
SET(CMAKE_CXX_FLAGS -pthread)

add_subdirectory(3rd_party/Box2D-cmake)

set(SOURCE_FILES main.cpp Comunicacion/Sockets/SocketPasivo.cpp Comunicacion/Sockets/SocketAmigo.cpp Servidor.cpp Planos/PlanoDePista.cpp Partida/MundoBox2D.cpp Acciones/Accion.cpp Acciones/Frenar.cpp Acciones/GiroAIzquierda.cpp
        Acciones/GiroADerecha.cpp Acciones/Acelerar.cpp Objetos/Carro/Vida.cpp Objetos/Modificadores/Modificador.cpp Objetos/Modificadores/CajaDeSalud.cpp Objetos/Carro/VelocidadBase.cpp
        Objetos/Carro/VelocidadBoost.cpp Objetos/Carro/EstadoVelocidad.cpp Objetos/Suelos/Curva.cpp
        Objetos/Modificadores/Boost.cpp Objetos/Modificadores/Barro.cpp Objetos/Modificadores/Aceite.cpp Objetos/Carro/Visibilidad.cpp Objetos/Carro/Agarre.cpp Partida/Partida.cpp
        Objetos/Modificadores/Piedra.cpp Objetos/Carro/Carro.cpp Hilo.h Planos/PlanoDeCarro.cpp Planos/PlanoDeCarro.h ConfiguracionServidor.cpp ConfiguracionServidor.h ServidorException.cpp ServidorException.h PartidaLlenaExcepcion.cpp PartidaLlenaExcepcion.h Comunicacion/Estados/EstadoCliente.cpp Comunicacion/Estados/EstadoCliente.h Comunicacion/Estados/EnMenu.cpp Comunicacion/Estados/EnMenu.h Comunicacion/Comandos/CrearPartida.cpp Comunicacion/Comandos/CrearPartida.h Comunicacion/Comandos/UnirAPartida.cpp Comunicacion/Comandos/UnirAPartida.h Comunicacion/Estados/EnJuego.cpp Comunicacion/Estados/EnJuego.h Comunicacion/Comandos/RecibirAccion.cpp Comunicacion/Comandos/RecibirAccion.h Comunicacion/HiloCliente.cpp Comunicacion/HiloCliente.h Comunicacion/Comandos/EnviarMapa.cpp Comunicacion/Comandos/EnviarMapa.h Comunicacion/Estados/EstadoPartida.cpp Comunicacion/Estados/EstadoPartida.h Comunicacion/Estados/EnEspera.cpp Comunicacion/Estados/EnEspera.h Comunicacion/HiloPartida.cpp Comunicacion/HiloPartida.h Comunicacion/Estados/EnCarrera.cpp Comunicacion/Estados/EnCarrera.h)

add_executable(tp ${SOURCE_FILES} main.cpp Comunicacion/ClienteProxy.cpp Comunicacion/Comandos/Comando.cpp
        Comunicacion/Utilidades.cpp
        Comunicacion/Sockets/SocketPasivo.cpp Comunicacion/Protocolo.cpp Comunicacion/Sockets/SocketAmigo.cpp Comunicacion/Sockets/SocketPassiveException.cpp Comunicacion/Sockets/SocketPeerException.cpp Comunicacion/Sockets/SocketPassiveException.cpp Comunicacion/Sockets/SocketException.cpp Servidor.cpp Planos/PlanoDePista.cpp Partida/MundoBox2D.cpp Acciones/Accion.cpp Acciones/Acelerar.cpp Acciones/Frenar.cpp
        Acciones/GiroAIzquierda.cpp Acciones/GiroADerecha.cpp Objetos/Carro/Vida.cpp Objetos/Modificadores/Modificador.cpp Objetos/Modificadores/CajaDeSalud.cpp Objetos/Modificadores/Piedra.cpp
        Objetos/Carro/VelocidadBase.cpp Objetos/Carro/VelocidadBoost.cpp Objetos/Carro/EstadoVelocidad.cpp
        Objetos/Modificadores/Boost.cpp Objetos/Modificadores/Barro.cpp Objetos/Modificadores/Aceite.cpp Objetos/Carro/Visibilidad.cpp Objetos/Carro/Agarre.cpp Objetos/Suelos/Curva.cpp
        Objetos/Carro/Carro.cpp Objetos/Suelos/Recta.cpp Partida/ManejadorDeContactos.cpp Objetos/Suelos/Asfalto.cpp Partida/Partida.cpp
        Objetos/Suelos/LimiteDePista.cpp Objetos/Suelos/Pasto.cpp Objetos/Carro/Velocidad.cpp Planos/PlanoDeSuelo.h Planos/PlanoDeRecta.cpp Planos/PlanoDeRecta.h Planos/PlanoDeCurva.cpp Planos/PlanoDeCurva.h Partida/Pista.cpp Partida/Pista.h Objetos/Objeto.cpp Objetos/Suelos/Material.cpp)
target_link_libraries(tp tobanteGaming::Box2D)
