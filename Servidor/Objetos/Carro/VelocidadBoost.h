#ifndef _VELOCIDADBOOST_H_
#define _VELOCIDADBOOST_H_

#include "Velocidad.h"

class VelocidadBoost: public Velocidad {
  private:
    int32 duracion;
  public:
    VelocidadBoost(float32 velocidadBase);

    std::string boost() override;

    std::string actualizar() override;
};


#endif
