#ifndef _PISTA_H_
#define _PISTA_H_

#include "Box2D/Box2D.h"
#include "ManejadorDeContactos.h"

class Pista {
  private:
    b2World pista;
    ManejadorDeContactos manejadorDeContactos;
  public:
    Pista();

    b2Body* agregarObjeto(b2BodyDef* objeto);

    void simular(float32 tiempo, int32 velocidad, int32 iteraciones);

    void actualizar();

    ~Pista();
};


#endif
