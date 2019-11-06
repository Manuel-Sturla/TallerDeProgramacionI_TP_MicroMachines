//
// Created by manfer on 5/11/19.
//

#ifndef SERVIDOR_RECIBIRACCION_H
#define SERVIDOR_RECIBIRACCION_H


#include "Comando.h"

class RecibirAccion: public Comando {
public:
    RecibirAccion() = default;

    void ejecutar(ClienteProxy &cliente) override;
};


#endif //SERVIDOR_RECIBIRACCION_H
