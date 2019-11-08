#include <sstream>
#include "PlanoDeRecta.h"
#define ANGULO_RECTA_1 0
#define ANGULO_RECTA_2 0.5f * b2_pi

PlanoDeRecta::PlanoDeRecta(std::string material, int x, int y, int tipo) {
    this -> material = material;
    this -> posicionX = x;
    this -> posicionY = y;
    this -> tipo = tipo;
}

void PlanoDeRecta::agregarSueloA(Pista *mapa) {
    mapa->agregarRecta(material, posicionX, posicionY, obtenerAngulo());
}

PlanoDeRecta::~PlanoDeRecta() {
}

float32 PlanoDeRecta::obtenerAngulo() {
    float32 angulo = ANGULO_RECTA_1;
    if (tipo == 2) {
        angulo = ANGULO_RECTA_2;
    }
    return angulo;
}
