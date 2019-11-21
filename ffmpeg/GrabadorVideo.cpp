//
// Created by manfer on 19/11/19.
//

#include <SDL2/SDL_system.h>
#include "GrabadorVideo.h"
#include "ErrorFfmpeg.h"
#include "BufferBloqueante.h"

GrabadorVideo::GrabadorVideo(BufferBloqueante &buffer) :
escalador(ancho, alto), continuar(true),
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
}

void GrabadorVideo::run() {
    //while (continuar){
        //int res = SDL_RenderReadPixels(renderizador, NULL, SDL_PIXELFORMAT_RGB24, dataBuffer.data(), ancho * 3);
        //if (res != 0) {
        //    throw ErrorFfmpeg("Error al obtener el renderizado del video", __LINE__, __FILE__);
        //}
        std::vector<char> aux = bufferDatos.sacar();
        escalador.escalar(frame, aux);
        video->escribirFrame();
    //}
    video->terminar();
}
