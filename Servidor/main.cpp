#include <stdio.h>
#include "Pista.h"
#include "Acelerar.h"
#include "Frenar.cpp.h"
#include "Carro.h"
#include "Recta.h"
#include "Pasto.h"
#include "Asfalto.h"
#include "3rd_party/Box2D-cmake/Box2D/Box2D/Box2D.h"
#define ANGULO_PARA_GIRO 0.5 * b2_pi //HARDCODEADO
#define VELOCIDAD_MAXIMA 5 //HARCODEADO

int main() {
  b2Vec2 gravedad(0.0f, 0.0f);
  Pista pista(gravedad);
  Pasto pasto;
  Asfalto asfalto;
  Recta recta(&asfalto);
  recta.agregarseA(&pista);
  Carro carro(VELOCIDAD_MAXIMA, ANGULO_PARA_GIRO);
  carro.agregarseA(&pista);
  Acelerar acelerar;
  float32 timeStep = 1.0f / 60.0f;
  int32 velocityIterations = 6;
  int32 positionIterations = 2;

  carro.ejecutarAccion(&frenar);
  for (int32 i = 0; i < 12; ++i) {
    pista.simular(timeStep, velocityIterations, positionIterations);
    carro.imprimirPosicion();
  }

  return 0;
}