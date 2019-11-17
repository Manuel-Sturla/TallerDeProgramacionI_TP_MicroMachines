//
// Created by diego on 22/10/19.
//

#include <SDL2/SDL_scancode.h>
#include "ComandoDerecha.h"

void ComandoDerecha::ejecutar() {
    if(estados[SDL_SCANCODE_RIGHT]){
        servidor.ejecutarMovimiento("doblar derecha");
    }
}
