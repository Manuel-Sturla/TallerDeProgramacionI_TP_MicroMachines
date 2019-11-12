//
// Created by manfer on 10/11/19.
//

#ifndef SERVIDOR_UNIRAPARTIDACORRECTO_H
#define SERVIDOR_UNIRAPARTIDACORRECTO_H


#include "EventoParseable.h"

class UnirAPartidaCorrecto: public EventoParseable {

public:
    std::string obtenerParseado() override;
};


#endif //SERVIDOR_UNIRAPARTIDACORRECTO_H
