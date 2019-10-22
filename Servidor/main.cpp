#include <stdio.h>
#include "3rd_party/Box2D-cmake/Box2D/Box2D/Box2D.h"
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

  carro.acelerar();

  // This is our little game loop.
  for (int32 i = 0; i < 60; ++i)
  {
    pista.simular(timeStep, velocityIterations, positionIterations);
    carro.imprimirPosicion();
  }

  carro.frenar();
  // This is our little game loop.
  for (int32 i = 0; i < 60; ++i)
  {
    pista.simular(timeStep, velocityIterations, positionIterations);
    carro.imprimirPosicion();
  }

  return 0;
}