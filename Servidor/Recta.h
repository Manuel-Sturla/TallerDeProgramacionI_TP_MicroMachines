#ifndef _RECTA_H_
#define _RECTA_H_

#include "Pista.h"
#include "Material.h"
#include "Suelo.h"

class Recta: public Suelo {
  private:
    b2BodyDef bodyDef;
    b2Body *body;
    Material *material;

  public:
    Recta(Material *unMaterial);

    void agregarseA(Pista *pista);

    std::string darId();

    void interactuar(Carro *unCarro) override;

    ~Recta();
};

#endif
