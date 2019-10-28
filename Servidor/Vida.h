#ifndef _VIDA_H_
#define _VIDA_H_

class Vida {
  private:
    int vida;
  public:
    Vida();

    void recibirDanio(int danio);

    void matar();

    void revivir();

    ~Vida();

};

#endif
