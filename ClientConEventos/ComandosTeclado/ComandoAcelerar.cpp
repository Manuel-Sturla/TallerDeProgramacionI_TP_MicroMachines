//
// Created by diego on 22/10/19.
//

#include <iostream>
#include <SDL2/SDL_keycode.h>
#include "ComandoAcelerar.h"

void ComandoAcelerar::ejecutar() {
    if(estados[SDL_SCANCODE_UP]){
        std::cout<<"Acelere\n";
        servidor.ejecutarMovimiento("acelerar");
        std::cout<<"Deje de acelerar\n";
    }
}
