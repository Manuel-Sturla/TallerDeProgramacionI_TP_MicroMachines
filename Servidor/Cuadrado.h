#ifndef _CUADRADO_H_
#define _CUADRADO_H_

#include "Figura.h"

class Cuadrado: public Figura {
  public:
    Cuadrado(Pista *pista, Suelo *unSuelo);

    std::string darId();

    bool esValido() override;

    void interactuar(Carro *unCarro) override;

    ~Cuadrado();
};


#endif
