//
// Created by manfer on 19/11/19.
//

#include "Frame.h"
#include "ErrorFfmpeg.h"

Frame::Frame() {
    frame = av_frame_alloc();
    if (!frame){
        throw ErrorFfmpeg("No hay suficiente memoria para guardar el Frame", __LINE__, __FILE__);
    }
}

Frame::~Frame() {
    av_frame_free(&frame);
}

uint8_t** Frame::obtenerDatos() {
    return frame->data;
}

void Frame::setPts(int64_t nuevoPts) {
    frame->pts = nuevoPts;
}

int Frame::obtenerAltura() {
    return frame->height;
}

int Frame::obtenerAncho() {
    return frame->width;
}

AVFrame *Frame::obtenerFrame() {
    return frame;
}

void Frame::inicializar(AVPixelFormat formatoPixeles, int ancho, int alto) {
    frame->format = formatoPixeles;
    frame->width = ancho;
    frame->height = alto;
    int ret = av_frame_get_buffer(this->frame, 0);
    if (ret < 0){
        throw ErrorFfmpeg("Error al reservar buffers del frame", __LINE__, __FILE__);
    }
}

int * Frame::obtenerTamanioLinea() {
    return frame->linesize;
}

void Frame::limpiar() {
    av_frame_unref(frame);
}
