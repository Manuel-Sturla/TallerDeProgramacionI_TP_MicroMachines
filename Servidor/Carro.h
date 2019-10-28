#ifndef _CARRO_H_
#define _CARRO_H_

#include "3rd_party/Box2D-cmake/Box2D/Box2D/Box2D.h"
#include "Pista.h"
#include "Accion.h"
#include "Objeto.h"
#include "Vida.h"

class Carro: public Objeto {
  private:
    b2BodyDef bodyDef;
    b2Body* body;
    Vida vida;
    float32 anguloDeGiro;
    float32 velocidadMax;
    float32 coeficienteDeRozamiento;

  public:
    Carro(float32 velocidadMaxima, float32 anguloDeGiro);

    void agregarseA(Pista *pista);

    void actualizar();

    void ejecutarAccion(Accion* unaAccion);

    void aplicarFriccion(float32 coeficienteDeRozamiento);

    std::string darId();

    void recibirDanio(int danio);

    void imprimirPosicion(); //FUNCION DE PRUEBA
};


#endif