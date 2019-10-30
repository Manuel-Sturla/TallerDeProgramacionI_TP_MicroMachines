#include "GiroADerecha.h"
#include "EstadoVelocidad.h"

void GiroADerecha::ejecutar(b2Body *body, EstadoVelocidad *estadoVelocidad, float32 angulo) {
  float32 anguloActual = body -> GetAngle();
  body -> SetTransform(body->GetPosition(), anguloActual - angulo);
}
