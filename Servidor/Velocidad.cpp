//
// Created by manfer on 29/10/19.
//

#include "Velocidad.h"

Velocidad::Velocidad(float32 velocidadMaxima):
velocidadMaxima(velocidadMaxima){
}

bool Velocidad::alcanzoLaVelocidadMaxima(b2Vec2 velocidadActual) {
    return  (velocidadActual.Normalize() >= velocidadMaxima);
}
