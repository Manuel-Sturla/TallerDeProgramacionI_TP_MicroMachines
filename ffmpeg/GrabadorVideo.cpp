//
// Created by manfer on 19/11/19.
//

#include <SDL2/SDL_system.h>
#include <iostream>
#include "GrabadorVideo.h"
#include "ErrorFfmpeg.h"
#include "BufferBloqueante.h"

#define SENIAL_FIN 'F'
GrabadorVideo::GrabadorVideo(BufferBloqueante &buffer) :
escalador(ancho, alto),
bufferDatos(buffer){
    av_register_all();
    contexto = avformat_alloc_context();
}

GrabadorVideo::~GrabadorVideo() {
    avformat_free_context(contexto);
}

void GrabadorVideo::grabarVideo(const std::string &nombre) {
    std::unique_ptr<VideoSalida> aux (new VideoSalida(nombre, frame));
    video = std::move(aux);
    std::unique_ptr<HiloGrabador> hilo (new HiloGrabador(frame, escalador, *video, bufferDatos));
    hiloGrabador = std::move(hilo);
    hiloGrabador->start();
}

void GrabadorVideo::terminar() {
    std::vector<char> senialFin (1,SENIAL_FIN);
    bufferDatos.guardar(senialFin);
    hiloGrabador->pausar();
    std::cout << "Voy a hacer el join" << std::endl;
    hiloGrabador->join();
    std::cout << "Hice el join" << std::endl;
    video->terminar();
}

void GrabadorVideo::pausar() {
    hiloGrabador->pausar();
}

void GrabadorVideo::reanudar() {
    hiloGrabador->reanudar();
}
