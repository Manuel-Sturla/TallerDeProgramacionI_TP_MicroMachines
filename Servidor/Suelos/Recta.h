#ifndef _RECTA_H_
#define _RECTA_H_

#include "../Pista.h"
#include "Material.h"
#include "Suelo.h"

class Recta: public Suelo {
  private:
    b2Body *cuerpo;
    Material *material;

  public:
    Recta(Pista *pista, Material *unMaterial, float32 x, float32 y);

    Recta(Recta &&otraRecta);

    Recta& operator= (Recta &&otraRecta);

    void interactuar(Carro *unCarro);

    std::string darId();

    bool esValido();

    ~Recta();
};

#endif
