#include "Carro.h"

Carro::Carro() {
  bodyDef.type = b2_dynamicBody;
  bodyDef.position.Set(0.0f, 4.0f);
}

void Carro::agregarseA(Pista *pista) {
  body = pista -> agregarCarro(bodyDef);

  // Define another box shape for our dynamic body.
  b2PolygonShape dynamicBox;
  dynamicBox.SetAsBox(1.0f, 1.0f);

  // Define the dynamic body fixture.
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &dynamicBox;

  // Set the box density to be non-zero, so it will be dynamic.
  fixtureDef.density = 1.0f;

  // Override the default friction.
  fixtureDef.friction = 0.3f;

  // Add the shape to the body.
  body->CreateFixture(&fixtureDef);
}

void Carro::acelerar() {
  b2Vec2 fuerza(100.0f, 0.0f);
  body -> ApplyForceToCenter(fuerza, true);
}

void Carro::frenar() {
  b2Vec2 fuerza2(-100.0f, 0.0f);
  body -> ApplyForceToCenter(fuerza2, true);
}

void Carro::imprimirPosicion() {
  b2Vec2 position = body->GetPosition();
  float32 angle = body->GetAngle();

  printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
}
