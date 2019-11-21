//
// Created by diego on 22/10/19.
//

#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_events.h>
#include "ComandoFrenar.h"

void ComandoFrenar::ejecutar() {
    if(estaApretado){
        servidor.ejecutarMovimiento("frenar");
    }
}
