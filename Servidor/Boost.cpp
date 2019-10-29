#include "Boost.h"

Boost::Boost(Pista *pista) {
  b2BodyDef bodyDef;
  bodyDef.type = b2_staticBody;
  bodyDef.position.Set(1.0f, 4.0f); //POSICION HARDCODEADA
  cuerpo = pista -> agregarObjeto(bodyDef);
  cuerpo -> SetUserData(this);
  b2PolygonShape staticBox;
  staticBox.SetAsBox(1.0f, 1.0f);
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &staticBox;
  // La densidad debe ser mayor a cero para que sea dinamico
  fixtureDef.density = 1.0f;
  fixtureDef.isSensor = true;
  cuerpo -> CreateFixture(&fixtureDef);
}

void Boost::interactuar(Carro *unCarro) {
  unCarro -> recibirBoost();
}

std::string Boost::darId() {
  return "Boost";
}

Boost::~Boost() {
}
