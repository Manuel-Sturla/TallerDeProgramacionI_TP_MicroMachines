#include "Mapa.h"
#include "Acciones/GiroAIzquierda.h"
#define ANGULO_PARA_GIRO b2_pi / 4 //HARDCODEADO
#define VELOCIDAD_MAXIMA 5 //HARCODEADO

Mapa::Mapa(b2Vec2 gravedad): pista(gravedad),
carro(VELOCIDAD_MAXIMA, ANGULO_PARA_GIRO, 100.0f, 0.0f, 4.0f)  {
  carro.agregarseA(&pista);
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
  pista.simular(timeStep, velocidadDeIteraciones, positionIterations);
  pista.actualizar();
  carro.imprimirPosicion();
  carro.actualizar();
}

void Mapa::agregarRecta(Recta recta) {
  rectas.emplace_back(recta);
}

void Mapa::agregarCurva(Curva curva) {
  curvas.emplace_back(curva);
}
