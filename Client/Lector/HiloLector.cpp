//
// Created by diego on 24/10/19.
//

#include <iostream>
#include "HiloLector.h"

HiloLector::HiloLector(Servidor &servidor) : comandos(servidor){}

void HiloLector::run() {
    int comando = 0;
    comando = LectorTeclado::leer();
    while(comando != SDLK_x){
        comandos.ejecutar(comando);
        comando = LectorTeclado::leer();
    }
    comandos.ejecutar(comando);
}
