#include "Carro.h"
#include <math.h>
#define ANGULO_PARA_GIRO 0.5 * b2_pi //HARDCODEADO
#define VELOCIDAD_MAXIMA 5

Carro::Carro() {
  bodyDef.type = b2_dynamicBody;
  bodyDef.position.Set(0.0f, 4.0f);
  anguloDeGiro = ANGULO_PARA_GIRO;
}

void Carro::agregarseA(Pista *pista) {
  body = pista -> agregarCarro(bodyDef);
  // Definicion del cuerpo dinamico
  b2PolygonShape dynamicBox;
  dynamicBox.SetAsBox(1.0f, 1.0f);
  // Define the dynamic body fixture.
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &dynamicBox;
  // La densidad debe ser mayor a cero para que sea dinamico
  fixtureDef.density = 1.0f;
  // Override the default friction.
  fixtureDef.friction = 0.0f;
  // Add the shape to the body.
  body->CreateFixture(&fixtureDef);
}

void Carro::acelerar() {
  b2Vec2 velocidad = body->GetLinearVelocity();
  if (velocidad.Length() < VELOCIDAD_MAXIMA) {
    float32 angulo = body -> GetAngle();
    b2Vec2 fuerza(100.0f * cos(angulo), 100.0f * sin(angulo));
    body -> ApplyForceToCenter(fuerza, true);
  }
}

void Carro::frenar() {
  b2Vec2 velocidad = body->GetLinearVelocity();
  if (velocidad.Length() <= VELOCIDAD_MAXIMA) {
    float32 angulo = body->GetAngle();
    b2Vec2 fuerza(-100.0f * cos(angulo), -100.0f * sin(angulo));
    body->ApplyForceToCenter(fuerza, true);
  }
}

void Carro::giroADerecha() {
  float32 anguloActual = body -> GetAngle();
  body -> SetTransform(body->GetPosition(), anguloActual - anguloDeGiro);
}

void Carro::giroAIzquierda() {
  float32 anguloActual = body -> GetAngle();
  body -> SetTransform(body->GetPosition(), anguloActual + anguloDeGiro);
}

void Carro::imprimirPosicion() {
  b2Vec2 position = body->GetPosition();
  float32 angle = body->GetAngle();
  printf("Nueva iteracion\n");
  printf("Posicion: ");
  printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
  b2Vec2 velocidad = body->GetLinearVelocity();
  printf("Velocidad: ");
  printf("%4.2f %4.2f\n", velocidad.x, velocidad.y);
}
