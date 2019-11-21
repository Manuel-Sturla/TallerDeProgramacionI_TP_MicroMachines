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

AdministradorComandosTeclado::AdministradorComandosTeclado(ServidorProxy &servidor) : \
estados(SDL_GetKeyboardState(nullptr)) {
    comandos[SDLK_UP] = new ComandoAcelerar(servidor, estados);
    comandos[SDLK_DOWN] = new ComandoFrenar(servidor, estados);
    comandos[SDLK_LEFT] = new ComandoIzquierda(servidor, estados);
    comandos[SDLK_RIGHT] = new ComandoDerecha(servidor, estados);
}

AdministradorComandosTeclado::~AdministradorComandosTeclado() {
    for(auto & comando : comandos){
        delete(comando.second);
    }
}

void AdministradorComandosTeclado::ejecutar() {
    for(auto & comando : comandos){
        comando.second->ejecutar();
    }
}

void AdministradorComandosTeclado::apretar(SDL_Keycode comando) {
    auto it = comandos.find(comando);
    if(it != comandos.end()){
        it->second->apretar();
    }
}

void AdministradorComandosTeclado::desapretar(SDL_Keycode comando) {
    auto it = comandos.find(comando);
    if(it != comandos.end()){
        it->second->desapretar();
    }
}
