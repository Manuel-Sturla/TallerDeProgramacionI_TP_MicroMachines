#include "GiroAIzquierda.h"

void GiroAIzquierda::ejecutar(b2Body *body, EstadoVelocidad *estadoVelocidad, float32 angulo) {
  body -> ApplyTorque(angulo * body -> GetMass() * 10, true);
}
