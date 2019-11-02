#ifndef _PLANODECURVA_H_
#define _PLANODECURVA_H_

#include "PlanoDeSuelo.h"

class PlanoDeCurva: public PlanoDeSuelo {
  public:
    PlanoDeCurva(std::string configuracion);

    void agregarSueloA(Pista *pista) override;

};


#endif
