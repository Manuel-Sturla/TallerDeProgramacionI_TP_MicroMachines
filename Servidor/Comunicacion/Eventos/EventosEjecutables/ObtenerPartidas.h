//
// Created by diego on 7/11/19.
//

#ifndef SERVIDOR_OBTENERPARTIDAS_H
#define SERVIDOR_OBTENERPARTIDAS_H


#include <map>
#include "../../../Partida/Partida.h"
#include "../../../Partida/HashProtegido.h"
#include "EventoEjecutables.h"

class ObtenerPartidas : public EventoEjecutables {
private:
    HashProtegido& partidas;

public:
    explicit ObtenerPartidas(HashProtegido &partidas);

    void ejecutar(ClienteProxy &cliente) override;

};


#endif //SERVIDOR_OBTENERPARTIDAS_H
