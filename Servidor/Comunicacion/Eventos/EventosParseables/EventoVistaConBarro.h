#ifndef _EVENTOVISTACONBARRO_H_
#define _EVENTOVISTACONBARRO_H_

#include "EventoParseable.h"
#include "../../../Objetos/Carro/Carro.h"

class EventoVistaConBarro: public EventoParseable {
private:
    std::string parseado;
public:
    EventoVistaConBarro(Carro &carro);

    std::string obtenerParseado() override;
};



#endif
