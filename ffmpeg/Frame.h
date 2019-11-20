//
// Created by manfer on 19/11/19.
//

#ifndef FFMPEG_FRAME_H
#define FFMPEG_FRAME_H

extern "C"{
#include <libavformat/avformat.h>
};
class Frame {
    AVFrame* frame;
public:
    Frame();
    uint8_t** obtenerDatos();
    int obtenerAltura();
    int obtenerAncho();
    void setPts(uint64_t nuevoPts);
    AVFrame* obtenerFrame();
    void inicializar(AVPixelFormat formatoPixeles, int ancho, int alto);
    int * obtenerTamanioLinea();


    void limpiar();
    ~Frame();
};


#endif //FFMPEG_FRAME_H
