#include "Mapa.h"
#include "Acciones/GiroAIzquierda.h"
#include "Acciones/Acelerar.h"

#define ANGULO_PARA_GIRO b2_pi / 4 //HARDCODEADO
#define VELOCIDAD_MAXIMA 5 //HARCODEADO

Mapa::Mapa(): carro(&pista, VELOCIDAD_MAXIMA, ANGULO_PARA_GIRO, 100.0f, 0.0f, 0.0f)  {
}

Material *Mapa::darMaterial(std::string materialPedido) {
  if (materialPedido == "Asfalto") {
    return &asfalto;
  } else if (materialPedido == "Pasto"){
    return  &pasto;
  } else {
    return &limiteDePista;
  }
}

Mapa::~Mapa() {
}

void Mapa::simular() {
  float32 timeStep = 1.0f / 60.0f;
  int32 velocidadDeIteraciones = 6;
  int32 positionIterations = 2;
  for (int32 i = 0; i < 50; ++i) {
    Acelerar acelerar;
    carro.ejecutarAccion(&acelerar);
    pista.simular(timeStep, velocidadDeIteraciones, positionIterations);
    pista.actualizar();
    carro.imprimirPosicion();
    carro.actualizar();
  }
}

void Mapa::agregarRecta(Recta recta) {
  rectas.emplace_back(std::move(recta));
}

void Mapa::agregarCurva(Curva curva) {
  curvas.emplace_back(std::move(curva));
}

Pista *Mapa::darPista() {
  return &pista;
}
