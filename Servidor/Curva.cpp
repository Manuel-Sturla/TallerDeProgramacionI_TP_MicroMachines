#include "Curva.h"
#define FUERA_DE_CURVA 0
#define EN_ASFALTO 3
#define EN_PASTO 2

Curva::Curva(Pista *pista, Asfalto *asfalto, Pasto *pasto) {
  defCuerpo.type = b2_staticBody;
  defCuerpo.position.Set(0.0f, 4.0f); //POSICION HARDCODEADA
  agregarseAPista(pista);
  this -> asfalto = asfalto;
  this -> pasto = pasto;
  interaccion = FUERA_DE_CURVA;
}

void Curva::agregarseAPista(Pista *pista) {
  cuerpo = pista -> agregarObjeto(defCuerpo);
  cuerpo -> SetUserData(this);
  b2PolygonShape caja;
  caja.SetAsBox(2.0f, 2.0f);
  b2FixtureDef fixtureCuadrado;
  fixtureCuadrado.shape = &caja;
  fixtureCuadrado.density = 0.0f;
  fixtureCuadrado.isSensor = true;
  fixtureCuadrado.userData = (void *) &cuadrado;
  cuerpo -> CreateFixture(&fixtureCuadrado);

  b2CircleShape circuloShape;
  circuloShape.m_p.Set(2.0,2.0); //HARCODEADO A TIPO DE CURVA 1
  circuloShape.m_radius = 4.0f; //DEPENDE DEL TAMANIO QUE VAYA A TENER LA PISTA
  b2FixtureDef fixtureCirculo;
  fixtureCirculo.shape = &circuloShape;
  fixtureCirculo.density = 0.0f;
  fixtureCirculo.isSensor = true;
  fixtureCirculo.userData = (void*) &circulo;
  cuerpo -> CreateFixture(&fixtureCirculo);
}

std::string Curva::darId() {
  return "Curva";
}

void Curva::interactuar(Carro *unCarro) {
  if (interaccion == EN_ASFALTO) {
    std::cout <<"En asfalto" << std::endl;
    asfalto -> interactuar(unCarro);
  } else if (interaccion == EN_PASTO) {
    std::cout <<"En pasto" << std::endl;
    pasto -> interactuar(unCarro);
  }
}

Curva::~Curva() {
}

void Curva::tipoDeInteraccion(int identificadorDeInteraccion) {
  std::cout <<"Se modifico el tipo de interaccion" << std::endl;
  interaccion = identificadorDeInteraccion;
}

bool Curva::esValido() {
  return true;
}
