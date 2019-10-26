#include "Recta.h"

Recta::Recta() {
  bodyDef.type = b2_staticBody;
  bodyDef.position.Set(0.0f, 4.0f);
}

void Recta::agregarseA(Pista *pista) {
  body = pista -> agregarCarro(bodyDef);
  // Definicion del cuerpo dinamico
  b2PolygonShape staticBox;
  staticBox.SetAsBox(10.0f, 10.0f);
  // Define the dynamic body fixture.
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &staticBox;
  // La densidad debe ser mayor a cero para que sea dinamico
  fixtureDef.density = 0.0f;
  // Override the default friction.
  fixtureDef.friction = 0.0f;
  // Add the shape to the body.
  body->CreateFixture(&fixtureDef);
}

Recta::~Recta() {
}
