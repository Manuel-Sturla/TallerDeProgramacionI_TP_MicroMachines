#include "Piedra.h"
#define DANIO_POR_PIEDRA 25

Piedra::Piedra(MundoBox2D &pista, float32 x, float32 y,
               unsigned long idRecibido) {
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
    fixtureDef.isSensor = true;
    validez = true;
    cuerpo -> CreateFixture(&fixtureDef);
    tipo = "Piedra";
}

void Piedra::interactuar(Carro *unCarro) {
  unCarro -> recibirDanio(DANIO_POR_PIEDRA);
  unCarro -> reducirVelocidad(0.75f);
  validez = false;
}

Piedra::~Piedra() {
}

bool Piedra::esValido() {
  return validez;
}
