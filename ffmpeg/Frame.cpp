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

void Frame::setPts(uint64_t nuevoPts) {
    frame->pts = nuevoPts;
}

int Frame::obtenerAltura() {
    return frame->height;
}

int Frame::obtenerAncho() {
    return frame->width;
}
