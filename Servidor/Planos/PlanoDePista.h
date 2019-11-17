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
  std::list<b2Vec2> posicionesDeInicio;
  float32 anguloInicial;
public:
  PlanoDePista(float32 anguloInicial);

  void agregarRecta(std::string material, int x, int y, int tipo, int numero);

  void agregarCurva(int x, int y, int tipo, int numero);

  void agregarPosicionDeInicio(int x, int y);

  void crearPista(Pista &mapa);

  ~PlanoDePista();
};


#endif
