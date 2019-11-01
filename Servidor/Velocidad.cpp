#include "Velocidad.h"

Velocidad::Velocidad(float32 velocidadMaxima):
velocidadMaxima(velocidadMaxima){
}

bool Velocidad::alcanzoLaVelocidadMaxima(b2Vec2 velocidadActual) {
    return  (velocidadActual.Normalize() >= velocidadMaxima);
}
