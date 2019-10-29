//
// Created by diego on 28/10/19.
//

#include "Auto.h"

Auto::Auto(Renderizador& renderizador){

void Auto::crear(Renderizador& renderizador, int ancho, int altura) {
    int tamAuto = 100;
    auto* posicion = new Posicion(ancho/2, altura/2, tamAuto, tamAuto);
    renderizador.agregarTextura("auto.png", posicion, 0);
    textura = renderizador.obtenerUltimaTextura();
}
