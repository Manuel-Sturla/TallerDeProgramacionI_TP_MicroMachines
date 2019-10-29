#include "CajaDeSalud.h"
#define CURACION 5

CajaDeSalud::CajaDeSalud(Pista *pista) {
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

void CajaDeSalud::interactuar(Carro *unCarro) {
  unCarro -> curar(CURACION);
  //eliminarseDePista(); //ROMPE AL INTENTAR ELIMINARLO
}

void CajaDeSalud::eliminarseDePista() {
  pista -> eliminarCuerpo(cuerpo);
}

std::string CajaDeSalud::darId() {
  return "CajaDeSalud";
}

CajaDeSalud::~CajaDeSalud() {

}
