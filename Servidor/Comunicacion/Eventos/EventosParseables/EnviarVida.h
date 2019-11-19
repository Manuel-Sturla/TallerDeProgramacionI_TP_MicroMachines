

#ifndef _ENVIARVIDA_H_
#define _ENVIARVIDA_H_



#include "EventoParseable.h"
#include "../../../Objetos/Carro/Carro.h"

class EnviarVida: public EventoParseable {
private:
    std::string parseado;
public:
    EnviarVida(Carro &carro);

    std::string obtenerParseado() override;
};

#endif
