#ifndef _MAPA_H_
#define _MAPA_H_

#include "Suelos/Pasto.h"
#include "Suelos/Asfalto.h"
#include "Suelos/LimiteDePista.h"
#include "Suelos/Recta.h"

class Mapa {
  private:

    Pista pista;
    Carro carro;
    Asfalto asfalto;
    Pasto pasto;
    LimiteDePista limiteDePista;

  public:
    Mapa(b2Vec2 gravedad);

    Material* darMaterial(std::string materialPedido);

    void simular();

    void agregarRecta(Recta recta);

    ~Mapa();
};


#endif
