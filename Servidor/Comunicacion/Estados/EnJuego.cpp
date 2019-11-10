#include "EnJuego.h"
#include "../../Partida/HashProtegido.h"
#include "../Utilidades.h"


#define MSJ_CMD_INVALIDO "ComandoInvalido"

void EnJuego::ejecutar(ClienteProxy &cliente) {
    std::string evento = cliente.recibir();
    std::vector<std::string> argumentos = separar(evento, ';');
    std::string eventoId = *argumentos.begin();
    if (comandos.find(eventoId) == comandos.end()){
        cliente.enviar(MSJ_CMD_INVALIDO);
    }else{
        argumentos.erase(argumentos.begin());
        comandos[eventoId]->ejecutar(cliente, argumentos);
    }
}


EnJuego::EnJuego(HashProtegido &partidas) {
    comandos.emplace("Accion", new RecibirAccion());
}
