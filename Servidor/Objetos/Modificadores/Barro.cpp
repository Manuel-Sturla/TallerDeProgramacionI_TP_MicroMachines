#include "Barro.h"

Barro::Barro(MundoBox2D &pista, float32 x, float32 y, size_t idRecibido) {
    id = "E" + std::to_string(idRecibido);
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(x, y);
    cuerpo = pista.agregarObjeto(&bodyDef);
    cuerpo -> SetUserData(this);
    b2PolygonShape staticBox;
    staticBox.SetAsBox(1.0f, 1.0f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &staticBox;
    fixtureDef.density = 1.0f;
    fixtureDef.isSensor = true;
    validez = true;
    cuerpo -> CreateFixture(&fixtureDef);
    tipo = "Barro";
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
