#ifndef _PLANODESUELO_H_
#define _PLANODESUELO_H_

#include <string>
#include "../Pista.h"

class PlanoDeSuelo {
  public:
    virtual void agregarSueloA(Pista *pista) = 0;
};

#endif
