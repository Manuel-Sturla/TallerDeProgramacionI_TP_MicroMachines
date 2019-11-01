#include "Partida.h"
#include "Modificadores/CajaDeSalud.h"
#include "Acciones/GiroADerecha.h"
#include "Acciones/GiroAIzquierda.h"
#define ANGULO_PARA_GIRO b2_pi / 4 //HARDCODEADO
#define VELOCIDAD_MAXIMA 5 //HARCODEADO

Partida::Partida(b2Vec2 gravedad): pista(gravedad), curva(&pista, &asfalto, &pasto, 0.0f, 4.0f),
carro(VELOCIDAD_MAXIMA, ANGULO_PARA_GIRO, 100.0f, 0.0f, 4.0f), cajaDeSalud(&pista,0.0f, 4.0f){
  timeStep = 1.0f / 60.0f;
  velocidadDeIteraciones = 6;
  positionIterations = 2;
  carro.agregarseA(&pista);
}

void Partida::simular() {
  //Acelerar acelerar;
  //carro.ejecutarAccion(&acelerar);
  GiroAIzquierda giroADerecha;
  carro.ejecutarAccion(&giroADerecha);
  pista.simular(timeStep, velocidadDeIteraciones, positionIterations);
  pista.actualizar();
  carro.imprimirPosicion();
  carro.actualizar();
}

Partida::~Partida() {
}
