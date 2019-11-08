#ifndef _PLANODECURVA_H_
#define _PLANODECURVA_H_

#include "PlanoDeSuelo.h"
#include "../Partida/Pista.h"

class PlanoDeCurva: public PlanoDeSuelo {
private:
    int posicionX;
    int posicionY;
    int tipo;

    float32 obtenerAngulo();
public:
    PlanoDeCurva(int x, int y, int tipo);

    void agregarSueloA(Pista *mapa) override;

    ~PlanoDeCurva();
};


#endif
