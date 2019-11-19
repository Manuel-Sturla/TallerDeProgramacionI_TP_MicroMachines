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
#include "VideoSalida.h"
#include "Escalador.h"

class GrabadorVideo {
    AVFormatContext* contexto;
    std::unique_ptr<VideoSalida> video;
    const long ancho = 352, alto = 288;
    Escalador escalador;
public:
    GrabadorVideo(); //Tendria que recibir el renderizador sobre la que va a grabar
    void grabarVideo(const std::string &nombre);
    void run();
    ~GrabadorVideo();
};


#endif //FFMPEG_GRABADORVIDEO_H
