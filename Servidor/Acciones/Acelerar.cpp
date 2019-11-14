#include "Acelerar.h"
#include "../Objetos/Carro/EstadoVelocidad.h"

void Acelerar::ejecutar(b2Body &body, EstadoVelocidad &estadoVelocidad, float32 angulo) {
    estadoVelocidad.acelerar(body);
}
