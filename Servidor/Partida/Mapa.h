#ifndef _MAPA_H_
#define _MAPA_H_

#include <list>
#include "../Objetos/Suelos/Pasto.h"
#include "../Objetos/Suelos/Asfalto.h"
#include "../Objetos/Suelos/LimiteDePista.h"
#include "../Objetos/Suelos/Recta.h"
#include "../Objetos/Suelos/Curva.h"

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

    Carro* getCarro();

    void empaquetarCarro(std::vector<std::string> *destino);

    void empaquetarSuelos(std::vector<std::string> *destino);

    void
    agregarRecta(std::string &material, float32 x, float32 y, float32 angulo);

    void agregarCurva(float32 x, float32 y, float32 angulo);

    ~Mapa();
};


#endif
