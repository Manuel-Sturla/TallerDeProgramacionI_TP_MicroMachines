#include "Pista.h"

Pista::Pista(b2Vec2& gravedad): pista(gravedad) {
  pista.SetContactListener(&manejadorDeContactos);
}

b2Body* Pista::agregarCarro(b2BodyDef& carro) {
  return pista.CreateBody(&carro);
}

void Pista::simular(float32 tiempo, int32 velocidad, int32 iteraciones) {
  pista.Step(tiempo, velocidad, iteraciones);
}

Pista::~Pista() {
}
