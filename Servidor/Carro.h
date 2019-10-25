#ifndef _CARRO_H_
#define _CARRO_H_

#include "3rd_party/Box2D-cmake/Box2D/Box2D/Box2D.h"
#include "Pista.h"
class Carro {
  private:
    b2BodyDef bodyDef;
    b2Body* body;
    float32 anguloDeGiro;

    void aplicarFuerza()
  public:
    Carro();

    void agregarseA(Pista *pista);

    void acelerar();

    void frenar();

    void giroADerecha();

    void giroAIzquierda();

    void imprimirPosicion(); //FUNCION DE PRUEBA
};


#endif