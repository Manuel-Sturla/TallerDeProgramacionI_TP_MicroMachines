//
// Created by manfer on 10/11/19.
//

#ifndef SERVIDOR_PARTIDAINVALIDA_H
#define SERVIDOR_PARTIDAINVALIDA_H


#include "EventosParseables.h"

class PartidaInvalida: public EventosParseables {
public:
    std::string obtenerParseado() override;
};


#endif //SERVIDOR_PARTIDAINVALIDA_H
