//
// Created by manfer on 26/10/19.
//

#ifndef LUATEST_JUGADORCPU_H
#define LUATEST_JUGADORCPU_H


#include "InterpreteLua.h"

class JugadorCPU {
    InterpreteLua interprete;
public:
    JugadorCPU(const std::string& rutaScript); //Puede recibir el mapa, para recibirlo una vez.
    std::string obtenerAccion(); //recibe, posPropia, posAutosContrarios, posExtras.
};


#endif //LUATEST_JUGADORCPU_H
