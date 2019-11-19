//
// Created by manfer on 19/11/19.
//

#include "Escalador.h"

Escalador::Escalador(const long &ancho, const long &alto) {
    escalador = sws_getContext(ancho, alto,
                   AV_PIX_FMT_RGB24, ancho, alto,
                   AV_PIX_FMT_YUV420P, 0, 0, 0, 0);
}

Escalador::~Escalador() {
    sws_freeContext(escalador);
}
