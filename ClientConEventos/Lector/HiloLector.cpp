//
// Created by diego on 24/10/19.
//

#include <iostream>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_timer.h>
#include "HiloLector.h"
#include "../Jugador/JugadorReal.h"

HiloLector::HiloLector(ServidorProxy &servidor, bool &keepTalking, std::shared_ptr<Jugador> &jugador) :\
comandos(servidor), keepTalking(keepTalking), jugador(jugador), servidor(servidor) {}

void HiloLector::run() {
    SDL_Event evento;
    while(keepTalking){
        while(SDL_PollEvent(&evento)){
            if(evento.type == SDL_QUIT){
                keepTalking = false;
            } else {
                comandos.ejecutar();

            }

        }
        SDL_Delay(20);
    }
    servidor.terminarConexion();
}
