//
// Created by manfer on 5/11/19.
//

#ifndef SERVIDOR_UNIRAPARTIDA_H
#define SERVIDOR_UNIRAPARTIDA_H


#include <map>
#include "../../../Partida/Partida.h"
#include "../../../ConfiguracionServidor.h"
#include "../../../Partida/HashProtegido.h"
#include "EventoEjecutable.h"

class UnirAPartida: public EventoEjecutable {
    HashProtegido& partidas;
    ConfiguracionServidor& mapasYAutos;
public:
    UnirAPartida(HashProtegido &partidas, ConfiguracionServidor& config);

    void ejecutar(ClienteProxy &cliente, std::vector<std::string> argumento) override;
};


#endif //SERVIDOR_UNIRAPARTIDA_H
