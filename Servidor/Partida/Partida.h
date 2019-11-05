#ifndef _PARTIDA_H_
#define _PARTIDA_H_

#include <vector>
#include "Box2D/Box2D.h"
#include "Pista.h"
#include "../Planos/PlanoDePista.h"
#include "../Planos/PlanoDeCarro.h"

class Partida {
  private:
    Pista pista;
    std::vector<std::string> extras;
    std::vector<std::string> autos;
    std::vector<std::string> suelos;

  public:
    Partida();

    void simular();

    std::vector<std::string>& obtenerExtras();

    std::vector<std::string>& obtenerAutos();

    std::vector<std::string>& obtenerMapa();

    Carro* agregarCliente(PlanoDeCarro *planoDeCarro);

    void actualizar();

    void crearPista(PlanoDePista *planoDePista);

    ~Partida();
};

#endif
