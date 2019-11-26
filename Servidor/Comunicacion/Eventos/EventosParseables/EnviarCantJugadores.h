//
// Created by manfer on 26/11/19.
//

#ifndef SERVIDOR_ENVIARCANTJUGADORES_H
#define SERVIDOR_ENVIARCANTJUGADORES_H


#include "EventoParseable.h"

class EnviarCantJugadores: public EventoParseable {
    size_t cantActualJugadores;
public:
    explicit EnviarCantJugadores(size_t cant);

    std::string obtenerParseado() override;
};


#endif //SERVIDOR_ENVIARCANTJUGADORES_H
