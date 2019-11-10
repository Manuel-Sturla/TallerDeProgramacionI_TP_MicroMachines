#include <sstream>
#include <utility>
#include "PlanoDeRecta.h"
#define ANGULO_RECTA_1 0
#define ANGULO_RECTA_2 0.5f * b2_pi

PlanoDeRecta::PlanoDeRecta(std::string material, int x, int y, int tipo,
                           int numero) {
    this -> material = std::move(material);
    this -> posicionX = x;
    this -> posicionY = y;
    this -> tipo = tipo;
    this -> numero = numero;
}

void PlanoDeRecta::agregarSueloA(Pista *mapa) {
    mapa->agregarRecta(material, posicionX, posicionY, obtenerAngulo(), numero);
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
