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
    int alto;
    int ancho;
public:
    Escalador(const int &anchoNuevo, const int &altoNuevo);
    void escalar(Frame& frame, std::vector<char> &datos);
    ~Escalador();
};


#endif //FFMPEG_ESCALADOR_H
