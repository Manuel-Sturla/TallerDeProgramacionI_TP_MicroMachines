#ifndef _PLANODECARRO_H_
#define _PLANODECARRO_H_

#include <string>
#include "../Partida/Pista.h"

class PlanoDeCarro {
private:
    float32 velocidadMax;
    float32 agarre;
    float32 anguloDeGiro;
    float32 aceleracion;
public:
    explicit PlanoDeCarro(float32 velocidadMax, float32 aceleracion,
        float32 anguloDeGiro, float32 agarre);

    Carro *crearCarro(Pista &pista, size_t id);

    ~PlanoDeCarro();
};


#endif
