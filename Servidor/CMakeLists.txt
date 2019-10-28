cmake_minimum_required(VERSION 3.6)
project(Servidor)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_subdirectory(3rd_party/Box2D-cmake)

set(SOURCE_FILES main.cpp Pista.cpp Accion.cpp Frenar.cpp GiroAIzquierda.cpp
        GiroADerecha.cpp Acelerar.cpp Carro.cpp )

add_executable(tp main.cpp Pista.cpp Accion.cpp Acelerar.cpp Frenar.cpp
        GiroAIzquierda.cpp GiroADerecha.cpp
        Carro.cpp Recta.cpp ManejadorDeContactos.cpp Asfalto.cpp
        LimiteDePista.cpp Pasto.cpp)
target_link_libraries(tp tobanteGaming::Box2D)
