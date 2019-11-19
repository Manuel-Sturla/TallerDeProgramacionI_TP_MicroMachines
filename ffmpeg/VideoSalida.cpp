//
// Created by manfer on 19/11/19.
//

#include "VideoSalida.h"
#include "ErrorFfmpeg.h"

void VideoSalida::escribirFrame() {
    codec.codificarFrame(frame);
    while (codec.obtenerPaquete(paquete)){
        archivoSalida.write(reinterpret_cast<const char *>(paquete->data), paquete->size);
    }
}

VideoSalida::VideoSalida(const std::string &nombre){
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
}
