#include "Partida.h"
#include "3rd_party/Box2D-cmake/Box2D/Box2D/Box2D.h"
#define ANGULO_PARA_GIRO 0.5 * b2_pi //HARDCODEADO
#define VELOCIDAD_MAXIMA 5 //HARCODEADO

int main() {
  b2Vec2 gravedad(0.0f, 0.0f);
  Partida partida(gravedad);

  for (int32 i = 0; i < 2000; ++i) {
    partida.simular();
  }
  return 0;
}