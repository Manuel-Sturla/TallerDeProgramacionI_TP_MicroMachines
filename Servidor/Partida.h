#ifndef _PARTIDA_H_
#define _PARTIDA_H_

#include "3rd_party/Box2D-cmake/Box2D/Box2D/Box2D.h"
#include "Mapa.h"
#include "Planos/PlanoDePista.h"

class Partida {
  private:
    Mapa mapa;

  public:
    Partida(b2Vec2 gravedad);

    void simular();

    void crearPista(PlanoDePista *planoDePista);

    ~Partida();
};

#endif
