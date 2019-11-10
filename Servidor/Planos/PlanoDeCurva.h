#ifndef _PLANODECURVA_H_
#define _PLANODECURVA_H_

#include "PlanoDeSuelo.h"
#include "../Partida/Pista.h"

class PlanoDeCurva: public PlanoDeSuelo {
private:
    int posicionX;
    int posicionY;
    int tipo;
    int numero;
    float32 obtenerAngulo();
public:
    PlanoDeCurva(int x, int y, int tipo, int numero);

    void agregarSueloA(Pista *mapa) override;

    ~PlanoDeCurva();
};


#endif
