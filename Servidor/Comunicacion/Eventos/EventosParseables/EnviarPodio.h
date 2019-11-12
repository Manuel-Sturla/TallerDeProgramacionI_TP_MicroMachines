#ifndef _ENVIARPODIO_H_
#define _ENVIARPODIO_H_



#include "../../../Partida/Podio.h"
#include "EventoParseable.h"

class EnviarPodio: public EventoParseable {
private:
    std::string mensaje;
public:
    EnviarPodio(Podio &podio);

    std::string obtenerParseado();

};



#endif //_ENVIARPODIO_H_
