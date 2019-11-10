//
// Created by manfer on 10/11/19.
//

#ifndef SERVIDOR_EVENTOEJECUTABLES_H
#define SERVIDOR_EVENTOEJECUTABLES_H

#include "../../ClienteProxy.h"

class EventoEjecutables {
public:
    virtual void ejecutar(ClienteProxy &cliente) = 0;

};


#endif //SERVIDOR_EVENTOEJECUTABLES_H
