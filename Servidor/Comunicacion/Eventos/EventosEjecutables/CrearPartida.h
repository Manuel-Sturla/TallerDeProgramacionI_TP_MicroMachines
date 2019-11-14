#ifndef SERVIDOR_CREARPARTIDA_H
#define SERVIDOR_CREARPARTIDA_H


#include <map>
#include "../../../Partida/Partida.h"
#include "../../../ConfiguracionServidor.h"
#include "../../../Partida/HashProtegido.h"
#include "EventoEjecutable.h"

class CrearPartida: public EventoEjecutable {
    HashProtegido& partidas;
    ConfiguracionServidor& mapasYAutos;
public:
    CrearPartida(HashProtegido &partidas,
                 ConfiguracionServidor &mapasYAutos);

    void ejecutar(ClienteProxy &cliente, std::vector<std::string> argumentos) override;
};


#endif //SERVIDOR_CREARPARTIDA_H
