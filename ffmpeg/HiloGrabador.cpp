//
// Created by manfer on 23/11/19.
//

#include <vector>
#include <iostream>
#include "HiloGrabador.h"

#define SENIAL_FIN 'F'

void HiloGrabador::run() {
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

HiloGrabador::HiloGrabador(Frame &frameRecibido,\
Escalador &escaladorRecibido, VideoSalida &videoRecibido, BufferBloqueante& bufferRecibido):
        frame(frameRecibido),
        video(videoRecibido),
        escalador(escaladorRecibido),
        bufferDatos(bufferRecibido),
        continuar(true),
        senialFin(1,SENIAL_FIN){
}

void HiloGrabador::pausar() {
    continuar = false;
}

void HiloGrabador::reanudar() {
    continuar = true;
}
