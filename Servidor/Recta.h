#ifndef _RECTA_H_
#define _RECTA_H_

#include "Pista.h"
#include "Material.h"

class Recta {
  private:
    b2BodyDef bodyDef;
    b2Body *body;
    Material *material;

  public:
    Recta(Material *unMaterial);

    void agregarseA(Pista *pista);

    ~Recta();
};


#endif
