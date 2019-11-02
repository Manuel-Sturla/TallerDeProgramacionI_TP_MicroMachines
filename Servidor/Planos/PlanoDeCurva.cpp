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
  getline(stringConfiguracion, tipo, ',');
}

void PlanoDeCurva::agregarSueloA(Mapa *mapa, Pista *pista) {
  Material *pasto = mapa -> darMaterial("Pasto");
  Material *asfalto = mapa -> darMaterial("Asfalto");
  Curva curva(pista, (Asfalto*) asfalto, (Pasto*) pasto, posicionX, posicionY);
  mapa -> agregarCurva(std::move(curva));
}

PlanoDeCurva::~PlanoDeCurva() {
}
