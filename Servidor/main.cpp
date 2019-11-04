#include "Servidor.h"

int main() {
    Servidor servidor("7778");
    servidor.start();
    servidor.join();
    return 0;
}