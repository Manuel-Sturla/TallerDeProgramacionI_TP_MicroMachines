//
// Created by manfer on 19/11/19.
//

#ifndef FFMPEG_VIDEOSALIDA_H
#define FFMPEG_VIDEOSALIDA_H


#include <fstream>
extern "C"{
    #include <libavformat/avformat.h>
};
#include "Codec.h"
#include "Frame.h"

class VideoSalida {
    Frame& frame;
    Codec codec;
    std::ofstream archivoSalida;
    AVPacket* paquete;
    AVOutputFormat* formatoSalida;
    int64_t ptsActual = 0;
    void inicializarFrame();
    void escribirPaquetes();
public:
    VideoSalida(const std::string &nombre, Frame &frame, const int &ancho, const int &alto);
    void escribirFrame();
    void terminar();
    ~VideoSalida();
};


#endif //FFMPEG_VIDEOSALIDA_H
