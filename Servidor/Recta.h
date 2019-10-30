#ifndef _RECTA_H_
#define _RECTA_H_

#include "Pista.h"
#include "Material.h"
#include "Suelo.h"
#include "Cuadrado.h"

class Recta: public Suelo {
  private:
    Material *material;
    Cuadrado cuadrado;

  public:
    Recta(Pista *pista, Material *unMaterial);

    void interactuar(Carro *unCarro);

    ~Recta();
};

#endif
