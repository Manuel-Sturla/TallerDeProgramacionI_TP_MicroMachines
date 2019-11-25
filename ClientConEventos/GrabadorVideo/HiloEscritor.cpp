//
// Created by manfer on 23/11/19.
//

#include <vector>
#include <iostream>
#include "HiloEscritor.h"

#define SENIAL_FIN 'F'

void HiloEscritor::run() {
    //FALTA try catch
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock::time_point t2;
    int espera = 0;
    while (continuar){
        std::vector<char> aux = bufferDatos.sacar();
        if (aux == senialFin){
            break;
        }
        escalador.escalar(frame, aux);
        t2 = std::chrono::high_resolution_clock::now();
        espera += (1000/30) - std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
        if(espera < 0){
            t1 = t2;
            continue;
        } else {
            video.escribirFrame();
            t1 = t2 + std::chrono::milliseconds(espera);
            espera = 0;
        }
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
