//
// Created by diego on 22/10/19.
//

#include <iostream>
#include <SDL2/SDL_events.h>
#include "AdministradorComandos.h"
#include "ComandoAcelerar.h"
#include "ComandoFrenar.h"
#include "ComandoIzquierda.h"
#include "ComandoDerecha.h"
#include "ComandoIniciarPartida.h"

AdministradorComandos::AdministradorComandos(ServidorProxy& servidor) : cerrar(servidor) {
    comandos.insert(std::pair<SDL_Keycode, Comando*>(SDLK_i, new ComandoIniciarPartida(servidor)));
    comandos.insert(std::pair<SDL_Keycode, Comando*>(SDLK_UP, new ComandoAcelerar(servidor)));
    comandos.insert(std::pair<SDL_Keycode, Comando*>(SDLK_DOWN, new ComandoFrenar(servidor)));
    comandos.insert(std::pair<SDL_Keycode, Comando*>(SDLK_LEFT, new ComandoIzquierda(servidor)));
    comandos.insert(std::pair<SDL_Keycode, Comando*>(SDLK_RIGHT, new ComandoDerecha(servidor)));
}

AdministradorComandos::~AdministradorComandos() {
    for(auto & comando : comandos){
        delete(comando.second);
    }
}

void AdministradorComandos::ejecutar(SDL_Keycode &comando) {
    auto it = comandos.find(comando);
    if(it != comandos.end()){
        it->second->ejecutar();
    }
}

void AdministradorComandos::cerrarPrograma() {
    cerrar.ejecutar();
}
