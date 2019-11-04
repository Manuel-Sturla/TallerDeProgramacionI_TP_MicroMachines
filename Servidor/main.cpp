#include "Partida/Partida.h"
#include "Servidor.h"

int main() {
    Servidor servidor("7780");
    servidor.start();
    servidor.join();
    return 0;
}