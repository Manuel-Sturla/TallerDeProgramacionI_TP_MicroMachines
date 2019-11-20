#include "Velocidad.h"

Velocidad::Velocidad(float32 velocidadMaxima, float32 aceleracion) :
velocidadMaxima(velocidadMaxima), aceleracion(aceleracion){
}

bool Velocidad::alcanzoLaVelocidadMaxima(b2Vec2 velocidadActual) {
    return  (velocidadActual.Length()  + velocidadMaxima * aceleracion >= velocidadMaxima);
}

float32 Velocidad::darImpulso() {
    return velocidadMaxima * aceleracion;
}

void Velocidad::obtenerDatos(CarroDTO_t &dto) {
    dto.velocidadMax = velocidadMaxima;
}
