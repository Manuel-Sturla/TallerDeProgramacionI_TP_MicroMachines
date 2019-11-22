#include "ManejadorDeContactos.h"
#include "../Objetos/Carro/Carro.h"
#include "../Objetos/Suelos/Curva.h"
#include <iostream>
ManejadorDeContactos::ManejadorDeContactos() {
}

void ManejadorDeContactos::BeginContact(b2Contact *contact) {
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
    if (static_cast<Objeto*>(objeto2) -> darId() == "Carro") {
        static_cast<Carro*>(objeto2) -> interactuar(static_cast<Carro*>(objeto1));
    } else {
        static_cast<Interactuable*>(objeto2) -> interactuar(static_cast<Carro*>(objeto1));
    }
  }
}

void ManejadorDeContactos::manejarFinDeContacto(b2Fixture *fixture1, b2Fixture *fixture2) {
    void *objeto1 = fixture1->GetBody()->GetUserData();
    void *objeto2 = fixture2->GetBody()->GetUserData();
    if (static_cast<Objeto *>(objeto1)->darId() == "Carro") {
        if (static_cast<Objeto *>(objeto2)->darId() == "Curva") {
            int interaccion = tipoDeInteraccionCarroCurva(fixture1->GetBody(),
                                                          fixture2->GetBody());
            int data = *(int *) fixture2->GetUserData();
            interaccion -= data;
            static_cast<Curva *>(objeto2)->tipoDeInteraccion(interaccion);
            static_cast<Interactuable *>(objeto2)->interactuar(
                static_cast<Carro *>(objeto1));
        } else if (static_cast<Objeto *>(objeto2)->darId() == "Recta") {
            buscarNuevoContactoEInteractuar(fixture1->GetBody(),
                                            fixture2->GetBody());
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

void ManejadorDeContactos::buscarNuevoContactoEInteractuar(b2Body *carro,
                                                           b2Body *suelo) {
    b2Fixture *texturaDeSuelo = suelo -> GetFixtureList();
    for (b2ContactEdge* iterador = carro -> GetContactList(); iterador != nullptr; iterador = iterador -> next) {
        b2Contact * contacto = iterador -> contact;
        b2Body *cuerpoAux1 = contacto -> GetFixtureA() -> GetBody();
        b2Body *cuerpoAux2 = contacto -> GetFixtureB() -> GetBody();
        if (cuerpoAux1 != suelo && cuerpoAux2 != suelo) {
            manejarContacto(contacto -> GetFixtureA(), contacto -> GetFixtureB());
            manejarContacto(contacto -> GetFixtureB(), contacto -> GetFixtureA());
        }
    }
}
