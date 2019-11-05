#include <sstream>
#include "PlanoDeCarro.h"

PlanoDeCarro::PlanoDeCarro(const std::string &configuracion) {
    std::istringstream stringConfiguracion(configuracion);
    std::string posicionString;
    getline(stringConfiguracion, posicionString, ',');
    velocidadMax = stoi(posicionString);
    getline(stringConfiguracion, posicionString, ',');
    anguloDeGiro = stoi(posicionString); //RECIBE UN ANGULO EN GRADOS
    anguloDeGiro = (anguloDeGiro * b2_pi) / 180; //LO PASA A RADIANES
    getline(stringConfiguracion, posicionString, ',');
    agarre = stoi(posicionString);
}

Carro * PlanoDeCarro::crearCarro(Pista *pista) {
    return pista->crearCarro(velocidadMax, anguloDeGiro, agarre);
}

PlanoDeCarro::~PlanoDeCarro() {
}
