#include <iostream>
#include "PlanoDePista.h"
#include "PlanoDeRecta.h"
#include "PlanoDeCurva.h"

PlanoDePista::PlanoDePista(float32 anguloInicial) {
    this -> anguloInicial = (anguloInicial * b2_pi) / 180;;
}

void PlanoDePista::crearPista(Pista &pista) {
    pista.setAnguloInicial(anguloInicial);
    std::list<std::unique_ptr<PlanoDeSuelo>>::iterator it;
    for (it = planosDeSuelos.begin(); it != planosDeSuelos.end(); it ++) {
        (*it)->agregarSueloA(pista);
    }
    std::list<b2Vec2>::iterator posiciones;
    for (posiciones = posicionesDeInicio.begin(); posiciones != posicionesDeInicio.end(); posiciones++) {
        pista.agregarPosicionDeInicio(*posiciones);
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

void PlanoDePista::agregarPosicionDeInicio(int x, int y) {
    posicionesDeInicio.emplace_back(b2Vec2(x,y));
}
