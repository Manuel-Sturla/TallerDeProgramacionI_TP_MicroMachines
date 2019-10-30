#include "Barro.h"

Barro::Barro(Pista *pista) {
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
  fixtureDef.isSensor = true;
  validez = true;
  cuerpo -> CreateFixture(&fixtureDef);
}

std::string Barro::darId() {
  return "Modificador";
}

void Barro::interactuar(Carro *unCarro) {
  unCarro -> reducirVisibilidad();
  validez = false;
}

Barro::~Barro() {
}

bool Barro::esValido() {
  return validez;
}
