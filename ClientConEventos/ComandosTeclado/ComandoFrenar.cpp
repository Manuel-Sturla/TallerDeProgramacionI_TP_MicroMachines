//
// Created by diego on 22/10/19.
//

#include <SDL2/SDL_scancode.h>
#include "ComandoFrenar.h"

void ComandoFrenar::ejecutar() {
    if(estados[SDL_SCANCODE_DOWN]){
        servidor.ejecutarMovimiento("frenar");
    }
}
