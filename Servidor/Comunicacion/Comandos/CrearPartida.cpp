//
// Created by manfer on 5/11/19.
//

#include "CrearPartida.h"

#define MSJ_PARTIDA_INVALIDA "Partida Ya existente"

CrearPartida::CrearPartida(std::map<std::string, std::shared_ptr<Partida>> &partidas,
                           ConfiguracionServidor &mapasYAutos) : partidas(partidas), mapasYAutos(mapasYAutos) {
}

void CrearPartida::ejecutar(ClienteProxy &cliente) {
    std::string nombrePartida = cliente.recibir();
    auto it = partidas.find(nombrePartida);
    if (it != partidas.end()){
        cliente.enviar(MSJ_PARTIDA_INVALIDA);
        return;
    }
    //Elije un mapa
    for (auto& mapa : mapasYAutos.obtenerNombresPlanos()){
        cliente.enviar(mapa);
    }
    cliente.enviar(MSJ_FIN);
    std::string mapa = cliente.recibir();
    int cantJugadores = std::stoi(cliente.recibir());
    partidas.emplace(nombrePartida, new Partida(cantJugadores, mapasYAutos.darPlanoDePista(mapa)));
    //Envio que la partida se creo correctamente?
    //Falta en algun lugar enviarle las posicoines del mapa
}
