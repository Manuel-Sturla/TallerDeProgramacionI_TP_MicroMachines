#include "Partida/Partida.h"
#include "Servidor.h"

int main() {
  SocketPasivo socketPasivo;
    Servidor servidor(&socketPasivo); //HARDCODEAR SERVICIOOOOOOOOOOOOOOOOOO
  servidor.run();
  return 0;
}