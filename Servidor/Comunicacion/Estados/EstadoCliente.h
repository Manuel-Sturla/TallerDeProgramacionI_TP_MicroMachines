//
// Created by manfer on 5/11/19.
//

#ifndef SERVIDOR_ESTADOCLIENTE_H
#define SERVIDOR_ESTADOCLIENTE_H


#include "../ClienteProxy.h"

class EstadoCliente {
public:
    virtual void ejecutar(ClienteProxy &cliente) = 0;

};


#endif //SERVIDOR_ESTADOCLIENTE_H
