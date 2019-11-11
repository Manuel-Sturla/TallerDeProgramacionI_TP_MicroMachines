#ifndef _SERVIDORCERRADO_H_
#define _SERVIDORCERRADO_H_

#include "EventoParseable.h"

class ServidorCerrado: public EventoParseable {
private:
    std::string mensaje;
public:
    ServidorCerrado();

    std::string obtenerParseado();
};



#endif
