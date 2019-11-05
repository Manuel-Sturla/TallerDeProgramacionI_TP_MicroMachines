#ifndef _CAJADESALUD_H_
#define _CAJADESALUD_H_

#include "Box2D/Box2D.h"
#include "Modificador.h"
#include "../../Partida/MundoBox2D.h"

class CajaDeSalud: public Modificador {
  public:
    CajaDeSalud(MundoBox2D *pista, float32 x, float32 y);

    void interactuar(Carro* unCarro);

    bool esValido();

    ~CajaDeSalud();
};

#endif
