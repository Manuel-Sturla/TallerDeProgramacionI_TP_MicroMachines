#ifndef _CURVA_H_
#define _CURVA_H_

#include <Box2D/Box2D.h>
#include "Material.h"
#include "Pista.h"

class Curva {
  private:
    b2BodyDef defCirculo;
    b2BodyDef defCuadrado;
    b2Body *circulo;
    b2Body *cuadrado;
    Material *material;
    bool tocandoCirculo;
    bool tocandoCuadrado;
  public:
    Curva();

    void agregarseAPista(Pista *pista);

    ~Curva();

};


#endif
