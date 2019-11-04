#include <sstream>
#include "PlanoDeRecta.h"
#define ANGULO_RECTA_1 0
#define ANGULO_RECTA_2 0.5f * b2_pi

PlanoDeRecta::PlanoDeRecta(const std::string& configuracion) {
    std::istringstream stringConfiguracion(configuracion);
    std::string posicionString;
    getline(stringConfiguracion, material, ',');
    getline(stringConfiguracion, posicionString, ',');
    posicionX = stoi(posicionString);
    getline(stringConfiguracion, posicionString, ',');
    posicionY = stoi(posicionString);
    getline(stringConfiguracion, tipo, ',');
}

void PlanoDeRecta::agregarSueloA(Mapa *mapa) {
    mapa->agregarRecta(material, posicionX, posicionY, obtenerAngulo());
}

PlanoDeRecta::~PlanoDeRecta() {
}

float32 PlanoDeRecta::obtenerAngulo() {
    float32 angulo = ANGULO_RECTA_1;
    if (tipo == "2") {
        angulo = ANGULO_RECTA_2;
    }
    return angulo;
}
