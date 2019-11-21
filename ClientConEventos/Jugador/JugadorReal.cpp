//
// Created by manfer on 14/11/19.
//

#include <SDL2/SDL_events.h>
#include "JugadorReal.h"

int JugadorReal::obtenerComando(AdministradorComandosTeclado &comandos) {
    SDL_Event evento;
    while(SDL_PollEvent(&evento)){
        if(evento.type == SDL_QUIT){
            return -1;
        } else if(evento.type == SDL_KEYDOWN) {
            auto& keyEvent = (SDL_KeyboardEvent&) evento;
            comandos.apretar(keyEvent.keysym.sym);
        } else if(evento.type == SDL_KEYUP){
            auto& keyEvent = (SDL_KeyboardEvent&) evento;
            comandos.desapretar(keyEvent.keysym.sym);
        }
    }
    return 0;
}

JugadorReal::JugadorReal(): Jugador(false) {
}
