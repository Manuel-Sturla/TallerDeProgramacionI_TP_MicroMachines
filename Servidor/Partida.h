#ifndef _PARTIDA_H_
#define _PARTIDA_H_

#include "Pista.h"
#include "Acciones/Acelerar.h"
#include "Modificadores/Boost.h"
#include "Carro/Carro.h"
#include "Suelos/Recta.h"
#include "Suelos/Asfalto.h"
#include "3rd_party/Box2D-cmake/Box2D/Box2D/Box2D.h"
#include "Modificadores/CajaDeSalud.h"
#include "Suelos/Pasto.h"
#include "Suelos/Curva.h"

class Partida {
  private:
    Pista pista;
    Asfalto asfalto;
    Pasto pasto;
    Curva curva;
    //Recta recta;
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
