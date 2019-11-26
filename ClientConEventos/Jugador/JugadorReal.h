//
// Created by manfer on 14/11/19.
//

#ifndef CLIENT_JUGADORREAL_H
#define CLIENT_JUGADORREAL_H


#include "../Lector/LectorTeclado.h"
#include "Jugador.h"

class JugadorReal: public Jugador {
public:
    JugadorReal();
    int obtenerComando(AdministradorComandosTeclado &comandos) override;
};


#endif //CLIENT_JUGADORREAL_H
