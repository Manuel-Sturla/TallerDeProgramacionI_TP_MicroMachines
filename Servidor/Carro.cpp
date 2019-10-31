#include "Carro.h"
#include <math.h>
#include "VelocidadBase.h"
#include "GiroAIzquierda.h"
#include "GiroADerecha.h"
#include <iostream>

Carro::Carro(float32 velocidadMaxima, float32 anguloDeGiro):
estadoVelocidad(velocidadMaxima) {
  bodyDef.type = b2_dynamicBody;
  bodyDef.position.Set(0.0f, 4.0f); //POSICION HARDCODEADA
  this -> anguloDeGiro = anguloDeGiro;
  id = "Carro";
}

void Carro::agregarseA(Pista *pista) {
  body = pista -> agregarObjeto(bodyDef);
  body -> SetUserData(this);
  b2PolygonShape dynamicBox;
  dynamicBox.SetAsBox(1.0f, 1.0f);
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &dynamicBox;
  // La densidad debe ser mayor a cero para que sea dinamico
  fixtureDef.density = 1.0f;
  fixtureDef.friction = 0.3f;
  body -> CreateFixture(&fixtureDef);
  body -> SetTransform(body -> GetPosition(), -0.5f * b2_pi);
  //GiroADerecha giroAIzquierda;
  //ejecutarAccion(&giroAIzquierda);
}

void Carro::ejecutarAccion(Accion *unaAccion) {
  unaAccion -> ejecutar(body, &estadoVelocidad, anguloDeGiro);
}

void Carro::actualizar() {
  b2Vec2 velocidad = body -> GetLinearVelocity();
  float32 factorDeFuerza = -2 * velocidad.Normalize();
  //VER COMO IR FRENANDO LA VELOCIDAD ANGULAR..........................................
  // HACER LA PARTE DEL AGARRE.........................................................
  //body -> ApplyAngularImpulse(0.1f * - body -> GetAngularVelocity(), true);
  body -> ApplyForce(coeficienteDeRozamiento * factorDeFuerza * velocidad, body -> GetWorldCenter(), true);
  visibilidad.actualizar();
  estadoVelocidad.actualizar(body);
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
  b2Vec2 velocidad = body -> GetLinearVelocity();
  body -> SetLinearVelocity(factor * velocidad);
}

void Carro::recibirBoost() {
  estadoVelocidad.boost();
}

void Carro::imprimirPosicion() {
  b2Vec2 position = body -> GetPosition();
  float32 angle = body -> GetAngle();
  printf("Nueva iteracion\n");
  printf("Posicion: ");
  printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
  b2Vec2 velocidad = body->GetLinearVelocity();
  //printf("Velocidad: ");
  //printf("%4.2f %4.2f\n", velocidad.x, velocidad.y);
}

bool Carro::esValido() {
  return true;
}
