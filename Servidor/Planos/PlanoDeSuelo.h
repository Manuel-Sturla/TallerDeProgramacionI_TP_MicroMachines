#ifndef _PLANODESUELO_H_
#define _PLANODESUELO_H_

#include <string>
#include "../Mapa.h"

class PlanoDeSuelo {
  public:
    virtual void agregarSueloA(Mapa *mapa, Pista *pista) = 0;
};

#endif
