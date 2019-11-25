//
// Created by manfer on 25/11/19.
//

#ifndef SERVIDOR_ENVIARPISTAS_H
#define SERVIDOR_ENVIARPISTAS_H


#include "EventoParseable.h"
#include "../../../ConfiguracionServidor.h"

class EnviarPistas: public EventoParseable {
    std::vector<std::string> pistas;
public:
    explicit EnviarPistas(std::vector<std::string>& pistas);

    std::string obtenerParseado() override;
};


#endif //SERVIDOR_ENVIARPISTAS_H
