#include "Piedra.h"
#define DANIO_POR_PIEDRA 25

Piedra::Piedra(Pista *pista) {
  b2BodyDef bodyDef;
  bodyDef.type = b2_staticBody;
  bodyDef.position.Set(3.0f, 4.0f); //POSICION HARDCODEADA
  cuerpo = pista -> agregarObjeto(bodyDef);
  cuerpo -> SetUserData(this);
  b2PolygonShape staticBox;
  staticBox.SetAsBox(1.0f, 1.0f);
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &staticBox;
  fixtureDef.density = 1.0f;
  fixtureDef.isSensor = true;
  cuerpo -> CreateFixture(&fixtureDef);
}

std::string Piedra::darId() {
  return "Piedra";
}

void Piedra::interactuar(Carro *unCarro) {
  unCarro -> recibirDanio(DANIO_POR_PIEDRA);
  unCarro -> reducirVelocidad(0.75f);
}

Piedra::~Piedra() {
}
