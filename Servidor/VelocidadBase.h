#ifndef _VELOCIDADBASE_H_
#define _VELOCIDADBASE_H_

#include "EstrategiaDeVelocidad.h"

class VelocidadBase: public EstrategiaDeVelocidad {
  public:
    explicit VelocidadBase(float32 velocidadMaxima);

    std::shared_ptr<EstrategiaDeVelocidad> boost() override;

    std::shared_ptr<EstrategiaDeVelocidad> actualizar() override;

};


#endif
