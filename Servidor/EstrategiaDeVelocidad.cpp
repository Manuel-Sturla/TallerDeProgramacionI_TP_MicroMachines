//
// Created by manfer on 29/10/19.
//

#include "EstrategiaDeVelocidad.h"

EstrategiaDeVelocidad::EstrategiaDeVelocidad(float32 velocidadMaxima):
velocidadMaxima(velocidadMaxima){
}

bool EstrategiaDeVelocidad::alcanzoLaVelocidadMaxima(b2Vec2 velocidadActual) {
    return  (velocidadActual.Normalize() >= velocidadMaxima);
}
