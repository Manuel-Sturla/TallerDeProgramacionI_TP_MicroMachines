#ifndef _VELOCIDADBASE_H_
#define _VELOCIDADBASE_H_

#include "Velocidad.h"

class VelocidadBase: public Velocidad {
  public:
    explicit VelocidadBase(float32 velocidadMaxima, float32 aceleracion);

    std::string boost() override;

    std::string actualizar() override;

};


#endif
