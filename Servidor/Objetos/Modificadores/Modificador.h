#ifndef _MODIFICADOR_H_
#define _MODIFICADOR_H_

#include "../Interactuable.h"
#include "../Carro/Carro.h"

class Modificador: public Interactuable {
  protected:
    bool validez;
    std::string tipo;
    std::string id;

  public:
    std::string darId();

    void empaquetar(std::vector<std::string> *destino);
};

#endif