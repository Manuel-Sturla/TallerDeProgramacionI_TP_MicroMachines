//
// Created by manfer on 5/11/19.
//

#ifndef SERVIDOR_CREARPARTIDA_H
#define SERVIDOR_CREARPARTIDA_H


#include <map>
#include "Comando.h"
#include "../../Partida/Partida.h"
#include "../../ConfiguracionServidor.h"

class CrearPartida: public Comando {
    std::map<std::string, std::shared_ptr<Partida>>& partidas;
    ConfiguracionServidor& mapasYAutos;
public:
    CrearPartida(std::map<std::string, std::shared_ptr<Partida>> &partidas,
                 ConfiguracionServidor &mapasYAutos);

    void ejecutar(ClienteProxy &cliente) override;
};


#endif //SERVIDOR_CREARPARTIDA_H
