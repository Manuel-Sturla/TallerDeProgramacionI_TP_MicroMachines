//
// Created by manfer on 14/11/19.
//

#ifndef CLIENT_JUGADOR_H
#define CLIENT_JUGADOR_H


#include "../ComandosTeclado/AdministradorComandosTeclado.h"

class Jugador {
    bool cpu;

public:
    explicit Jugador(bool cpu);
    virtual int obtenerComando(AdministradorComandosTeclado &comandos) = 0;
    bool esCpu();

};


#endif //CLIENT_JUGADOR_H
