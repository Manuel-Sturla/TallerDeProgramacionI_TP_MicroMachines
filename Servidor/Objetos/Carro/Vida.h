#ifndef _VIDA_H_
#define _VIDA_H_

class Vida {
  private:
    int vida;
    int esperaParaRevivir;
    bool enJuego;
  public:
    Vida();

    void recibirDanio(int danio);

    void aumentarVida(int aumento);

    void matar();

    bool puedoRevivir();

    bool estoyVivo();

    void revivir();

    void salirDeJuego();

    ~Vida();

};

#endif
