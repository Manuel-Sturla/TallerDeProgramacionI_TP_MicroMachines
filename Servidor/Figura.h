#ifndef _FIGURA_H_
#define _FIGURA_H_

#include "Interactuable.h"
#include "Suelos/Suelo.h"

class Figura: public Interactuable {
  protected:
    b2BodyDef defCuerpo;
    b2Body *cuerpo;
    Suelo *suelo;
  public:

};


#endif 
