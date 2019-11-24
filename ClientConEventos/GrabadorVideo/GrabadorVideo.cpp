//
// Created by manfer on 19/11/19.
//

#include <SDL2/SDL_system.h>
#include <iostream>
#include "GrabadorVideo.h"
#include "ErrorFfmpeg.h"
#include "BufferBloqueante.h"

#define SENIAL_FIN 'F'
GrabadorVideo::GrabadorVideo(Renderizador& render) :
        renderizador(render),
        escalador(render.obtenerAncho(), render.obtenerAltura()),
        ancho(render.obtenerAncho()),
        alto(render.obtenerAltura()),
        bufferDatos(),
        grabando(false){
    av_register_all();
    contexto = avformat_alloc_context();
}

GrabadorVideo::~GrabadorVideo() {
    if (grabando){
        terminar();
    }
    avformat_free_context(contexto);
}

void GrabadorVideo::grabarVideo(const std::string &nombre) {
    grabando = true;
    std::unique_ptr<VideoSalida> aux (new VideoSalida(nombre, frame, ancho, alto));
    video = std::move(aux);
    std::unique_ptr<HiloEscritor> hilo (new HiloEscritor(frame, escalador, *video, bufferDatos));
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
    grabando = false;
}

void GrabadorVideo::pausar() {
    hiloGrabador->pausar();
}

void GrabadorVideo::reanudar() {
    hiloGrabador->reanudar();
}

void GrabadorVideo::obtenerDatosTextura() {
    std::vector<char> aux = renderizador.obtenerDatos(alto, ancho, formato);
    bufferDatos.guardar(aux);
}

bool GrabadorVideo::estaGrabando() {
    return grabando;
}
