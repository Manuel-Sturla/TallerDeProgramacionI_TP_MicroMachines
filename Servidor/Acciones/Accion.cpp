#include "Accion.h"

void Accion::aplicarFuerza(b2Body *body, float32 factorDeFuerza) {
    float32 angulo = body->GetAngle();
    b2Vec2 fuerza(factorDeFuerza * cos(angulo), factorDeFuerza * sin(angulo));
    body -> ApplyForceToCenter(fuerza, true);
}
