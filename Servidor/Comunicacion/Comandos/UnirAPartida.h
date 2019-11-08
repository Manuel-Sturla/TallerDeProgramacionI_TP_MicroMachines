//
// Created by manfer on 5/11/19.
//

#ifndef SERVIDOR_UNIRAPARTIDA_H
#define SERVIDOR_UNIRAPARTIDA_H


#include <map>
#include "Comando.h"
#include "../../Partida/Partida.h"
#include "../../ConfiguracionServidor.h"

class UnirAPartida: public Comando {
    std::map<std::string, std::shared_ptr<Partida>>& partidas;
    ConfiguracionServidor& mapasYAutos;
public:
    UnirAPartida(std::map<std::string, std::shared_ptr<Partida>>& partidas, ConfiguracionServidor& config);

    void ejecutar(ClienteProxy &cliente) override;

};


#endif //SERVIDOR_UNIRAPARTIDA_H
