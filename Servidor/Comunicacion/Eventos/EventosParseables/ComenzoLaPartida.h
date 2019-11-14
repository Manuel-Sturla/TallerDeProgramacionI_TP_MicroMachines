#ifndef SERVIDOR_COMENZOLAPARTIDA_H
#define SERVIDOR_COMENZOLAPARTIDA_H


#include "EventoParseable.h"

class ComenzoLaPartida: public EventoParseable {
public:
    std::string obtenerParseado() override;
};


#endif //SERVIDOR_COMENZOLAPARTIDA_H
