#include "Cuadrado.h"

Cuadrado::Cuadrado(Pista *pista, Suelo *unSuelo) {
  suelo = unSuelo;
  defCuerpo.type = b2_staticBody;
  defCuerpo.position.Set(0.0f, 4.0f); //Posicion HARDCODEADA
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

std::string Cuadrado::darId() {
  return "Cuadrado";
}

bool Cuadrado::esValido() {
  return true;
}

void Cuadrado::interactuar(Carro *unCarro) {
  suelo -> interactuar(unCarro);
}

Cuadrado::~Cuadrado() {
}
