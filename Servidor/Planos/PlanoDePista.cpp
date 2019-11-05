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

void PlanoDePista::crearPista(Pista *mapa) {
    std::list<std::unique_ptr<PlanoDeSuelo>>::iterator it;
    for (it = planosDeSuelos.begin(); it != planosDeSuelos.end(); it ++) {
        (*it)->agregarSueloA(mapa);
    }
}

PlanoDePista::~PlanoDePista() {
}
