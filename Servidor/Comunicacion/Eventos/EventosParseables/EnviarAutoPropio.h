//
// Created by manfer on 10/11/19.
//

#ifndef SERVIDOR_ENVIARAUTOPROPIO_H
#define SERVIDOR_ENVIARAUTOPROPIO_H


#include "EventosParseables.h"
#include "../../../Objetos/Carro/Carro.h"

class EnviarAutoPropio: public EventosParseables {
    Carro* carro;
public:
    explicit EnviarAutoPropio(Carro* carro);

    std::string obtenerParseado() override;
};


#endif //SERVIDOR_ENVIARAUTOPROPIO_H
