#ifndef _FINSIMULACION_H_
#define _FINSIMULACION_H_



#include "EventoParseable.h"

class FinSimulacion: public EventoParseable {
public:
    std::string obtenerParseado() override;
};



#endif //_FINSIMULACION_H_
