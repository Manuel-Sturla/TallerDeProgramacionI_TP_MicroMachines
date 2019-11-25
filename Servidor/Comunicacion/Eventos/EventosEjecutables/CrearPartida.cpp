#include "CrearPartida.h"
#include "../../Utilidades.h"
#include "../EventosParseables/PartidaInvalida.h"
#include "../../../PartidaLlenaExcepcion.h"

#define MSJ_PARTIDA_INVALIDA "Partida Ya existente"

CrearPartida::CrearPartida(HashProtegido &partidas,
                           ConfiguracionServidor &mapasYAutos) : partidas(partidas), mapasYAutos(mapasYAutos) {
}

void CrearPartida::ejecutar(ClienteProxy &cliente, std::vector<std::string> argumentos) {
    std::string clave = argumentos[0];
    int cantJugadores = 1;
    int cantVueltas = 1;
    try{
        cantJugadores = std::stoi(argumentos[1]);
        cantVueltas = std::stoi(argumentos[2]);
    }catch(std::invalid_argument &e){
    }
    std::string pista = argumentos[3];
    if (partidas.ubicar(clave, new Partida(cantJugadores, \
    mapasYAutos.darPlanoDePista(pista), cantVueltas, mapasYAutos.obtenerMods()))){
        partidas.obtener(clave)->start();
    }else{
        cliente.encolarEvento(new PartidaInvalida());
    }
    //EL MAPA SE ELIJE ANTES
/*    for (auto& mapa : mapasYAutos.obtenerNombresPlanos()){
        cliente.enviar(mapa);
    }
    cliente.enviar(MSJ_FIN);
    std::string mapa = cliente.recibir();*/
}
