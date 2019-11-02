//
// Created by manfer on 2/11/19.
//

#include "EnviarMapa.h"

EnviarMapa::EnviarMapa(Protocolo &protocolo):protocolo(protocolo), posMapa( std::vector<std::string> {"Asfalto, 2-1", "..."}) {
}

void EnviarMapa::ejecutar() {
    for (auto& pos: posMapa){
        protocolo.enviar(pos);
    }
    protocolo.enviar(MSJ_FIN);
}
