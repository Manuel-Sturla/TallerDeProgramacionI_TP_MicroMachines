//
// Created by diego on 24/10/19.
//

#include <iostream>
#include <SDL2/SDL_events.h>
#include "HiloLector.h"
#include "../Jugador/JugadorReal.h"

HiloLector::HiloLector(ServidorProxy &servidor, bool &keepTalking, std::shared_ptr<Jugador> &jugador) :\
comandos(servidor), keepTalking(keepTalking), jugador(jugador) {}

void HiloLector::run() {
    int comando = 0;
    comando = jugador->obtenerComando();
    while(comando != -1){
        comandos.ejecutar(comando);
        comando = jugador->obtenerComando();
    }
    keepTalking = false;
    comandos.cerrarPrograma();
}
