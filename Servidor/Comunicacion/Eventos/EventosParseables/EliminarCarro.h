#ifndef _ELIMINARCARRO_H_
#define _ELIMINARCARRO_H_

#include "EventoParseable.h"
#include "../../../Objetos/Carro/Carro.h"

class EliminarCarro: public EventoParseable {
private:
    std::string parseo;
public:
    explicit EliminarCarro(size_t idCarro);

    std::string obtenerParseado() override;

};



#endif
