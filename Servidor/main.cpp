#include "Partida.h"
#include "Servidor.h"

int main() {
  Servidor servidor;
  b2Vec2 gravedad(0.0f, 0.0f);
  Partida partida(gravedad);

  for (int32 i = 0; i < 5; ++i) {
    partida.simular();
  }

  return 0;
}