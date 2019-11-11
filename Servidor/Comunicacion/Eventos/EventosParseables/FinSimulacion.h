//
// Created by hugo on 11/11/19.
//

#ifndef _FINSIMULACION_H_
#define _FINSIMULACION_H_



#include "EventosParseables.h"

class FinSimulacion: public EventosParseables {
public:
    std::string obtenerParseado() override;
};



#endif //_FINSIMULACION_H_
