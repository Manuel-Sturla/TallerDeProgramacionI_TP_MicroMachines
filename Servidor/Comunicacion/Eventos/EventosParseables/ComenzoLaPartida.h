//
// Created by manfer on 10/11/19.
//

#ifndef SERVIDOR_COMENZOLAPARTIDA_H
#define SERVIDOR_COMENZOLAPARTIDA_H


#include "EventosParseables.h"

class ComenzoLaPartida: public EventosParseables {
public:
    std::string obtenerParseado() override;
};


#endif //SERVIDOR_COMENZOLAPARTIDA_H
