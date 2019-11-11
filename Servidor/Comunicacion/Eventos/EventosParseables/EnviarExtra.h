//
// Created by manfer on 11/11/19.
//

#ifndef SERVIDOR_ENVIAREXTRA_H
#define SERVIDOR_ENVIAREXTRA_H


#include "EventosParseables.h"
#include "../../../Objetos/Modificadores/Modificador.h"

class EnviarExtra: public EventosParseables {
    std::string parseado;
public:
    EnviarExtra(std::unique_ptr<Modificador> &modificable);

    std::string obtenerParseado() override;
};


#endif //SERVIDOR_ENVIAREXTRA_H
