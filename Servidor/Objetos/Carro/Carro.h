#ifndef _CARRO_H_
#define _CARRO_H_

#include "Box2D/Box2D.h"
#include "../../Partida/MundoBox2D.h"
#include "../../Acciones/Accion.h"
#include "Vida.h"
#include "Visibilidad.h"
#include "Velocidad.h"
#include "EstadoVelocidad.h"
#include "Agarre.h"
#include "Posicion.h"
#include "../Objeto.h"


class Carro: public Objeto {
  private:
    b2BodyDef bodyDef;
    Vida vida;
    Visibilidad visibilidad;
    EstadoVelocidad estadoVelocidad;
    Agarre agarre;
    Posicion posicion;
    float32 anguloDeGiro;
    float32 coeficienteDeRozamiento;

  public:
    //El agarre debe ser un numero en el intervalo (0 ; 100]
    Carro(MundoBox2D *pista, float32 velocidadMaxima, float32 anguloDeGiro, float32 agarre, float32 x,  float32 y);

    void agregarseA(MundoBox2D *pista, float32 x, float32 y);

    void actualizar();

    void ejecutarAccion(Accion* unaAccion);

    void aplicarFriccion(float32 coeficienteDeRozamiento);

    std::string darId() override;

    void recibirDanio(int danio);

    void curar(int aumentoDeVida);

    void reducirVelocidad(float32 factor);

    void recibirBoost();

    void reducirVisibilidad();

    void reducirAgarre();

    void actualizarPosicion(int numeroDeSuelo);

    bool esValido() override;

    void empaquetar(std::vector<std::string> *destino) override;

    void interactuar(Carro *otroCarro);

    void imprimirPosicion(); //FUNCION DE PRUEBA
};


#endif