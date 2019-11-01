#include "Pista.h"
#include "Objeto.h"

Pista::Pista(b2Vec2& gravedad): pista(gravedad) {
  pista.SetContactListener(&manejadorDeContactos);
}

b2Body* Pista::agregarObjeto(b2BodyDef& carro) {
  return pista.CreateBody(&carro);
}

void Pista::simular(float32 tiempo, int32 velocidad, int32 iteraciones) {
  pista.Step(tiempo, velocidad, iteraciones);
}

Pista::~Pista() {
}

void Pista::actualizar() {
  b2Body* cuerpoActual = pista.GetBodyList();
  while (cuerpoActual) {
    void* objetoActual = cuerpoActual ->GetUserData();
    if (!static_cast<Objeto*>(objetoActual) -> esValido()) {
      b2Body* cuerpoAux = cuerpoActual -> GetNext();
      pista.DestroyBody(cuerpoActual);
      cuerpoActual = cuerpoAux;
    } else {
      cuerpoActual = cuerpoActual -> GetNext();
    }
  }
}
