//
// Created by manfer on 23/11/19.
//

#ifndef FFMPEG_HILOGRABADOR_H
#define FFMPEG_HILOGRABADOR_H


#include <atomic>
#include "Frame.h"
#include "Escalador.h"
#include "VideoSalida.h"
#include "BufferBloqueante.h"
#include "../Hilo.h"

class HiloGrabador: public Hilo {
    std::atomic<bool> continuar;
    Frame& frame;
    Escalador& escalador;
    VideoSalida& video;
    BufferBloqueante& bufferDatos;
    const std::vector<char> senialFin;
public:
    HiloGrabador(Frame& frame, Escalador& escalador, VideoSalida& video, BufferBloqueante& buffer);

    void run() override;

    void pausar();

    void reanudar();
};


#endif //FFMPEG_HILOGRABADOR_H
