//
// Created by manfer on 23/11/19.
//

#include <vector>
#include <iostream>
#include "HiloEscritor.h"

#define SENIAL_FIN 'F'

void HiloEscritor::run() {
    //FALTA try catch
    while (continuar){
        std::vector<char> aux = bufferDatos.sacar();
        if (aux == senialFin){
            break;
        }
        escalador.escalar(frame, aux);
        video.escribirFrame();
    }
}

HiloEscritor::HiloEscritor(Frame &frameRecibido,\
Escalador &escaladorRecibido, VideoSalida &videoRecibido, BufferBloqueante& bufferRecibido):
        continuar(true),
        frame(frameRecibido),
        escalador(escaladorRecibido),
        video(videoRecibido),
        bufferDatos(bufferRecibido),
        senialFin(1,SENIAL_FIN){
}

void HiloEscritor::pausar() {
    continuar = false;
}

void HiloEscritor::reanudar() {
    continuar = true;
}
