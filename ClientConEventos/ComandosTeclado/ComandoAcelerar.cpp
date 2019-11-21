//
// Created by diego on 22/10/19.
//

#include <iostream>
#include <SDL2/SDL_keycode.h>
#include "ComandoAcelerar.h"

void ComandoAcelerar::ejecutar() {
    if(estaApretado){
        servidor.ejecutarMovimiento("acelerar");
    }
}
