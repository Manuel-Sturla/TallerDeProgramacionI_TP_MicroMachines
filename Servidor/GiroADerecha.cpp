#include "GiroADerecha.h"
#include "EstadoVelocidad.h"

void GiroADerecha::ejecutar(b2Body *body, EstadoVelocidad *estadoVelocidad, float32 angulo) {
  /*
  float anguloDeseado = body -> GetAngle() - angulo;
  float nextAngle = body -> GetAngle() + body->GetAngularVelocity() / 3.0;
  float totalRotation = anguloDeseado - nextAngle;//use angle in next time step
  body->ApplyTorque( totalRotation < 0 ? -10 * body -> GetMass(): 10, true );
  */
  body -> ApplyTorque(angulo * body -> GetMass() * -10, true);
}
