#include <iostream>
#include "GiroAIzquierda.h"

void GiroAIzquierda::ejecutar(b2Body *body, EstadoVelocidad *estadoVelocidad, float32 angulo) {
  float desiredAngularVelocity = angulo * 60;
  float torque = body -> GetInertia() * desiredAngularVelocity * 60.0;
  body->ApplyTorque(torque, true);
}
