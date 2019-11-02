//
// Created by manfer on 2/11/19.
//

#include "EnviarMapa.h"

EnviarMapa::EnviarMapa(Protocolo &protocolo):protocolo(protocolo) {
}

void EnviarMapa::ejecutar() {
    for (auto& pos: posMapa){
        protocolo.enviar(pos);
    }
    protocolo.enviar(MSJ_FIN);
}
