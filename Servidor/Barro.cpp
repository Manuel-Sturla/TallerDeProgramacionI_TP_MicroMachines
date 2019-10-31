#include "Barro.h"

Barro::Barro(Pista *pista, float32 x, float32 y) {
  b2BodyDef bodyDef;
  this -> pista = pista;
  bodyDef.type = b2_staticBody;
  bodyDef.position.Set(x, y);
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
