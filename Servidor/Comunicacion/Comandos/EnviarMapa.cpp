//
// Created by manfer on 6/11/19.
//

#include "EnviarMapa.h"

EnviarMapa::EnviarMapa(std::map<std::string, std::shared_ptr<Partida>> &partidas): partidas(partidas) {
}

void EnviarMapa::ejecutar(ClienteProxy &cliente) {
    //Recibe la partida de la cual se va a enviar el mapa
    //std::string partida = cliente.recibir();
    std::string partida = "prueba";
    std::vector<std::string> posiciones = partidas[partida]->obtenerMapa();
    for (auto& pos : partidas[partida]->obtenerMapa()){
        cliente.enviar(pos);
    }
    cliente.enviar(MSJ_FIN);
}
