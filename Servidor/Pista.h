#ifndef _PISTA_H_
#define _PISTA_H_

#include "3rd_party/Box2D-cmake/Box2D/Box2D/Box2D.h"
#include "ManejadorDeContactos.h"

class Pista {
  private:
    b2World pista;
    ManejadorDeContactos manejadorDeContactos;
  public:
    Pista(b2Vec2& gravedad);

    b2Body* agregarCarro(b2BodyDef& carro);

    void simular(float32 tiempo, int32 velocidad, int32 iteraciones);

    ~Pista();
};


#endif
