#ifndef _PLANODECARRO_H_
#define _PLANODECARRO_H_

#include <string>
#include "../Partida/Pista.h"

class PlanoDeCarro {
private:
    int velocidadMax;
    int agarre;
    float32 anguloDeGiro;
    int aceleracion;
public:
    explicit PlanoDeCarro(int velocidadMax, float32 anguloDeGiro, int agarre);

    Carro *crearCarro(Pista *pista);

    ~PlanoDeCarro();
};


#endif
