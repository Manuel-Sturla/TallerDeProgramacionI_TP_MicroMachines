#ifndef _CAJADESALUD_H_
#define _CAJADESALUD_H_

#include "3rd_party/Box2D-cmake/Box2D/Box2D/Box2D.h"
#include "Modificador.h"
#include "Pista.h"

class CajaDeSalud: public Modificador {
  private:
    b2Body* cuerpo;
    Pista *pista;

    void eliminarseDePista();

  public:
    CajaDeSalud(Pista *pista);

    std::string darId();

    void interactuar(Carro* unCarro);

    ~CajaDeSalud();
};

#endif
