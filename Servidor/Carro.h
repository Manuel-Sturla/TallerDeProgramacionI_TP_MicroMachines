#ifndef _CARRO_H_
#define _CARRO_H_

#include "3rd_party/Box2D-cmake/Box2D/Box2D/Box2D.h"
#include "Pista.h"
#include "Objeto.h"
class Carro: public Objeto {
  private:
    b2BodyDef bodyDef;
    b2Body* body;
    float32 anguloDeGiro;
    float32 velocidadMax;

    //El factor de fuerza es multiplicado por el cos del angulo en el eje x
    // y por el sen del angulo en y
    void aplicarFuerza(float32 factorDeFuerza);
  public:
    Carro(float32 velocidadMaxima, float32 anguloDeGiro);

    void agregarseA(Pista *pista);

    void acelerar();

    void frenar();

    void giroADerecha();

    void giroAIzquierda();

    void aplicarFriccion(float32 coeficienteDeRozamiento);

    std::string darId();

    void imprimirPosicion(); //FUNCION DE PRUEBA
};


#endif