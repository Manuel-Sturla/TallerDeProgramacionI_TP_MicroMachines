#include <stdio.h>
#include "3rd_party/Box2D-cmake/Box2D/Box2D/Box2D.h"
int main() {
  // El mundo no tiene gravidad
  b2Vec2 gravity(0.0f, 0.0f);

  // Construct a world object, which will hold and simulate the rigid bodies.
  b2World world(gravity);

  b2BodyDef bodyDef;
  bodyDef.type = b2_dynamicBody;
  bodyDef.position.Set(0.0f, 4.0f);
  b2Body* body = world.CreateBody(&bodyDef);


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

  float32 timeStep = 1.0f / 60.0f;
  int32 velocityIterations = 6;
  int32 positionIterations = 2;

  //Aplico una fuerza
  b2Vec2 fuerza(10.0f, 0.0f);

  // This is our little game loop.
  for (int32 i = 0; i < 60; ++i)
  {
    // Instruct the world to perform a single step of simulation.
    // It is generally best to keep the time step and iterations fixed.
    body -> ApplyForceToCenter(fuerza, true);
    world.Step(timeStep, velocityIterations, positionIterations);

    // Now print the position and angle of the body.
    b2Vec2 position = body->GetPosition();
    float32 angle = body->GetAngle();

    printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
  }

  return 0;
}