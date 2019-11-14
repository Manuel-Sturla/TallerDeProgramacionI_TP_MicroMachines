#ifndef SERVIDOR_PARTIDAINVALIDA_H
#define SERVIDOR_PARTIDAINVALIDA_H


#include "EventoParseable.h"

class PartidaInvalida: public EventoParseable {
public:
    std::string obtenerParseado() override;
};


#endif //SERVIDOR_PARTIDAINVALIDA_H
