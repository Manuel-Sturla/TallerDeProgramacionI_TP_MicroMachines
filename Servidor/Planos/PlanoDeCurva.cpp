#include <sstream>
#include "PlanoDeCurva.h"
#include "../Suelos/Curva.h"

#define MITAD_DE_LARGO_DE_SUELO 2

PlanoDeCurva::PlanoDeCurva(const std::string& configuracion) {
  std::istringstream stringConfiguracion(configuracion);
  std::string posicionString;
  getline(stringConfiguracion, posicionString, ',');
  posicionX = stoi(posicionString) * MITAD_DE_LARGO_DE_SUELO;
  getline(stringConfiguracion, posicionString, ',');
  posicionY = stoi(posicionString) * MITAD_DE_LARGO_DE_SUELO;
  getline(stringConfiguracion, tipo, ','); //SOSPECHOSO
}

void PlanoDeCurva::agregarSueloA(Mapa *mapa) {
  mapa->agregarCurva(posicionX, posicionY, 0);
}

PlanoDeCurva::~PlanoDeCurva() {
}
