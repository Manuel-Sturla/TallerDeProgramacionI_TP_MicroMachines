#ifndef _PLANODESUELO_H_
#define _PLANODESUELO_H_

#include <string>
#include "../Pista.h"

class PlanoDeSuelo {
  protected:
    std::string configuracion;

  public:
    PlanoDeSuelo(std::string unaConfiguracion);

    void agregarSueloA(Pista *pista);

};


#endif
