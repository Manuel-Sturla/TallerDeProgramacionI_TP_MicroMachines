#ifndef _PLANODECURVA_H_
#define _PLANODECURVA_H_

#include "PlanoDeSuelo.h"
#include "../Partida/Pista.h"

class PlanoDeCurva: public PlanoDeSuelo {
private:
    int posicionX;
    int posicionY;
    std::string tipo;

    float32 obtenerAngulo();
public:
    PlanoDeCurva(const std::string& configuracion);

    void agregarSueloA(Pista *mapa) override;

    ~PlanoDeCurva();
};


#endif
