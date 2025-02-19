//
// Created by manfer on 19/11/19.
//

#ifndef FFMPEG_CODEC_H
#define FFMPEG_CODEC_H

#include "Frame.h"

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavutil/opt.h>
}

class Codec {
    AVCodecID id = AV_CODEC_ID_H264;
    AVCodec* codec;
    AVCodecContext* contexto;
public:
    Codec(const int &ancho, const int &alto);
    void codificarFrame(Frame &frame);
    void finalizar();
    void inicializarFrame(Frame &frame);
    /* Guarda un paquete codificado en <paquete> y devuelve true en
     * caso de que se haya guardado correctamente */
    bool obtenerPaquete(AVPacket* paquete);
    AVCodecID obtenerID();

    ~Codec();
};


#endif //FFMPEG_CODEC_H
