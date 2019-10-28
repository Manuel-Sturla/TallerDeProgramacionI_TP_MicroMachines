#include "Carro.h"
#include <math.h>

Carro::Carro(float32 velocidadMaxima, float32 anguloDeGiro) {
  bodyDef.type = b2_dynamicBody;
  bodyDef.position.Set(0.0f, 4.0f); //POSICION HARDCODEADA
  this -> anguloDeGiro = anguloDeGiro;
  this -> velocidadMax = velocidadMaxima;
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
}

void Carro::ejecutarAccion(Accion *unaAccion) {
  unaAccion -> ejecutar(body, velocidadMax, anguloDeGiro);
}

void Carro::actualizar() {
  b2Vec2 velocidad = body -> GetLinearVelocity();
  float32 factorDeFuerza = -2 * velocidad.Normalize();
  body -> ApplyForce(coeficienteDeRozamiento * factorDeFuerza * velocidad, body -> GetWorldCenter(), true);
}

void Carro::aplicarFriccion(float32 coeficienteDeRozamiento) {
  this -> coeficienteDeRozamiento = coeficienteDeRozamiento;
}

std::string Carro::darId() {
  return id;
}

void Carro::imprimirPosicion() {
  b2Vec2 position = body -> GetPosition();
  float32 angle = body -> GetAngle();
  printf("Nueva iteracion\n");
  printf("Posicion: ");
  printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
  b2Vec2 velocidad = body->GetLinearVelocity();
  printf("Velocidad: ");
  printf("%4.2f %4.2f\n", velocidad.x, velocidad.y);
}
