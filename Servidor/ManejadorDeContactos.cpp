#include "ManejadorDeContactos.h"
#include "Carro.h"

ManejadorDeContactos::ManejadorDeContactos() {
}

void ManejadorDeContactos::BeginContact(b2Contact *contact) {
  //Solo un carro, el resto de objetos son pista o pasto
  void* bodyUserData = contact -> GetFixtureA() -> GetBody() -> GetUserData();
  if (bodyUserData) {
    static_cast<Carro*>(bodyUserData) -> aplicarFriccion(0.3f);
  }

  bodyUserData = contact -> GetFixtureB() -> GetBody() -> GetUserData();
  if (bodyUserData)
    static_cast<Carro*>(bodyUserData) -> aplicarFriccion(0.3f);
}

void ManejadorDeContactos::EndContact(b2Contact *contact) {
}

ManejadorDeContactos::~ManejadorDeContactos() {
}
