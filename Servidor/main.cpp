#include "Partida.h"
#include "3rd_party/Box2D-cmake/Box2D/Box2D/Box2D.h"
#include "Servidor.h"

int main() {

  b2Vec2 gravedad(0.0f, 0.0f);
  Partida partida(gravedad);

  for (int32 i = 0; i < 5; ++i) {
    partida.simular();
  }
/*
  Servidor servidor;*/
  return 0;
}