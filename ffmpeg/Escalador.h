//
// Created by manfer on 19/11/19.
//

#ifndef FFMPEG_ESCALADOR_H
#define FFMPEG_ESCALADOR_H

#include "Frame.h"

extern "C"{
#include <libswscale/swscale.h>
};

class Escalador {
    SwsContext* escalador;
public:
    Escalador(const long &ancho, const long &alto);
    void escalar(Frame frame);
    ~Escalador();
};


#endif //FFMPEG_ESCALADOR_H
