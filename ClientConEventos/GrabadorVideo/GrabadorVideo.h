//
// Created by manfer on 19/11/19.
//

#ifndef FFMPEG_GRABADORVIDEO_H
#define FFMPEG_GRABADORVIDEO_H

extern "C" {
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
}

#include <string>
#include <memory>
#include <vector>
#include "VideoSalida.h"
#include "Escalador.h"
#include "BufferBloqueante.h"
#include "HiloEscritor.h"
#include "../Sdl/Renderizador.h"
#include <atomic>

class GrabadorVideo {
    Renderizador& renderizador;
    Escalador escalador;
    AVFormatContext* contexto;
    const int ancho , alto;
    Frame frame;
    BufferBloqueante bufferDatos;
    std::unique_ptr<HiloEscritor> hiloGrabador;
    std::atomic<bool> grabando;
    uint32_t formato = SDL_PIXELFORMAT_RGB24;
    std::unique_ptr<VideoSalida> video;
public:
    explicit GrabadorVideo(Renderizador& render);
    void obtenerDatosTextura();
    void grabarVideo(const std::string &nombre);
    void pausar();
    void reanudar();
    void terminar();
    bool estaGrabando();
    ~GrabadorVideo();
};


#endif //FFMPEG_GRABADORVIDEO_H
