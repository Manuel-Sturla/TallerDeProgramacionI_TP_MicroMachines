#include "Recta.h"
#include "Asfalto.h"
#include "Pasto.h"

Recta::Recta() {
  bodyDef.type = b2_staticBody;
  bodyDef.position.Set(0.0f, 4.0f);
  material = new Asfalto();
}

void Recta::agregarseA(Pista *pista) {
  body = pista -> agregarObjeto(bodyDef);
  // Definicion del cuerpo dinamico
  b2PolygonShape staticBox;
  staticBox.SetAsBox(10.0f, 10.0f);

  // Define the dynamic body fixture.
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &staticBox;
  fixtureDef.density = 0.0f;
  // Override the default friction.
  fixtureDef.friction = 0.3f;
  fixtureDef.isSensor = true;
  // Add the shape to the body.
  body->CreateFixture(&fixtureDef);
}

Recta::~Recta() {
  delete material;
}
