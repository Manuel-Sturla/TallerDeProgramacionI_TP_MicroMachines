#ifndef _VIDA_H_
#define _VIDA_H_

#include <string>
#include <vector>

class Vida {
  private:
    int vida;
    int esperaParaRevivir;
    bool enJuego;
    bool moriEnLaSimulacionActual;
  public:
    Vida();

    void recibirDanio(int danio);

    void aumentarVida(int aumento);

    void matar();

    bool puedoRevivir();

    bool estoyVivo();

    bool moriRecientemente();

    void revivir();

    void salirDeJuego();

    void empaquetar(std::vector<std::string> *destino);

    ~Vida();

};

#endif
