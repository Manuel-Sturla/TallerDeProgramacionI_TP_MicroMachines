#include <sstream>
#include "PlanoDeCurva.h"

PlanoDeCurva::PlanoDeCurva(const std::string& configuracion) {
    std::istringstream stringConfiguracion(configuracion);
    std::string posicionString;
    getline(stringConfiguracion, posicionString, ',');
    posicionX = stoi(posicionString);
    getline(stringConfiguracion, posicionString, ',');
    posicionY = stoi(posicionString);
    getline(stringConfiguracion, tipo, ',');
}

void PlanoDeCurva::agregarSueloA(Mapa *mapa) {
    mapa->agregarCurva(posicionX, posicionY, 0);
}

PlanoDeCurva::~PlanoDeCurva() {
}
