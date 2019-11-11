//
// Created by diego on 22/10/19.
//

#include "LectorTeclado.h"
#include <SDL2/SDL.h>
#include <iostream>

SDL_Keycode LectorTeclado::leer() {
    SDL_Event evento;
    SDL_WaitEvent(&evento);
    if(evento.type == SDL_QUIT){
        return -1;
    } else if(evento.type == SDL_KEYDOWN) {
        auto& keyEvent = (SDL_KeyboardEvent&) evento;
        return keyEvent.keysym.sym;
    }
    return 0;
}

LectorTeclado::LectorTeclado() {
    activo = true;
}
