//
// Created by diego on 24/10/19.
//

#include <iostream>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_timer.h>
#include "HiloLector.h"
#include "../Jugador/JugadorReal.h"

HiloLector::HiloLector(ServidorProxy &servidor, bool &keepTalking, std::shared_ptr<Jugador> &jugador,
                       int fpsRenderizacion, GrabadorVideo &grabador) :\
comandos(servidor, grabador), keepTalking(keepTalking), jugador(jugador), servidor(servidor), fpsRenderizacion(fpsRenderizacion) {}

void HiloLector::run() {
    while(keepTalking){
        if(jugador->obtenerComando(comandos) == -1){
            keepTalking = false;
        }
        comandos.ejecutar();
        SDL_Delay(1000/fpsRenderizacion);
    }
    servidor.terminarConexion();
}
