#include "Recta.h"

Recta::Recta(Material *unMaterial) {
  bodyDef.type = b2_staticBody;
  bodyDef.position.Set(0.0f, 4.0f); //POSICION HARDCODEADA
  material = unMaterial;
}

void Recta::agregarseA(Pista *pista) {
  body = pista -> agregarObjeto(bodyDef);
  body -> SetUserData(material);
  b2PolygonShape staticBox;
  staticBox.SetAsBox(10.0f, 10.0f); //TAMANIO DE RECTA HARDCODEADO
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &staticBox;
  fixtureDef.density = 0.0f;
  fixtureDef.friction = 0.3f;
  fixtureDef.isSensor = true;
  body -> CreateFixture(&fixtureDef);
}

Recta::~Recta() {
}

bool Recta::esValido() {
  return true;
}
