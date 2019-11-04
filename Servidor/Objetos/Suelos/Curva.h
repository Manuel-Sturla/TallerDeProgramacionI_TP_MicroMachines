#ifndef _CURVA_H_
#define _CURVA_H_

#include <Box2D/Box2D.h>
#include "Material.h"
#include "../../Partida/Pista.h"
#include "Suelo.h"
#include "Asfalto.h"
#include "Pasto.h"

class Curva: public Suelo {
  private:
    const int circulo = 1;
    const int cuadrado = 2;
    int interaccion;
    Asfalto *asfalto;
    Pasto *pasto;

  public:
    Curva(Pista *pista, Asfalto *asfalto, Pasto *pasto, float32 x, float32 y,
          float32 angulo);

    void agregarseAPista(Pista *pista, float32 angulo);

    std::string darId();

    Curva(Curva &&otraCurva);

    Curva(const Curva& otraCurva);

    Curva&operator=(const Curva& otraCurva);

    Curva& operator= (Curva &&otraCurva);

    bool esValido() override;

    void tipoDeInteraccion(int identificadorDeInteraccion);

    void interactuar(Carro *unCarro);

    void empaquetar(std::vector<std::string> *destino);

    ~Curva();

};


#endif
