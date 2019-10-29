//
// Created by manfer on 28/10/19.
//

#include "Carro.h"

Carro::Carro(float velocidad) :velMax(velocidad){
}

void Carro::actualizarVelocidadMax(float velocidad) {
    velMax = velocidad;
}

float Carro::obtenerVelicidadMax() {
    return velMax;
}
