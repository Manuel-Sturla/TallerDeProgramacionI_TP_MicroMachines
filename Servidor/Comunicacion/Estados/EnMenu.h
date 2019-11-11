//
// Created by manfer on 5/11/19.
//

#ifndef SERVIDOR_ENMENU_H
#define SERVIDOR_ENMENU_H


#include <map>
#include <memory>
#include "EstadoCliente.h"
#include "../../Partida/Partida.h"
#include "../../ConfiguracionServidor.h"
#include "../../Partida/HashProtegido.h"
#include "../Eventos/EventosEjecutables/EventoEjecutable.h"


class EnMenu: public EstadoCliente {
    HashProtegido& partidas;
    ConfiguracionServidor& mapasYAutos;
    std::map<std::string, std::shared_ptr<EventoEjecutable>> comandos;

public:
    EnMenu(HashProtegido &partidas,
           ConfiguracionServidor &config);

    void ejecutar(ClienteProxy &cliente) override;

};


#endif //SERVIDOR_ENMENU_H
