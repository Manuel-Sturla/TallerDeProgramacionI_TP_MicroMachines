//
// Created by manfer on 5/11/19.
//

#include "CrearPartida.h"
#include "../Utilidades.h"

#define MSJ_PARTIDA_INVALIDA "Partida Ya existente"

CrearPartida::CrearPartida(HashProtegido &partidas,
                           ConfiguracionServidor &mapasYAutos) : partidas(partidas), mapasYAutos(mapasYAutos) {
}

void CrearPartida::ejecutar(ClienteProxy &cliente) {
    std::string datosPartida = cliente.recibir();
    std::vector<std::string> datos = separar(datosPartida, ';');
    std::string clave = datos[0];
    int cantJugadores = std::stoi(datos[1]);
    if (partidas.ubicar(clave, new Partida(cantJugadores, mapasYAutos.darPlanoDePista("Prueba 1")))){
        partidas.obtener(clave)->start();
    }else{
        cliente.enviar(MSJ_PARTIDA_INVALIDA);
    }

    //EL MAPA SE ELIJE ANTES
/*    for (auto& mapa : mapasYAutos.obtenerNombresPlanos()){
        cliente.enviar(mapa);
    }
    cliente.enviar(MSJ_FIN);
    std::string mapa = cliente.recibir();*/
}
