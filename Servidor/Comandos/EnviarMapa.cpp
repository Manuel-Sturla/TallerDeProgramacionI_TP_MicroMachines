#include "EnviarMapa.h"

EnviarMapa::EnviarMapa(Protocolo &protocolo, std::vector<std::string>& mapa):
protocolo(protocolo), posMapa(mapa) {
}

void EnviarMapa::ejecutar() {
    for (auto& pos: posMapa){
        protocolo.enviar(pos);
    }
    protocolo.enviar(MSJ_FIN);
}
