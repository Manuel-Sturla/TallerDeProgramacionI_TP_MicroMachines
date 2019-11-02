#include <sstream>
#include "PlanoDeRecta.h"
#include "../Suelos/Recta.h"
#define MITAD_DE_LARGO_DE_SUELO 2

PlanoDeRecta::PlanoDeRecta(std::string configuracion) {
  std::istringstream stringConfiguracion(configuracion);
  std::string posicionString;
  getline(stringConfiguracion, material, ',');
  getline(stringConfiguracion, posicionString, ',');
  posicionX = stoi(posicionString) * MITAD_DE_LARGO_DE_SUELO;
  getline(stringConfiguracion, posicionString, ',');
  posicionY = stoi(posicionString) * MITAD_DE_LARGO_DE_SUELO;
  getline(stringConfiguracion, tipo, ',');
}

void PlanoDeRecta::agregarSueloA(Mapa *mapa, Pista *pista) {
  Material *materialParaRecta = mapa -> darMaterial(material);
  Recta recta(pista, materialParaRecta, posicionX, posicionY);
}

PlanoDeRecta::~PlanoDeRecta() {
}
