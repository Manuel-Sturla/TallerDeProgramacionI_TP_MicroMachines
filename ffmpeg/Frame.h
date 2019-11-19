//
// Created by manfer on 19/11/19.
//

#ifndef FFMPEG_FRAME_H
#define FFMPEG_FRAME_H


#include <libavutil/frame.h>

class Frame {
    AVFrame* frame;
public:
    Frame();
    uint8_t** obtenerDatos();
    int obtenerAltura();
    int obtenerAncho();
    void setPts(uint64_t nuevoPts);
    ~Frame();
};


#endif //FFMPEG_FRAME_H
