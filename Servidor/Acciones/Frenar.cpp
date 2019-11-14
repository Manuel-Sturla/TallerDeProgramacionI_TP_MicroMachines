#include "Frenar.h"
#include "../Objetos/Carro/EstadoVelocidad.h"

void Frenar::ejecutar(b2Body &body, EstadoVelocidad &estadoVelocidad, float32 angulo) {
    estadoVelocidad.frenar(body);
}
