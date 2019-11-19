//
// Created by manfer on 19/11/19.
//

#ifndef FFMPEG_VIDEOSALIDA_H
#define FFMPEG_VIDEOSALIDA_H


#include <fstream>
#include <libavformat/avformat.h>
#include "Codec.h"

class VideoSalida {
    //Codec
    Codec codec;
    std::ofstream archivoSalida;
    AVFrame* frame;
    AVPacket* paquete;
    AVOutputFormat* formatoSalida;
public:
    VideoSalida(const std::string& nombre);
    void escribirFrame();
};


#endif //FFMPEG_VIDEOSALIDA_H
