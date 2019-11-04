#include <iostream>
#include "GiroADerecha.h"
#include "../Objetos/Carro/EstadoVelocidad.h"

void GiroADerecha::ejecutar(b2Body *body, EstadoVelocidad *estadoVelocidad, float32 angulo) {
  float desiredAngularVelocity = - angulo * 60;
  float torque = body -> GetInertia() * desiredAngularVelocity * 60.0;
  body->ApplyTorque(torque, true);
}
