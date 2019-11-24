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
#include <atomic>

class GrabadorVideo {
    AVFormatContext* contexto;
    std::unique_ptr<VideoSalida> video;
    const long ancho = 352, alto = 288;
    Escalador escalador;
    Frame frame;
    BufferBloqueante& bufferDatos;
    std::unique_ptr<HiloEscritor> hiloGrabador;
public:
    explicit GrabadorVideo(BufferBloqueante &buffer);
    void grabarVideo(const std::string &nombre);
    void pausar();
    void reanudar();
    void terminar();
    ~GrabadorVideo();
};


#endif //FFMPEG_GRABADORVIDEO_H
