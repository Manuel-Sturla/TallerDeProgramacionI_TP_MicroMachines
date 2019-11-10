//
// Created by manfer on 10/11/19.
//

#ifndef SERVIDOR_ENVIARPARTIDAS_H
#define SERVIDOR_ENVIARPARTIDAS_H


#include "../../Partida/HashProtegido.h"
#include "EventosParseables.h"

class EnviarPartidas: public EventosParseables {
    HashProtegido& partidas;
public:
    EnviarPartidas(HashProtegido& partidas);

private:
    std::string obtenerParseado() override;
};


#endif //SERVIDOR_ENVIARPARTIDAS_H
