#include "Boost.h"

Boost::Boost(Pista *pista, float32 x, float32 y) {
  b2BodyDef bodyDef;
  bodyDef.type = b2_staticBody;
  bodyDef.position.Set(x, y);
  cuerpo = pista -> agregarObjeto(&bodyDef);
  cuerpo -> SetUserData(this);
  b2PolygonShape staticBox;
  staticBox.SetAsBox(1.0f, 1.0f);
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &staticBox;
  fixtureDef.density = 1.0f;
  validez = true;
  fixtureDef.isSensor = true;
  cuerpo -> CreateFixture(&fixtureDef);
  id = "Boost";
}

void Boost::interactuar(Carro *unCarro) {
  unCarro -> recibirBoost();
  validez = false;
}

Boost::~Boost() {
}

bool Boost::esValido() {
  return validez;
}
