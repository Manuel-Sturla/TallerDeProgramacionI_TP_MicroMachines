#include "Pista.h"
#include "Objeto.h"

Pista::Pista(): pista(b2Vec2(0.0f, 0.0f)) {
  pista.SetContactListener(&manejadorDeContactos);
}

b2Body* Pista::agregarObjeto(b2BodyDef* objeto) {
  return pista.CreateBody(objeto);
}

void Pista::simular(float32 tiempo, int32 velocidad, int32 iteraciones) {
  pista.Step(tiempo, velocidad, iteraciones);
}

Pista::~Pista() {
}

void Pista::actualizar() {
  b2Body* cuerpoActual = pista.GetBodyList();
  while (cuerpoActual) {
    void* objetoActual = cuerpoActual -> GetUserData();
    if (!static_cast<Objeto*>(objetoActual) -> esValido()) {
      b2Body* cuerpoAux = cuerpoActual -> GetNext();
      pista.DestroyBody(cuerpoActual);
      cuerpoActual = cuerpoAux;
    } else {
      cuerpoActual = cuerpoActual -> GetNext();
    }
  }
}
