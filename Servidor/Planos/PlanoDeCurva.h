#ifndef _PLANODECURVA_H_
#define _PLANODECURVA_H_

#include "PlanoDeSuelo.h"
#include "../Partida/Mapa.h"

class PlanoDeCurva: public PlanoDeSuelo {
private:
  int posicionX;
  int posicionY;
  std::string tipo;
public:
  PlanoDeCurva(const std::string& configuracion);

  void agregarSueloA(Mapa *mapa) override;

  ~PlanoDeCurva();
};


#endif
