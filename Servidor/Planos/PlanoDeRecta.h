#ifndef _PLANODERECTA_H_
#define _PLANODERECTA_H_

#include "PlanoDeSuelo.h"

class PlanoDeRecta: public PlanoDeSuelo {
  private:
    std::string material;
    int posicionX;
    int posicionY;
    std::string tipo;
  public:
    PlanoDeRecta(std::string configuracion);

    void agregarSueloA(Pista *pista) override;

    ~PlanoDeRecta();
};


#endif
