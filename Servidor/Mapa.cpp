#include "Mapa.h"
#include "Acciones/GiroAIzquierda.h"
#include "Acciones/Acelerar.h"

#define ANGULO_PARA_GIRO b2_pi / 4 //HARDCODEADO
#define VELOCIDAD_MAXIMA 5 //HARCODEADO

Mapa::Mapa(): carro(&pista, VELOCIDAD_MAXIMA, ANGULO_PARA_GIRO, 100.0f, 0.0f, 0.0f),
recta(&pista, &asfalto, 0, 0), recta1(&pista, &pasto, 4, 0),
recta2(&pista, &asfalto, 4, 4), curva(&pista, &asfalto, &pasto, 0,4){
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

void Mapa::agregarRecta(Recta recta) {
  rectas.emplace_back(std::move(recta));
}

void Mapa::agregarCurva(Curva curva) {
  curvas.emplace_back(std::move(curva));
}

Pista *Mapa::darPista() {
  return &pista;
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

void Mapa::empaquetarCarro(std::vector<std::string> *destino) {
  carro.empaquetar(destino);
}

void Mapa::empaquetarSuelos(std::vector<std::string> *destino) {
  //std::list<Recta>::iterator itRectas;
  //std::list<Curva>::iterator itCurvas;
  destino -> emplace_back("4"); //LONGITUD DEL CUADRADO
  recta.empaquetar(destino);
  recta1.empaquetar(destino);
  //recta2.empaquetar(destino);
  //curva.empaquetar(destino);
  /*
  for (itRectas = rectas.begin(); itRectas != rectas.end(); itRectas++) {
    itRectas -> empaquetar(destino);
  }
  for (itCurvas = curvas.begin(); itCurvas != curvas.end(); itCurvas++) {
    itCurvas ->empaquetar(destino);
  }*/
}
