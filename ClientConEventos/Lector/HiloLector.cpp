//
// Created by diego on 24/10/19.
//

#include <iostream>
#include <SDL2/SDL_events.h>
#include "HiloLector.h"

HiloLector::HiloLector(ServidorProxy &servidor, bool &keepTalking) :\
comandos(servidor), keepTalking(keepTalking) {}

void HiloLector::run() {
    int comando = 0;
    comando = LectorTeclado::leer();
    while(comando != -1){
        comandos.ejecutar(comando);
        comando = LectorTeclado::leer();
    }
    keepTalking = false;
    comandos.cerrarPrograma();
}
