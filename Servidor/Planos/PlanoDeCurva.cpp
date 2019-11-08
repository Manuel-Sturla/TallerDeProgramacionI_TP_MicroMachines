#include "PlanoDeCurva.h"
#define ANGULO_CURVA_1 0
#define ANGULO_CURVA_2 0.5f * b2_pi
#define ANGULO_CURVA_3 b2_pi
#define ANGULO_CURVA_4 1.5f * b2_pi

PlanoDeCurva::PlanoDeCurva(int x, int y, int tipo) {
    this -> posicionX = x;
    this -> posicionY = y;
    this -> tipo = tipo;
}

void PlanoDeCurva::agregarSueloA(Pista *mapa) {
    mapa->agregarCurva(posicionX, posicionY, obtenerAngulo());
}

PlanoDeCurva::~PlanoDeCurva() {
}

float32 PlanoDeCurva::obtenerAngulo() {
    float32 angulo = ANGULO_CURVA_1;
    if (tipo == 2) {
        angulo = ANGULO_CURVA_2;
    } else if (tipo == 3) {
        angulo = ANGULO_CURVA_3;
    } else if (tipo == 4) {
        angulo = ANGULO_CURVA_4;
    }
    return angulo;
}
