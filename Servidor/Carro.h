#ifndef _CARRO_H_
#define _CARRO_H_

#include "3rd_party/Box2D-cmake/Box2D/Box2D/Box2D.h"
#include "Pista.h"
#include "Accion.h"
#include "Objeto.h"
#include "Vida.h"
#include "Visibilidad.h"
#include "Velocidad.h"
#include "EstadoVelocidad.h"

class Carro: public Objeto {
  private:
    b2BodyDef bodyDef;
    b2Body* cuerpo;
    Vida vida;
    Visibilidad visibilidad;
    EstadoVelocidad estadoVelocidad;
    float32 anguloDeGiro;
    float32 coeficienteDeRozamiento;
    float32 agarre;

  public:
    Carro(float32 velocidadMaxima, float32 anguloDeGiro, float32 agarre, float32 x,  float32 y);

    void agregarseA(Pista *pista);

    void actualizar();

    void ejecutarAccion(Accion* unaAccion);

    void aplicarFriccion(float32 coeficienteDeRozamiento);

    std::string darId();

    void recibirDanio(int danio);

    void curar(int aumentoDeVida);

    void reducirVelocidad(float32 factor);

    void recibirBoost();

    void reducirVisibilidad();

    void reducirAgarre();

    bool esValido() override;

    void imprimirPosicion(); //FUNCION DE PRUEBA
};


#endif