#include "Boost.h"

Boost::Boost(MundoBox2D &pista, float32 x, float32 y, unsigned long idRecibido) {
    id = "E" + std::to_string(idRecibido);
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(x, y);
    cuerpo = pista.agregarObjeto(&bodyDef);
    cuerpo -> SetUserData(this);
    b2PolygonShape staticBox;
    staticBox.SetAsBox(0.5f, 0.5f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &staticBox;
    fixtureDef.density = 1.0f;
    validez = true;
    fixtureDef.isSensor = true;
    cuerpo -> CreateFixture(&fixtureDef);
    tipo = "Boost";
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
