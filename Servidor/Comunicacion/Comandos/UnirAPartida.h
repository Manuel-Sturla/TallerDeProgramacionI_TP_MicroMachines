//
// Created by manfer on 5/11/19.
//

#ifndef SERVIDOR_UNIRAPARTIDA_H
#define SERVIDOR_UNIRAPARTIDA_H


#include <map>
#include "Comando.h"
#include "../../Partida/Partida.h"
#include "../../ConfiguracionServidor.h"
#include "../../Partida/HashProtegido.h"

class UnirAPartida: public Comando {
    HashProtegido& partidas;
    ConfiguracionServidor& mapasYAutos;
public:
    UnirAPartida(HashProtegido &partidas, ConfiguracionServidor& config);

    void ejecutar(ClienteProxy &cliente) override;

};


#endif //SERVIDOR_UNIRAPARTIDA_H
