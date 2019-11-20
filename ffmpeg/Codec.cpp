//
// Created by manfer on 19/11/19.
//

#include "Codec.h"
#include "ErrorFfmpeg.h"
#include "Frame.h"

Codec::Codec() {
    codec = avcodec_find_encoder(id);
    if (!codec){
        throw ErrorFfmpeg("No se pudo instanciar el codec", __LINE__, __FILE__);
    }
    this->contexto = avcodec_alloc_context3(codec);

    this->contexto->width = 352; //Podria recibirlo por parametro
    this->contexto->height = 288;
    this->contexto->time_base = {1,25};
    this->contexto->framerate = {25,1};
    this->contexto->pix_fmt = AV_PIX_FMT_YUV420P;
    this->contexto->gop_size = 10;
    this->contexto->max_b_frames = 2;
    if (codec->id == AV_CODEC_ID_H265) {
        this->contexto->profile = FF_PROFILE_H264_BASELINE;
        int ret = av_opt_set(contexto->priv_data, "preset", "slow", 0);
        if (ret != 0){
            throw ErrorFfmpeg("Error al setear las opciones del contexto del Codec",
                strerror(ret), __LINE__, __FILE__);
        }
    }
    avcodec_open2(this->contexto, codec, NULL);
}

Codec::~Codec() {
    avcodec_free_context(&contexto);
}

void Codec::codificarFrame(Frame &frame) {
    int ret = avcodec_send_frame(contexto, frame.obtenerFrame());
    if (ret < 0){
        throw ErrorFfmpeg("Error al codificar frame: ", strerror(ret), __LINE__, __FILE__);
    }
}

bool Codec::obtenerPaquete(AVPacket *paquete) {
    int ret = avcodec_receive_packet(contexto, paquete);
    if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF){
        return false;
    }else if (ret < 0) {
        throw ErrorFfmpeg("Error al obtener paquete codificado: ", strerror(ret), __LINE__, __FILE__);
    }
    return true;
}

AVCodecID Codec::obtenerID() {
    return id;
}

void Codec::inicializarFrame(Frame &frame) {
    frame.inicializar(contexto->pix_fmt, contexto->width, contexto->height);
}

void Codec::finalizar() {
    int ret = avcodec_send_frame(contexto, NULL);
    if (ret < 0){
        throw ErrorFfmpeg("Error al codificar frame: ", strerror(ret), __LINE__, __FILE__);
    }
}
