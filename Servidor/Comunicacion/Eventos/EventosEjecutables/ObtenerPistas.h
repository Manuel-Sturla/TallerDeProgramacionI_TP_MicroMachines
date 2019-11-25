//
// Created by manfer on 25/11/19.
//

#ifndef SERVIDOR_OBTENERPISTAS_H
#define SERVIDOR_OBTENERPISTAS_H


#include "EventoEjecutable.h"
#include "../../../ConfiguracionServidor.h"

class ObtenerPistas: public EventoEjecutable {
    ConfiguracionServidor& configuracionServidor;
public:
    explicit ObtenerPistas(ConfiguracionServidor& pistas);

    void ejecutar(ClienteProxy &cliente, std::vector<std::string> argumentos) override;

};


#endif //SERVIDOR_OBTENERPISTAS_H
