//
// Created by diego on 25/11/19.
//

#include "ComandoGrabar.h"

ComandoGrabar::ComandoGrabar(GrabadorVideo& grabador, ServidorProxy &servidor, const Uint8 *estados) :\
ComandoTeclado(servidor, estados), grabador(grabador) {
    grabando = false;
    cantVideos = 0;
}

void ComandoGrabar::ejecutar() {}

void ComandoGrabar::apretar() {
    ComandoTeclado::apretar();
}

void ComandoGrabar::desapretar() {
    if(estaApretado && !grabando){
        grabador.grabarVideo("Video"+std::to_string(cantVideos)+".mpeg");
        grabando = true;
    } else if(estaApretado && grabando){
        grabador.terminar();
        grabando = false;
        cantVideos++;
    }
    ComandoTeclado::desapretar();
}


