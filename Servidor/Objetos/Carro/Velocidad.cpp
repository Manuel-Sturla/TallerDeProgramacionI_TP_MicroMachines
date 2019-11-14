#include "Velocidad.h"
#define  ACELERACION 0.2

Velocidad::Velocidad(float32 velocidadMaxima):
velocidadMaxima(velocidadMaxima){
}

bool Velocidad::alcanzoLaVelocidadMaxima(b2Vec2 velocidadActual) {
    return  (velocidadActual.Length()  + velocidadMaxima*ACELERACION >= velocidadMaxima);
}
