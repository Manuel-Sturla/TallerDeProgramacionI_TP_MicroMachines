//
// Created by diego on 22/10/19.
//

#include <iostream>
#include <SDL2/SDL_keycode.h>
#include "ComandoAcelerar.h"

void ComandoAcelerar::ejecutar() {
    std::cout<<estados[SDL_SCANCODE_UP]<<'\n';
    if(estados[SDL_SCANCODE_UP]){
        servidor.ejecutarMovimiento("acelerar");
    }
}
