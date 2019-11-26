#ifndef _SUELO_H_
#define _SUELO_H_

#include "../Interactuable.h"
#include "../Modificadores/Modificador.h"
#include <list>

class Suelo: public Interactuable {
protected:
    int numeroDeSuelo;
public:
    virtual void interactuar(Carro *unCarro) = 0;

    void revivirCarro(MundoBox2D &mundoBox2D, Carro *unCarro);

    void colocarExtra(MundoBox2D &mundoBox2D, std::list<std::unique_ptr<Modificador>> &extras);
};

#endif
