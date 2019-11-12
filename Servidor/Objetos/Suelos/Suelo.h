#ifndef _SUELO_H_
#define _SUELO_H_

#include "../Interactuable.h"

class Suelo: public Interactuable {
protected:
    int numeroDeSuelo;
public:
    virtual void interactuar(Carro *unCarro) = 0;

    virtual void revivirCarro(MundoBox2D *mundoBox2D, Carro *unCarro) = 0;
};

#endif
