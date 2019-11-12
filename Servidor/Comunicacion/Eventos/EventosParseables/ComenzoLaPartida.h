//
// Created by manfer on 10/11/19.
//

#ifndef SERVIDOR_COMENZOLAPARTIDA_H
#define SERVIDOR_COMENZOLAPARTIDA_H


#include "EventoParseable.h"

class ComenzoLaPartida: public EventoParseable {
public:
    std::string obtenerParseado() override;
};


#endif //SERVIDOR_COMENZOLAPARTIDA_H
