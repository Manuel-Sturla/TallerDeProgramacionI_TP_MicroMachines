//
// Created by manfer on 14/11/19.
//

#ifndef CLIENT_JUGADORCPU_H
#define CLIENT_JUGADORCPU_H


#include "JugadorReal.h"
#include "Lua/InterpreteLua.h"
#include "Jugador.h"
#include "../Juego/Desplazable.h"

class JugadorCPU: public Jugador {
    InterpreteLua interprete;
    Desplazable* miAuto = nullptr;
public:
    JugadorCPU(const std::string& rutaScript);
    int obtenerComando() override ;
    void ponerAuto(Desplazable* unAuto);
    void ponerMapa(std::vector<std::string> &comando);
};


#endif //CLIENT_JUGADORCPU_H
