#ifndef _CAJADESALUD_H_
#define _CAJADESALUD_H_

#include "3rd_party/Box2D-cmake/Box2D/Box2D/Box2D.h"
#include "Modificador.h"
#include "Pista.h"

class CajaDeSalud: public Modificador {
  public:
    CajaDeSalud(Pista *pista, float32 x, float32 y);

    void interactuar(Carro* unCarro);

    bool esValido();

    ~CajaDeSalud();
};

#endif
