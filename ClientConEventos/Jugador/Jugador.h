//
// Created by manfer on 14/11/19.
//

#ifndef CLIENT_JUGADOR_H
#define CLIENT_JUGADOR_H


#include "../Lector/LectorTeclado.h"

class Jugador {
    LectorTeclado lector;
protected:
    bool cpu = false;
public:
    int obtenerComando();
    bool esCpu();
};


#endif //CLIENT_JUGADOR_H
