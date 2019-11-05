#ifndef _MUNDOBOX2D_H_
#define _MUNDOBOX2D_H_

#include "Box2D/Box2D.h"
#include "ManejadorDeContactos.h"

class MundoBox2D {
  private:
    b2World world;
    ManejadorDeContactos manejadorDeContactos;
  public:
    MundoBox2D();

    b2Body* agregarObjeto(b2BodyDef* objeto);

    void simular(float32 tiempo, int32 velocidad, int32 iteraciones);

    void actualizar();

    ~MundoBox2D();
};


#endif
