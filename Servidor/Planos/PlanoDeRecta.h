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
    int numero;

    float32 obtenerAngulo();
public:
    PlanoDeRecta(std::string material, int x, int y, int tipo, int numero);

    void agregarSueloA(Pista &mapa) override;

    ~PlanoDeRecta();
};


#endif
