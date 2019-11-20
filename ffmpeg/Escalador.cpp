//
// Created by manfer on 19/11/19.
//

#include <vector>
#include "Escalador.h"

Escalador::Escalador(const int &anchoNuevo, const int &altoNuevo) {
    escalador = sws_getContext(anchoNuevo, altoNuevo,
                               AV_PIX_FMT_RGB24, anchoNuevo, altoNuevo,
                               AV_PIX_FMT_YUV420P, 0, 0, 0, 0);
    ancho = anchoNuevo;
    alto = altoNuevo;
}

Escalador::~Escalador() {
    sws_freeContext(escalador);
}

void Escalador::escalar(Frame& frame, std::vector<char> &datos) {
    const u_int8_t* tmp = (const u_int8_t*) datos.data();
    // El ancho del video x3 por la cantidad de bytes
    int anchoMultiplicado = ancho * 3;
    sws_scale(escalador, &tmp, &anchoMultiplicado, 0, frame.obtenerAltura(),
            frame.obtenerDatos(), frame.obtenerTamanioLinea());
}
