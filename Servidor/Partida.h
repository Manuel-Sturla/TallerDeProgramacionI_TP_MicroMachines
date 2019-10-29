#ifndef _PARTIDA_H_
#define _PARTIDA_H_

#include "Pista.h"
#include "Acelerar.h"
#include "Boost.h"
#include "Carro.h"
#include "Recta.h"
#include "Asfalto.h"
#include "3rd_party/Box2D-cmake/Box2D/Box2D/Box2D.h"
#include "CajaDeSalud.h"

class Partida {
  private:
    Pista pista;
    Asfalto asfalto;
    Recta recta;
    Carro carro;
    CajaDeSalud cajaDeSalud;
    float32 timeStep;
    int32 velocidadDeIteraciones;
    int32 positionIterations;

  public:
    Partida(b2Vec2 gravedad);

    void simular();

    ~Partida();
};

#endif
