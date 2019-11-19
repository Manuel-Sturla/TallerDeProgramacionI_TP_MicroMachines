//
// Created by diego on 19/11/19.
//

#ifndef SERVIDOR_ENVIARGANADOR_H
#define SERVIDOR_ENVIARGANADOR_H


#include "EventoParseable.h"
#include "../../../Partida/Podio.h"

class EnviarGanador : public EventoParseable {
private:
    std::string mensaje;
public:
    explicit EnviarGanador(Podio &podio);

    std::string obtenerParseado() override;

};


#endif //SERVIDOR_ENVIARGANADOR_H
