#include <iostream>
#include "PlanoDePista.h"
#include "PlanoDeRecta.h"
#include "PlanoDeCurva.h"

PlanoDePista::PlanoDePista() {
}

void PlanoDePista::crearPista(Pista *mapa) {
    std::list<std::unique_ptr<PlanoDeSuelo>>::iterator it;
    for (it = planosDeSuelos.begin(); it != planosDeSuelos.end(); it ++) {
        (*it)->agregarSueloA(mapa);
    }
}

PlanoDePista::~PlanoDePista() {
}

void PlanoDePista::agregarRecta(std::string material, int x, int y, int tipo,
                                int numero) {
    planosDeSuelos.emplace_back(new PlanoDeRecta(material, x, y, tipo, numero));
}

void PlanoDePista::agregarCurva(int x, int y, int tipo, int numero) {
    planosDeSuelos.emplace_back(new PlanoDeCurva(x, y, tipo, numero));
}
