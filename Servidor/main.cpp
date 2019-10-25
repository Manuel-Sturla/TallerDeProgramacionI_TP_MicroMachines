#include <stdio.h>
#include "Pista.h"
#include "Carro.h"
int main() {
  b2Vec2 gravedad(0.0f, 0.0f);
  Pista pista(gravedad);
  Carro carro;
  carro.agregarseA(&pista);

  float32 timeStep = 1.0f / 60.0f;
  int32 velocityIterations = 6;
  int32 positionIterations = 2;

  carro.giroAIzquierda();
  for (int32 i = 0; i < 20; ++i) {
    carro.acelerar();
    pista.simular(timeStep, velocityIterations, positionIterations);
    carro.imprimirPosicion();
  }
/*
  for (int32 i = 0; i < 20; ++i) {
    carro.frenar();
    pista.simular(timeStep, velocityIterations, positionIterations);
    carro.imprimirPosicion();
  }*/
  return 0;
}