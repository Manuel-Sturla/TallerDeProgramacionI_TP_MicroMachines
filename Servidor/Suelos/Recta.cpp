#include "Recta.h"

Recta::Recta(Pista *pista, Material *unMaterial, float32 x, float32 y) {
  material = unMaterial;
  b2BodyDef defCuerpo;
  defCuerpo.type = b2_staticBody;
  defCuerpo.position.Set(x, y);
  cuerpo = pista -> agregarObjeto(defCuerpo);
  cuerpo -> SetUserData(this);
  b2PolygonShape cajaEstatica;
  cajaEstatica.SetAsBox(2.0f, 2.0f); //TAMANIO DE CUADRADO HARDCODEADO
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &cajaEstatica;
  fixtureDef.density = 0.0f;
  fixtureDef.friction = 0.3f;
  fixtureDef.isSensor = true;
  cuerpo -> CreateFixture(&fixtureDef);
}

Recta::~Recta() {
}

void Recta::interactuar(Carro *unCarro) {
  material -> interactuar(unCarro);
}

std::string Recta::darId() {
  return "Recta";
}

bool Recta::esValido() {
  return true;
}

Recta::Recta(Recta &&otraRecta) {
  this -> cuerpo = otraRecta.cuerpo;
  this -> material = otraRecta.material;
  otraRecta.cuerpo = nullptr;
  otraRecta.material = nullptr;
}

Recta &Recta::operator=(Recta &&otraRecta) {
  if (this == &otraRecta) {
    return *this;
  }
  this -> cuerpo = otraRecta.cuerpo;
  this -> material = otraRecta.material;
  otraRecta.cuerpo = nullptr;
  otraRecta.material = nullptr;
  return *this;
}
