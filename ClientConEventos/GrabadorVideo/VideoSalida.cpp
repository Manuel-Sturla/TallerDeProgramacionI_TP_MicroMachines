//
// Created by manfer on 19/11/19.
//

#include "VideoSalida.h"
#include "ErrorFfmpeg.h"
void VideoSalida::escribirPaquetes(){
    while (codec.obtenerPaquete(paquete)){
        archivoSalida.write(reinterpret_cast<const char *>(paquete->data), paquete->size);
    }
}

void VideoSalida::escribirFrame() {
    frame.setPts(ptsActual);
    ptsActual++;
    codec.codificarFrame(frame);
    escribirPaquetes();
}

VideoSalida::VideoSalida(const std::string &nombre, Frame &frame) : frame(frame){
    this->paquete = av_packet_alloc();
    // Intenta deducir formato según extensión
    this->formatoSalida = av_guess_format(NULL, nombre.c_str(), NULL);
    if (!this->formatoSalida) {
        // Intenta usar el formato standard
        this->formatoSalida = av_guess_format("mpeg", NULL, NULL);
    }
    if (!this->formatoSalida) {
        throw ErrorFfmpeg("No se pudo identificar el formato de salida", __LINE__, __FILE__);
    }
    this->formatoSalida->video_codec = codec.obtenerID();
    archivoSalida.open(nombre, std::ofstream::out | std::ofstream::binary);
    if (!archivoSalida.is_open()){
        throw ErrorFfmpeg("No se pudo crear el archivo de salida", __LINE__, __FILE__);
    }

    inicializarFrame();
}

void VideoSalida::inicializarFrame() {
    codec.inicializarFrame(frame);
    ptsActual = 0;
}

VideoSalida::~VideoSalida() {
    av_packet_free(&paquete);
}

void VideoSalida::terminar() {
    codec.finalizar();
    escribirPaquetes();
    uint8_t fin[] = { 0, 0, 1, 0xb7 };
    archivoSalida.write(reinterpret_cast<const char *>(fin), sizeof(fin));
}
