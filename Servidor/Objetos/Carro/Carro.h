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
    std::string idConductor;
    Vida vida;
    Visibilidad visibilidad;
    EstadoVelocidad estadoVelocidad;
    Agarre agarre;
    Posicion posicion;
    float32 anguloDeGiro;
    float32 coeficienteDeRozamiento;

  public:

    Carro(MundoBox2D &mundoBox2D, float32 velocidadMaxima, float32 aceleracion,
        float32 anguloDeGiro, float32 agarre, float32 x,  float32 y, float32  anguloInicial,
        size_t idCliente);

    void agregarseA(MundoBox2D &mundoBox2D, float32 x, float32 y, float32 anguloInicial);

    int obtenerSueloParaRevivir();

    void actualizar();

    void borrar();

    void ejecutarAccion(Accion& unaAccion);

    void revivir(MundoBox2D &pista, float32 x, float32 y);

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

    bool operator< (const Carro& otroCarro);

    std::string darIdConductor();

    bool moriRecientemente();

    bool termineCarrera(int cantidadDeVueltasParaTerminar);

    void empaquetarVida(std::vector<std::string> *destino);

    void empaquetarId(c);

    void imprimirPosicion(); //FUNCION DE PRUEBA
};


#endif