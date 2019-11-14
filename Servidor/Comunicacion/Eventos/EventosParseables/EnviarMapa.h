#ifndef SERVIDOR_ENVIARMAPA_H
#define SERVIDOR_ENVIARMAPA_H


#include "EventoParseable.h"
#include "../../../Partida/Pista.h"

class EnviarMapa: public EventoParseable {
    Pista& pista;
public:
    explicit EnviarMapa(Pista& pista);

    std::string obtenerParseado() override;
};


#endif //SERVIDOR_ENVIARMAPA_H
