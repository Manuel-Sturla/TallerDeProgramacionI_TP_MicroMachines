//
// Created by diego on 22/10/19.
//

#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_events.h>
#include "ComandoIzquierda.h"

void ComandoIzquierda::ejecutar() {
    if(estaApretado){
        servidor.ejecutarMovimiento("doblar izquierda");
    }
}
