//
// Created by diego on 22/10/19.
//

#include <iostream>
#include <SDL2/SDL_events.h>
#include "AdministradorComandosTeclado.h"
#include "ComandoAcelerar.h"
#include "ComandoFrenar.h"
#include "ComandoIzquierda.h"
#include "ComandoDerecha.h"
#include "../Lector/LectorTeclado.h"

AdministradorComandosTeclado::AdministradorComandosTeclado(ServidorProxy &servidor) : \
estados(SDL_GetKeyboardState(nullptr)) {
    comandos.emplace_back(new ComandoAcelerar(servidor, estados));
    comandos.emplace_back(new ComandoFrenar(servidor, estados));
    comandos.emplace_back(new ComandoIzquierda(servidor, estados));
    comandos.emplace_back(new ComandoDerecha(servidor, estados));
}

AdministradorComandosTeclado::~AdministradorComandosTeclado() {
    for(auto & comando : comandos){
        delete(comando);
    }
}

void AdministradorComandosTeclado::ejecutar() {
    for(auto & comando : comandos){
        comando->ejecutar();
    }
}
