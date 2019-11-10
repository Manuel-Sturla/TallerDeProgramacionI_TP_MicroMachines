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
#include "../Comandos/Comando.h"
#include "../../Partida/HashProtegido.h"


class EnMenu: public EstadoCliente {
    HashProtegido& partidas;
    ConfiguracionServidor& mapasYAutos;
    std::map<std::string, std::shared_ptr<Comando>> comandos;

public:
    EnMenu(HashProtegido &partidas,
           ConfiguracionServidor &config);

    void ejecutar(ClienteProxy &cliente) override;

};


#endif //SERVIDOR_ENMENU_H
