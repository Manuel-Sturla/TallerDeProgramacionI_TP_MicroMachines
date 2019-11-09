#ifndef _RECTA_H_
#define _RECTA_H_

#include "../../Partida/MundoBox2D.h"
#include "Material.h"
#include "Suelo.h"

class Recta: public Suelo {
  private:
    Material *material;

  public:
    Recta(MundoBox2D *pista, Material *unMaterial, float32 x, float32 y,
          float32 angulo, int numeroDeSuelo);

    Recta(Recta &&otraRecta);

    Recta(const Recta&);

    Recta&operator=(const Recta &otraRecta);

    Recta& operator= (Recta &&otraRecta);

    void interactuar(Carro *unCarro);

    std::string darId();

    bool esValido();

    void empaquetar(std::vector<std::string> *destino);

    ~Recta();
};

#endif
