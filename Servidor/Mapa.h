#ifndef _MAPA_H_
#define _MAPA_H_

#include <list>
#include "Suelos/Pasto.h"
#include "Suelos/Asfalto.h"
#include "Suelos/LimiteDePista.h"
#include "Suelos/Recta.h"
#include "Suelos/Curva.h"

class Mapa {
  private:
    Pista pista;
    Carro carro;
    Asfalto asfalto;
    Pasto pasto;
    LimiteDePista limiteDePista;
    std::list<Recta> rectas;
    std::list<Curva> curvas;

  public:
    Mapa();

    Material* darMaterial(std::string materialPedido);

    void simular();

    Pista* darPista();

    void agregarRecta(Recta recta);

    void agregarCurva(Curva curva);

    ~Mapa();
};


#endif
