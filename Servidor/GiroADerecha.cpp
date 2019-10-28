#include "GiroADerecha.h"

void GiroADerecha::ejecutar(b2Body *body, float32 velocidadMax) {
  float32 anguloActual = body -> GetAngle();
  body -> SetTransform(body->GetPosition(), anguloActual - 3);//anguloDeGiro);
}
