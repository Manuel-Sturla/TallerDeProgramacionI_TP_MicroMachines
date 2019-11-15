#include <sstream>
#include "PlanoDeCarro.h"

PlanoDeCarro::PlanoDeCarro(float32 velocidadMax, float32  aceleacion, float32 anguloDeGiro, float32 agarre) {
    this -> velocidadMax = velocidadMax;
    this -> anguloDeGiro = (anguloDeGiro * b2_pi) / 180;
    this -> agarre = agarre;
    this -> aceleracion = aceleacion;
}

Carro * PlanoDeCarro::crearCarro(Pista &pista, size_t id) {
    return pista.crearCarro(velocidadMax, aceleracion, anguloDeGiro, agarre, id);
}

PlanoDeCarro::~PlanoDeCarro() {
}
