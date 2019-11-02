#ifndef _PLANODECURVA_H_
#define _PLANODECURVA_H_

#include "PlanoDeSuelo.h"
#include "../Mapa.h"

class PlanoDeCurva: public PlanoDeSuelo {
  public:
    PlanoDeCurva(std::string configuracion);

    void agregarSueloA(Mapa *mapa, Pista *pista) override;

};


#endif
