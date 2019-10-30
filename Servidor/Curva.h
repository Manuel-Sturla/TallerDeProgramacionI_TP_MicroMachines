#ifndef _CURVA_H_
#define _CURVA_H_

#include <Box2D/Box2D.h>
#include "Material.h"
#include "Pista.h"
#include "Suelo.h"
#include "Asfalto.h"
#include "Pasto.h"

class Curva: public Suelo {
  private:
    b2BodyDef defCirculo;
    b2BodyDef defCuadrado;
    b2Body *circulo;
    b2Body *cuadrado;
    Material *material;
    Asfalto asfalto;
    Pasto pasto;
    bool tocandoCirculo;
    bool tocandoCuadrado;
  public:
    Curva();

    void agregarseAPista(Pista *pista);

    std::string darId();

    void interactuar(Carro *unCarro);

    ~Curva();

};


#endif
