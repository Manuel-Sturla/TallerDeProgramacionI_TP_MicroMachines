#include "CrearPartida.h"
#include "../../Utilidades.h"
#include "../EventosParseables/PartidaInvalida.h"
#include "../../../PartidaLlenaExcepcion.h"

#define MSJ_PARTIDA_INVALIDA "Partida Ya existente"

#define CANT_ARGUMENTOS 4
#define CANT_MAX_JUGADORES 6
#define CANT_MAX_VUELTAS 10
#define PISTA_POR_DEFECTO "Dona"
#define CANT_JUGADORES_POR_DEFECTO 1
#define CANT_VUELTAS_POR_DEFECTO 1
CrearPartida::CrearPartida(HashProtegido &partidas,
                           ConfiguracionServidor &mapasYAutos) : partidas(partidas), mapasYAutos(mapasYAutos) {
}

void CrearPartida::ejecutar(ClienteProxy &cliente, std::vector<std::string> argumentos) {
    std::string clave = argumentos[0];
    int cantJugadores = CANT_JUGADORES_POR_DEFECTO;
    int cantVueltas = CANT_VUELTAS_POR_DEFECTO;
    std::string pista = PISTA_POR_DEFECTO;
    try{
        if (argumentos.size() == CANT_ARGUMENTOS) {
            cantJugadores = std::stoi(argumentos[1]);
        }
        if (cantJugadores > CANT_MAX_JUGADORES) {
            cantJugadores = CANT_MAX_JUGADORES;
        }
            cantVueltas = std::stoi(argumentos[2]);
        if (cantVueltas > CANT_MAX_VUELTAS){
            cantVueltas = CANT_MAX_VUELTAS;
        }
        pista = argumentos[3];
        std::vector<std::string> mapas = mapasYAutos.obtenerNombresPlanos();
        if (std::find(mapas.begin(), mapas.end(), pista) == mapas.end()){
            pista = PISTA_POR_DEFECTO;
        }
    }catch(std::invalid_argument &e){
    }
    if (partidas.ubicar(clave, new Partida(cantJugadores, \
    mapasYAutos.darPlanoDePista(pista), cantVueltas, mapasYAutos.obtenerMods()))){
        partidas.obtener(clave)->start();
    }else{
        cliente.encolarEvento(new PartidaInvalida());
    }
}
