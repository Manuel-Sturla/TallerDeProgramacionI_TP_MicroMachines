#ifndef _PARTIDA_H_
#define _PARTIDA_H_

#include <vector>
#include "3rd_party/Box2D-cmake/Box2D/Box2D/Box2D.h"
#include "Mapa.h"
#include "Planos/PlanoDePista.h"

class Partida {
  private:
    Mapa mapa;
    std::vector<std::string> extras;
    std::vector<std::string> autos;
    std::vector<std::string> suelos;

  public:
    Partida();

    void simular();

    std::vector<std::string>& obtenerExtras();

    std::vector<std::string>& obtenerAutos();

    std::vector<std::string>& obtenerMapa();

    void actualizar();

    void crearPista(PlanoDePista *planoDePista);

    ~Partida();
};

#endif
