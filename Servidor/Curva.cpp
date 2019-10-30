#include "Curva.h"

Curva::Curva() {
  defCuadrado.type = b2_staticBody;
  defCuadrado.position.Set(0.0f, 4.0f); //POSICION HARDCODEADA
  defCirculo.type = b2_staticBody;
  defCirculo.position.Set(2.0f, 2.0f); //POSICION HARDCODEADA PARA CURVA TIPO 1
}

void Curva::agregarseAPista(Pista *pista) {
  cuadrado = pista -> agregarObjeto(defCuadrado);
  circulo = pista -> agregarObjeto(defCirculo);
  //QUE SETEO DE USER DATA????

  b2PolygonShape caja;
  caja.SetAsBox(2.0f, 2.0f);
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &caja;
  fixtureDef.density = 0.0f;
  fixtureDef.isSensor = true;
  cuadrado -> CreateFixture(&fixtureDef);

  b2CircleShape circuloShape;
  circuloShape.m_p.Set(0,0);
  circuloShape.m_radius = 4.0f; //DEPENDE DEL TAMANIO QUE VAYA A TENER LA PISTA
  b2FixtureDef fixtureCirculo;
  fixtureCirculo.shape = &circuloShape;
  fixtureCirculo.density = 0.0f;
  fixtureCirculo.isSensor = true;
  circulo -> CreateFixture(&fixtureCirculo);

}

std::string Curva::darId() {
  return "Curva";
}

void Curva::interactuar(Carro *unCarro) {

}

Curva::~Curva() {
}
