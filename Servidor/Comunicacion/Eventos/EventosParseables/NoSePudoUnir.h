#ifndef SERVIDOR_NOSEPUDOUNIR_H
#define SERVIDOR_NOSEPUDOUNIR_H


#include "EventoParseable.h"

class NoSePudoUnir: public EventoParseable{
public:
    std::string obtenerParseado() override;
};


#endif //SERVIDOR_NOSEPUDOUNIR_H
