cmake_minimum_required(VERSION 3.6)
project(Servidor)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_subdirectory(3rd_party/Box2D-cmake)

set(SOURCE_FILES main.cpp  Servidor.cpp Planos/PlanoDePista.cpp Pista.cpp Acciones/Accion.cpp Acciones/Frenar.cpp Acciones/GiroAIzquierda.cpp
        Acciones/GiroADerecha.cpp Acciones/Acelerar.cpp Carro/Vida.cpp Modificadores/Modificador.cpp Modificadores/CajaDeSalud.cpp Carro/VelocidadBase.cpp
        Carro/VelocidadBoost.cpp Carro/EstadoVelocidad.cpp Suelos/Curva.cpp
        Modificadores/Boost.cpp Modificadores/Barro.cpp Modificadores/Aceite.cpp Carro/Visibilidad.cpp Carro/Agarre.cpp Partida.cpp
        Modificadores/Piedra.cpp Carro/Carro.cpp)

add_executable(tp main.cpp Servidor.cpp Planos/PlanoDePista.cpp Pista.cpp Acciones/Accion.cpp Acciones/Acelerar.cpp Acciones/Frenar.cpp
        Acciones/GiroAIzquierda.cpp Acciones/GiroADerecha.cpp Carro/Vida.cpp Modificadores/Modificador.cpp Modificadores/CajaDeSalud.cpp Modificadores/Piedra.cpp
        Carro/VelocidadBase.cpp Carro/VelocidadBoost.cpp Carro/EstadoVelocidad.cpp
        Modificadores/Boost.cpp Modificadores/Barro.cpp Modificadores/Aceite.cpp Carro/Visibilidad.cpp Carro/Agarre.cpp Suelos/Curva.cpp
        Carro/Carro.cpp Suelos/Recta.cpp ManejadorDeContactos.cpp Suelos/Asfalto.cpp Partida.cpp
        Suelos/LimiteDePista.cpp Suelos/Pasto.cpp Carro/Velocidad.cpp Planos/PlanoDeSuelo.h Planos/PlanoDeRecta.cpp Planos/PlanoDeRecta.h Planos/PlanoDeCurva.cpp Planos/PlanoDeCurva.h Mapa.cpp Mapa.h)
target_link_libraries(tp tobanteGaming::Box2D)
