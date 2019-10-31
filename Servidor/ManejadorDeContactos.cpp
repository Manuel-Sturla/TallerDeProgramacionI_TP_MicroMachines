#include "ManejadorDeContactos.h"
#include "Carro.h"
#include "Interactuable.h"
#include "Objeto.h"
#include "Curva.h"
#include <iostream>
ManejadorDeContactos::ManejadorDeContactos() {
}

void ManejadorDeContactos::BeginContact(b2Contact *contact) {
  //Solo un carro
  b2Fixture *fixture1 = contact -> GetFixtureA();
  b2Fixture *fixture2 = contact -> GetFixtureB();
  manejarContacto(fixture1, fixture2);
  manejarContacto(fixture2, fixture1);
}

void ManejadorDeContactos::EndContact(b2Contact *contact) {
  b2Fixture *fixture1 = contact -> GetFixtureA();
  b2Fixture *fixture2 = contact -> GetFixtureB();
  manejarFinDeContacto(fixture1, fixture2);
  manejarFinDeContacto(fixture2, fixture1);
}

void ManejadorDeContactos::manejarContacto(b2Fixture *fixture1, b2Fixture *fixture2) {
  void* objeto1 = fixture1 -> GetBody() -> GetUserData();
  void* objeto2 = fixture2 -> GetBody() -> GetUserData();
  if (static_cast<Objeto*>(objeto1) -> darId() == "Carro") {
    if (static_cast<Objeto*>(objeto2) -> darId() == "Curva") {
      int interaccion = tipoDeInteraccionCarroCurva(fixture1 -> GetBody(), fixture2 -> GetBody());
      static_cast<Curva*>(objeto2) -> tipoDeInteraccion(interaccion);
    }
    static_cast<Interactuable*>(objeto2) -> interactuar(static_cast<Carro*>(objeto1));
  }
}

void ManejadorDeContactos::manejarFinDeContacto(b2Fixture *fixture1, b2Fixture *fixture2) {
  void* objeto1 = fixture1 -> GetBody() -> GetUserData();
  void* objeto2 = fixture2 -> GetBody() -> GetUserData();
  if (static_cast<Objeto*>(objeto1) -> darId() == "Carro") {
    if (static_cast<Objeto*>(objeto2) -> darId() == "Curva") {
      int interaccion = tipoDeInteraccionCarroCurva(fixture1 -> GetBody(), fixture2 -> GetBody());
      int data = *(int *)fixture2 ->GetUserData();
      std::cout << "La data es " << data << std::endl;
      interaccion -= data;
      static_cast<Curva*>(objeto2) -> tipoDeInteraccion(interaccion);
      static_cast<Interactuable*>(objeto2) -> interactuar(static_cast<Carro*>(objeto1));
    }
  }

}

ManejadorDeContactos::~ManejadorDeContactos() {
}

int ManejadorDeContactos::tipoDeInteraccionCarroCurva(b2Body *carro, b2Body *curva) {
  int tipoDeInteraccion = 0;
  b2Fixture *fixtureCurva1 = curva -> GetFixtureList();
  b2Fixture *fixtureCurva2 = fixtureCurva1 -> GetNext();
  for (b2ContactEdge* iterador = carro -> GetContactList(); iterador != nullptr; iterador = iterador -> next) {
    b2Contact * contacto = iterador -> contact;
    b2Fixture *fixtureAux1 = contacto -> GetFixtureA();
    b2Fixture *fixtureAux2 = contacto -> GetFixtureB();
    if (fixtureAux1 == fixtureCurva1 || fixtureAux1 == fixtureCurva2) {
      int data = *(int *)fixtureAux1 ->GetUserData();
      tipoDeInteraccion += data;
    } else if (fixtureAux2 == fixtureCurva1 || fixtureAux2 == fixtureCurva2) {
      int data = *(int *)fixtureAux2 ->GetUserData();
      tipoDeInteraccion += data;
    }
  }
  return tipoDeInteraccion;
}
