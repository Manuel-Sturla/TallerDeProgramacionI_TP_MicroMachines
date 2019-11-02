#include "Carro.h"
#include <math.h>
#include "VelocidadBase.h"
#include "../Acciones/GiroAIzquierda.h"
#include "../Acciones/GiroADerecha.h"
#include <iostream>

Carro::Carro(float32 velocidadMaxima, float32 anguloDeGiro, float32  agarre, float32 x, float32 y):
estadoVelocidad(velocidadMaxima), agarre(agarre) {
  bodyDef.type = b2_dynamicBody;
  bodyDef.position.Set(x, y);
  this -> anguloDeGiro = anguloDeGiro;
  id = "Carro";
}

void Carro::agregarseA(Pista *pista) {
  cuerpo = pista -> agregarObjeto(bodyDef);
  cuerpo -> SetUserData(this);
  b2PolygonShape dynamicBox;
  dynamicBox.SetAsBox(1.0f, 1.0f);
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &dynamicBox;
  fixtureDef.density = 1.0f;
  fixtureDef.friction = 0.3f;
  cuerpo -> CreateFixture(&fixtureDef);
}

void Carro::ejecutarAccion(Accion *unaAccion) {
  unaAccion -> ejecutar(cuerpo, &estadoVelocidad, anguloDeGiro);
}

void Carro::actualizar() {
  b2Vec2 velocidad = cuerpo -> GetLinearVelocity();
  float32 factorDeFuerza = -2 * velocidad.Normalize();
  agarre.actualizar(cuerpo);
  //PREGUNTAR COMO NORMALIZAR LOS ANGULOS
  cuerpo -> ApplyForce(coeficienteDeRozamiento * factorDeFuerza * velocidad, cuerpo -> GetWorldCenter(), true);
  visibilidad.actualizar();
  estadoVelocidad.actualizar(cuerpo);
}

void Carro::aplicarFriccion(float32 coeficienteDeRozamiento) {
  this -> coeficienteDeRozamiento = coeficienteDeRozamiento;
}

void Carro::reducirVisibilidad() {
  visibilidad.reducirVisibilidad();
}

std::string Carro::darId() {
  return id;
}

void Carro::recibirDanio(int danio) {
  vida.recibirDanio(danio);
}

void Carro::curar(int aumentoDeVida) {
  vida.aumentarVida(aumentoDeVida);
}

void Carro::reducirVelocidad(float32 factor) {
  b2Vec2 velocidad = cuerpo -> GetLinearVelocity();
  cuerpo -> SetLinearVelocity(factor * velocidad);
}

void Carro::recibirBoost() {
  estadoVelocidad.boost();
}

void Carro::imprimirPosicion() {
  b2Vec2 position = cuerpo -> GetPosition();
  float32 angle = cuerpo -> GetAngle();
  printf("Nueva iteracion\n");
  printf("Posicion: ");
  printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
}

bool Carro::esValido() {
  return vida.estoyVivo();
}

void Carro::reducirAgarre() {
  agarre.reducirAgarre();
}
