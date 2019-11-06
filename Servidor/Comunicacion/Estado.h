//
// Created by manfer on 5/11/19.
//

#ifndef SERVIDOR_ESTADO_H
#define SERVIDOR_ESTADO_H


#include "ClienteProxy.h"

class Estado {
public:
    virtual void ejecutar(ClienteProxy &cliente) = 0;

};


#endif //SERVIDOR_ESTADO_H
