#ifndef _PLANODESUELO_H_
#define _PLANODESUELO_H_

#include <string>
#include "../Partida/Pista.h"

class PlanoDeSuelo {
public:
    virtual void agregarSueloA(Pista &mapa) = 0;
};

#endif
