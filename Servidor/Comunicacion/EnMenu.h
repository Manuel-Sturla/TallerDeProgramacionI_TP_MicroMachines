//
// Created by manfer on 5/11/19.
//

#ifndef SERVIDOR_ENMENU_H
#define SERVIDOR_ENMENU_H


#include <map>
#include <memory>
#include "Estado.h"
#include "../Partida/Partida.h"
#include "../ConfiguracionServidor.h"
#include "Comandos/Comando.h"


class EnMenu: public Estado {
    std::map<std::string, std::shared_ptr<Partida>>& partidas;
    ConfiguracionServidor& mapasYAutos;
    std::map<std::string, std::shared_ptr<Comando>> comandos;

public:
    EnMenu(std::map<std::string, std::shared_ptr<Partida>>& partidas,
           ConfiguracionServidor &config);

    void ejecutar(ClienteProxy &cliente) override;

};


#endif //SERVIDOR_ENMENU_H
