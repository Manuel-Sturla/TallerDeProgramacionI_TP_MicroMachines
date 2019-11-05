#include "MundoBox2D.h"
#include "../Objetos/Objeto.h"

MundoBox2D::MundoBox2D(): world(b2Vec2(0.0f, 0.0f)) {
  world.SetContactListener(&manejadorDeContactos);
}

b2Body* MundoBox2D::agregarObjeto(b2BodyDef* objeto) {
  return world.CreateBody(objeto);
}

void MundoBox2D::simular(float32 tiempo, int32 velocidad, int32 iteraciones) {
  world.Step(tiempo, velocidad, iteraciones);
}

MundoBox2D::~MundoBox2D() {
}

void MundoBox2D::actualizar() {
  b2Body* cuerpoActual = world.GetBodyList();
  while (cuerpoActual) {
    void* objetoActual = cuerpoActual -> GetUserData();
    if (!static_cast<Objeto*>(objetoActual) -> esValido()) {
      b2Body* cuerpoAux = cuerpoActual -> GetNext();
      world.DestroyBody(cuerpoActual);
      cuerpoActual = cuerpoAux;
    } else {
      cuerpoActual = cuerpoActual -> GetNext();
    }
  }
}
