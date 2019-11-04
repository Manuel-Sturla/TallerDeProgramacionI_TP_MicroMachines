#ifndef _INTERACTUABLE_H_
#define _INTERACTUABLE_H_

#include <string>
#include "Objeto.h"
#include "Carro/Carro.h"

class Interactuable: public Objeto {
public:
    virtual void interactuar(Carro* unCarro) = 0;
};

#endif
