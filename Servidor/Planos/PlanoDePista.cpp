#include <iostream>
#include <sstream>
#include "PlanoDePista.h"
#include "PlanoDeRecta.h"
#include "PlanoDeCurva.h"

PlanoDePista::PlanoDePista() {
}

void PlanoDePista::agregarSuelo(std::string configuracion) {
  std::istringstream stringConfiguracion(configuracion);
  std::string tipoDeSueloAAgregar;
  getline(stringConfiguracion, tipoDeSueloAAgregar, ',');
  getline(stringConfiguracion, configuracion);
  if (tipoDeSueloAAgregar == "Recta") {
    planosDeSuelos.emplace_back(new PlanoDeRecta(configuracion));
  } else if (tipoDeSueloAAgregar == "Curva") {
    planosDeSuelos.emplace_back(new PlanoDeCurva(configuracion));
  }
}

PlanoDePista::~PlanoDePista() {
}
