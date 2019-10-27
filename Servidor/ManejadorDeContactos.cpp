#include "ManejadorDeContactos.h"
#include "Carro.h"
#include "Interactuable.h"
#include "Objeto.h"

ManejadorDeContactos::ManejadorDeContactos() {
}

void ManejadorDeContactos::BeginContact(b2Contact *contact) {
  //Solo un carro, el resto de objetos son pista de asfalto
  void* interactuable1 = contact -> GetFixtureA() -> GetBody() -> GetUserData();
  void* interactuable2 = contact -> GetFixtureB() -> GetBody() -> GetUserData();
  if (static_cast<Objeto*>(interactuable1) -> darId() == "Carro") {
    static_cast<Interactuable*>(interactuable2) -> interactuar(static_cast<Carro*>(interactuable1));
  }

  if (static_cast<Objeto*>(interactuable2) -> darId() == "Carro") {
    static_cast<Interactuable*>(interactuable1) -> interactuar(static_cast<Carro*>(interactuable2));
  }
}

void ManejadorDeContactos::EndContact(b2Contact *contact) {
}

ManejadorDeContactos::~ManejadorDeContactos() {
}
