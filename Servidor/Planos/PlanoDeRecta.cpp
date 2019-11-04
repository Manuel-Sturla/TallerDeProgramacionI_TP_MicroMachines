#include <sstream>
#include "PlanoDeRecta.h"
#include "../Objetos/Suelos/Recta.h"
#define MITAD_DE_LARGO_DE_SUELO 2

PlanoDeRecta::PlanoDeRecta(const std::string& configuracion) {
  std::istringstream stringConfiguracion(configuracion);
  std::string posicionString;
  getline(stringConfiguracion, material, ',');
  getline(stringConfiguracion, posicionString, ',');
  posicionX = stoi(posicionString) * MITAD_DE_LARGO_DE_SUELO;
  getline(stringConfiguracion, posicionString, ',');
  posicionY = stoi(posicionString) * MITAD_DE_LARGO_DE_SUELO;
  getline(stringConfiguracion, tipo, ',');
}

void PlanoDeRecta::agregarSueloA(Mapa *mapa) {
  mapa->agregarRecta(material, posicionX, posicionY, 0);
}

PlanoDeRecta::~PlanoDeRecta() {
}
