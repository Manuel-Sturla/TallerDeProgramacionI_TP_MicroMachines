//
// Created by diego on 24/10/19.
//

#include <iostream>
#include <SDL2/SDL_events.h>
#include "HiloLector.h"

HiloLector::HiloLector(ServidorProxy& servidor) : comandos(servidor){}

void HiloLector::run() {
    int comando = 0;
    comando = LectorTeclado::leer();
    while(comando != -1){
        comandos.ejecutar(comando);
        comando = LectorTeclado::leer();
    }
    comandos.cerrarPrograma();
}
