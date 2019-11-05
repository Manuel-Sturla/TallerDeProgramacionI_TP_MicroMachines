#ifndef _PIEDRA_H_
#define _PIEDRA_H_

#include "Modificador.h"
#include "../../Partida/MundoBox2D.h"

class Piedra: public Modificador {
  public:
    Piedra(MundoBox2D *pista, float32 x, float32 y);

    void interactuar(Carro* unCarro);

    bool esValido();

    ~Piedra();
};


#endif
