#ifndef SERVIDOR_ENVIARPARTIDAS_H
#define SERVIDOR_ENVIARPARTIDAS_H


#include "../../../Partida/HashProtegido.h"
#include "EventoParseable.h"

class EnviarPartidas: public EventoParseable {
private:
    HashProtegido& partidas;
public:
    EnviarPartidas(HashProtegido& partidas);
    std::string obtenerParseado() override;
};


#endif //SERVIDOR_ENVIARPARTIDAS_H
