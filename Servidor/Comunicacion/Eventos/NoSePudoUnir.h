//
// Created by manfer on 10/11/19.
//

#ifndef SERVIDOR_NOSEPUDOUNIR_H
#define SERVIDOR_NOSEPUDOUNIR_H


#include "EventosParseables.h"

class NoSePudoUnir: public EventosParseables{
public:
    std::string obtenerParseado() override;
};


#endif //SERVIDOR_NOSEPUDOUNIR_H
