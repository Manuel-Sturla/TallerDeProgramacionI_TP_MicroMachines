#ifndef _MANEJADORDECONTACTOS_H_
#define _MANEJADORDECONTACTOS_H_

#include "Box2D/Box2D.h"

class ManejadorDeContactos: public b2ContactListener {
  public:
    ManejadorDeContactos();

    void BeginContact(b2Contact *contact);

    void EndContact(b2Contact *contact);

    void manejarContacto(b2Fixture *objeto1, b2Fixture *objeto2);

    void manejarFinDeContacto(b2Fixture *objeto1, b2Fixture *objeto2);

    void buscarNuevoContactoEInteractuar(b2Body *carro, b2Body *suelo);

    int tipoDeInteraccionCarroCurva(b2Body *carro, b2Body *curva);

    ~ManejadorDeContactos();
};


#endif
