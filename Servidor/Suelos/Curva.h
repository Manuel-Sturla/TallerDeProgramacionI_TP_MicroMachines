#ifndef _CURVA_H_
#define _CURVA_H_

#include <Box2D/Box2D.h>
#include "Material.h"
#include "../Pista.h"
#include "Suelo.h"
#include "Asfalto.h"
#include "Pasto.h"

class Curva: public Suelo {
  private:
    b2BodyDef defCuerpo;
    b2Body *cuerpo;
    const int circulo = 1;
    const int cuadrado = 2;
    int interaccion;
    Asfalto *asfalto;
    Pasto *pasto;

  public:
    Curva(Pista *pista, Asfalto *asfalto, Pasto *pasto, float32 x, float32 y);

    void agregarseAPista(Pista *pista);

    std::string darId();

    bool esValido() override;

    void tipoDeInteraccion(int identificadorDeInteraccion);

    void interactuar(Carro *unCarro);

    ~Curva();

};


#endif
