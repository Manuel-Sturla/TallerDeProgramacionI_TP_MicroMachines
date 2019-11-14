//
// Created by manfer on 14/11/19.
//

#ifndef CLIENT_JUGADORCPU_H
#define CLIENT_JUGADORCPU_H


#include "Jugador.h"
#include "Lua/InterpreteLua.h"

class JugadorCPU: public Jugador {
    InterpreteLua interprete;
public:
    JugadorCPU(const std::string& rutaScript);
    int obtenerComando();
    void ponerMapa(std::vector<std::string> &comando);
};


#endif //CLIENT_JUGADORCPU_H
