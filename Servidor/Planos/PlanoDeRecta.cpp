#include <sstream>
#include "PlanoDeRecta.h"

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
    mapa->agregarRecta(material, posicionX, posicionY, 0);
}

PlanoDeRecta::~PlanoDeRecta() {
}
