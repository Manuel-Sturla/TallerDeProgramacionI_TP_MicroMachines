#ifndef _SUELO_H_
#define _SUELO_H_

#include "../Interactuable.h"

class Suelo: public Interactuable {
protected:
    int numeroDeSuelo;
public:
    virtual void interactuar(Carro *unCarro) = 0;
};

#endif
