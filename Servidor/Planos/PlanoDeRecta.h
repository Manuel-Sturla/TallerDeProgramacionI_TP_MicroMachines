#ifndef _PLANODERECTA_H_
#define _PLANODERECTA_H_

#include "PlanoDeSuelo.h"
#include "../Partida/Pista.h"

class PlanoDeRecta: public PlanoDeSuelo {
private:
    std::string material;
    int posicionX;
    int posicionY;
    int tipo;

    float32 obtenerAngulo();
public:
    PlanoDeRecta(std::string material, int x, int y, int tipo);

    void agregarSueloA(Pista *mapa) override;

    ~PlanoDeRecta();
};


#endif
