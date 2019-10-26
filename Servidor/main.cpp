#include <stdio.h>
#include "Pista.h"
#include "Carro.h"
#include "Recta.h"
//#include "3rd_party/Box2D-cmake/Box2D/Testbed/Framework/DebugDraw.h"

int main() {
  b2Vec2 gravedad(0.0f, 0.0f);
  Pista pista(gravedad);
  //Recta recta;
  //recta.agregarseA(&pista);
  Carro carro;
  carro.agregarseA(&pista);
  //DebugDraw debug;

  float32 timeStep = 1.0f / 60.0f;
  int32 velocityIterations = 6;
  int32 positionIterations = 2;

  for (int32 i = 0; i < 12; ++i) {
    carro.acelerar();
    pista.simular(timeStep, velocityIterations, positionIterations);
    carro.imprimirPosicion();
  }

  for (int32 i = 0; i < 12; ++i) {
    carro.frenar();
    pista.simular(timeStep, velocityIterations, positionIterations);
    carro.imprimirPosicion();
  }

  return 0;
}