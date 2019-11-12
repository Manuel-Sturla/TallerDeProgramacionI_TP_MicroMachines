//
// Created by hugo on 11/11/19.
//

#ifndef _ENVIARCARRO_H_
#define _ENVIARCARRO_H_



#include "EventoParseable.h"
#include "../../../Objetos/Carro/Carro.h"

class EnviarCarro: public EventoParseable {
    std::string parseo;
public:
    explicit EnviarCarro(Carro& carro);

    std::string obtenerParseado() override;

};



#endif //_ENVIARCARRO_H_
