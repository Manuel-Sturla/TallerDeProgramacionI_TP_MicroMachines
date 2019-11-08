#ifndef _PLANODEPISTA_H_
#define _PLANODEPISTA_H_

#include <string>
#include <list>
#include <memory>
#include "PlanoDeSuelo.h"
#include "../Partida/Pista.h"

class PlanoDePista {
private:
  std::list<std::unique_ptr<PlanoDeSuelo>> planosDeSuelos;
public:
  PlanoDePista();

  void agregarRecta(std::string material, int x, int y, int tipo);

  void agregarCurva(int x, int y, int tipo);

  void crearPista(Pista *mapa);

  ~PlanoDePista();
};


#endif
