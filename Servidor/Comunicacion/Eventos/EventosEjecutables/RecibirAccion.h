
#ifndef SERVIDOR_RECIBIRACCION_H
#define SERVIDOR_RECIBIRACCION_H

#include "EventoEjecutables.h"

class RecibirAccion: public EventoEjecutables {
public:
    RecibirAccion() = default;

    void ejecutar(ClienteProxy &cliente) override;
};


#endif //SERVIDOR_RECIBIRACCION_H
