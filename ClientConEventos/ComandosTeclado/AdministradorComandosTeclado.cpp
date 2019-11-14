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
#include "ComandoIniciarPartida.h"

AdministradorComandosTeclado::AdministradorComandosTeclado(ServidorProxy& servidor) : cerrar(servidor) {
    comandos.insert(std::pair<SDL_Keycode, ComandoTeclado*>(SDLK_i, new ComandoIniciarPartida(servidor)));
    comandos.insert(std::pair<SDL_Keycode, ComandoTeclado*>(SDLK_UP, new ComandoAcelerar(servidor)));
    comandos.insert(std::pair<SDL_Keycode, ComandoTeclado*>(SDLK_DOWN, new ComandoFrenar(servidor)));
    comandos.insert(std::pair<SDL_Keycode, ComandoTeclado*>(SDLK_LEFT, new ComandoIzquierda(servidor)));
    comandos.insert(std::pair<SDL_Keycode, ComandoTeclado*>(SDLK_RIGHT, new ComandoDerecha(servidor)));
}

AdministradorComandosTeclado::~AdministradorComandosTeclado() {
    for(auto & comando : comandos){
        delete(comando.second);
    }
}

void AdministradorComandosTeclado::ejecutar(SDL_Keycode &comando) {
    auto it = comandos.find(comando);
    if(it != comandos.end()){
        it->second->ejecutar();
    }
}

void AdministradorComandosTeclado::cerrarPrograma() {
    cerrar.ejecutar();
}
