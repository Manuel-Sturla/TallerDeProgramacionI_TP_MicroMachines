//
// Created by manfer on 5/11/19.
//

#include "CrearPartida.h"
#include "../Utilidades.h"

#define MSJ_PARTIDA_INVALIDA "Partida Ya existente"

CrearPartida::CrearPartida(std::map<std::string, std::shared_ptr<Partida>> &partidas,
                           ConfiguracionServidor &mapasYAutos) : partidas(partidas), mapasYAutos(mapasYAutos) {
}

void CrearPartida::ejecutar(ClienteProxy &cliente) {
    std::string datosPartida = cliente.recibir();
    std::vector<std::string> datos = separar(datosPartida, ';');
    auto it = partidas.find(datos[0]);
    if (it != partidas.end()){
        cliente.enviar(MSJ_PARTIDA_INVALIDA);
        return;
    }
    //Elije un mapa
/*    for (auto& mapa : mapasYAutos.obtenerNombresPlanos()){
        cliente.enviar(mapa);
    }
    cliente.enviar(MSJ_FIN);
    std::string mapa = cliente.recibir();*/
    int cantJugadores = std::stoi(datos[1]);
    partidas.emplace(datos[0], new Partida(cantJugadores, mapasYAutos.darPlanoDePista("Prueba 1")));
    partidas[datos[0]]->start();
}
