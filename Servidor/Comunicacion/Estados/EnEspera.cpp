//
// Created by manfer on 7/11/19.
//

#include "EnEspera.h"

EnEspera::EnEspera(size_t cantMaxima) : cantMaximaJugadores(cantMaxima),
    cantActualJugadores(0){

}

void EnEspera::sumarJugador() {
    std::unique_lock<std::mutex> lock(mutex);
    cantActualJugadores++;
    if (enJuego()){
        estaLLena.notify_all();
    }
}

void EnEspera::ejecutar() {
    std::unique_lock<std::mutex> lock(mutex);
    while (!enJuego()){
        estaLLena.wait(lock);
    }
}

bool EnEspera::enJuego() {
    return cantActualJugadores == cantMaximaJugadores;
}
