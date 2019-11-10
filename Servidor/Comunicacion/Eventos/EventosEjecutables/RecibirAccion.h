
#ifndef SERVIDOR_RECIBIRACCION_H
#define SERVIDOR_RECIBIRACCION_H

#include "EventoEjecutables.h"

class RecibirAccion: public EventoEjecutables {
public:
    RecibirAccion() = default;

    void ejecutar(ClienteProxy &cliente, std::vector<std::string> argumentos) override;
};


#endif //SERVIDOR_RECIBIRACCION_H
