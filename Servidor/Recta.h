#ifndef _RECTA_H_
#define _RECTA_H_

#include "Pista.h"

class Recta {
  private:
    b2BodyDef bodyDef;
    b2Body* body;
  public:
    Recta();

    void agregarseA(Pista *pista);

    ~Recta();
};


#endif
