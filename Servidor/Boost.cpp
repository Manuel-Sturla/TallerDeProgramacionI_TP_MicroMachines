#include "Boost.h"

Boost::Boost(Pista *pista) {
  b2BodyDef bodyDef;
  this -> pista = pista;
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
  validez = true;
  fixtureDef.isSensor = true;
  cuerpo -> CreateFixture(&fixtureDef);
}

void Boost::interactuar(Carro *unCarro) {
  unCarro -> recibirBoost();
  validez = false;
}

std::string Boost::darId() {
  return "Modificador";
}

Boost::~Boost() {
}

bool Boost::esValido() {
  return validez;
}
